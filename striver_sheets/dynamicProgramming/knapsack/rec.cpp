int func(int ind, int bag, vector<int> & weights, vector<int> & values){
    //base cases
    // cout<<"ind : "<<ind<<" bag : "<<bag<<endl;
    if(ind ==0){
        if(weights[ind]<=bag)return values[ind];
        else return 0;
    }

    if(bag==0){
        return 0;
    }

    int notPick=0+func(ind-1, bag, weights, values);
    int pick=0;
    if(weights[ind]<=bag){
        pick=values[ind] + func(ind-1, bag-weights[ind], weights, values);
    }

    return max(pick, notPick);
}

int knapsack(vector<int> & weights, vector<int> & values, int bag){
    int n=weights.size();
    return func(n-1, bag, weights, values);
