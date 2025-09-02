#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define mprint(m)                                       \
    for (auto it : m)                                   \
        cout << it.first << " : " << it.second << endl; \
    cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

const int INF = 1e9;
const ll MOD = 1e9 + 7;

class Twitter
{
public:
    int time;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int,int>>> tweets;
    //userId --> vector of {time, tweetId}

    Twitter()
    {
        time=0;
        follows.clear();
        tweets.clear();
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> feed;

        priority_queue<array<int, 4>> pq;

        //users own tweets
        if(tweets.count(userId)){
            //we posted the tweets inside a vector and we need the latest tweets which will obviouly be at the ends of the vector., hence we take this approach:
            int idx=tweets[userId].size()-1;
            pq.push({tweets[userId][idx].first, tweets[userId][idx].second, userId, idx});
            //pq has {time, tweetid, whose tweet, index in that user's timeline}
        }

        for(int f: follows[userId]){
            if(tweets.count(f) && !tweets[f].empty()){ //only if user f exists AND has tweets
                int idx = tweets[f].size()-1;
                pq.push({tweets[f][idx].first, tweets[f][idx].second, f, idx});
            }
        }

        while(!pq.empty() && feed.size()<10){
            auto top = pq.top();
            pq.pop();

            int tweetId= top[1];
            int uId= top[2];
            int idx= top[3];

            feed.push_back(tweetId);

            if(idx>0){
                pq.push({tweets[uId][idx-1].first, tweets[uId][idx-1].second, uId, idx-1});
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId)
    {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        follows[followerId].erase(followeeId);
    }
};

int main()
{
    FAST_IO;
    Twitter *obj = new Twitter();
    obj->postTweet(1, 5);
    obj->postTweet(1, 3);
    vprint(obj->getNewsFeed(1));

    return 0;
}
// by ad73prem