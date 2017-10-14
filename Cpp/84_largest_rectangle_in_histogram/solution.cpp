class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> index;
        
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i ++)
        {
            while (index.size() > 0 && heights[index.top()] >= heights[i])
            {
                int h = heights[index.top()];
                index.pop();
                int sidx = index.size() > 0 ? index.top() : -1;
                if (h * (i - sidx - 1) > res) res = h * (i-sidx-1);
            }
            index.push(i);
        }
        return res;
    }
};