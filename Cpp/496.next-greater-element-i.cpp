class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /* Brute force, TC: O(MN) SC: O(M+N) */
//         unordered_map<int, int> hash_map;
//         for (int i = 0; i < nums2.size(); ++ i) hash_map[nums2[i]] = i;
        
//         vector<int> res;
//         for (int &num1 : nums1) {
//             int pos = hash_map[num1];
//             auto it = find_if(nums2.begin()+pos, nums2.end(), [&](int num){ return num > num1; });
//             if (it != nums2.end()) res.push_back(*it);
//             else res.push_back(-1);
//         }
//         return res;
        
        /* Stack, TC: O(M+N), SC: O(M+N) */
        stack<int> st;
        unordered_map<int, int> hash_map;
        
        for (int i = 0; i < nums2.size(); ++ i) {
            while (!st.empty() && st.top() < nums2[i]) {
                hash_map[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while (!st.empty()) {
            hash_map[st.top()] = -1;
            st.pop();
        }
        
        vector<int> res;
        for (int num1 : nums1) {
            res.push_back(hash_map[num1]);
        }
        return res;
    }
};