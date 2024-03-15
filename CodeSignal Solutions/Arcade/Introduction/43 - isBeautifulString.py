def solution(inputString):
    s = set(inputString)
    s = sorted(s)
    abc = "abcdefghijklmnopqrstuvwxyz"
    for i in range(len(s)):
        if s[i] != abc[i]:
            return False
    for i in range(1, len(s)):
        if ord(s[i]) - ord(s[i-1]) != 1:
            return False
        if inputString.count(s[i]) > inputString.count(s[i-1]):
            return False
    return True
def solution(inputString):
    result = [inputString.count(c) for c in string.ascii_lowercase]
    return result[::-1] == sorted(result)