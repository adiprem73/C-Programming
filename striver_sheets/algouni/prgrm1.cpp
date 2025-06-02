#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

//by aditya prem

struct Leaf {
    int x, y;
    Leaf(int x, int y) : x(x), y(y) {}
    bool operator<(const Leaf& other) const {
        return x < other.x; 
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    string commands;
    cin >> commands;

    vector<Leaf> leaves;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        leaves.emplace_back(x, y);
    }

   
    Leaf current = leaves[0];

    
    map<int, set<Leaf>> mapA; 
    map<int, set<Leaf>> mapB; 
    map<int, set<Leaf>> mapC; 
    map<int, set<Leaf>> mapD; 

    for (const auto& leaf : leaves) {
        int diff = leaf.y - leaf.x;
        int sum = leaf.x + leaf.y;
        mapA[diff].insert(leaf);
        mapB[sum].insert(leaf);
        
    }

    
    for (char cmd : commands) {
        int diff = current.y - current.x;
        int sum = current.x + current.y;
        set<Leaf>* current_set = nullptr;
        Leaf next(0, 0);
        bool found = false;

        switch (cmd) {
            case 'A': {
                auto it = mapA.find(diff);
                if (it != mapA.end()) {
                    auto& leaves_set = it->second;
                    auto leaf_it = leaves_set.upper_bound(current);
                    if (leaf_it != leaves_set.end()) {
                        next = *leaf_it;
                        found = true;
                    }
                }
                break;
            }
            case 'B': {
                auto it = mapB.find(sum);
                if (it != mapB.end()) {
                    auto& leaves_set = it->second;
                    auto leaf_it = leaves_set.upper_bound(current);
                    if (leaf_it != leaves_set.end()) {
                        next = *leaf_it;
                        found = true;
                    }
                }
                break;
            }
            case 'C': {
                auto it = mapB.find(sum);
                if (it != mapB.end()) {
                    auto& leaves_set = it->second;
                    
                    auto leaf_it = leaves_set.lower_bound(current);
                    if (leaf_it != leaves_set.begin()) {
                        --leaf_it;
                        next = *leaf_it;
                        found = true;
                    }
                }
                break;
            }
            case 'D': {
                auto it = mapA.find(diff);
                if (it != mapA.end()) {
                    auto& leaves_set = it->second;
                    auto leaf_it = leaves_set.lower_bound(current);
                    if (leaf_it != leaves_set.begin()) {
                        --leaf_it;
                        next = *leaf_it;
                        found = true;
                    }
                }
                break;
            }
        }

        if (found) {
            
            int current_diff = current.y - current.x;
            int current_sum = current.x + current.y;
            mapA[current_diff].erase(current);
            mapB[current_sum].erase(current);
            
            current = next;
        }
    }

    cout << current.x << " " << current.y << endl;

    return 0;
}