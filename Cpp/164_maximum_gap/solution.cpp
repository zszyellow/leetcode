class Solution 
{
public:
    // bucket sort
    int maximumGap(vector<int>& nums)
    {
        // min and max element
        int minE;
        int maxE;
        // bucket sort variables
        int bucket_size;
        int bucket_num;
        int bucket_id;
        int last_max;
        // other variables needed
        int i       = 0;
        int res     = 0;
        int max_gap = INT_MIN;
        int len     = nums.size();
        
        if (len > 1)
        {
            minE = maxE = nums[0];
            for (i = 1; i < sSize; i ++)
            {
                if (minE > nums[i]) minE = nums[i];
                else if (maxE < nums[i]) maxE = nums[i];
            }
            bucket_size = max(1, (maxE-minE)/(sSize-1));
            bucket_num  = (maxE-minE)/bucket_size + 1;
            if (bucket_num <= 1) return maxE - minE; 
            
            // bucket
            vector<int> bucket_max(bucket_num, INT_MIN);
            vector<int> bucket_min(bucket_num, INT_MAX);
            vector<int> bucket_count(bucket_num, 0);
            for (i = 0; i < sSize; i ++)
            {
                bucket_id = (nums[i]-minE) / bucket_size;
                bucket_count[bucket_id] ++;
                bucket_min[bucket_id] = std::min(bucket_min[bucket_id], nums[i]);
                bucket_max[bucket_id] = std::max(bucket_max[bucket_id], nums[i]);
            }
            last_max = minE;
            for (i = 0; i < bucket_num; i ++)
            {
                if (bucket_count[i] > 0)
                {
                    max_gap = max(max_gap, bucket_min[i]-last_max);
                    last_max = bucket_max[i];
                }
            }
            return max_gap;
        }
        return 0;
    }
};