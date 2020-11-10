class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // Greedy, TC: O(N), SC: O(N)
        unordered_map<int, int> counts, ends;
        for (int &num : nums) counts[num] ++;
        
        for (int &num : nums) {
            if (counts[num] == 0) continue;
            
            if (ends[num-1] > 0) {
                counts[num] --;
                ends[num-1] --;
                ends[num] ++;
            }
            else if (counts[num+1] > 0 && counts[num+2] > 0) {
                ends[num+2] ++;
                counts[num] --;
                counts[num+1] --;
                counts[num+2] --;
            }
            else {
                return false;
            }
        }
        return true;
    }
};