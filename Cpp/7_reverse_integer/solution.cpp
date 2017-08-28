class Solution {
public:
    int reverse(int x) {
        int result = 0;
        
        while (x != 0)
        {
            int tail = x % 10;
            int tmp = result * 10 + tail;
            if ((tmp - tail) / 10 != result) return 0;
            x /= 10;
            result = tmp;
        }
        
        return result;
    }
};