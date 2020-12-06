class Solution {
public:
    string interpret(string command) {
        int N = command.size(), i = 0;
        string res;
        
        while (i < N) {
            if (command[i] == 'G') {
                res += 'G';
                i ++;
            }
            else if (command[i+1] == ')') {
                res += 'o';
                i += 2;
            }
            else {
                res += "al";
                i += 4;
            }
        }
        
        return res;
    }
};