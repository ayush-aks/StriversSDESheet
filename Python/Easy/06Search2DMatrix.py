# Using Binary Search Approach
matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
target = 3
def searchMatrix(matrix, target):
    for i in range(len(matrix)):
        low=0
        high=len(matrix[i])-1
        while low<=high:
            mid=low+(high-low)//2
            if matrix[i][mid]==target:
                return True
            elif matrix[i][mid]<target:
                low=mid+1
            else:
                high=mid-1
    return False

print(searchMatrix(matrix, target))