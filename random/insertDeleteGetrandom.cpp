#include<bits/stdc++.h>
using namespace std;

class RandomizedSet
{
private:
set<int> st;
public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        bool flag;
        flag= (st.count(val))? false: true;
        st.insert(val);
        return flag;
    }

    bool remove(int val)
    {
        for(auto it: st){
            if(it== val){
                st.erase(it);
                return true;
            }
        }
        return false;
    }

    int getRandom()
    {
        int n=st.size();
        int r= rand()%n +1;
        auto it= st.begin();
        advance(it, r);
        return *it;
    }
};

int main() {
    RandomizedSet* rst= new RandomizedSet();
    cout<<rst->insert(1)<<endl;
    cout<<rst->remove(2)<<endl;
    cout << rst->insert(2) << endl;
    cout<<rst->getRandom()<<endl;
    cout<<rst->remove(1)<<endl;
    cout << rst->insert(2) << endl;
    cout<<rst->getRandom()<<endl;

    return 0;
}
//by ad73prem