class Solution {
public:
    int find_max_index(vector<int> height, int start, int end, bool to_left)
    {
        int idx = 0;
        int max = -1;
        int loop_begin = to_left ? end - 1 : start;
        int loop_end = to_left ? start - 1 : end;
        int loop_step = to_left ? -1 : 1;
        for (int i = loop_begin; i != loop_end; i += loop_step)
        {
            if (height[i] >= max) { max = height[i]; idx = i; }
        }
        return idx;
    }
    
    void trace(vector<int> height, int start, int end, int &sum, bool to_left)
    {
        if (start == end) return;
        int tmp = find_max_index(height, start, end, to_left);
        if (to_left) 
        {
            for (int i = tmp + 1; i < end; i ++) { sum += height[tmp] - height[i]; }
            trace(height, start, tmp, sum, to_left);
        }
        else
        {
            for (int i = tmp - 1; i >= start; i --) { sum += height[tmp] - height[i]; }
            trace(height, tmp+1, end, sum, to_left);
        }
    }
    
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int len = height.size();
        int sum = 0;
        int idx = find_max_index(height, 0, len, false);
        trace(height, 0, idx, sum, true);
        trace(height, idx+1, len, sum, false);
        return sum;
    }
};