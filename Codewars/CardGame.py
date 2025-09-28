# https://www.codewars.com/kata/61fef3a2d8fa98021d38c4e5/train/python

memo = {}
def card_game(n):
    if n in memo: return memo[n]
    if n == 0: return 0
    if n % 2: # odd
        res = n - card_game(n - 1)
    else: # even
        if n % 4 == 0:
            res = 3 if n == 4 else max(n - card_game(n // 2), n // 2 + card_game(n // 2 - 2))
        else:
            res = max(n // 2 + card_game(n // 2 - 1), 1 + card_game(n - 2))    
    memo[n] = res
    return res

# Test

print(card_game(10))
print(card_game(4))
print(card_game(5))
print(card_game(12))
print(card_game(100000000000))