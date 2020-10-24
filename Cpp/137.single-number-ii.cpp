class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seen_once = 0, seen_twice = 0;
        /**
         * first appearance: 
         * add num to seen_once 
         * don't add to seen_twice because of presence in seen_once
            
         * second appearance: 
         * remove num from seen_once 
         * add num to seen_twice
            
         * third appearance: 
         * don't add to seen_once because of presence in seen_twice
         */
        for (int num : nums) {
            seen_once = ~seen_twice & (seen_once ^ num);
            seen_twice = ~seen_once & (seen_twice ^ num);
        }
        return seen_once;
    }
};