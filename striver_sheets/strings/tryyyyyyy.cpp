#include <bits/stdc++.h>
using namespace std;

/*
  We read a single line of tokens (space-separated).
  First we classify each token as an operation or an operand.
  If any token is neither, we immediately print the invalid-words message.
  Otherwise, we check if we have exactly (#ops + 1) operands.
  If not, we print the incomplete-or-invalid message.
  Finally, we evaluate right-to-left:
    Let m = ops.size(),
        operands indexed 0..m,
        ops indexed 0..m-1 in appearance order.
    Compute
      T = apply( ops[m-1], operands[0], operands[1] )
    Then for j = m-2 down to 0:
      idx = (m-1)-j + 1 = m - j
      T = apply( ops[j], T, operands[idx] ).
    Print T.
  Any division/mod-zero or other invalid evaluation also
  triggers the incomplete-or-invalid message.
*/

bool tryParseNumber(const string &s, long long &out) {
    // Split on 'c'
    vector<string> parts;
    size_t i = 0, n = s.size();
    while (i < n) {
        size_t j = s.find('c', i);
        if (j == string::npos) j = n;
        if (j == i) return false; // empty part
        parts.push_back(s.substr(i, j - i));
        i = j + 1;
    }
    static unordered_map<string,int> digit = {
        {"zero",0}, {"one",1},   {"two",2},   {"three",3},
        {"four",4}, {"five",5},  {"six",6},   {"seven",7},
        {"eight",8},{"nine",9}
    };
    long long val = 0;
    for (auto &p : parts) {
        auto it = digit.find(p);
        if (it == digit.end()) return false;
        val = val * 10 + it->second;
    }
    out = val;
    return true;
}

bool applyOp(int op, long long a, long long b, long long &res) {
    // 0=add,1=sub,2=mul,3=rem,4=pow
    switch(op) {
        case 0: res = a + b; return true;
        case 1: res = a - b; return true;
        case 2: res = a * b; return true;
        case 3:
            if (b == 0) return false;
            res = a % b;
            return true;
        case 4:
            if (b < 0) return false;
            // integer power
            {
                long long r = 1;
                for (long long i = 0; i < b; i++) {
                    // guard overflow? Assume fits in 64-bit
                    r = r * a;
                }
                res = r;
            }
            return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    if (!getline(cin, line)) return 0;
    if (line.empty()) {
        cout << "expression is not complete or invalid\n";
        return 0;
    }

    // split line into tokens
    istringstream iss(line);
    vector<string> tokens;
    string w;
    while (iss >> w) {
        tokens.push_back(w);
    }

    static unordered_map<string,int> opmap = {
        {"add",0}, {"sub",1}, {"mul",2}, {"rem",3}, {"pow",4}
    };

    vector<int> ops;
    vector<long long> operands;
    bool invalidWord = false;

    for (auto &t : tokens) {
        auto it = opmap.find(t);
        if (it != opmap.end()) {
            ops.push_back(it->second);
        } else {
            long long num;
            if (!tryParseNumber(t, num)) {
                invalidWord = true;
                break;
            }
            operands.push_back(num);
        }
    }

    if (invalidWord) {
        cout << "expression evaluation stopped invalid words present\n";
        return 0;
    }

    // we need exactly #operands == #ops + 1
    if ((int)operands.size() != (int)ops.size() + 1) {
        cout << "expression is not complete or invalid\n";
        return 0;
    }

    // evaluate right-to-left
    int m = ops.size();
    long long result;
    if (m == 0) {
        // no ops: must have exactly 1 operand
        result = operands[0];
    } else {
        // first apply the last op to operands[0], operands[1]
        if (!applyOp(ops[m-1], operands[0], operands[1], result)) {
            cout << "expression is not complete or invalid\n";
            return 0;
        }
        // then fold backwards
        for (int j = m - 2; j >= 0; j--) {
            int idx = (m - 1) - j + 1; // = m - j
            long long tmp;
            if (!applyOp(ops[j], result, operands[idx], tmp)) {
                cout << "expression is not complete or invalid\n";
                return 0;
            }
            result = tmp;
        }
    }

    cout << result << "\n";
    return 0;
}
