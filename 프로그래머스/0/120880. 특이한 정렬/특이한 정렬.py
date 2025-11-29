def solution(numlist, n):
    answer = []
    arr = []
    for num in numlist:
        dist = abs(n - num)
        arr.append((dist, -num))
    arr.sort()
    
    for tup in arr:
        answer.append(-tup[1])
    return answer