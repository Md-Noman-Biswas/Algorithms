#include<bits/stdc++.h>
using namespace std;
void printBinary(int n){
    for(int i=10; i>=0; i--){
        cout << ((n >> i) & 1);
    }
    cout << "\n";
}
int main(){
    for(int i=0; i<8; i++){
        printBinary(i);
        if(i&1){
            cout << "odd" << "\n";
        }else{
            cout << "even" << "\n";
        }
    }
}