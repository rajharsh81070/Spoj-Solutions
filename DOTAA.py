for _ in range(int(input())):
	n, m, d = map(int, input().split())
	ans = 0
	for _ in range(n):
		h = int(input())
		ans += (h//d)
		if not(h%d):
			ans -= 1
	if ans >= m:
		print("YES")
	else:
		print("NO")