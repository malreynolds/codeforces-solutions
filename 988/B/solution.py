

from functools import cmp_to_key

n = int(input())
strings = []
for i in range(n):
    s = input()
    strings.append(s)

def compare(x, y):
    return True

strings.sort(key=cmp_to_key(compare))
print(strings)
valid = True
for i in range(n - 1):
    if strings[i] not in strings[i + 1]:
        valid = False
        break

if valid:
    print("YES")
    for s in strings:
        print(s)
else:
    print("NO")