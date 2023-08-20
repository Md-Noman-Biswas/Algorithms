#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n;
long long m;
long long trees[N];
bool isWoodSufficient(int h){
    long long sum=0;
    for(int i=0; i<n; i++){
        if(trees[i] >= h){
            sum += (trees[i] - h);
        }
    }
    return sum >= m;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> trees[i];
    }
    int l = 0, h = 1e9;
    while(h - l > 1){
        int mid = (h+l)/2;
        if(isWoodSufficient(mid) == 1){
            l = mid;
        }else{
            h = mid - 1;
        }
    }
    if(isWoodSufficient(h)){
        cout << h << "\n";
    }else{
        cout << l << "\n";
    }
}