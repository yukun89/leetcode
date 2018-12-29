  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
#include <vector>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
		int height = getHeightOfTree(root);
		int width = (int)(pow(2,height)) -1;
		vector<vector<string> > result(height, vector<string>(width, ""));
		fillTree(result, root, 0, width, 0/*height*/);
		return result;
    }

private:
	int getHeightOfTree(TreeNode *root)	
	{
		if( nullptr == root )
			return 0;
		return std::max(getHeightOfTree(root->left), getHeightOfTree(root->right)) +1;
	}

	void fillTree(vector<vector<string>> &result, TreeNode *root, int left_index, int right_index, int height){
		if(nullptr == root) return;
		int mid = (left_index + right_index)/2;
		result[height][mid]=std::to_string(root->val);
		fillTree(result, root->left, left_index, mid-1, height+1);
		fillTree(result, root->right, mid+1, right_index, height+1);
	}
    
};
//int<<>>string. vector cons
