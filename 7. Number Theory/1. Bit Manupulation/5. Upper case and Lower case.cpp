#include<bits/stdc++.h>
using namespace std;
void printBinary(int n){
    for(int i=10; i>=0; i--){
        cout << ((n >> i) & 1);
    }
    cout << "\n";
}
int main(){
    for(char c = 'A'; c <= 'E'; c++){
        cout << c << "\n";
        printBinary((int)c);
    }
    for(char c = 'a'; c <= 'e'; c++){
        cout << c << "\n";
        printBinary((int)c);
    }
    //tolower
    char A = 'A';
    char a = A | (1 << 5);
    cout << a << "\n";
    //toUpper
    char a2 = 'a';
    char A2 = (a & (~(1 << 5)));
    cout << A2 << "\n";
    cout << "Another way:\n";
    cout << char(1<<5) << "\n";//its space
    //uppercase to lowercase
    cout << char('C' | ' ') << "\n";
    //lowercase to uppercase
    printBinary('_');
    cout << char('c' & '_') << "\n";

}