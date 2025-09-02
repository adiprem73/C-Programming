#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define mprint(m) for (auto it:m) cout<<it.first<<" : "<<it.second<<endl; cout<<endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>

const int INF = 1e9;
const ll MOD = 1e9+7;

class Twitter {
public:

    int time=0;
    priority_queue<pair<int,pair<int,int>>> pq; //maxHeap  (tweetid, userid)
    map<int, unordered_set<int>> usersFollows; //key : userId... values : userIds the user follows
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({time,{tweetId, userId}});
        time++;

        //registration of new user
        if(usersFollows.find(userId)==usersFollows.end()){
            usersFollows[userId]={};
        }


    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        auto temp=pq;
        while(ans.size()!=10 && !temp.empty()){
            auto it=temp.top();
            temp.pop();

            int tId= it.second.first;
            int uId= it.second.second;

            if(uId==userId || usersFollows[userId].find(uId) != usersFollows[userId].end()){
                ans.push_back(tId);
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        usersFollows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        usersFollows[followerId].erase(followeeId);
    }
};

int main() {
    FAST_IO;
    Twitter* obj= new Twitter();
    obj->postTweet(1,5);
    obj->postTweet(1,3);
    vprint(obj->getNewsFeed(1));

    return 0;
}
//by ad73prem