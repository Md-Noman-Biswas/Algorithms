#include<bits/stdc++.h>
using namespace std;
void printBinary(int n){
    for(int i=10; i>=0; i--){
        cout << ((n >> i) & 1);
    }
    cout << "\n";
}
int main(){
    int n;
    cin >> n;
    vector<int> masks(n,0);
    for(int i=0; i<n; i++){
        int num_workers;
        cin >> num_workers;
        int mask = 0;
        for(int j=0; j<num_workers; j++){
            int day;
            cin >> day;
            mask = (mask | (1 << day));
        }
        masks[i] = mask;
    }
    // for(int i=0; i<n; i++){
    //     cout << masks[i] << "\n";
    //     printBinary(masks[i]);
    // }
    int max_days = 0;
    int person1 = -1;
    int person2 = -2;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int intersection = masks[i] & masks[j];//O(1)
            int common_days = __builtin_popcount(intersection);//O(1)
            if(common_days > max_days){
                max_days = common_days;
                person1 = i;
                person2 = j;
            }
            max_days = max(max_days, common_days);
            //cout << i << " " << j << " " << common_days << "\n";
        }
    }

    cout << person1 << " " << person2 << " " << max_days << "\n";
    //TC = O(n^2)
}