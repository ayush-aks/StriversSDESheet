# nums -> Provided in leetcode ide
nums = [2,0,2,1,1,0]
def sortColors(nums):
    left = i = 0
    right = len(nums) - 1
    while i <= right :
        while(nums[i] == 2 and i < right):
            nums[i], nums[right] = nums[right], nums[i]
            right -= 1
        while(nums[i] == 0 and i > left):
            nums[i], nums[left] = nums[left], nums[i]
            left +=1
        i += 1

print(sortColors(nums))