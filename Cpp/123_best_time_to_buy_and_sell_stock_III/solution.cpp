class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN;
        int hold2 = INT_MIN;
        int release1 = 0;
        int release2 = 0;
        for (int i : prices)
        {
            release2 = std::max(release2, hold2+i);
            hold2 = std::max(hold2, release1-i);
            release1 = std::max(release1, hold1+i);
            hold1 = std::max(hold1, -i);
        }
        return release2;
    }
};