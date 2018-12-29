//re: candidates, idx, N.
//key:no dup
//solu:
//test:1. [1, 1, 1, 1]
#include<map>
#include<vector>
using namespace std;

class Solution {
	public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		map<int,int> can_num_map;
		for(auto &a:candidates)
		{
			if(can_num_map.find(a) == can_num_map.end())
			{
				can_num_map[a]=1;
			}
			else
				can_num_map[a]++;
		}
	    vector<vector<int>> ans;
		vector<int> path;
		search(ans, can_num_map, 0/*index*/, target, path) ;    
		return ans;
	}
	void search(vector<vector<int>> &ans, map<int, int>&can_num_map, int idx, int target, vector<int> path){
		if(target == 0)
		{
			ans.push_back(path);
			return ;
		}else if(target < 0)
			return ;
		if(idx == can_num_map.size()) return ;
		//try
		map<int, int>::iterator it=can_num_map.begin();
		for(int i=0;i<idx;i++) it++;
		int val=it->first;
		int count = it->second;
		if(target >= val )
		{
			for(int i=0;i<count+1;i++)
			{
				search(ans, can_num_map, idx+1, target-i*val, path);
				path.push_back(val);
			}
		}
	}
};
