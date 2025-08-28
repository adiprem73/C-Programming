#include <bits/stdc++.h>
using namespace std;

bool check(int x, int y) {
    int high=max(x,y);
    int low=min(x,y);
    if(high>2*(low+1)){
        return false;
    }return true;
}

vector<string> findWords(vector<string>& words) {
    string s1="qwertyuiop";
    string s2="asdfghjkl";
    string s3="zxcvbnm";

    for(auto it: words){
        set<char> st;
        st.clear();
        for(int i=0;i<it.length();i++){
            st.insert(it[i]);
        }
        bool flag=true;
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int a,b,c,d; 
        cin >> a >> b >> c >> d;

        int x1 = a, y1 = b;       
        int x2 = c - a, y2 = d - b; 

        if (check(x1,y1) && check(x2,y2)) cout << "YES\n";
        else cout << "NO\n";
    }
}
