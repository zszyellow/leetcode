/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 *
 * https://leetcode.com/problems/all-possible-full-binary-trees/description/
 *
 * algorithms
 * Medium (69.23%)
 * Total Accepted:    12.8K
 * Total Submissions: 18.4K
 * Testcase Example:  '7'
 *
 * A full binary tree is a binary tree where each node has exactly 0 or 2
 * children.
 * 
 * Return a list of all possible full binary trees with N nodes.  Each element
 * of the answer is the root node of one possible tree.
 * 
 * Each node of each tree in the answer must have node.val = 0.
 * 
 * You may return the final list of trees in any order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 7
 * Output:
 * [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 20
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int, vector<TreeNode*>> mem;
    vector<TreeNode*> allPossibleFBT(int N) {
        if (mem.find(N) == mem.end()) {
            vector<TreeNode*> res;
            if (N == 1) {
                res.push_back(new TreeNode(0));
            }
            else if (N % 2 == 1) {
                for (int x = 0; x < N; x ++) {
                    int y = N - 1 - x;
                    for (auto left : allPossibleFBT(x)) {
                        for (auto right : allPossibleFBT(y)) {
                            auto tmp = new TreeNode(0);
                            tmp->left = left;
                            tmp->right = right;
                            res.push_back(tmp);
                        }
                    }
                }
            }

            mem[N] = res; 
        }
        return mem[N];
    }
};
