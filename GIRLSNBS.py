import math
g, b = map(int , input().split())
while g!=-1 and b!=-1:
	if b > g:
		g, b = b, g
	ans = 0
	if g!=0 and b!=0:
		ans = math.ceil(g/(b+1.0))
	print(ans)
	g, b = map(int , input().split())