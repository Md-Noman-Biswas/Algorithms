#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
//TC = log(n)
//TC of inbuilt function is also same
int main(){
    int t;
    cin >> t;
    while(t--){
    int a,b;
    cin >> a >> b;
    int GCD = gcd(a,b);
    int LCM = (a*b)/GCD;
    cout << "GCD: " << GCD << "\n";
    cout << "LCM: " << LCM << "\n";
    }
}