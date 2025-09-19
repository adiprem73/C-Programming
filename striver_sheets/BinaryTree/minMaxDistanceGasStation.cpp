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

/*
arr[]= {1 2 3 4 5} and k=4... we need to insert k new gas stations in the array.
wr have to insert it in such a way that the max distance between any two gas stations in minimised. (the gas stations are to be made as clos as possible to each other in general)

{1    1.25    1.5     1.75    2   3   4   4.5     5}

{1   1.5    2   2.5     3   3.5     4   4.5     5}... this way the max distance between two stations is 0.5.

arr= {1     7} and k=2

... we would always want to insert the new gas stations in between the gas stations
1      .    .   7=====> distance would be  (7-1)/3
1       3   5   7=====> distance would be 2



1  13  17  23,      k=5

first take k=1: maximum distance right now is betwwemn 1 and 13. dist=12
k=2, 1  7  13  17  23
1  7  13  17  20  23


📌there might come time swhen we have to remove what we put and re enter the elements into the array. 

suppose 1  .  .  13. now we would put 13-1=12/3=4 distances apart
        1  5  9  13. now if we get to put another k in between 1 and 13 then we can reduce the max distance even more if we remove the 5 and the 9 and put 13-1=12/4=3 distances apart gast stations

        hence, it woul dbecome 1  4  7  10  13 and the now max distance is even minimised into 3

for(gas stations : 1 to k){
    vector how many={0,0,0}... ((these denotes the spaces im betweenn the gas stations and the values denote the number of gas stations already inserted in each space))

    maximumVal=-1; maximumInd=-1;

    for( i : 0 to n-1){
        diff = arr[i+1]- arr[i];
        sectionLenght= diff/ (howmany[i]+1);
        if(maxi<sectionLength){
            maximumVal= sectionLength;
            maxInd=i;
        }
        howmany[maxind]++;
    }

    maxAns= -1;

    for(i:0 to n-1){
        sectionLenght= (arr[i+1]-arr[i])/ howmnay[i]+1;
        maxAns= nmax(maxAns, sectionslength)
    }
    return maxAnsp;


}


*/


/*
long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n=arr.size();
    vector<int> inBetweenCnt(n-1, 0);
    //we will place the gas stations one at a time
    for(int gasStations=1;gasStations<=k;gasStations++){
        long double  maxDistance=-1;
        int maxDistInd=-1;

        for(int i=0;i<n-1;i++){
            int diff= arr[i+1]-arr[i];
            int sectionLenght= diff/ inBetweenCnt[i]+1;

            if(maxDistance< sectionLenght){
                maxDistance= sectionLenght;
                maxDistInd= i;
            }
            inBetweenCnt[maxDistInd]++;
        }
    }

    int maxAns=-1;
    for(int i=0;i<n-1;i++){
        int sectionLen= (arr[i+1]-arr[i])/ (inBetweenCnt[i]+1);
        maxAns= max(maxAns, sectionLen);
    }
    return maxAns;
}
*/

/*

//optimising priotrity queue : we will store the maxDistance and maxDistInd inside the priority queue so that we can easuly access it by priority queue top

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> inBetweenCnt(n - 1, 0);
    priority_queue<pair<long double,int>> pq; //(dsitance, index)
    // we will place the gas stations one at a time

    //inserting all the section in the priority queue
    for(int i=0;i<n;i++){
        pq.push({arr[i+1]-arr[i], i});
    }
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto tp= pq.top();
        pq.pop();
        int secInd= tp.second;
        inBetweenCnt[secInd]++;

        long double oldDiff= arr[secInd+1]-arr[secInd];

        long double newSecLen = oldDiff/ (long double)(inBetweenCnt[secInd]+1);

        pq.push({newSecLen, secInd});
    }

    return pq.top().first;
}

*/
/*
//applying binary search:


we always do this for binary search in long double
while(high-low > 10^-6){



        low=mid;

        high=mid;
}

the range of the answer: 0 to something : max{distance between the elements of the array}


low= 0;
high= maxDist;

while(high-low>10^-6){
    mid = low+high / 2.0;
    int cnt= countOfGasStation(arr, mid);
    if(cnt>k)low=mid;
    else high=mid;

}
return high;


*/

int numberOfGasStationsReq(long double dist, vector<int> &arr){
    int cnt=0;
    for(int i=1;i<arr.size();i++){
        int numberInBetween= (arr[i]- arr[i-1])/dist;
        if((arr[i]-arr[i-1])/dist == numberInBetween*dist){
            numberInBetween--;
        }
        cnt+=numberInBetween;
    }return cnt;

}


long double minimiseMaxDistance(vector<int> & arr, int k){
    int n=arr.size();
    long double low=0;
    long double high=0;
    for(int i=0;i<n-1;i++){
        high= max(high, (long double)arr[i+1]-arr[i]);
    }

    long double diff= 1e-6;
    while(high-low>diff){
        long double mid= (low+high)/(2.0);
        int cnt= numberOfGasStationsReq(mid, arr);
        if(cnt>k){
            low=mid;
        }else{
            high = mid;
        }
    }
    return high;
}

int main()
{
    FAST_IO;
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    return 0;
}
//by ad73prem