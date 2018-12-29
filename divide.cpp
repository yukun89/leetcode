#include<climit>
typedef long long ll;
class Solution {
public:
	//INT_MIN, -1
    int divide(int dividend, int divisor) {
 		if(divisor == 0) return INT_MAX;      
		ll ans=0;
		ll n=abs(ll(dividend));
		ll d=abs(ll(divisor));
		while(n>=d){
			ll a = d;
			ll m=1;
			while(n > (a<<1)) { a<<=1;m<<1;}
			ans +=m;
			n-=a;
		}
		if(dividend < 0 && dividend >0 || dividend >=0 && divisor <0) 
			return -ans;
		else
			return ans;
    }
};
