#!/usr/bin/env python
# Desuno! the judgement tool for competitive programming
# Copyright(C) 2011 peryaudo. All rights reserved.

import sys
import os
import os.path
import optparse
import pickle
import re
import urllib2
import lxml.html
import subprocess

# Abstract Classes
class website:
	REQUIRE_COMPILE_TIME_TESTER = False
	def __init__(self):
		return
	def get_test_data(self, name, cache, testcase_name=''):
		return ('', '')
	def get_compile_time_tester(self, name, lang_name):
		return ''

class language:
	LANGUAGE = ''
	def __init__(self):
		return
	def compile(self, filename, tmpdir, compile_time_tester=''):
		return
	def test(self, tmpdir, testdata=''):
		return

# Judgement site and Compiler dependency classes, should be moved to another .py
class AOJ(website):
	def get_test_data(self, name, cache, testcase_name=''):
		if cache.exist(name + '_in') and cache.exist(name + '_out'):
			return (cache.get(name + '_in'), cache.get(name + '_out'))

		problem_id = re.sub('^aoj([0-9]+)$', r'\1', name)

		root = lxml.html.fromstring(urllib2.urlopen('http://rose.u-aizu.ac.jp/onlinejudge/ProblemSet/description.jsp?id=' + '%04u' % int(problem_id)).read())
		sample_input = root.xpath('//h2[.="Sample Input"]/following-sibling::node()/text()')
		dst_in = ''
		if len(sample_input) > 0:
			dst_in = sample_input[0].strip() + '\n'
		cache.set(name + '_in', dst_in)

		sample_output = root.xpath('//h2[.="Sample Output"]/following-sibling::node()/text()')
		if len(sample_output) == 0:
			sample_output = root.xpath('//h2[.="Output for the Sample Input"]/following-sibling::node()/text()')

		dst_out = ''
		if len(sample_output) > 0:
			dst_out = sample_output[0].strip() + '\n'
		cache.set(name + '_out', dst_out)

		return (dst_in, dst_out)

class JOI(AOJ):
	LISTS = {'pre5': 500, 'pre6': 510, 'pre7': 521, 'pre8': 532, 'pre9': 543,
			'final5': 505, 'final6': 516, 'final7': 527, 'final8': 538}
	def get_test_data(self, name, cache, testcase_name=''):
		problem_id = re.sub('^joi([a-z0-9]+)_([0-9]+)$', r'\1 \2', name).split(' ')
		if len(problem_id) < 2:
			return ('', '')
		if (testcase_name == '' or testcase_name == 'AOJ'):
			aoj_problem_id = 'aoj%04u' % (int(problem_id[1]) - 1 + self.LISTS[problem_id[0]])
			return AOJ.get_test_data(self, aoj_problem_id, cache)
		else:
			return ('', '')

class gxx(language):
	LANGUAGE = 'C++'
	def compile(self, filename, tmpdir, compile_time_tester=''):
		fi = open(filename, 'r')

		os.chdir(tmpdir)
		fo = open('desuno_tmp.cpp', 'w')

		fo.write(fi.read())
		fo.write(compile_time_tester)

		fo.close()
		fi.close()

		if os.system('g++ -o desuno_tmp desuno_tmp.cpp'):
			return True
		return False

	def test(self, tmpdir, testdata='', answerdata=''):
		os.chdir(tmpdir)
		p = subprocess.Popen('./desuno_tmp', stdin=subprocess.PIPE, stdout=subprocess.PIPE)

		return p.communicate(testdata)[0]

# Cache class for test data
class tester_cache:
	def __init__(self, cachedir):
		self.cachedir = os.path.abspath(cachedir)
		if not os.path.exists(cachedir):
			os.mkdir(cachedir)
		return

	def exist(self, key):
		return os.path.exists(self.cachedir + '/' + key)

	def get(self, key):
		dst = ''
		if os.path.exists(self.cachedir + '/' + key):
			f = open(self.cachedir + '/' + key, 'rb')
			dst = f.read()
			f.close()
		return dst

	def set(self, key, value):
		f = open(self.cachedir + '/' + key, 'wb')
		f.write(value)
		f.close()
		return

# Main class
class desuno:
	FILETYPES = {'.cpp': gxx()}
	WEBSITES = [('aoj[0-9]+', AOJ()), ('joi[a-z0-9_]+', JOI())]
	tmpdir = '/tmp'
	def __init__(self, argv):
		if self.parse_args(argv):
			sys.stderr.write('too few arguments. to show usage, use --help or -h\n')
			return

		if self.parse_file_type(self.filename):
			sys.stderr.write('could not detect language or contest by its filename.\n')
			return

		#self.cache = tester_cache(os.path.dirname(os.path.abspath(__file__)) + '/.desuno_cache')
		self.cache = tester_cache(self.tmpdir + '/.desuno_cache')


		if self.mode == 'run':
			self.run()
		elif self.mode == 'compile':
			self.compile()
		elif self.mode == 'test':
			self.test()
		else:
			sys.stderr.write('invalid mode.\n')
			return

	def parse_args(self, argv):
		op = optparse.OptionParser('%prog [options] <mode> <filename>')
		op.add_option('-t', '--tester', type='string', dest='tester', help='use particular test data')
		op.add_option('-r', '--raw_tester', type='string', dest='raw_tester', help='use raw test data')

		(self.options, args) = op.parse_args(argv)
		if len(args) < 2:
			return True
		
		(self.mode, self.filename) = args[1], args[2]
		return False

	def parse_file_type(self, filename):
		(self.name, ext) = os.path.splitext(os.path.basename(self.filename))
		if ext in self.FILETYPES:
			self.lang = self.FILETYPES[ext]
		else:
			return True

		no_match = True
		for pattern, site in self.WEBSITES:
			if re.match(pattern, self.name):
				self.site = site
				no_match = False

		if no_match:
			return True

		return False

	def run(self):
		if self.compile():
			sys.stderr.write('[compile returns not 0. exit.]\n')
			return
		self.test()
		return

	def compile(self):
		tester = ''
		if self.site.REQUIRE_COMPILE_TIME_TESTER:
			tester = self.site.get_compile_time_tester(self.name, self.lang.LANGUAGE)

		if self.lang.compile(self.filename, self.tmpdir, tester):
			return True
		return False

	def test(self):
		testdata, answerdata = self.site.get_test_data(self.name, self.cache)
		testdata = testdata.replace('\r', '')
		answerdata = answerdata.replace('\r', '')
		ret = self.lang.test(self.tmpdir, testdata, answerdata)
		ret = ret.replace('\r', '')
		print ret
		if answerdata != '':
			if ret == answerdata:
				print '[The answer is correct]'
			else:
				if ret.strip() == answerdata.strip():
					print '[The answer is wrong, but it is an presentation error]'
				else:
					print '[The answer is wrong. expected answer is ]'
					print answerdata
		return

if  __name__ == '__main__':
	d = desuno(sys.argv);
