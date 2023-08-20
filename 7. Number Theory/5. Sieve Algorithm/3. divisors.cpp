#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> divisors[N];
int sum[N];
int main(){
    //Nlog(n)
    for(int i = 2; i < N/2; i++){
        for(int j=i; j<N/2; j+=i){
            divisors[j].push_back(i);
            sum[j] += i;
        }
    }
    for(int i=1; i<100; i++){
        cout << i << "-> ";
        for(int div: divisors[i]){
            cout << div << " ";
        }
        cout <<"\n" << "sum-> ";
        cout << sum [i] << "\n";
        cout << "num of div-> " <<divisors[i].size() << "\n";
        cout << "\n";
    }
}