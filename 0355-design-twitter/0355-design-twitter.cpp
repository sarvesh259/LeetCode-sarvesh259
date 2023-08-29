class Twitter {
public:
    map<int,set<int>> friends;
    int cur=0;
    priority_queue<vector<int>> timeline;
    Twitter() {
        friends.clear();
        cur=0;
        timeline=priority_queue<vector<int>>();
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push({cur++,userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int n=0;
        priority_queue<vector<int>> t=timeline;
        while(!t.empty()&&n<10)
        {
            auto it=t.top();
            t.pop();
            if(userId==it[1]||friends[userId].count(it[1]))
            {
                ans.push_back(it[2]);
                n++;
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */