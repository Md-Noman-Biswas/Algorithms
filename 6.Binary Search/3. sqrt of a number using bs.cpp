#include<bits/stdc++.h>
using namespace std;
double eps = 1e-7;
int main(){
    double x;
    cin >> x;
    double l = 1, h = x;
    while(h-l>eps){
        double mid = (h+l)/2;
        if(mid * mid > x){
            h = mid;
        }else{
            l = mid;
        }
    }
    cout << setprecision(10) << l << "\n";

}