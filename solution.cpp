#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	//case : empty.
    vector<string> letterCombinations(string digits) {
 		std::map<char,string> mapping;
		mapping.insert(make_pair('0', " "));
		mapping.insert(make_pair('1', ""));
		mapping.insert(make_pair('2', "abc"));
		mapping.insert(make_pair('3', "def"));
		mapping.insert(make_pair('4', "ghi"));
		mapping.insert(make_pair('5', "jkl"));
		mapping.insert(make_pair('6', "mno"));
		mapping.insert(make_pair('7', "pqrs"));
		mapping.insert(make_pair('8', "tuv"));
		mapping.insert(make_pair('9', "xyz"));
		vector<string> ans;
		string init;
		func(ans, digits, 0, init, mapping);
		return ans;
    }
	void func(vector<string> &ans, const string &digits, int cur, string &pre, map<char,string> &dict){
		if(cur == pre.length() ) {
			if(cur != 0){
				ans.emplace_back(pre);
			}
			return ;
		}
		char ch=pre[cur];
		for(auto &w:dict[ch]){
			string new_pre(pre);
			new_pre.push_back(w);
			func(ans, digits, cur+1, new_pre , dict);
		}
		return ;
	}
    vector<string> run(string digits) {
		return letterCombinations(digits);
	}
};
