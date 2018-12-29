class Solution {
public:
	//1221, 121
    bool isPalindrome(int x) {
 		int temp=0; 
		while(x !=0){
			temp = temp * 10 +x%10;
			x=x/10;
		}
		return temp == x;	
    }
};
