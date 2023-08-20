#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int subset_ct = (1<<n);
    vector<vector<int>> subsets;
    for(int mask = 0; mask < subset_ct; mask++){
        vector<int> subset;
        for(int i=0; i<n; i++){
            if((mask & (1<<i)) != 0){//mask value 000->001->010->011->100->101->110->111
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
    //size of 1st for loop 2^n
    //O(n*2^n)
    return subsets;
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    auto all_subsets = subsets(v);
    for(auto it: all_subsets){
        for(auto ele: it){
            cout << ele << " ";
        }
        cout << "\n";
    }
}