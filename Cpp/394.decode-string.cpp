/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
// solution 1: stack
class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<string> chars;
        stack<int> nums;
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num*10 + (c - '0');
            } 
            else if (isalpha(c)) {
                res.push_back(c);
            }
            else if (c == '[') {
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            } 
            else if (c == ']') {
                string tmp = res;
                for (int i = 0; i < nums.top()-1; i ++) {
                    res += tmp;
                }
                res = chars.top() + res;
                chars.pop();
                nums.pop();
            }
        }
        
        return res;
    }
};

// solution 2: recursion
// class Solution {
// public:
//     string decodeString(string s) {
//         int i = 0;
//         return helper(s, i);
//     }
    
//     string helper(string& s, int& i) {
//         string res;
        
//         while(i < s.size() && s[i] != ']') {
//             if (!isdigit(s[i])) {
//                 res += s[i];
//                 i ++;
//             }
//             else {
//                 int n = 0;
//                 while (i < s.size() && isdigit(s[i])) {
//                     n = n*10 + (s[i] - '0');
//                     i ++;
//                 }
//                 i ++;
//                 string tmp = helper(s, i);
//                 i ++;
                
//                 while (n -- > 0) {
//                     res += tmp;
//                 }
//             }
//         }
        
//         return res;
//     }
// };
// @lc code=end

