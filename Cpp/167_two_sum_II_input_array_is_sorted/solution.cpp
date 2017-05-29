class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, len = numbers.size(), right = len - 1;
        while (left < right)
        {
            if (numbers[left] + numbers[right] == target) break;
            else if (numbers[left] + numbers[right] > target) right --;
            else left ++;
        }
        vector<int> res{left+1, right+1};
        return res;
    }
};