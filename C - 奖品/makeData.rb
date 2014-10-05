def setPath( i )
	s1 = "prize"
	s2 = i.to_s
	s3 = ".in"
	s1 + s2 + s3
end

def out( path, i )
	prng = Random.new
	t = 10
	File.open(path, "w") { |f|
		f << "#{t}\n"
		maxN = 1
		maxW = 1
		case i
		when 1
			maxN = 5; maxW = 1000;
		when 2, 3
			maxN = 9; maxW = 10000;
		when 4, 5, 6
			maxN = 15; maxW = 100000;
		when 7, 8, 9, 10
			maxN = 18; maxW = 1000000;
		end
		minN = maxN - 2
		t.to_i.times {
			n = prng.rand(minN..maxN)
			w = Array.new
			maxK = 1
			n.times {
				wi = prng.rand(1..maxW);
				maxK = maxK + wi;
				w << wi;
			}
			k = prng.rand(1..(2 * maxK))
			f << "#{n} #{k}\n"
			n.times { |i|
				f << "#{w[i]} "
			}
			f << "\n"
		}
	}
end

10.times { |j|
	out(setPath(j + 1), j + 1)
}