main = getLine >>= putStrLn . show . solve . (read :: String -> Int)
	where solve 0 = 1
	      solve n = (3 ^ (n - 1)) `mod` (10^6 + 3)
