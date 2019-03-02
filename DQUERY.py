n = int(input())
lst = [0]
tmp_lst = list(map(int, input().split()))
query_lst = [0]*(n+1)
for i in range(1, n+1):
	x = tmp_lst[i-1]
	if x not in lst:
		query_lst[i] = query_lst[i-1]+1
	else:
		query_lst[i] = query_lst[i-1]
	lst.append(x)
for _ in range(int(input())):
	a, b = map(int, input().split())
	print(query_lst[b])