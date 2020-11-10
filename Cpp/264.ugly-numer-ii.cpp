class Ugly {
public:
    vector<int> nums;
    Ugly() : nums(1690) {
        nums[0] = 1;
        int cur = 0, i2 = 0, i3 = 0, i5 = 0;
        
        for (int i = 1; i < 1690; ++i) {
            cur = min(min(nums[i2]*2, nums[i3]*3), nums[i5]*5);
            nums[i] = cur;
            i2 += cur == nums[i2]*2 ? 1 : 0;
            i3 += cur == nums[i3]*3 ? 1 : 0;
            i5 += cur == nums[i5]*5 ? 1 : 0;
        }
    }
};

class Solution {
public:
    // static const Ugly u;
    int nthUglyNumber(int n) {
        return u.nums[n-1];
    }
private:
    static const Ugly u;
};

const Ugly Solution::u = Ugly();