class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return buildTree(nums, 0, nums.size());
    }

	TreeNode* buildTree(vector<int> &nums, int start, int end){
		if(start == end) return nullptr;
		int max=INT_MIN, index=start;
		for(int i=start;i<end;i++){
			if (nums[i] > max){
				max=nums[i];
				index = i;
			}
		}
		TreeNode *new_node = new TreeNode(nums[index]);		
		TreeNode *left_node = buildTree(nums, start, index);
		TreeNode *right_node = buildTree(nums, index+1, end);
		new_node->left = left_node;
		new_node->right = right_node;
		return new_node;
	}

};
