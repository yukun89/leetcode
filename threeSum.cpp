#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	//can not use may times.
	//no dumplicated result.
    vector<vector<int>> threeSum(vector<int>& nums) {
		map<long long, int> tmp;
 		for(auto a:nums){
			if(tmp.find(a) == tmp.end()){
				tmp[a]=1;
			}else{
				tmp[a]++;
			}
		} 
		set<vector<int> > tans;
		int n=nums.size();
		for(int i=0;i<n;i++){
			for(int j=i+1;i<n;i++){
				long long target=(long long)nums[i]+(long long)nums[j];
				target = target *(-1);
				if (tmp.find(target) != tmp.end()){
					int occ=0;
					if(tmp.find(nums[i]) != tmp.end()) occ++;
					if(tmp.find(nums[j]) != tmp.end()) occ++;
					if(tmp[target] > occ) {
						vector<int> each;
						each.push_back(nums[i]);
						each.push_back(nums[j]);
						each.push_back(target);
						std::sort(each.begin(),each.end());
						tans.insert(each);
					}
				}
			}
		}
		vector<vector<int>> ans;
		for(auto e:tans)
			ans.push_back(e);
		return ans;
    }
};
