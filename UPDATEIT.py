BIT = [0]*10001

def update(i, val, n):
	idx = i
	while (i<=n):
		BIT[i]+=val
		i+=(i&(-i))
	# print()

def query(i, n):
	ans = 0
	while (i>0):
		ans+=BIT[i]
		i-=(i&(-i))
	return ans

for _ in range(int(input())):
	n, u = map(int, input().split())

	for _ in range(u):
		i, j, val = map(int, input().split())
		update(i+1, val, n)
		update(j+2, -val, n)

	for _ in range(int(input())):
		idx = int(input())
		print(query(idx+1, n))