class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int to_give = 1, idx = 0;
        
        while (candies > 0) {
            idx = to_give % num_people == 0 ? num_people - 1 : to_give % num_people - 1;
            if (candies <= to_give) res[idx] += candies;
            else res[idx] += to_give;
            candies -= to_give;
            to_give ++;
        }
        return res;
    }
};