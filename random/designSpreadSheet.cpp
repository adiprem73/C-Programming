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

class Spreadsheet {
    private:
        map<char, vector<int>> sheet;
    public:
        Spreadsheet(int rows) {
            vector<int> vec(rows, 0);
            for(char i='A'; i<='Z';i++){
                sheet[i]= vec;
            }
        }
        
        void setCell(string cell, int value) {
            char col= cell[0];
            int row= stoi(cell.substr(1));
            // cout<<col<<" "<<row<<endl;
            sheet[col][row]=value;
        }
        
        void resetCell(string cell) {
            char col = cell[0];
            int row = stoi(cell.substr(1));
            sheet[col][row] = 0;
        }
        
        int getValue(string formula) {
            vector<string> operands;
            string word="";
            int cnt=0;
            for(int i=0;i<formula.length();i++){
                if(formula[i]=='+'){
                    operands.push_back(word);
                    word="";
                }
                if(formula[i]!='+' && formula[i]!='='){
                    word=word+formula[i];
                }
                if(formula[i]>='A'&& formula[i]<='Z'){
                    // cout<<"hello"<<endl;
                    cnt++;
                }
            }
            operands.push_back(word);
            // cout<<"hello"<<endl;
            // cout<<operands[0]<<" "<<operands[1]<<endl;
            // cout<<" cnt : "<<cnt<<endl;
            if(cnt==2){
                char col1= operands[0][0];
                char col2 = operands[1][0];
                int row1= stoi(operands[0].substr(1));
                int row2= stoi(operands[1].substr(1));
                return sheet[col1][row1]+sheet[col2][row2];
            }
            if(cnt==1){
                if(operands[0][0]>='A' && operands[0][0]<='Z'){
                    char col= operands[0][0];
                    int row= stoi(operands[0].substr(1));
                    int val2= stoi(operands[1]);
                    return sheet[col][row]+val2;
                }
                else{
                    char col = operands[1][0];
                    // cout<<"hello"<<endl;
                    int row = stoi(operands[1].substr(1));
                    // cout<<"hello"<<row<<endl;
                    int val2 = stoi(operands[0]);
                    return sheet[col][row] + val2;
                }
            }
            if (cnt==0){
                cout<<stoi(operands[0]);
                return stoi(operands[0])+stoi(operands[1]);
            }
            return 0;
        }
    };

int main() {
    FAST_IO;
    Spreadsheet sp(24);
    // cout<<sp.getValue("=45265+U720")<<endl;
    sp.setCell("B24", 66688);
    // cout << sp.getValue("=A1+6")<<endl;
    // sp.setCell("B2", 15);
    // cout<<sp.getValue("=A1+B2")<<endl;
    sp.resetCell("O15");
    // cout << sp.getValue("=A1+B2") << endl;
    return 0;
}
//by ad73prem