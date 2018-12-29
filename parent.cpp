#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> ans;
   		if (n==0) return ans; 	     
		if (n==1) {
			ans.push_back("()");
			return ans;
		}

		int left=1;
		for(left=1;left<=n;left++)		
		{
			vector<string> l_res = generateParenthesis(left-1);
			if( l_res.size() == 0){
				l_res.push_back("()");
			}else{
				for(int i=0;i<l_res.size();i++){
					l_res[i].push_back(')');
					l_res[i].insert(l_res[i].begin(), '(');
				}
			} 
			vector<string> r_res = generateParenthesis(n-left);
			for(int i=0;i<l_res.size();i++)
			{
				for(int j=0;j<r_res.size();j++){
					ans.push_back(l_res[i] + r_res[j]);
				}
				if(r_res.size() == 0){
					ans.push_back(l_res[i]);
				}
			}
		}
		return ans;
    }
};
