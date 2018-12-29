#include<iostream>
#include<string>
using namespace std;
class Solution {
private:
	//test point: "X", "-4x"
	void find_mig(long long &a, long long &b, const string &s)
	{
		a=0;
		b=0;
		int flag=1, start=0;
		bool goon=true;
		while(goon == true)
		{
			size_t flag_index =s.find_first_of("+-", start);
			if(flag_index == string::npos)
			{
				flag_index=s.size();
				goon=false;
			}
			else if (flag_index ==0)
			{
				flag= s[flag_index]=='+'? 1:-1;
				continue;
			}
				string ss=s.substr(start, flag_index-start);
				if(ss=="x") ss="1x";
				long long temp=std::stoi(ss,nullptr); 
				if( ss.back()=='x'){
					b += temp*flag;
				}	
				else{
					a += temp*flag;
				}
			if(!goon)
				break;
				start = flag_index +1;
			flag= s[flag_index]=='+'? 1:-1;
		}

	}
public:
    string solveEquation(string equation) {
		string nostr="No solution", infstr= "Infinite solutions";
		//a+bx=c+dx >> (b-d)x=(c-a)
		size_t eq_index=equation.find_first_of("=");			
		if(eq_index == string::npos)
			return nostr;
		long long a=0, b=0, c=0, d=0;
		find_mig(a, b, equation.substr(0, eq_index));
		find_mig(c, d, equation.substr(eq_index+1));
		if(b==d)
		{
			if(c==a)
				return infstr;
			else
				return nostr;
		}
		return "x+"+std::to_string((c-a)/(b-d));
    }
	
};

int main()
{
	Solution solu;
	cout << solu.solveEquation("x+5-3+x=6+x-2");
}
