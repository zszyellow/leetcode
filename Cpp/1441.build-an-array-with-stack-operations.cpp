class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int cur_num = 1;
        for (int& num : target) {
            while (cur_num < num) {
                res.push_back("Push");
                res.push_back("Pop");
                cur_num ++;
            }
            res.push_back("Push");
            cur_num ++;
        }
        return res;
    }
};