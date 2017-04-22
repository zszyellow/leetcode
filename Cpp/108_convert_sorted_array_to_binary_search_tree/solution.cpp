class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        if (nums.empty()) return NULL;
        int len = nums.size();
        return dfs(nums, 0, len-1);
    }

    TreeNode* dfs(vector<int>& nums, int begin, int end)
    {
        if (begin > end) return NULL;
        int mid = (begin + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, begin, mid-1);
        root->right = dfs(nums, mid+1, end);
        return root;
    }
};
