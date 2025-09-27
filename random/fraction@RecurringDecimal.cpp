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

bool checkDenominator(int n){
    // this function will check if there is some other factor other thant 2 and 5 is present or not. if present then repeating

    for(int i=1;i*i<=n;i++){
        double d= (double)n/ (double)i;
        if(d==2.0 || d==5.0){
            
        }else{
            return false;
        }
    }
    return true;
}

// false means: some other factor other than 2 and 5--> repeating digits after decimal

string findRepeating(int num, int den){

    string result;

    

    unordered_map<int,int> seen;
    string decimals;
    long long remainder= ((long long)num)%((long long)den);
    int pos=0;
    while(remainder!=0 && seen.find(remainder)==seen.end()){ //loop continue till the number becomes 0 or it is already stoed in the seen map
        seen[remainder]=pos++;
        remainder*=10;
        int digit= (int) (remainder/ (long long)den);
        decimals.push_back(char('0'+digit));
        remainder=remainder%(long long)den;
    }

    if(remainder==0){
        return "";
    }

    else{
        int start= seen[remainder];
        return decimals.substr(start);
    }
}

string fractionToDecimal(int numerator, int denominator)
{

    string result;

    if((numerator<0 ^ denominator<0) && numerator!=0) result.push_back('-');

    long long num=llabs((long long)numerator);
    long long den= llabs((long long)denominator);
    
    long long part1= num/den;
    // cout << part1 << endl;
    // cout << part1 << endl;
    result+=to_string(llabs(part1));
    

    unordered_map<int, int> seen;
    string decimals;
    long long remainder = ((long long)num) % ((long long)den);
    if(remainder==0){
        return result;
    }
    result.push_back('.');

    int pos = 0;
    while (remainder != 0 && seen.find(remainder) == seen.end())
    { // loop continue till the number becomes 0 or it is already stoed in the seen map
        seen[remainder] = pos++;
        remainder *= 10;
        int digit = (int)(remainder / (long long)den);
        decimals.push_back(char('0' + digit));
        remainder = remainder % (long long)den;
    }

    if (remainder == 0)
    {
        result+=decimals;
    }

    else
    {
        int start = seen[remainder];
        result+=decimals.substr(0,start) + '(' + decimals.substr(start) + ')';
    }

    return result;
    // now the rest o fthe number that is after the decimal is to be calculated --> r/denominator
    
    // a division will give terminating if the denominator contains such a number whose factors are only 2 and 5. if any other factor comes then its repeating

}

int main()
{
    FAST_IO;
    cout << fractionToDecimal(-2147483648, 1);
    return 0;
}
//by ad73prem