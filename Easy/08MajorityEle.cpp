#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n)
{
    map<int,int> mp;

	for(int i =0;i<n ;i++){
		mp[arr[i]]++;
	}

    int low = n/2;
	for(auto i: mp){
		if(i.second>low){
			return i.first;
		}
	}
	return -1;
}

int main()
{
    int arr[] = {2,3,9,2,2};
    int size = 5;

    cout<<findMajorityElement(arr, size);
    return 0;
}
