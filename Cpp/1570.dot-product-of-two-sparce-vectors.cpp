class SparseVector {
public:
    unordered_map<int, int> m;
    
    SparseVector(vector<int> &nums) {
       for (int i = 0; i < nums.size(); ++ i) {
           if (nums[i]) this->m[i] = nums[i]; 
       } 
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        auto n = vec.m;
        for (auto [idx, val] : n) {
            if (this->m.find(idx) != this->m.end()) {
                res += val * this->m[idx];
            }
        }
        
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);