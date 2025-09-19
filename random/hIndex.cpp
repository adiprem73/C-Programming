#include<bits/stdc++.h>
using namespace std;

int hIndex(vector<int> & citations){
    sort(citations.rbegin(), citations.rend());
    int mini=INT_MAX;
    int hindex;
    for(int i=0;i<citations.size();i++){
        mini=min(mini, citations[i]);
        if(mini<i+1){
            hindex=i;
            break;
        }
    }
    return hindex;
}

int main() {
    vector<int> nums={1,3,1};
    cout<<hIndex(nums);
    return 0;
}
//by ad73prem