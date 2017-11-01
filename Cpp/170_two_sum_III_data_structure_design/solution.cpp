class TwoSum 
{
private:
    unordered_map<int,int> m;
    
public:
    /** Initialize your data structure here. */
    TwoSum() 
    {
        this->m.clear();
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) 
    {
        m[number] ++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) 
    {
        for (auto it = m.begin(); it != m.end(); ++ it) 
        {
            int num = it->first;
            int tmp = value - num;
            if (tmp == num && it->second > 1 || tmp != num && m.find(tmp) != m.end()) return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */