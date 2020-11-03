class SnakeGame {
private:
    int width_;
    int height_;
    int food_idx_;
    vector<vector<int>> food_;
    unordered_set<int> visited_;
    deque<vector<int>> snake_;

public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        width_ = width;
        height_ = height;
        food_ = food;
        food_idx_ = 0;
        snake_.push_back({0, 0});
        visited_.insert(0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int head_x = snake_.front()[0], head_y = snake_.front()[1];
        vector<int> tail = snake_.back();
        int tail_pos = tail[0] * width_ + tail[1];
        visited_.erase(tail_pos);
        snake_.pop_back();
        
        if (direction == "U") head_x --;
        else if (direction == "D") head_x ++;
        else if (direction == "L") head_y --;
        else head_y ++;
        
        int new_head_pos = head_x * width_ + head_y;
        if (head_x < 0 || head_x >= height_ || head_y < 0 || head_y >= width_ || visited_.count(new_head_pos)) {
            return -1;
        }
        
        snake_.push_front({head_x, head_y});
        visited_.insert(new_head_pos);
        
        if (food_idx_ < food_.size() && head_x == food_[food_idx_][0] && head_y == food_[food_idx_][1]) {
            snake_.push_back(tail);
            visited_.insert(tail_pos);
            food_idx_ ++;
        }
        
        return snake_.size() - 1;
    }
};