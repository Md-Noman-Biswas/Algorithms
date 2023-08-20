#include<bits/stdc++.h>
using namespace std;
void printBinary(int n){
    for(int i=10; i>=0; i--){
        cout << ((n >> i) & 1);
    }
    cout << "\n";
}
int main(){
    printBinary(59);
    int i = 3;//to which bit
    /*
    00000111011
    00000001111
    00000010000-1
    */
    int a = 59;
    int b = a & ((1<<(i+1))-1);
    printBinary(b);
}