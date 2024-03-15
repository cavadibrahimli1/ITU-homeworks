def solution(inputString):
    numbers = inputString.split('.')
    if len(numbers) != 4: return False
    for number in numbers:
        if not number.isdigit(): return False
        if int(number) not in range(256):
            return False
    return True

def solution(inputString):
    numbers = inputString.split('.')
    return len(numbers) == 4 and all(number.isdigit() and 0 <= int(number) <= 255 for number in numbers)

from ipaddress import ip_address as ip

def solution(inputString):
    try: ip(inputString)
    except: return False
    return True
