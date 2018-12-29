class Solution {
public:
    string convert(string s, int numRows) {
		if(numRows == 1) return s;
 		size_t len=s.length();	       
		std::vector<string> row(numRows, "");
		int index=0, flag=1, i;
		while(i < len){
			row[index].push_back(s[i++]);
			index += flag;
			if(index = numRows)
			{
				index = numRows -2;
				flag = -1;
			}
			else if(index == -1){
				index = 1;
				flag = 1;
			}
		}
		string res;
		for(auto each:row){
			res+=each;
		}
		return res;
    }
};
