class Solution 
{
private:
    int squareSum(int n)
    {
        int res = 0;
        while (n)
        {
            int tmp = n % 10;
            res += tmp * tmp;
            n /= 10;
        }
        return res;
    }
    
public:
    bool isHappy(int n) 
    {
        int slow = n;
        int fast = n;
        do
        {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        } while (slow != fast);
        if (slow == 1) return true;
        else return false;
    }
};