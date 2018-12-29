#include<vector>
#include<map>
#include<set>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int len=nums.size(); 
	   int ans, diff= INT_MAX;
		sort(nums.begin(), nums.end());
		for(int first = 0; first<n; first++){
			long long find=target - nums[first];
			int front=first+1, back = n-1;
			while(front < back){
				long long tmp=nums[front] + nums[back];
				if(tmp < find){
					front ++;
				}else if(tmp> find){
					back --;
				}else{
					return target;
				}
				if(abs(find  - tmp) < diff){
					diff = abs(find - tmp);
					ans = tmp+nums[first];
				}
			}
		}
		return ans;
    }
};
