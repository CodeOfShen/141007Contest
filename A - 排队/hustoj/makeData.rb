def setPath( i )
	s1 = "queue"
	s2 = i.to_s
	s3 = ".in"
	s1 + s2 + s3
end

def out( path)
	prng = Random.new
	t = 1497
	File.open(path, "w") { |f|
		f << "1500\n0\n1\n2\n"
		maxN = 10 ** (11);
		t.to_i.times {
			a = prng.rand(0..maxN.to_i)
			f << "#{a}\n"
		}
	}
end

out("test0.in")