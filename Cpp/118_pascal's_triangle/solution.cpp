class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        for (int i = 0; i < numRows; i ++)
        {
            vector<int> tmp;
            if (i == 0) 
                tmp.push_back(1);
            else
            {
                auto prev = res[i-1];
                tmp.push_back(1);
                for (int j = 0; j < prev.size()-1; j ++)
                    tmp.push_back(prev[j]+prev[j+1]);
                tmp.push_back(1);
            }
            res.push_back(tmp);
        }
        return res;
    }
};