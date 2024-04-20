#include<bits/stdc++.h>
using namespace std;


int power(int base, int p, int m){
    //binary exponentiation
    int res = 1;
    while(p){
        if(p%2 == 1){
            res = (res*base)%m;
            p--;
        }
        else{
            base *= base;
            p /= 2;
        }
    }
    return res % m;
}
int main(){
    int a,b,m;
    cin >> a >> b >> m; //(a/b)%m
    int x = power(b,m-2,m);
    int ans = (a*x)%m;
    cout << ans << "\n";
}