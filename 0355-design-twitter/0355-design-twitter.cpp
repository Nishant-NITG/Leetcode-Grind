class Twitter {
private:
  
    int time;

   
    unordered_map<int, unordered_set<int>> followees;


    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

      
        followees[userId].insert(userId);

        for (int uid : followees[userId]) {
            for (auto &t : tweets[uid]) {
                pq.push(t);
            }
        }

        vector<int> feed;
        while (!pq.empty() && feed.size() < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followees[followerId].erase(followeeId);
    }
};
