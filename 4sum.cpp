#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());
 		vector<vector<int>> ans;       
		int i=0, j=0, k=0, l=0;
		int N=nums.size();
		for(i=0;i<N;i++)
		{
			if(i>0 && nums[i]==nums[i-1])
				continue;
			for(j=i+1;i<N;j++)
			{
				if(j>i+1 && nums[j] == nums[j-1])
					continue;
				k=j+1;l=N-1;
				long long new_target = target - nums[i] - nums[j];
				while(k<l){
					long long test=nums[k] + nums[l];
					if(test == new_target){
						//could we use {}
						int tmp[]={nums[i], nums[j], nums[k], nums[l]};
						vector<int> line(tmp, tmp+4);
						ans.push_back(line);
						do{k++;}while(k+1<N && nums[k+1] ==nums[k]);
					}
					else if(test < new_target){
						while(k+1<N && nums[k+1] ==nums[k])
							k++;
					}
					else{
						while(l-1 >k && nums[l-1] == nums[l])
							l--;
					}
				}
			}
		}
		return ans;
    }
};
