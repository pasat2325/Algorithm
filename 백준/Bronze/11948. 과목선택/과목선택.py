arr1 = [int(input()) for i in range(4)]
arr2 = [int(input()) for i in range(2)]
arr1 = sorted(arr1)
arr2 = sorted(arr2)
res = arr2[1] + arr1[1] + arr1[2] + arr1[3]
print(res)   