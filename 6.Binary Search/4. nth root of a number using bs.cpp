#include<bits/stdc++.h>
using namespace std;
double eps = 1e-7;
double multiply(double mid, int n){
    double ans = 1;
    for(int i=0; i<n; i++){
        ans *= mid;
    }
    return ans;
}
int main(){
    double x;
    cin >> x;
    int n;
    cin >> n;
    double l = 1, h = x;
    //N*log(10^d)
    while(h-l>eps){
        double mid = (h+l)/2;
        if(multiply(mid, n) > x){
            h = mid;
        }else{
            l = mid;
        }
    }
    cout << setprecision(10) << l << "\n";
    cout << pow(x, 1.0/n) << endl;

}