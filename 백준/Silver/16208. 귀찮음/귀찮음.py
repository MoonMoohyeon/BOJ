n = int(input())
li = list(map(int,input().split()))
li = sorted(li)
result = 0
length = 0
for i in li:
	length += i

for i in li:
	result += i * (length - i)
	length -= i

print(result)