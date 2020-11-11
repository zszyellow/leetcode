class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() : user_hm() {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (user_hm.find(userId) == user_hm.end()) {
            auto u = make_unique<User>(userId);
            user_hm[userId] = move(u);
        }
        user_hm[userId]->post(tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if (user_hm.find(userId) == user_hm.end()) return res;
        
        unordered_set<int> &users = user_hm[userId]->followed;
        auto comp = [](const Tweet* lhs, const Tweet* rhs) {
            return lhs->time < rhs->time;
        };
        priority_queue<Tweet*, vector<Tweet*>, decltype(comp)> pq(comp);
        if (user_hm[userId]->t_head) pq.push(user_hm[userId]->t_head.get());
        for (const int &user : users) {
            if (user == userId) continue;
            auto t = user_hm[user]->t_head.get();
            if (t) pq.push(t);
        }
        
        int limit = 10;
        while (!pq.empty() && limit > 0) {
            auto t = pq.top();
            pq.pop();
            res.push_back(t->id);
            limit --;
            if (t->next) pq.push(t->next.get());
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (user_hm.find(followerId) == user_hm.end()) {
            auto u = make_unique<User>(followerId);
            user_hm[followerId] = move(u);
        }
        if (user_hm.find(followeeId) == user_hm.end()) {
            auto u = make_unique<User>(followeeId);
            user_hm[followeeId] = move(u);
        }
        user_hm[followerId]->follow(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (user_hm.find(followerId) == user_hm.end() || user_hm.find(followeeId) == user_hm.end()) 
            return;
        user_hm[followerId]->unfollow(followeeId);
    }
private:
    struct Tweet {
        int id;
        int time;
        unique_ptr<Tweet> next;
        Tweet(int id) : id(id), time(time_stamp++), next(nullptr) {}
    };
    
    struct User {
        int id;
        unordered_set<int> followed;
        unique_ptr<Tweet> t_head;
        
        User(int id) : id(id), followed(), t_head(nullptr) { follow(id); }
        void follow(int id) { followed.insert(id); }
        void unfollow(int id) { followed.erase(id); }
        void post(int id) {
            auto t = make_unique<Tweet>(id);
            if (t_head) t->next = move(t_head);
            t_head = move(t);
        }
    };
    
    static int time_stamp;
    unordered_map<int, unique_ptr<User>> user_hm;
};

int Twitter::time_stamp = 0;

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */