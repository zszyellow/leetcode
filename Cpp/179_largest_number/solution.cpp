class Solution  
{
public:
    string largestNumber(vector<int>& nums) 
    {
        string res = "";
        vector<string> seq;
        for (int i : nums) seq.push_back(std::to_string(i));
        std::sort(seq.begin(), seq.end(), comp);
        for (string str : seq) res += str;
        while (res[0] == '0' && res.size() > 1) res.erase(0, 1);
        return res;
    }
private:
    static bool comp(const string a, const string b)
    {
        return a+b > b+a;
    }
};