#include<bits/stdc++.h>
using namespace std;
void printBinary(int n){
    for(int i=10; i>=0; i--){
        cout << ((n >> i) & 1);
    }
    cout << "\n";
}
int main(){
    int n = 5;
    cout << (n>>1) << "\n";//n/2
    cout << (n<<1) << "\n";//n*2
    //101 -> (2^2*1 + 2^1*0 + 2^0*1)/2
    //10 -> (2^1*1 + 2^0*0) 
}