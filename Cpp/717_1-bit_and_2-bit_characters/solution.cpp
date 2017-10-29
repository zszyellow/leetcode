class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        if (bits.empty()) return false;
        if (!bits[0])
        {
            if (bits.size() == 1) return true;
            vector<int> tmp(bits.begin()+1, bits.end());
            if (isOneBitCharacter(tmp)) return true;
        }
        else if (bits.size() > 2)
        {
            vector<int> tmp(bits.begin()+2, bits.end());
            if (isOneBitCharacter(tmp)) return true;
        }
        return false;
    }
};