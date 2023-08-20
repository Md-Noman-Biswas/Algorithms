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
    int a = 59;
    int i = 4;//to which bit (starts from 0 index)
    /*00000111011
      11111100000 - ~(1<<(i+1) - 1)
      00000011111 - (1<<(i+1) - 1)
      00000100000 - 1<<i+1
    */
    int b = (a & (~((1 << (i+1)) - 1)));
    printBinary(b);

}