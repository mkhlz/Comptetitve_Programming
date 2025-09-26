# https://www.codewars.com/kata/51fc12de24a9d8cb0e000001/python

isbn = "1234512345"

def valid_ISBN10(isbn):
    if len(isbn) != 10:
        return False
    sum = 0
    for idx, item in enumerate(str(isbn)):
        if item.isdigit() == False:
            continue
        curr = (idx + 1) * int(item)
        sum = sum + curr
    if sum % 11 == 0:
        return True
    else:
        return False

print(valid_ISBN10(isbn))
        
        