#include<string>
using namespace std;
class Solution {
public:
	//aaaa, abcba
    string longestPalindrome(string s) {
	size_t len=s.length();
	bool ans[len+1][len+1];//index, len
	for(int i=0;i<len;i++){
		ans[i][0]=true;
		ans[i][1]=true;
	}
	string res=s.substr(0,1);
	for(int l=2;l<=len;l++){
		for(int i=0;i<=len-l;i++){
			ans[i][l]= (ans[i+1][l-2]) && (s[i] == s[i+l-1]);
			if(ans[i][l]) res=s.substr(i,l);
		}
    }
	return res;
	}
};

