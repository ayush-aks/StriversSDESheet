# Return elements that appear more than n/3 times:
nums = [3,2,3]

def majorityElement(nums):
    d=dict()
    k=len(nums)//3
    a=[]
    for i in nums:
        if i in d:
            d[i]+=1
        else:
            d[i]=1
    for i in nums:
        if d[i]>k and i not in a:
            a.append(i)
    return a

print(majorityElement(nums))