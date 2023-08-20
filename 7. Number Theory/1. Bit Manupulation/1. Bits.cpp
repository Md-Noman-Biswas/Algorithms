#include<bits/stdc++.h>
using namespace std;
int main(){
    cout << INT_MAX << "\n";
    int a = (1LL << 31)-1;
    /*
    1 bit is reserved thats why we are taking 31 bit
    ll should be a added couse (1 << 32) is a 33 bit number.
    thats why it cant store unless ll is done.
    it cant store 1<<32 because its a signed integer.
    here 1 bits stays reserved to show sign.
    so it becomes 33. thats why it overflows.
    on the other hand, unsigned needs no such bits to
    show sign. thats why it can store 1<<32
    */ 
    cout << a << "\n";
    unsigned int b = (1LL << 32) - 1;
    cout << b << endl;
}