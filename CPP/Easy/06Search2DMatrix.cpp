#include <bits/stdc++.h>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int x) {

        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=n*m-1;
        int mid=(low+high)/2;

        while(low<=high)
        {
            mid=(low+high)/2;

			if(matrix[mid/m][mid%m]<x)
            	low=mid+1;
            else if(matrix[mid/m][mid%m]==x)
            	return true;
            else
            	high=mid-1;
        }
        return false;
}


int main()
{
    vector<vector<int>> arr = {{1,2,3,4},
							{5,6,7,8},
							{9,10,11,12}};
    int target = 8;

    cout<<searchMatrix(arr, target)<<endl;

    return 0;
}
