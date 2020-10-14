class Solution {
public:
    int maximum69Number (int num) {
        string digits = std::to_string(num);
        // for (char& digit : digits) {
        //     if (digit == '6') {
        //         digit = '9';
        //         break;
        //     }
        // }
        auto pos =  digits.find('6');
        if (std::string::npos != pos) digits[pos] = '9';
        return std::stoi(digits);
    }
};