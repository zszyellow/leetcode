class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        for (int i = 0; i <= rowIndex; i ++)
        {
            vector<int> tmp;
            if (i == 0) 
                tmp.push_back(1);
            else
            {
                tmp.push_back(1);
                for (int j = 0; j < prev.size()-1; j ++)
                    tmp.push_back(prev[j]+prev[j+1]);
                tmp.push_back(1);
            }
            prev = tmp;
        }
        return prev;
    }
};