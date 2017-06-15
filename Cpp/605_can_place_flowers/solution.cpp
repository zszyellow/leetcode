class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size(), count = 0;
        for (int i = 0; i < len; i ++) 
        {
            bool flag = true;
            if (flowerbed[i] == 1) flag = false;
            else
            {
                if (i - 1 >= 0 && flowerbed[i-1] == 1) flag = false;
                if (i + 1 < len && flowerbed[i+1] == 1) flag = false;
            }
            
            if (flag) 
            {
                flowerbed[i] = 1;
                count ++;
            }
        }
        
        return count >= n;
    }
};