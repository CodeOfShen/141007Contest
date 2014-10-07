def setPath( i )
	s1 = "prize"
	s2 = i.to_s
	s3 = ".in"
	s1 + s2 + s3
end

def out( path )
	prng = Random.new
	t = 20
	File.open(path, "w") { |f|
		f << "#{t}\n"
		maxN = 16; maxW = 10000;
		minN = maxN - 2
		t.to_i.times {
			n = maxN
			w = Array.new
			maxK = 1
			n.times {
				wi = prng.rand(1..maxW);
				maxK = maxK + wi;
				w << wi;
			}
			k = prng.rand(1..(6 * maxK))
			f << "#{n} #{k}\n"
			n.times { |i|
				f << "#{w[i]} "
			}
			f << "\n"
		}
	}
end


out("test0.in")