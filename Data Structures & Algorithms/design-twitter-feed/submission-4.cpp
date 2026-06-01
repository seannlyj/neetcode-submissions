//Twitter()
//postTweet(1,1)
//postTweet(1,2)
//postTweet(1,3)
//postTweet(1,4)
//postTweet(1,5)
//postTweet(1,6)
//postTweet(1,7)
//postTweet(1,8)
//postTweet(1,9)
//postTweet(1,10)
//postTweet(1,11)
//getNewsFeed(1): [11,10,9,8,7,6,5,4,3,2]
//follow(2, 1)
//getNewsFeed(2): [11,10,9,8,7,6,5,4,3,2]
//unfollow(2,1)
//getNewsFeed(2): []

class Twitter {
private:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets; //userID -> [{timestamp, tweetId}];
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> posts;
        vector<int> userIds;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxheap;
        
        // add self to user ids
        userIds.push_back(userId);
        for(auto following : following[userId]){
            userIds.push_back(following);
        }

        // iterate through all users
        for(auto user : userIds) {
            // iterate through all tweets from user
            for(auto tweet : tweets[user]){
                maxheap.push({tweet.first, tweet.second});
            }
        }

        // push back into posts in the right order
        const int max = 10;
        int counter = 0;
        while(!maxheap.empty()){
            if(counter >= max)
                break;
            posts.push_back(maxheap.top().second);
            maxheap.pop();
            counter++;
        }

        return posts;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
