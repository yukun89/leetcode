#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	//at lest one string in strs.
	//a, b
    string longestCommonPrefix(vector<string>& strs) {
 	    size_t  row = strs.size();       
		bool end=false;
        int j;
		for( j=0;;j++){
			for(int i=0; i<row; i++){
				if(strs[i].length()<j+1 || strs[0][j] != strs[i][j]){
					end=true;
					break;
				}
			}
			if(end) 
				break;
		}
		//failed in index = j.
		return strs[0].substr(0,j);
    }
};

