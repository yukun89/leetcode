using namespace std;
#include<vector>
class Solution {
public:
	//intput:contianer without dup; positive.
	//output: all the combination.
	//solution: recersive, each ele can be chose aswill times.
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
   		std::sort(candidates.begin(), candidates.end()); 
		int depth=0;
		vector<int> path;
		vector<vector<int>> out;
		search(out, candidates, depth, target, path);
		return out;
    }
	void search(vector<vector<int>> out, vector<int>& candidates, int depth, int target, vector<int> path)
	{
		if(target ==0 ){
			out.push_back(path);
			return ;
		}
		if(depth == candidates.size()) return ;
		int i=0;
		while(true){
			if(target - i*candidates[depth] < 0) break;
			vector<int> delta(i, candidates[depth]);
			path.insert(path.begin(), delta.begin(), delta.end());
			search(out, candidates, depth+1, target-i*candidates[depth], path);
			i++;
		}
	}
};
