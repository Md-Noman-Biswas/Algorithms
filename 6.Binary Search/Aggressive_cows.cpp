#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, cows;
int position[N];
bool can_place_cows(int minD){
    int lastpos = -1;
    int cows_ct = cows;
    for(int i=0; i<n; i++){
        if(position[i] - lastpos >= minD || lastpos == -1){
            cows_ct--;
            lastpos = position[i];
        }
        if(cows_ct == 0) break;
    }
    return cows_ct == 0;
}
void solve(){
    //TTTTFFFF
    cin >> n;
    cin >> cows;
    for(int i=0; i<n; i++){
        cin >> position[i];
    }
    sort(position, position + n);
    int l = 0, h = 1e9;
    while(h - l > 1){
        int mid = (l+h)/2;
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