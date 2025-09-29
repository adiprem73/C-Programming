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
double distance(vector<int> a, vector<int> b){
    int x=a[0]-b[0];
    int y=a[1]-b[1];
    x=x*x;
    y-y*y;
    double dist= sqrt(x+y);
    return dist;
}


double largestTriangleArea(vector<vector<int>>& points) {
    double ans=INT_MIN;
    int n=points.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                vector<int> p= points[i];
                vector<int> q = points[j];
                vector<int> r = points[k];
                double u= distance(p,q);
                double v= distance(q,r);
                double w= distance(r,p);
                double perimeter= (u+v+w)/2;
                double area= sqrt(perimeter*(perimeter-u)*(perimeter-v)*(perimeter-w));
                ans=max(ans, area);
            }
        }
    }
    return ans;
}

*/

double largestTriangleArea(vector<vector<int>> &points)
{
    double ans = 0.0;
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int x1= points[i][0];
                int x2 = points[j][0];
                int x3 = points[k][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                int y3 = points[k][1];
                double area = 0.5* fabs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
                ans= max(ans, area);
            }
        }
    }
    return ans;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem