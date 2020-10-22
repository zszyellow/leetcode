/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
private:
    unordered_map<int, unordered_map<int, bool>> visited;
    vector<pair<int, int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // up, right, down, left
public:
    void cleanRoom(Robot& robot) {
        backtrack(robot, 0, 0, 0);
    }
    
    void backtrack(Robot &robot, int r, int c, int d) {
        visited[r][c] = true;
        robot.clean();
        
        for (int i = 0; i < 4; ++ i) {
            int new_direction = (d + i) % 4;
            int new_row = r + directions[new_direction].first;
            int new_col = c + directions[new_direction].second;
            
            if (!visited[new_row][new_col] && robot.move()) {
                backtrack(robot, new_row, new_col, new_direction);
                goBack(robot);
            }
            robot.turnRight();
        }
    }
    
    void goBack(Robot &robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
};