# https://codeforces.com/problemset/problem/59/A
# Author: mkhlz

s = input().strip()
l = sum(1 for c in s if c.islower())
u = sum(1 for c in s if c.isupper())
print(s.lower() if l >= u else s.upper())