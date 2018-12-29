#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       vector<int> result;
		for( int i=0; i<numbers.size(); i++){
			int to_find = target - numbers[i];
			int j = i+1, k=numbers.size()-1;
			while (j<=k)
			{
				int mid = (j+k)/2;
				if( numbers[mid] == to_find)
				{
					result.push_back(i + 1);
					result.push_back(mid +1);
					return result;
				}
				else if( to_find > numbers[mid])
				{
					j=mid+1;
				}
				else
				{
					k=mid-1;
				}
			}
			//j>=k
		}	
		//should not come here
		result.push_back(0);
		result.push_back(0);
		return result;
    }
};
