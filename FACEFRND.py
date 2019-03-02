lst = []
ans = 0
for _ in range(int(input())):
	tmp_lst = list(map(float, input().split()))
	tmp_lst.pop(1)
	if tmp_lst[0] in lst:
	lst = lst + tmp_lst
print(len(set(lst)))