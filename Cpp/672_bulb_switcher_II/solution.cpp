class Solution {
public:
    int flipLights(int n, int m) {
        vector<bool> lights(n, true);
        set<vector<bool>> res;
        vector<bool> copy(lights);
        
        // cause every even number times of one operation will change nothing, so the max number of situations can be 2 ^ 4 = 16
        for (int i = 0; i < 16; i ++)
        {
            int operationNum = 0;
            for (int j = 0; j < 4; j ++)
            {
                if (i & (1 << j)) operationNum ++;
            }
            
            if (operationNum > m) continue;
            if (operationNum % 2 != m % 2) continue;
            if (i & 1) 
            {
                for (int x = 0; x < n; x ++) lights[x] = !lights[x];
            }
            if (i & 2)
            {
                for (int x = 0; x < n; x += 2) lights[x] = !lights[x];
            }
            if (i & 4) 
            {
                for (int x = 1; x < n; x += 2) lights[x] = !lights[x];
            }
            if (i & 8)
            {
                for (int x = 0; x < n; x += 3) lights[x] = !lights[x];
            }
            
            res.insert(lights);
            lights = copy;
        }
       
        return res.size();
    }
};