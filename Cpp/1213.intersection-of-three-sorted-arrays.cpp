class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> res;
        vector<int> counts(2002, 0);
        for (int i = 0; i < arr1.size(); i++){
            counts[arr1[i]]++;
        }
        
        for (int i = 0; i < arr2.size(); i++){
            counts[arr2[i]]++;
        }
        
        for (int i = 0; i < arr3.size(); i++){
            if (++ counts[arr3[i]] == 3) res.push_back(arr3[i]);
        }
        
        return res;  
    }
};