class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0, len = height.size();
        for (int i = 0; i < len - 1 ; i ++)
        {
            for (int j = i + 1; j < len; j ++)
            {
                int min = height[i] > height[j] ? height[j] : height[i]; 
                int temp = (j - i) * min;
                if (max < temp) max = temp;
            }
        }
        
        return max;
    }
};