### A Pluto.jl notebook ###
# v0.19.16

using Markdown
using InteractiveUtils

# ╔═╡ 286e3758-9787-44dc-841f-85348b2748cd
let
	# input and helper functions
	using DelimitedFiles
	day2_input = readdlm("./inputs/day2.txt", Char)
	function rps(a,b)
		r = a-b
		r == -23 ? 3 : r == -24 ? 6 : r == -21 ? 6 : 0
	end
	modifier = Dict('X'=>2,'Y'=>1,'Z'=>0)
	_mod(a,b) = mod1(a - b + modifier[b], 3)
	
	s1 = sum(replace(day2_input[:, 2], 'X' => 1, 'Y' => 2, 'Z' => 3))
	s2 = sum(Base.splat(rps), eachrow(day2_input))
	p1 = s1 + s2

	
	s3 = sum(Base.splat(_mod), eachrow(day2_input))
	s4 = sum(replace(day2_input[:, 2], 'X' => 0, 'Y' => 3, 'Z' => 6))
	p2 = s3+s4
	
	p1,p2
end

# ╔═╡ ce372dac-c58b-444b-b0b6-a88665a58771
let
	# input and helper functions
	input = readlines("./inputs/day3.txt")
	priority(c) = c in 'a':'z' ? c - '`' : c - 'A' + 27
	
	p1 = sum(priority∘only, [intersect(l[1:end÷2], l[end÷2+1:end]) for l in input])

	using Base.Iterators
	p2 = sum(priority∘only, [intersect(l...) for l in partition(input, 3)])
	p1, p2
end

# ╔═╡ 3156ab8c-71cb-11ed-204a-09b40247effd
md"## Day 1"

# ╔═╡ 25a6d924-5973-4868-91e2-3a4845a5a2a3
let
	# input and helper functions
	day1_input = readchomp("./inputs/day1.txt")
	elfenergy(str) = sum(parse.(Int64, split(str, "\n")))

	elfs = split(day1_input, "\n\n")
	sums = sort!(elfenergy.(elfs))
	#part1, part2
	sums[end], sum(last(sums, 3))
end

# ╔═╡ 6574e63c-d54c-4c53-8e28-0cd0e131ee41
md"## Day 2"

# ╔═╡ 995e1fb8-875f-48f0-8bc2-b81aa3bec651
md"## Day 3"

# ╔═╡ f9e5cdab-02a8-4314-a509-9f0b472dcaba
md"## Day 4"

# ╔═╡ 1e39b66d-fc6a-4dc1-b204-50d35dac18b2
let
	# input and helper functions
	input = readlines("./inputs/day4.txt")
	function ranges(line)
		l1, h1, l2, h2 = parse.(Int, split(line, r"-|,"))
		l1:h1, l2:h2
	end
	_in(a, b; by) = by(in(b), a) || by(in(a), b)
	_in(by) = x -> _in(x...; by) # curring

	p1 = count(_in(all)∘ranges, input)
	p2 = count(_in(any)∘ranges, input)
	p1, p2
end

# ╔═╡ 00000000-0000-0000-0000-000000000001
PLUTO_PROJECT_TOML_CONTENTS = """
[deps]
DelimitedFiles = "8bb1440f-4735-579b-a4ab-409b98df4dab"
"""

# ╔═╡ 00000000-0000-0000-0000-000000000002
PLUTO_MANIFEST_TOML_CONTENTS = """
# This file is machine-generated - editing it directly is not advised

julia_version = "1.8.3"
manifest_format = "2.0"
project_hash = "739f2f3af706c750957bd6ec39e0874ba8eb265d"

[[deps.DelimitedFiles]]
deps = ["Mmap"]
uuid = "8bb1440f-4735-579b-a4ab-409b98df4dab"

[[deps.Mmap]]
uuid = "a63ad114-7e13-5084-954f-fe012c677804"
"""

# ╔═╡ Cell order:
# ╟─3156ab8c-71cb-11ed-204a-09b40247effd
# ╠═25a6d924-5973-4868-91e2-3a4845a5a2a3
# ╟─6574e63c-d54c-4c53-8e28-0cd0e131ee41
# ╠═286e3758-9787-44dc-841f-85348b2748cd
# ╟─995e1fb8-875f-48f0-8bc2-b81aa3bec651
# ╠═ce372dac-c58b-444b-b0b6-a88665a58771
# ╟─f9e5cdab-02a8-4314-a509-9f0b472dcaba
# ╠═1e39b66d-fc6a-4dc1-b204-50d35dac18b2
# ╟─00000000-0000-0000-0000-000000000001
# ╟─00000000-0000-0000-0000-000000000002
