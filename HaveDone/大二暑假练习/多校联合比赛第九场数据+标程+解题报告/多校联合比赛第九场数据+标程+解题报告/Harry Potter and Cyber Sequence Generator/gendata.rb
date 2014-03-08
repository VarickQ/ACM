#!/usr/bin/ruby
puts 10
names = ["SET", "ADD", "MUL"]
op1   = ["C1", "C2"]
10.times{
  puts rand 10000000
  rand(100).times{
	x = names.sample
        y = op1.sample
        if x != "MUL"
	    if rand(100) > 37
                 z = rand(1000000000)
            else
                 z = op1.sample
            end
        else
		z = rand(1000000000)
	end
        puts "#{x} #{y}, #{z}"        
  }
  puts "END"
  puts q = rand(100)
  q.times{
       puts rand(1e99.to_i)
  }
}