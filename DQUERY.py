n = int(input())
lst = list(map(int, input().split()))
for _ in range(int(input())):
	i, j = map(int, input().split())
	print(len(set(lst[i-1:j])))