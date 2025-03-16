#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
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

int findBeauty(string s){
    map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    int maxFreq=0;
    int minFreq=INT_MAX;
    for(auto it: mp){
        maxFreq=max(maxFreq,it.second);
        minFreq=min(minFreq,it.second);

    }
    return maxFreq-minFreq;
}

int beautySum(string s) {
    vector<string> sub;
    string temp;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            sub.push_back(temp);
        }
        temp="";
    }
    int sumBeauty=0;
    for(int i=0;i<sub.size();i++){
        sumBeauty+=findBeauty(sub[i]);
    }
    return sumBeauty;
}

int main() {
    FAST_IO;
    string s="njuvwehovhmnwfypqqzzguivrvmfuxdsbebskjfwzmjjqrrqwgdkibdkjhrrmjdehakrmjqtwwtqmyfzkqvyzbjggtmuaadmbwqynqosylguacktujyvxsoufzmltvttdupsuujbwrnfbbmqwyshsiytguxfuipcdutjoaracfxqogfsdhaczietafvkdlzzsyxycbemyedyrwkjzvudzgngixyftbldeyoadukxwsazunrrwafyvayfrbeqkzztdqnrgrgxmfkxxprzvshbsotcqffoteucenrnfxlphzrpllvuidrihuluvinpt";
    cout<<beautySum(s);
    return 0;
}
//by ad73prem