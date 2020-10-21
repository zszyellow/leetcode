class Solution {
public:
    int digitSum(int n) {
        return n < 10 ? n : n % 10 + digitSum(n/10);
    }
    
    int countLargestGroup(int n) {
        vector<int> group_size(37, 0);
        for (int i = 1; i <= n; ++ i) group_size[digitSum(i)] ++;
        int max_group_size = *max_element(group_size.begin(), group_size.end());
        return count(group_size.begin(), group_size.end(), max_group_size);
    }
};