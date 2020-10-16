class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> hashset;
        int res = 0;

        for (int &a : A) {
            if (hashset.find(a) != hashset.end()) {
                res = a;
                break;
            }
            else hashset.insert(a);
        }
        return res;
    }
};