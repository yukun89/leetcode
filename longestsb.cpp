class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if(s.length() < 2)
			return s.length();
 		int i=0, j=1;       
		std::Set<char> cons;
		cons.insert(s[0]);
		while(i<s.length() && j<s.length())
		{
			if(cons.find(s[j]) == cons.end())
			{
				cons.insert(s[j++]);
				mx=std::max(mx,j-i)
			}
			else{
				cons.era(s[i++]);
			}
		}
		return mx;
    }
};
