# One of the most popular problem in DSA 
# Also known as Maximum Subarray Sum problem 

arr = [1, 2, 7, -4, 3, 2, -10, 9, 1]
def maxSubarraySum(arr):
    curSum = 0
    maxSum = -99999999

    for i in range(len(arr)):
        curSum = curSum + arr[i]
        maxSum = max(maxSum, curSum)

        if curSum < 0:
            curSum = 0
    
    if maxSum < 0:
        maxSum = 0
    
    return maxSum

print(maxSubarraySum(arr))