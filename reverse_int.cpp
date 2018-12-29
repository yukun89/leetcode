#define INT_MAX 0X7FFFFFFF
#define INT_MIN 0X80000000
class Solution {
public:
	//case:123, -123, -max, 10, overflow.
	//123>>321
    int reverse(int x) {
       long long y=0; 
	   long long tmp=x;
	   int flag=1;
	   if(tmp <0)
	   {
		   tmp = tmp*(-1);
		   flag = -1;
	   }
	   while( tmp !=0 ){
		   int last = tmp%10;
		   tmp = tmp/10;
		   y = y*10 +last;
	   }
	   if( y == INT_MAX+1)
		   return INT_MIN;
	   else if(y > INT_MAX +1)
		   return 0;
	   else
		   return (int)y*flag;
    }
};
