#include<bits/stdc++.h>
using namespace std;

bool func(vector<int> &a, vector<int> &b){
    // we need to sort by ends in ascending
    if(a[1]<b[1])return true;
    else if(a[1]==b[1]){
        if(a[0]>b[0])return true;
        else return false;
    }else {
        return false;
    }
}

int intersectionSizeTwo(vector<vector<int>> &intervals)
{
    // the very first job is to sort the intervals in the desried way
    sort(intervals.begin(), intervals.end(), func);
    // for(int i=0;i<intervals.size(); i++){
    //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
    // }

    // now since the sorting is done we will start maintiannign the set
    set<int> st;
    int last1,last2;
    if(intervals[0][0]!=intervals[0][1]){
        last1= intervals[0][0];
        last2= intervals[0][1];
    }
    st.insert(last1);
    st.insert(last2);

    for(int i=1;i<intervals.size();i++){
        int a= intervals[i][0];
        int b= intervals[i][1];
        cout<<"interval : "<<a<<" "<<b<<endl;
        cout<<"last1: "<<last1<<" last2: "<<last2<<endl;

        if (last1 >= a && last1 <= b && last2 >= a && last2 <= b){
            // do nothing in this case
            // cout<<"i did noting"<<endl;
        }
        else if ((last1 >= a && last1 <= b) || (last2 >= a && last2 <= b))
        {
            st.insert(b);
            auto it = st.end();
            it--; // now points to last (largest)
            last2 = *it;

            if (it != st.begin())
            {
                it--; // now points to second last
                last1 = *it;
            }
        }
        else{
            st.insert(b);
            st.insert(b-1);
            auto it = st.end();
            it--; // now points to last (largest)
            last2 = *it;

            if (it != st.begin())
            {
                it--; // now points to second last
                last1 = *it;
            }
        }
        // set<int> st_copy = st;
        // cout << "st copy: ";
        // for (int x : st_copy) cout << x << " ";
        // cout << endl;
    }
    vector<int> vec(st.begin(), st.end());
    // for(auto it: vec){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    return vec.size();
}

int main()
{
    // vector<vector<int>> intervals={{1,3},{2,3},{3,7},{8,9}};
    // vector<vector<int>> intervals = {{2,10},{3,7},{3,15},{4,11},{6,12},{6,16},{7,8},{7,11},{7,15},{11,12}};
    vector<vector<int>> intervals={{3,13},{2,8},{5,10}};

    cout<<intersectionSizeTwo(intervals);
    return 0;
}
//by ad73prem