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

bool check(long long int s, int j, vector<long long int> & ans, vector<int> & skills, vector<int> & mana){
    int n=skills.size();
    int m= mana.size();
    long long int time=s;

    //basically we need to check that the time that we are taking at that time each wizard must be free

    for( int i=1;i<=n ;i++){
        if(time<ans[i]){
            return false;
        }

        time+= skills[i-1] * mana[j-1];
    }
    return true;
}

long long minTime2(vector<int> &skill, vector<int> &mana)
{
    int n=skill.size();
    int m=mana.size();
    vector<long long int> ans(n+1, 0);

    long long int sum=0;
    long long int maxi= *(max_element(mana.begin(), mana.end()));

    // this loop just creates the very  first row of the process. this can be done easily since the first row does not depend on any choice or nanhtning. its very easy to determine the first row
    for(int i=1;i<=n;i++){
        ans[i]= ans[i-1]+skill[i-1]*1LL*mana[0];
        sum+=skill[i-1];
    }
    // vprint(ans);


    // now filling up from the 2nd rows require some understanding
    int totalSkill = sum;

    for(int j=2;j<=m;j++){

        //we will perform binary search on asnwers here
        long long int low= ans[0]+1; // since the start time will start from previous row only. it will be something greater than that only

        long long high= ans.back()+ totalSkill*maxi; //this is the maximum limit the start time might take

        long long int startTime = high;

        while (low<=high){
            long long int mid= low+ (high-low)/2;
            if(check(mid, j, ans, skill, mana)){
                startTime= min(startTime, mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        // here we will get the startTime. now we can easily loop to find the other times

        ans[1]= startTime + mana[j-1] * skill[0];

        for(int i=2;i<=n;i++){
            ans[i]= ans[i-1] + skill[i-1]* 1LL * mana[j-1];
        }
        
    }
    return ans[n];
}


long long minTime(vector<int> & skill, vector<int> & mana){
    int n=skill.size();
    int m=mana.size();

    vector<long long> finishTime(n, 0);

    for(int i=0;i<m;i++){

        long long now= finishTime[0];
        int currPotion = mana[i];

        for(int j=1;j<n;j++){
            now= max ( now + skill[j-1] * 1LL * currPotion, finishTime[j]);
        }
        // now is the starting timeof the last wizard for each potion
        // cout<<" now : "<<now<<endl;
        finishTime[n-1]= now + skill[n-1] * currPotion;
        
        for(int j=n-2; j>=0 ; j--){
            finishTime[j]= finishTime[j+1]- skill[j+1]*currPotion;
        }
        // vprint(finishTime);
    }
    return finishTime[n-1];
}


int main()
{
    FAST_IO;
    vector<int> skill = {1, 5, 2, 4};
    vector<int> mana = {5, 1, 4, 2};

    cout<<minTime(skill, mana) ;
    return 0;
}
//by ad73prem