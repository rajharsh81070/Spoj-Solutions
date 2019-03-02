n, m = map(int, input().split())
lst = list(map(int, input().split()))
j = 0
ans = 0
mx = -1
for i in range(n):
	ans += lst[i]
	if ans > m:
		while ans > m:
			ans -= lst[j]
			j+=1
	if mx < ans:
		mx = ans
	# print(mx, end=' ')
print(mx, end='')