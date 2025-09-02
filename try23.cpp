#include <bits/stdc++.h>
using namespace std;

vector<long> getMaxWeight(vector<int> parcel_wroight, vector<int> parcel_count, vector<int> max_parcels){
    int n = (int)parcel_wroight.size();
    int q = (int)max_parcels.size();
    if(n == 0 || q == 0) return vector<long>(q, 0L);

    int maxCount = 0;
    int maxQuery = 0;
    for (int c : parcel_count) maxCount = max(maxCount, c);
    for (int k : max_parcels)  maxQuery = max(maxQuery, k);

    int M = max(maxCount, maxQuery);
    if (M < 1) M = 1;

    vector<long long> maxWeightByCount(M + 2, 0LL);
    for (int i = 0; i < n; ++i) {
        int c = parcel_count[i];
        if (c < 0) continue; 
        if (c > M) {
            maxWeightByCount.resize(c + 2, 0LL);
            M = c;
        }
        maxWeightByCount[c] = max(maxWeightByCount[c], (long long)parcel_wroight[i]);
    }

    vector<long long> maxWeightAtLeast(M + 3, 0LL);
    for (int c = M; c >= 0; --c) {
        maxWeightAtLeast[c] = max(maxWeightAtLeast[c + 1], maxWeightByCount[c]);
    }

    vector<long long> prefixMaxConst(M + 3, 0LL);
    for (int c = 0; c <= M; ++c) {
        long long val = maxWeightByCount[c] * (long long)c; 
        prefixMaxConst[c] = (c == 0) ? val : max(prefixMaxConst[c - 1], val);
    }


    vector<long> ans;
    ans.reserve(q);
    for (int k : max_parcels) {
        long long best = 0;
        if (k <= M) {
            long long optA = (long long)k * maxWeightAtLeast[k];
            long long optB = (k - 1 >= 0) ? prefixMaxConst[k - 1] : 0LL;
            best = max(optA, optB);
        } else {
            best = prefixMaxConst[M];
        }
        ans.push_back((long)best);
    }

    return ans;
}

#include <bits/stdc++.h>
using namespace std;

vector<long> getMaxWeight(vector<int> parcel_wroight, vector<int> parcel_count, vector<int> max_parcels){
    int n = (int)parcel_wroight.size();
    int q = (int)max_parcels.size();
    if(n == 0 || q == 0) return vector<long>(q, 0L);

    // Find maxima to size helper arrays
    int maxCount = 0;
    int maxQuery = 0;
    for (int c : parcel_count) maxCount = max(maxCount, c);
    for (int k : max_parcels)  maxQuery = max(maxQuery, k);

    int M = max(maxCount, maxQuery);
    if (M < 0) M = 0;

    // max weight among parcel types that have exactly count = i
    vector<long long> maxWeightByCount(M + 1, 0LL);
    for (int i = 0; i < n; ++i) {
        int c = parcel_count[i];
        if (c <= 0) continue;               // defensive (constraints say c >= 1)
        if (c > M) continue;               // won't happen because M includes maxCount, but safe
        maxWeightByCount[c] = max(maxWeightByCount[c], (long long)parcel_wroight[i]);
    }

    // maxWeightAtLeast[k] = max weight among parcel types with count >= k
    vector<long long> maxWeightAtLeast(M + 2, 0LL);
    for (int c = M; c >= 0; --c){
        maxWeightAtLeast[c] = maxWeightAtLeast[c + 1];
        if (c <= M) maxWeightAtLeast[c] = max(maxWeightAtLeast[c], maxWeightByCount[c]);
    }

    // prefixMaxConst[i] = best value weight*count for any type with count <= i
    vector<long long> prefixMaxConst(M + 1, 0LL);
    long long bestSoFar = 0LL;
    for (int c = 0; c <= M; ++c){
        long long val = maxWeightByCount[c] * (long long)c; // constant if k > c
        bestSoFar = max(bestSoFar, val);
        prefixMaxConst[c] = bestSoFar;
    }

    // Answer queries
    vector<long> ans;
    ans.reserve(q);
    for (int k : max_parcels){
        long long best = 0LL;
        if (k <= M){
            long long optA = (long long)k * maxWeightAtLeast[k];      // pick a type with count >= k
            long long optB = (k - 1 >= 0) ? prefixMaxConst[min(k - 1, M)] : 0LL; // pick a type with count < k
            best = max(optA, optB);
        } else {
            // no type has count >= k, must pick type with count <= M
            best = prefixMaxConst[M];
        }
        ans.push_back(static_cast<long>(best));
    }

    return ans;
}




int main(){
    vector<int> a={4,5,6};
    vector<int> b={3,2,5};
    vector<int> c={3};
    vector<long> ans=getMaxWeight(a,b,c);

    for(auto it: ans){
        cout<<it<<" ";
    }
}