class Solution 
{
public:
    vector<int> count_words(vector<char> str)
    {
        vector<int> res;
        for (int i = 0; i < str.size(); i ++)
            if (str[i] == ' ') res.push_back(i); 
        return res;
    }
    
    // void print_vec(vector<char> str)
    // {
    //     for (auto ch : str)
    //     {
    //         if (ch != ' ') cout << ch;
    //         else cout << '#';
    //     }
    //     cout << endl;
    // }
    
    void reverseWords(vector<char>& str) 
    {
        auto blank_pos = count_words(str);
        int num = blank_pos.size() + 1;
        if (num == 1) return;
        else if (num % 2 == 1) 
        {
            int left_pos = blank_pos[num/2-1];
            int right_pos = blank_pos[num/2];
            
            vector<char> left(str.begin(), str.begin()+left_pos);
            // print_vec(left);
            vector<char> right(str.begin()+(right_pos+1), str.end());
            // print_vec(right);
            vector<char> mid(str.begin()+left_pos, str.begin()+(right_pos+1));
            // print_vec(mid);
            
            reverseWords(left);
            reverseWords(right);
            std::copy(mid.begin(), mid.end(), std::back_inserter(right));
            std::copy(left.begin(), left.end(), std::back_inserter(right));
            str = right;
        }
        else 
        {
            int mid_pos = blank_pos[num/2-1];
            vector<char> left(str.begin(), str.begin()+mid_pos);
            vector<char> right(str.begin()+(mid_pos+1), str.end());
            reverseWords(left);
            reverseWords(right);
            right.push_back(' ');
            std::copy(left.begin(), left.end(), std::back_inserter(right));
            str = right;
        }
    }
};