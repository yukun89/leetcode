class Solution {
public:
    int strStr(string haystack, string needle) {
 		int ans =-1;       
		size_t n=haystack.size(), m=needle.size();
		int i;
		for (i=0;i<=n-m; i++)	
		{
			if(haystack.compare(i, m, needle) ==0)
				return i;
		}
		return -1;
    }
};
