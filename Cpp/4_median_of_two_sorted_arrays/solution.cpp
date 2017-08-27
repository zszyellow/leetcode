class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size())
        {
            if (i >= nums1.size()) nums3.push_back(nums2[j++]);
            else if (j >= nums2.size()) nums3.push_back(nums1[i++]);
            else if (nums1[i] < nums2[j]) nums3.push_back(nums1[i++]);
            else nums3.push_back(nums2[j++]);
        }
        if (nums3.size() % 2 == 0) return (nums3[nums3.size()/2] + nums3[nums3.size()/2 - 1])/2.0;
        else return nums3[nums3.size()/2];
    }
};