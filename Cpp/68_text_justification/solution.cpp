class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        // num reprents the number of words in every row 
        // cur is the current sum of lengths of added words
        int num, cur;
        
        for (int i = 0; i < words.size(); i += num) 
        {
            for (num = cur = 0; i + num < words.size() && cur + words[i+num].size() <= maxWidth - num; num ++) 
                cur += words[i+num].size();
            
            string tmp = words[i];
            for (int j = 0; j < num - 1; j ++) 
            {
                if (i + num >= words.size()) tmp += " ";
                else tmp += string((maxWidth-cur) / (num-1) + (j < (maxWidth-cur) % (num-1)), ' ');
                tmp += words[i+j+1];
            }
            tmp += string(maxWidth - tmp.size(), ' ');
            res.push_back(tmp);
        }
        
        return res;
    }
};