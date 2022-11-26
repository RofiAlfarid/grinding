


def pairs(k, arr):
    # Write your code here
    arr.sort()
    print(arr)
    l = len(arr)
    res = 0
    for i in range(l):
        for j in range(i+1,l):
            if arr[j] - arr[i] > k:
                break
            elif arr[j] - arr[i] == k:
                res += 1
                break
    return res