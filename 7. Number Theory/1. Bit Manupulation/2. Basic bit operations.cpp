#include<bits/stdc++.h>
using namespace std;
void printBinary(int num){
    for(int i=10; i>=0; i--){
        cout << ((num >> i) & 1); //it takes ith bit to 0th position
        //we can count bit in this way too using ct += (num>>i)&1
    }
    cout << "\n";
}
int main(){
    printBinary(13);
    int a = 13;//8421//1101
    int i = 3;
    if((a & (1<<i)) != 0){//1000
        cout << "set bit" << "\n";
    }else{
        cout << "not set bit" << "\n";
    }
    //to set bit the 1th index
    printBinary(a | (1<<1));
    //to unset 3rd(ith) bit
    printBinary(a & ~(1<<3));
    // toggle = means turning 1 to 0 or 0 to 1
    printBinary(a^(1<<3));//XOR
    //bitcount
    int ct = 0;
    for(int i = 31; i >= 0; i--){
        if((a & (1<<i)) != 0){
            ct++;
        }
    }
    cout << ct << "\n";
    cout << __builtin_popcount(a) << "\n";//only works on int
    cout << __builtin_popcountll((1LL << 35)) << "\n";
    cout << __builtin_popcountll((1LL << 35)-1) << "\n";//2^n-1 theory
}