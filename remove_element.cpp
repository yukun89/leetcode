class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int i=0, j=nums.length()-1;
		while(i<j){
			if(nums[i] != val)
				i++;
			else{
				int tmp=nums[i];
				nums[i]=nums[j];
				nums[j]=tmp;
				j--
			}
		}	
		return nums[i] != val ? i+1:i;
    }
};
