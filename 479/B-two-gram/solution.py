n = int(input())
s = input()

best_count = 0
for i in range(n - 1):
    substr = s[i:i+2]
    pos = s.find(substr, 0)
    count = 0
    while pos != -1:
        count += 1
        pos = s.find(substr, pos+1)
    if count > best_count:
        ans = substr
        best_count = count
print(ans)
    
