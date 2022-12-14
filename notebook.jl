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
md"# Day 1"

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
md"# Day 2"

# ╔═╡ 995e1fb8-875f-48f0-8bc2-b81aa3bec651
md"# Day 3"

# ╔═╡ f9e5cdab-02a8-4314-a509-9f0b472dcaba
md"# Day 4"

# ╔═╡ 1e39b66d-fc6a-4dc1-b204-50d35dac18b2
let
	# input and helper functions
	input = readlines("./inputs/day4.txt")
	function ranges(line)
		l1, h1, l2, h2 = parse.(Int, split(line, r"-|,"))
		l1:h1, l2:h2
	end
	_in(a, b; by) = by(in(b), a) || by(in(a), b)
	_in(by) = x -> _in(x...; by) # currying

	p1 = count(_in(all)∘ranges, input)
	p2 = count(_in(any)∘ranges, input)
	p1, p2
end

# ╔═╡ 060155c9-ff07-48bc-a8f7-44007e7d14bb
md"# Day 5"

# ╔═╡ 1138d342-50d7-4663-81a8-9ce1ca050b25
let
	input = readchomp("./inputs/day5.txt")
	config_txt, inst_txt = split(input, "\n\n")
	config_M = replace(
			mapreduce(collect, hcat, 
				eachline(IOBuffer(config_txt))
			)[[2:4:34;], 1:end-1], 
		' '=>missing)
	inst = only.(eachmatch.(r"(\d+).*(\d+).*(\d+)", split(inst_txt, "\n")))
	
	function main(modifier)
		config = reverse.(collect.(skipmissing.(eachrow(config_M))))
		for i in inst
			n, from, to = parse.(Int64, i)
			E = lastindex(config[from])
			ran = E-n+1:E
			grab = config[from][ran]
			deleteat!(config[from], ran)
			append!(config[to], modifier(grab))	
		end
		join(last.(config))
	end
	
	p1 = main(reverse)
	p2 = main(identity)
	p1,p2
end

# ╔═╡ 08cb5e65-0a20-48ad-b14e-5296bff09023
md"# Day 6"

# ╔═╡ c610a703-eec7-4bad-ab2a-168091cc8207
let
	input = readchomp("./inputs/day6.txt")
	decode(txt, N) = findfirst(i -> allunique(txt[i-N+1:i]), N:lastindex(txt))+N-1
	
	p1 = decode(input, 4)
	p2 = decode(input, 14)
	p1,p2
end

# ╔═╡ 48398739-f46c-4ce2-807b-20c7a0da4502
md"# Day 7"

# ╔═╡ accf7d6e-e4ed-4abc-83aa-6289122d1dea
let
	input = readlines("./inputs/day7.txt")
	root_dict = Dict()
	current = ""
	for l in input
		target = last(split(l))
		if startswith(l, "\$ cd")
			current = normpath(joinpath(current, target))
		elseif startswith(l, "dir")
		elseif startswith(l, "\$ ls")
			root_dict[current] = Dict{String, Int}()
		else
			num, fname = split(l)
			fsize = parse(Int64, num)
			root_dict[current][fname] = fsize
		end
	end
	Ks = keys(root_dict)
	function dir_tot(path)
		all_subs = filter(startswith(path), Ks)
		return sum(sum(values(root_dict[sub])) for sub in all_subs)
	end
	
	p1 = 0; p2 = typemax(Int64)
	del_target = dir_tot("/") - 40000000
	for k in Ks
		dsum = dir_tot(k)
		if dsum < 100000
			p1 += dsum
		end
		if del_target < dsum < p2
			p2 = dsum
		end
	end
	p1, p2
end

# ╔═╡ d410eee3-d5a1-4aca-a77e-57421084d4bd
md"# Day 8"

# ╔═╡ 479775b7-5ba6-4f43-884a-79e28b108e0c
let
	input = mapreduce(collect, hcat, readlines("./inputs/day8.txt"))
	forest = parse.(Int, input)
	CI = CartesianIndex
	CIs = CartesianIndices(input)
	
	function treelines(c)
		c+CI(1, 0) : CI(99, c[2]),         #down
		c+CI(0, 1) : CI(c[1], 99),         #right
		reverse(CI(1, c[2]) : c-CI(1, 0)), #up
		reverse(CI(c[1], 1) : c-CI(0, 1))  #left
	end
	visible(c) = any(all(<(forest[c]), forest[tl]) for tl in treelines(c))
	p1 = count(visible, CIs)

	function scenic(c, tl)
		score = 0
		h0 = forest[c]
		for h in forest[tl]
			score += 1
			h >= h0 && break
		end
		score
	end
	scenic(c) = prod(scenic.(Ref(c), treelines(c)))
	p2=maximum(scenic, CIs)
	
	p1,p2
end

# ╔═╡ 77b46bc4-0b63-4a8a-8e06-92b3f0a3f12e
md"# Day 9"

# ╔═╡ 0c005615-a806-4501-90ed-88471522e5f0
let
	input = readlines("./inputs/day9.txt")
	CI = CartesianIndex
	function follow(H, T)
		Δ = H - T
		if abs(Δ[1]) <= 1 && abs(Δ[2]) <= 1
			T
		else
			T + CI(sign(Δ[1]), sign(Δ[2]))
		end
	end
	dir = Dict("R"=>CI(0,1), "L"=>CI(0, -1), "U"=>CI(1, 0), "D"=>CI(-1, 0))
	function snake(N)
		visited = Set([CI(1,1)])
		knots = fill(CI(1,1), N)
		for line in input
			d_txt, n_txt = split(line)
			d = dir[d_txt]
			n = parse(Int, n_txt)
			for _ = 1:n
				knots[1] += d
				for i = 2:N
					knots[i] = follow(knots[i-1], knots[i])
				end
				push!(visited, last(knots))
			end
		end
		return length(visited)
	end
	
	p1 = snake(2)
	p2 = snake(10)
	p1, p2
end

# ╔═╡ d741b76c-ac2e-483c-9a0c-b4c4aebf5777
md"# Day 10"

# ╔═╡ 6dd4a4e4-c541-4554-9aa8-160a6982bc16
let
	input = split.(readlines("./inputs/day10.txt"))
	cycle = X = idx = 1
	WIDTH = 40
	p1 = _add = 0
	canvas = fill('.', WIDTH, 6)
	
	while idx < lastindex(input)
		inst = input[idx]
		cycle in 20:40:220 && (p1 += X*cycle)
		X <= rem(cycle, WIDTH) <= X+2 && (canvas[cycle] = '#')
		
		if _add != 0 # buffered addv
			X += _add
			_add = 0
		elseif inst[1] == "noop"
			idx += 1
		elseif _add == 0
			_add = parse(Int, inst[2])
			idx += 1
		end
		cycle += 1
	end
	
	print(p1, '\n', join(join.(eachcol(canvas)), "\n"))
end

# ╔═╡ 63f8825c-5bfa-4b57-a0c0-76b35df34fc2
md"# Day 11"

# ╔═╡ 72894ac2-e464-47fb-8045-692a81e8ed73
let
	struct Monkey{F}
		items::Vector{Int}
		op::F
		div::Int
		targets::NTuple{2, Int}
		seen::Ref{Int}
	end
	function Monkey(str)
		l = split(str, '\n')
		items = parse.(Int, only.(eachmatch(r"(\d+)", l[2])))
		op_str, n = last(split(l[3]), 2)
		op = getfield(Main, Symbol(op_str))
		func = if n == "old"
			x -> op(x, x)
		else
			let N = parse(Int, n) # don't close-over `n`
				x -> op(x, N)
			end
		end
		testdiv = parse(Int, last(split(l[4])))
		targets = Tuple(parse(Int, last(split(x))) for x in l[5:6]) .+ 1
		
		Monkey(items, func, testdiv, targets, Ref(0))
	end
	function inspect!(M; denom, ring)
		(; op, items) = M
		M.seen[] += length(items)
		@. items = fld(op(mod(items, denom*ring)), denom)
	end
	monkeytest(M, item) = rem(item, M.div) == 0
	throwto(M, item, MS) = monkeytest(M, item) ? M.targets[1] : M.targets[2]
	function turn!(Ms, M; kw...)
		inspect!(M; kw...)
		items = M.items
		while !isempty(items)
			item = popfirst!(items)
			idx = throwto(M, item, M)
			push!(Ms[idx].items, item)
		end
	end
	function play!(N, Ms; kw...)
		for _=1:N, m in Ms
			turn!(Ms, m; kw...)
		end
		last(sort!([m.seen[] for m in Ms]), 2) |> prod
	end
	
	input = split(readchomp("./inputs/day11.txt"), "\n\n")

	monkeys = Monkey.(input)
	ring = prod(m.div for m in monkeys)
	p1 = play!(20, monkeys; denom=3, ring)
	p2 = play!(10000, Monkey.(input); denom=1, ring)

	p1, p2
end

# ╔═╡ d02baf9c-5989-4156-b97c-cc478c89f09d
md"## Day 12"

# ╔═╡ 230590e2-4404-4b02-9b27-73e2642f8584
let
	# Matrix{Char}
	input = mapreduce(permutedims∘collect, vcat, readlines("./inputs/day12.txt"))
	start = findfirst(==('S'), input)
	dest = findfirst(==('E'), input)
	CI = CartesianIndex
	adjs = Tuple(CI(x) for x in ((0,1), (0,-1), (1,0), (-1,0)))
	# Matrix{Int}
	terr = replace(input, 'S'=>'a', 'E'=>'z')

	function main(M, start, dest)
	    CM = CartesianIndices(M)
	    Q = [0=>start]
	    tot_risks = fill(typemax(Int), size(M))
	    while true
			isempty(Q) && return typemax(Int) # dead end
	        risk, here = pop!(Q)
	        tot_risks[here] <= risk && continue # not a better route
	        tot_risks[here] = risk
	        here == dest && return risk # reached goal
	
	        for a in adjs
	            (ne = here+a) ∉ CM && continue # out of bound
				M[ne] - M[here] >1 && continue # can't climb
	            s = risk + 1 => ne
	            i = searchsortedfirst(Q, s; rev=true)
	            insert!(Q, i, s)
	        end
	    end
	end

	p1 = main(terr, start, dest)
	As = findall(==('a'), terr)
	p2 = minimum(s->main(terr, s, dest), As)
	p1, p2
end

# ╔═╡ 293d9a47-ba00-44ef-8021-b893e0de5e26
md"## Day 13"

# ╔═╡ a6bdacd1-70e1-4878-bef4-4342d5dcdb23
let
	input = eval.(Meta.parse.(filter(!isempty, readlines("./inputs/day13.txt"))))
	comp(a::Number, b::Number) = a < b ? true : a > b ? false : nothing
	comp(a::Number, b::Vector) = comp([a], b)
	comp(a::Vector, b::Number) = comp(a, [b])
	function comp(a::Vector, b::Vector)
		for i in eachindex(b)
			!isassigned(a, i) && return true
			c = comp(a[i], b[i])
			isnothing(c) && continue # inconclusive
			return c
		end
		length(b) < length(a) && return false
		return nothing
	end

	p1 = findall(i->comp(input[i], input[i+1]), 1:2:300) |> sum
	
	push!(input, [[2]]); push!(input, [[6]])
	sort!(input; lt=comp)
	p2 = findfirst(==([[2]]), input) * findfirst(==([[6]]), input)

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
# ╟─060155c9-ff07-48bc-a8f7-44007e7d14bb
# ╠═1138d342-50d7-4663-81a8-9ce1ca050b25
# ╟─08cb5e65-0a20-48ad-b14e-5296bff09023
# ╠═c610a703-eec7-4bad-ab2a-168091cc8207
# ╟─48398739-f46c-4ce2-807b-20c7a0da4502
# ╠═accf7d6e-e4ed-4abc-83aa-6289122d1dea
# ╟─d410eee3-d5a1-4aca-a77e-57421084d4bd
# ╠═479775b7-5ba6-4f43-884a-79e28b108e0c
# ╟─77b46bc4-0b63-4a8a-8e06-92b3f0a3f12e
# ╠═0c005615-a806-4501-90ed-88471522e5f0
# ╟─d741b76c-ac2e-483c-9a0c-b4c4aebf5777
# ╠═6dd4a4e4-c541-4554-9aa8-160a6982bc16
# ╟─63f8825c-5bfa-4b57-a0c0-76b35df34fc2
# ╠═72894ac2-e464-47fb-8045-692a81e8ed73
# ╟─d02baf9c-5989-4156-b97c-cc478c89f09d
# ╠═230590e2-4404-4b02-9b27-73e2642f8584
# ╟─293d9a47-ba00-44ef-8021-b893e0de5e26
# ╠═a6bdacd1-70e1-4878-bef4-4342d5dcdb23
# ╟─00000000-0000-0000-0000-000000000001
# ╟─00000000-0000-0000-0000-000000000002
