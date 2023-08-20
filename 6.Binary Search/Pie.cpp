#include<bits/stdc++.h>
double eps = 1e-7;
using namespace std;
long double pi = 3.141592653589793238;
int n, f;
const int N = 1e6 + 10;
long double radii[N], volume[N], mid;
bool func(long double midd){
    int ff = 0;
    for(int i=0; i<n; i++){
        ff += (int)(volume[i]/midd);
    }
    return ff >= f;
}
void solve(){
    cin >> n >> f;
    f++;
    for(int i=0; i<n; i++){
        cin >> radii[i];
        volume[i] = (pi*radii[i]*radii[i]);
    }
    sort(volume, volume + n);
    long double l = 0, h = volume[n-1];
    while(h - l > eps){
        mid = (l+h)/2; 
        if(func(mid) == 1){
            l = mid;
        }else{
            h = mid;
        }
    }
    if(func(h)){
        cout << setprecision(4) << fixed << h << "\n";
    }else{
        cout << setprecision(4) << fixed << l << "\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}