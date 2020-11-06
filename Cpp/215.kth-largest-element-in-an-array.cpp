class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(less<int>(), nums);
        while (--k) 
            pq.pop();
        return pq.top();
    }
};