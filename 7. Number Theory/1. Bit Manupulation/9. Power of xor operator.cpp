#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 4, b = 6;
    /*
    1 0 -> 1
    0 1 -> 1
    0 0 -> 0
    1 1 -> 0
    */
   a = a^b;
   b = b^a; // b = b ^ (a^b)
   // b^b = 0
   //a ^ 0 -> a
   // b = a
   a = a^b;
   // (a^b)^a -> b
   cout << a << " " << b << "\n";

}