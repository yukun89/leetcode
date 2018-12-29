#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int left=0, right=nums.size()-1;        
		int mid=left;
		int ans=left;
		while(left <= right){
			mid=(left+right)/2;
			if(target == nums[mid])
				ans=mid;
			else if(target > nums[mid])
				left = mid+1;
			else
				right = mid-1;
		}
		return left;
    }
};
