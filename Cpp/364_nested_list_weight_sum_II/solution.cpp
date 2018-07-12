/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = 1;
        for (int i = 0; i < nestedList.size(); i ++) {
            if (!nestedList[i].isInteger()) {
                int tmp = getDepth(nestedList[i]);
                depth = max(depth, tmp);
            }
        }
        
        int res = 0;
        for (int i = 0; i < nestedList.size(); i ++) {
            if (nestedList[i].isInteger()) res += nestedList[i].getInteger()* depth; 
            else dfs(nestedList[i], depth-1, res);
        }
        return res;
    }
    
    int getDepth(NestedInteger& nested) {
        if(nested.isInteger()) return 1;
        else {
            int res = 1;
            vector<NestedInteger> tmp = nested.getList();
            for (int i = 0; i < tmp.size(); i ++) {
                res = max(res, 1+getDepth(tmp[i]));
            }
            return res;
        }
    }
    
    void dfs(NestedInteger& nested, int depth, int& res) {
        if (nested.isInteger()) res += nested.getInteger()*depth;
        else {
            vector<NestedInteger> tmp = nested.getList();
            for (int i = 0; i < tmp.size(); i ++) {
                if (tmp[i].isInteger()) res += tmp[i].getInteger() * depth; 
                else dfs(tmp[i], depth-1, res);
            }
        }
    }
};