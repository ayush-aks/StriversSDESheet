# Majority Element 2 - Sorting approach
# Can also be solved using Hash Map or Moore Voting Algorithm
nums = [2,2,1,1,1,2,2]

def majorityElement(nums):
    nums.sort()
    n = len(nums)
    return nums[n//2]

print(majorityElement(nums))