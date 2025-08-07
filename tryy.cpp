#include <bits/stdc++.h>
using namespace std;

static const int FULL_MASK = 0x3FE;

int rowMask[9], colMask[9], blockMask[9];
int init_val[9][9], assignment_[9][9], best_assign[9][9];
int cell_type[9][9]; 
int K, best_mod, current_mod, assigned_count;
bool foundZero;
int hintMask;
vector<pair<int,int>> mod_cells;

inline int blockIndex(int r, int c) {
    return (r/3)*3 + (c/3);
}


void dfs() {
    if(foundZero) return;
    if(current_mod >= best_mod) return;
    if(current_mod > K) return;        
    
    if(assigned_count == (int)mod_cells.size()) {
        best_mod = current_mod;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                best_assign[i][j] = assignment_[i][j];
        if(best_mod == 0) foundZero = true;
        return;
    }
    
    
    int minCount = 10, selR=-1, selC=-1, selMask=0;
    for(auto &p: mod_cells) {
        int r = p.first, c = p.second;
        if(assignment_[r][c] != 0) continue;
        int b = blockIndex(r,c);
        int avail = ~(rowMask[r] | colMask[c] | blockMask[b]) & FULL_MASK;
        if(cell_type[r][c] == 2) {
            
            avail &= hintMask;
        }
        int cnt = __builtin_popcount(avail);
        if(cnt == 0) return;            
        if(cnt < minCount) {
            minCount = cnt;
            selR = r; selC = c;
            selMask = avail;
            if(cnt == 1) break;         
        }
    }
    
    int iv = init_val[selR][selC];
    vector<int> cands;
    if(iv > 0 && (selMask & (1 << iv))) {
        cands.push_back(iv);
    }
    for(int v = 1; v <= 9; v++) {
        if(v == iv) continue;
        if(selMask & (1 << v)) {
            cands.push_back(v);
        }
    }
    
    int b = blockIndex(selR, selC);
    for(int v: cands) {
        assignment_[selR][selC] = v;
        rowMask[selR]    |= (1<<v);
        colMask[selC]    |= (1<<v);
        blockMask[b]     |= (1<<v);
        
        assigned_count++;
        int delt = (v != init_val[selR][selC]) ? 1 : 0;
        current_mod += delt;
        
        dfs();
        
        current_mod -= delt;
        assigned_count--;
        rowMask[selR]    ^= (1<<v);
        colMask[selC]    ^= (1<<v);
        blockMask[b]     ^= (1<<v);
        assignment_[selR][selC] = 0;
        
        if(foundZero) return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            string s;
            cin >> s;
            int val;
            if(s.back() == '0'){
                val = stoi(s.substr(0, s.size()-1));
                cell_type[i][j] = 2;
            }
            else if(s.size() > 1 && s[0] == '0'){
                val = stoi(s.substr(1));
                cell_type[i][j] = 1;
            }
            else {
                val = stoi(s);
                cell_type[i][j] = 0;
            }
            init_val[i][j] = val;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> hints;
    int x;
    while(iss >> x) hints.push_back(x);
    hintMask = 0;
    for(int v : hints) {
        hintMask |= (1<<v);
    }
    cin >> K;
    
    memset(rowMask, 0, sizeof(rowMask));
    memset(colMask, 0, sizeof(colMask));
    memset(blockMask, 0, sizeof(blockMask));
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            assignment_[i][j] = 0;
        }
    }
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(cell_type[i][j] == 0){
                int v = init_val[i][j];
                assignment_[i][j] = v;
                rowMask[i] |= (1<<v);
                colMask[j] |= (1<<v);
                blockMask[blockIndex(i,j)] |= (1<<v);
            } else {
                mod_cells.emplace_back(i,j);
            }
        }
    }
    
    if(mod_cells.empty()){
        bool ok = true;
        for(int i=0;i<9;i++){
            if(rowMask[i] != FULL_MASK) ok = false;
            if(colMask[i] != FULL_MASK) ok = false;
            if(blockMask[i] != FULL_MASK) ok = false;
        }
        if(ok) {
            cout << "Won\n";
        } else {
            cout << "Impossible\n";
        }
        return 0;
    }
    
    best_mod = K + 1;
    current_mod = 0;
    assigned_count = 0;
    foundZero = false;
    
    dfs();
    
    if(best_mod == 0){
        cout << "Won\n";
    }
    else if(best_mod > K){
        cout << "Impossible\n";
    }
    else {
        vector<pair<int,int>> wrong;
        for(auto &p : mod_cells){
            int r = p.first, c = p.second;
            if(best_assign[r][c] != init_val[r][c]) {
                wrong.emplace_back(r,c);
            }
        }
        sort(wrong.begin(), wrong.end());
        for(auto &p: wrong) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    
    return 0;
}
