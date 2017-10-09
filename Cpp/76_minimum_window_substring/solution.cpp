class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        int counter = t.size(); 
        int begin = 0, end = 0, head = 0; 
        int distance = INT_MAX; 

        for (auto val : t)  map[val] ++; 
        while (end < s.size())
        {
            if (map[s[end++]]-- > 0) counter --;
            while (!counter)
            { 
                if (end - begin < distance) 
                {
                    distance = end - begin;
                    head = begin;
                }
                if (map[s[begin++]]++ == 0) counter ++;
            }  
        }

        return distance == INT_MAX ? "" : s.substr(head, distance);
    }
};