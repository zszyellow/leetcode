class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> heights_cp(heights);
        std::sort(heights_cp.begin(), heights_cp.end());
        
        int res = 0;
        for (int i = 0; i < heights.size(); ++ i) {
            if (heights[i] != heights_cp[i]) res ++;
        }
        return res;
    }
};