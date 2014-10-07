def setPath( i )
	s1 = "test"
	s2 = i.to_s
	s3 = ".in"
	s1 + s2 + s3
end

def out( path, i )
	prng = Random.new
	t = 150
	File.open(path, "w") { |f|
		f << "#{t}\n"
		maxN = 1
		case i
		when 1
			maxN = 10 ** (1500)	
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

1.times { |i|
	out(setPath(i + 1), i + 1)
}