inp = input()
li = list(inp)
chk = 0
for i in li:
	chk += int(i)

if '0' not in inp or chk % 3 != 0:
	print(-1)
else:
	li.sort(reverse=True)
	print(''.join(li))