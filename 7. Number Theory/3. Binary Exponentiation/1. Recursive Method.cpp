#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int binExpRecur(int a, int b){
    if(b == 0) return 1;
    int res = binExpRecur(a, b/2);
    if(b&1){//checking if b is odd
        return (a * ((res * 1LL * res) % M)) % M;
    }else{
        return (res * 1LL * res) % M;//adding 1LL to avoid overflow cause res*res exceeds 10^9
    }
    //TC = log(power)
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << binExpRecur(a,b);
}