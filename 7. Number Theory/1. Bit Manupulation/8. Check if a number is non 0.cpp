#include<bits/stdc++.h>
using namespace std;
void printBinary(int n){
    for(int i=10; i>=0; i--){
        cout << ((n >> i) & 1);
    }
    cout << "\n";
}
int main(){
    int n;
    cin >> n;
    /*
    n and power of 2 = 00010000000
    n-1 =              00001111111
    */
    if(n&(n-1)){
        cout << "not power of 2" << "\n"; 
    }else{
        cout << "power of 2" << "\n";
    }
}
