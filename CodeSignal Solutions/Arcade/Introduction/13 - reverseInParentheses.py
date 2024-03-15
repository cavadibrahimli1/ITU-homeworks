def solution(inputString):
    for i in range(len(inputString)):
        if inputString[i] == "(":
            start = i
        if inputString[i] == ")":
            end = i
            return solution(inputString[:start] + inputString[start+1:end][::-1] + inputString[end+1:])
    return inputString
