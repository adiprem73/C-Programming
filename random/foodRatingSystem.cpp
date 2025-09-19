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

class FoodRatings
{


private:
    struct Compare
    {
        bool operator()(const pair<int, string> &a,
                        const pair<int, string> &b) const
        {
            if (a.first != b.first)
                return a.first < b.first; // larger int first
            return a.second > b.second;   // lexicographically smaller string first
        }
    };
map <string ,pair<int, string>> data;
map <string, priority_queue <pair<int,string>, vector<pair<int, string>>, Compare > > underlyingData;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n=foods.size();
        for(int i=0;i<n;i++){
            data[foods[i]]={ratings[i], cuisines[i]};
            underlyingData[cuisines[i]].push({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        data[food].first= newRating; //update the rating int the data
        //just push the data in the pq
        underlyingData[data[food].second].push({newRating, food});
    }

    string highestRated(string cuisine)
    {
        auto &pq= underlyingData[cuisine];
        while(!pq.empty()){
            auto top= pq.top();
            const string &foodname= top.second;
            int rating= top.first;

            if(data[foodname].first == rating){
                return foodname;
            }
            pq.pop();
        } 
    }
};

int main()
{
    FAST_IO;
    vector<string> food = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisine = {"korean", "japanese", "japanese", "greek", "japanese", "korean"} ;
    vector<int> ratings = {9, 12, 8, 15, 14, 7}; 
    FoodRatings obj(food, cuisine, ratings);
    cout<<obj.highestRated("korean")<<endl;
    cout << obj.highestRated("japanese")<<endl;
    obj.changeRating("sushi", 16);
    cout << obj.highestRated("japanese") << endl;
    obj.changeRating("ramen", 16);
    cout<< obj.highestRated("japanese")<<endl;
    return 0;
}
// by ad73prem