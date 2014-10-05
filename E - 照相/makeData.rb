def setPath( i )
	s1 = "photo"
	s2 = i.to_s
	s3 = ".in"
	s1 + s2 + s3
end

def out( path, i )
	prng = Random.new
	t = 200
	File.open(path, "w") { |f|
		f << "#{t}\n"
		maxN = 1
		case i
		when 1
			maxN = 1000000
		when 2, 3
			maxN = 10 ** 12
		when 4, 5, 6
			maxN = 10 ** (160 * i)
		when 7, 8, 9, 10
			maxN = 10 ** (150 * i)
		end
		t.to_i.times {
			a = prng.rand(1..maxN.to_i)
			b = prng.rand(1..maxN.to_i)
			maxK = a * b * 2;
			k = prng.rand(1..maxK.to_i)
			f << "#{a} #{b} #{k}\n"
		}
	}
end

10.times { |i|
	out(setPath(i + 1), i + 1)
}