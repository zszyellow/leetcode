class SubrectangleQueries {
private:
    vector<vector<int>> history;
    vector<vector<int>> *rect;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = &rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        history.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        int i = history.size() - 1;
        while (i >= 0) {
            vector<int> &h = history[i --]; 
            if (row >= h[0] && col >= h[1] && row <= h[2] && col <= h[3]) return h[4];
        }
        return (*rect)[row][col];
    }
};


/* brute force */
// class SubrectangleQueries {
// private:
//     vector<vector<int>> rect;
// public:
//     SubrectangleQueries(vector<vector<int>>& rectangle) {
//         rect = rectangle;
//     }
    
//     void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
//         for (int i = row1; i <= row2; ++ i) {
//             for (int j = col1; j <= col2; ++ j) {
//                 this->rect[i][j] = newValue;
//             }
//         }
//     }
    
//     int getValue(int row, int col) {
//         return this->rect[row][col];
//     }
// };

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */