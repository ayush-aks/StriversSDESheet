# returns index of array/list that add up to target
# Approach used -> HashMap (Dict)
nums = [2,1,3,5]
target = 4

def twoSum(nums, target):
    prevMap = {}  # Hashmap with val -> index

    for i, n in enumerate(nums):
        diff = target - n
        if diff in prevMap:
            return [prevMap[diff], i]
        prevMap[n] = i
    return []

print(twoSum(nums,target))