1.return the range, of [-1,-1]
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans(2,-1);
       int lower=search(nums, target);
	   if(lower>=nums.size() || target != nums[lower])
		   return ans;
	   int upper = search(nums, target+1);
	   ans.front()=lower;ans.back()=upper-1;
	   return ans;
    }
	int search(vector<int> &nums, int target){
		int l=0, r=nums.size()-1, mid=0;
		while(l<=r ){
			mid=(l+r)/2;
			if(nums[mid] == target)
				return mid;
			else if(target > nums[mid])
				l=mid+1;
			else
				r=mid-1;
		}
		return l;
	}
};
