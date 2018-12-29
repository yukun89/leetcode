#include<string>
#include<deque>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
 		std::deque<char> sto;	       
		for(int i=0;i<s.length();i++){
			if(!sto.empty()){
				char top=sto.back();
				if(match(top, s[i]))
				{
					sto.pop_back();
					continue;
				}
			}
			if(sto.empty() && !isleft(s[i]))
					return false;
			sto.push_back(s[i]);
		}
		return sto.empty();
    }
	bool isleft(char ch){
		return ch=='(' || ch=='[' || ch=='{';
	}
	bool match(char a, char b)
	{
		return (a=='(' && b==')') ||
		(a=='[' && b==']') ||
		(a=='{' && b=='}');
	}
};
