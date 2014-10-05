def setPath( i )
	s1 = "guide"
	s2 = i.to_s
	s3 = ".in"
	s1 + s2 + s3
end

def out( path, i )
	prng = Random.new
	t = 120
	File.open(path, "w") { |f|
		f << "#{t}\n"
		maxN = 1
		minN = 1
		maxD = 1
		case i
		when 1
			minN = 20; maxN = 100; maxD = 5;
		when 2, 3
			minN = 100; maxN = 500; maxD = 10;
		when 4, 5, 6
			minN = 3500; maxN = 4000; maxD = 35;
		when 7, 8, 9, 10
			minN = 7500; maxN = 8000; maxD = 40;
		end
		t.to_i.times {
			n = prng.rand(minN..maxN)
			cur = 1
			endflag = n
			f << "#{n}\n"
			n.times { |i|
				if cur == endflag then 
					f << "#{i} 0\n"
				else 
					d = prng.rand(1..maxD)
					fst = cur
					snd = cur + d
					if snd >= endflag then 
						snd = endflag
						d = snd - fst
					end
					f << "#{i} #{d}"

					d.times { |j| f << " #{j + cur}" }
					f << "\n"
					cur = snd
				end
			}
		}
	}
end

10.times { |j|
	out(setPath(j + 1), j + 1)
}