class Solution {
public:
    bool judgeCircle(string moves) {
        map<char, int> move_counts{{'U', 0}, {'D', 0}, {'L', 0}, {'R', 0}};
        for (char &move : moves) {
            move_counts[move] ++;
        }
        return move_counts['U'] - move_counts['D'] == 0 &&
            move_counts['L'] - move_counts['R'] == 0;
    }
};