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

int trapRainWater(vector<vector<int>> &heightMap)
{

    int n= heightMap.size(); // no. of rows
    if(!n) return 0; 
    int m= heightMap[0].size(); // no. of columns

    if(n<3 || m<3) return 0; // without alteast 3 columsna dn 3 rows rainwater cannot be trapped at all

    // we need a datastructure that is of the form (height, (row, column))... 
    // either we can use pair<int, pair<int,int>> or we can do something like this
    using var= pair<int,pair<int,int>>;

    // now we will create the minHeap
    priority_queue<var, vector<var>, greater<var>> pq;

    // we will also need a visited array 2D
    vector<vector<bool>> vis(n, vector<bool>(m,false));

    // we will staert by pushing the boundaries since boundaries are only responsible for trapping the water... so we will start from the boundaries and then enter inwards by traversing neighbours of the smalles boundaires

    // pushin the vertical boundaries
    for(int i=0;i<n;i++){ // iterating over the rows
        pq.push({heightMap[i][0], {i,0}}); // pushig the first element of each row
        vis[i][0]= true;
        pq.push({heightMap[i][m-1], {i, m-1}}); // pushing the last elemennt of each row
        vis[i][m-1]= true;
    }

    // pushin the horizontal boundaires
    for(int i=0;i<m;i++){
        if(vis[0][i]== false){
            pq.push({heightMap[0][i], {0, i}});
            vis[0][i] = true;
        }
        if(vis[n-1][i]== false){
            pq.push({heightMap[n - 1][i], {n - 1, i}});
            vis[n - 1][i] = true;
        }
        
    }

    int water=0; // to store the water

    //for traversal
    vector<int> dx={0, 1, 0, -1};
    vector<int> dy={-1, 0, 1, 0};

    while(!pq.empty()){
        auto x= pq.top();
        pq.pop();
        int height= x.first;
        int row= x.second.first;
        int col= x.second.second;

        // now we need to explore the neighbours
        for(int i=0;i<4;i++){
            int nrow= row+dx[i];
            int ncol= col+dy[i];
            // if the neighbour is a valid neighbour and not visited yet
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]== false){
                vis[nrow][ncol]= true;
                int nheight= heightMap[nrow][ncol];
                // if the nheight is less than the height then only water will be stored in it or else water can't be stored in it
                if(nheight< height){
                    water+= (height-nheight);
                    pq.push({height, {nrow, ncol}});
                }else{
                    pq.push({nheight, {nrow, ncol}});
                }
            }
        }
    }
    return water;
}

int main()
{
    FAST_IO;
    
    return 0;
}
//by ad73prem