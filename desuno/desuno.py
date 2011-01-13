#!/usr/bin/env python
# Desuno! the judgement tool for competitive programming
# Copyright(C) 2011 peryaudo. All rights reserved.

import sys
import os
import os.path
from optparse import OptionParser
import pickle
import re

# Abstract Classes
class website:
	REQUIRE_COMPILE_TIME_TESTER = False
	def __init__(self):
		return
	def get_test_data(self, cache, option=''):
		return ''
	def get_compile_time_tester(self, lang_name):
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
	def get_test_data(self, cache, option=''):
		#!FIXME! write tester obtainer
		return ''

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

	def test(self, tmpdir, testdata=''):
		os.chdir(tmpdir)
		#!FIXME! write tester using stdin
		return

# Cache class for test data
class tester_cache:
	def open(self, filename):
		self.filename = os.path.abspath(filename)
		self.testers = {}

		if os.path.exists(filename):
			f = open(filename, 'r')
			self.testers = pickle.load(f)
			f.close()
		return

	def save(self, filename=''):
		f = open(filename if filename != '' else self.filename, 'w')
		pickle.dump(self.testers, f)
		f.close()
		return

	def get(self, key):
		if key in self.testers:
			return self.testers[key]
		else:
			return ''

	def set(self, key, value):
		self.testers[key] = value
		return

# Main class
class desuno:
	FILETYPES = {'.cpp': gxx()}
	WEBSITES = [('aoj[0-9]+', AOJ())]
	tmpdir = '/tmp'
	def __init__(self, argv):
		if self.parse_args(argv):
			sys.stderr.write('too few arguments. to show usage, use --help or -h\n')
			return

		if self.parse_file_type(self.filename):
			sys.stderr.write('could not detect language or contest by its filename.\n')
			return

		self.cache = tester_cache()
		self.cache.open(os.path.dirname(os.path.abspath(__file__)) + '/.desuno_cache')


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
		op = OptionParser('%prog [options] <mode> <filename>')
		op.add_option('-t', '--tester', type='string', dest='tester', help='use particular test data')

		(self.options, args) = op.parse_args(argv)
		if len(args) < 2:
			return True
		
		(self.mode, self.filename) = args[1], args[2]
		return False

	def parse_file_type(self, filename):
		(root, ext) = os.path.splitext(self.filename)
		tail = os.path.basename(self.filename)
		if ext in self.FILETYPES:
			self.lang = self.FILETYPES[ext]
		else:
			return True

		no_match = True
		for pattern, site in self.WEBSITES:
			if re.match(pattern, tail):
				self.site = site
				no_match = False

		if no_match:
			return True

		return False

	def run(self):
		self.compile()
		self.test()
		return

	def compile(self):
		tester = ''
		if self.site.REQUIRE_COMPILE_TIME_TESTER:
			tester = self.site.get_compile_time_tester(self.lang.LANGUAGE)

		self.lang.compile(self.filename, self.tmpdir, tester)
		return

	def test(self):
		self.lang.test(self.tmpdir)

		return

if  __name__ == '__main__':
	d = desuno(sys.argv);
