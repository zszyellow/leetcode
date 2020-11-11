class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int N = candies.size();
        unordered_map<int, int> cnts;
        for (int &candy : candies) cnts[candy] ++;
        return cnts.size() > N/2 ? N/2 : cnts.size();
    }
};