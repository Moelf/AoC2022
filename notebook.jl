### A Pluto.jl notebook ###
# v0.19.16

using Markdown
using InteractiveUtils

# ╔═╡ 3156ab8c-71cb-11ed-204a-09b40247effd
md"## Day1"

# ╔═╡ 25a6d924-5973-4868-91e2-3a4845a5a2a3
begin
	# input and helper functions
	day1_input = readchomp("./inputs/day1")
	day1_elfenergy(str) = sum(parse.(Int64, split(str, "\n")))

	day1_elfs = split(day1_input, "\n\n")
	day1_sums = sort!(day1_elfenergy.(day1_elfs))
	#part1, part2
	day1_sums[end], sum(last(day1_sums, 3))
end

# ╔═╡ 00000000-0000-0000-0000-000000000001
PLUTO_PROJECT_TOML_CONTENTS = """
[deps]
"""

# ╔═╡ 00000000-0000-0000-0000-000000000002
PLUTO_MANIFEST_TOML_CONTENTS = """
# This file is machine-generated - editing it directly is not advised

julia_version = "1.8.3"
manifest_format = "2.0"
project_hash = "da39a3ee5e6b4b0d3255bfef95601890afd80709"

[deps]
"""

# ╔═╡ Cell order:
# ╟─3156ab8c-71cb-11ed-204a-09b40247effd
# ╠═25a6d924-5973-4868-91e2-3a4845a5a2a3
# ╟─00000000-0000-0000-0000-000000000001
# ╟─00000000-0000-0000-0000-000000000002
