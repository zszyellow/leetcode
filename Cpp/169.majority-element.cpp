class Solution {
public:
    /*  Boyer-Moore Voting Algorithm */
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for (int num : nums) {
            if (count == 0) candidate = num;
            count = num == candidate ? count + 1 : count - 1;
        }
        return candidate;
    }
};