class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int last = 0;
        
        for (int d : data) {
            bitset<8> mask(d);
            if (last == 0) {
                if (mask[7] == 0) continue;
                else if (mask[6] == 0) return false;
                else if (mask[5] == 0) last = 1;
                else if (mask[4] == 0) last = 2;
                else if (mask[3] == 0) last = 3;
                else return false;
            } else {
                if (mask[7] == 1 && mask[6] == 0) last --;
                else return false;
            }
        }
        return last == 0;
    }
};