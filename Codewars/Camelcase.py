# https://www.codewars.com/kata/517abf86da9663f1d2000003/python

test = "the-stealth-warrior"

def to_camel_case(text):
    if not text:
        return ""
    parts = text.replace("-", "_").split("_")
    if text[0].islower():
        return parts[0] + "".join(word.capitalize() for word in parts[1:])
    else:
        return "".join (word.capitalize() for word in parts)