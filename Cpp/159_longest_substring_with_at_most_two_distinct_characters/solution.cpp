class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> map(128,0);
        int counter = 0; 
        int begin = 0, end = 0; 
        int distance = 0; 

        while (end < s.size()) 
        {
            if (map[s[end++]]++ == 0) counter ++;
            while (counter > 2) 
                if (map[s[begin++]]-- == 1) counter --;
            if (distance < end - begin) distance = end - begin;
        }
        return distance;
    }
};