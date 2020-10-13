class Solution {
public:
    bool isGoodTriplet(vector<int>& triplet, int a, int b, int c) {
        return abs(triplet[0]-triplet[1]) <= a &&
                abs(triplet[1]-triplet[2]) <= b &&
                abs(triplet[0]-triplet[2]) <= c;
    }
    
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int res = 0;
        
        for (int i = 0; i < arr.size(); i ++) {
            for (int j = i + 1; j < arr.size(); j ++) {
                for (int k = j + 1; k < arr.size(); k ++) {
                    vector<int> triplet{arr[i], arr[j], arr[k]};
                    if (isGoodTriplet(triplet, a, b, c)) res ++;
                }
            }
        }
        
        return res;
    }
};