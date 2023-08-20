#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10; 
#define ll long long;
int cows, n;
int stalls[N];
bool can_place_cows(int minD){
    int cows_count = 1;
    int last_pos = stalls[0];
    for(int i=0; i<n; i++){
        if((stalls[i] - last_pos) >= minD || last_pos == -1){
            cows_count++;
            last_pos = stalls[i];
        }
        if(cows_count >= cows){
            return true;
        }
    }
    return false;
}
void solve(){
    cin >> n;
    cin >> cows;
    for(int i=0; i<n; i++){
        cin >> stalls[i];
    }
    sort(stalls, stalls + n);
    int l = 0; 
    int h = n-1;
    while(h-l > 1){
        int mid = (h+l)/2;
        if(can_place_cows(mid)){
            l = mid;
        }else{
            h = mid - 1;
        }
    }
    if(can_place_cows(h)){
        cout << h << "\n";
    }else{
        cout << l << "\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}