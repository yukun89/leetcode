class Solution {
public:
//1.empty nums, case2: 1, 1, 2; case 3: 1, 2, 3, 4
    int removeDuplicates(vector<int>& nums) {
	   if(nums.size()==0) return 0; 
	   int i=0, j=1;
	   while(j<nums.size()){
		   if(nums[j] != nums[i]){
			   i++;
			   nums[i] = nums[j];
		   	   j++;
		   }
		   else{
			   j++;
		   }
	   }
	   return i+1;
    }
};
