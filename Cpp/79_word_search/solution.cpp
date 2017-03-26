#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    public:
        bool exist(vector<vector<char> >& board, string word)
        {
            int rows = board.size();
            int cols = board[0].size();
            vector<vector<bool> > visited(rows, vector<bool>(cols, false));

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (dfs(board, word, i, j, visited, 0))
                        return true;
                }
            }

            return false;
        }

        bool dfs(vector<vector<char> >& board, string word, int i, int j, vector<vector<bool> > &visited, int idx)
        {
            if (idx == word.size())
                return true;
            if (i < 0 || j < 0 || i == board.size() || j == board[0].size())
                return false;

            if (!visited[i][j] && board[i][j] == word[idx])
            {
                visited[i][j] = true;
                if (dfs(board, word, i+1, j, visited, idx+1) ||
                    dfs(board, word, i-1, j, visited, idx+1) ||
                    dfs(board, word, i, j+1, visited, idx+1) ||
                    dfs(board, word, i, j-1, visited, idx+1))
                    return true;
                visited[i][j] = false;
            }

            return false;
        }
};

// test cases
int main(int argc, char const* argv[])
{
    Solution solution1;
    vector<vector<char> > testcase1{
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    // test procedure
    cout << "start test case1:" << endl;
    if (solution1.exist(testcase1, "ABCCED") &&
        solution1.exist(testcase1, "SEE") &&
        !solution1.exist(testcase1, "ABCB"))
        cout << "test case1 passed" << endl;
    else
        cout << "test case1 failed" << endl;

    return 0;
}
