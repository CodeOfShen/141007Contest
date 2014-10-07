def setPath( i )
	s1 = "queue"
	s2 = i.to_s
	s3 = ".in"
	s1 + s2 + s3
end

def out( path, i )
	prng = Random.new
	t = prng.rand(1000..1500)
	File.open(path, "w") { |f|
		f << "#{t}\n"
		maxN = 10 ** (i + 1);
		t.to_i.times {
			a = prng.rand(0..maxN.to_i)
			f << "#{a}\n"
		}
	}
end

10.times { |i|
	out(setPath(i + 1), i + 1)
}