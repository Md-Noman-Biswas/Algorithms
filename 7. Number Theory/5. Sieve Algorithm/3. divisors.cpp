#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> divisors[N];
int sum[N];

void calculate_div(){
    for(int i = 1; i*i < N; i++){
        for(int j=i; j < N; j+=i){
            divisors[j].push_back(i);
            sum[j] += i;
        }
    }
}


int main(){
    //Nlog(n)
    calculate_div();
    // for(int i=1; i<100; i++){
    //     cout << i << "-> ";
    //     for(int div: divisors[i]){
    //         cout << div << " ";
    //     }
    //     cout <<"\n" << "sum-> ";
    //     cout << sum [i] << "\n";
    //     cout << "num of div-> " <<divisors[i].size() << "\n";
    //     cout << "\n";
    // }
    cout << sum[100] << "\n";
}
