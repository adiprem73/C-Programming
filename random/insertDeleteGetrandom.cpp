#include<bits/stdc++.h>
using namespace std;

class RandomizedSet
{
private:
vector<int> nums;
unordered_map <int,int> mp;
mt19937 rng; //random number generator
public:
    RandomizedSet()
    {       
        random_device rd;
        rng.seed(rd());

    }

    bool insert(int val)
    {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        mp[val]= nums.size();
        nums.push_back(val);
        
        return true;

    }

    bool remove(int val)
    {
        // to perform removal in o(1)... we swap with the last element and then we pop_back
        
        auto it= mp.find(val);
        if(it == mp.end()){
            // could not find the value
            return false;
        }

        int idx= it->second;
        int lastIdx= nums.size()-1;
        if(idx!= lastIdx){
            // swap the element at the  lastindex and the value found
            int lastVal = nums[lastIdx];
            nums[idx]=lastVal;
            mp[lastVal]= idx; //update the map containing indexes accordingly
        }
        nums.pop_back(); //remove the last element
        mp.erase(it);
        return true;
    }

    int getRandom()
    {
        uniform_int_distribution<int> dist(0, nums.size()-1);
        return nums[dist(rng)];
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