#include<bits/stdc++.h>
using namespace std;

const int N = 3010;
vector<bool> isPrime(N,1);
vector<int> prime_divisors[N];

void siv(){
    //TC = N(log(log(n)))
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<N; i++){
        if(isPrime[i] == true){
            for(int j=2*i; j<N; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void prime_div(){
    //Nlog(n)
    for(int i=2; i<N; i++){
        for(int j=i; j<N; j+=i){
            if(isPrime[i]){
                prime_divisors[j].push_back(i);
            }
        }
    }
    // for(int i=1; i<11; i++){
    //     cout << i << "-> ";
    //     for(int div: divisors[i]){
    //         cout << div << " ";
    //     }
    //     cout << "\n";
    // }
}

int main(){
    int n;
    cin >> n;
    siv();
    prime_div();
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(prime_divisors[i].size() == 2){
            ans++;
        }
    }
    cout << ans << "\n";
}