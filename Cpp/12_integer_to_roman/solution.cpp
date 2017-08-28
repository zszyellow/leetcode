class Solution {
public:
    string intToRoman(int num) {
        // map<int, string> m = {
        //     {1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}
        // };
        string thousand[] = {"", "M", "MM", "MMM"};
        string hundred[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ten[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string one[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        return thousand[num/1000] + hundred[(num%1000)/100] + ten[(num%100)/10] + one[num%10];
    }
};