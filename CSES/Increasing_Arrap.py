n, *a = map(int, open(0).read().split())
moves = 0
for i in range(1, n):
    if a[i] < a[i-1]:
        moves += a[i-1] - a[i]
        a[i] = a[i-1]
print(moves)