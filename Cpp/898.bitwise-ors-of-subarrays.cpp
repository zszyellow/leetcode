class Solution {
public:
    // int subarrayBitwiseORs(vector<int> A) {
    //     unordered_set<int> res, cur, cur2;
    //     for (int i : A) {
    //         cur2 = {i};
    //         for (int j : cur) cur2.insert(i|j);
    //         cur = cur2;
    //         for (int j : cur) res.insert(j);
    //     }
    //     return res.size();
    // }
    
    int subarrayBitwiseORs(vector<int> A) {
        vector<int> res;
        int left = 0, right;
        for (int a: A) {
            right = res.size();
            res.push_back(a);
            for (int i = left; i < right; ++i) {
                if (res.back() != (res[i] | a)) {
                    res.push_back(res[i] | a);
                }
            }
            left = right;
        }
        return unordered_set(res.begin(), res.end()).size();
    }
};