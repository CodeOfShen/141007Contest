def setPath( i )
	s1 = "test"
	s2 = i.to_s
	s3 = ".in"
	s1 + s2 + s3
end

def out( path, i )
	prng = Random.new
	t = 10
	File.open(path, "w") { |f|
		f << "#{t}\n"
		minN = 7500; maxN = 8000; maxD = 40;
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

1.times { |j|
	out(setPath(j), j)
}