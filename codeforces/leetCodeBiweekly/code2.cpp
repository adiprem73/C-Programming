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

// int totalWaviness(int num1, int num2) {
//     int ans=0;
//     for(int i=num1;i<=num2;i++){
//         string s= to_string(i);
//         int cnt=0;
//         int len= s.length();
//         if(len>=3){
//             for(int i=1;i<len-1;i++){
//                 if(s[i]>s[i-1] && s[i]>s[i+1]){
//                     cnt++;
//                 }
//                 else if(s[i]<s[i-1] && s[i]<s[i+1]){
//                     cnt++;
//                 }
//             }
//             ans+=cnt;
//         }
//     }    
//     return ans;   
// }

long long totalWaviness(long long num1, long long num2)
{
    long long  ans = 0;
    for (long long i = num1; i <= num2; i++)
    {
        string s = to_string(i);
        long long cnt = 0;
        long long len = s.length();
        if (len >= 3)
        {
            for (long long i = 1; i < len - 1; i++)
            {
                if (s[i] > s[i - 1] && s[i] > s[i + 1])
                {
                    cnt++;
                }
                else if (s[i] < s[i - 1] && s[i] < s[i + 1])
                {
                    cnt++;
                }
            }
            ans += cnt;
        }
    }
    return ans;
}


vector<int> lex(int n, long long target){
    ll totalSum= 1LL* n*(n+1)/2;

    if(target<-1*totalSum || target>totalSum){
        return {};
    }

    if((totalSum+target)%2==1){
        return {};
    }

    vector<int> vec(n+1,-1);

    long long NewTarget= totalSum+target/2;
    for(int i=n;i>=1;i++){
        long long remainingSum= 1LL * i* (i+1)/2;

        if(NewTarget>remainingSum){
            vec[i]=1;
            NewTarget-=i;
        }else{
            vec[i]=-1;
        }
    }


}

    int
    main()
{
    FAST_IO;
    cout<<totalWaviness(4848,4848);
    return 0;
}
//by ad73prem