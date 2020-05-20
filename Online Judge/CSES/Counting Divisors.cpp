#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
const int MOD = 1e9+7;
const int N_SIZE = 1e6+5;
vector<ll> primes;

void get_primes(){
    char *sieve;
    sieve = new char[N_SIZE/8+1];
    memset(sieve, 0xFF, (N_SIZE/8+1) * sizeof(char));
    for(int x = 2; x <= N_SIZE; x++)
        if(sieve[x/8] & (0x01 << (x % 8))){
            primes.push_back(x);
            for(int j = 2*x; j <= N_SIZE; j += x)
                sieve[j/8] &= ~(0x01 << (j % 8));
        }
    delete[] sieve;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> d(N_SIZE + 1);
	for(int i = 1; i <= N_SIZE; i++){
        for(int j = i; j <= N_SIZE; j += i){
            d[j]++;
        }
	}
	ll t;
	cin >> t;
	while(t--){
        int a;
        cin >> a;
        cout << d[a] << endl;
	}
    return 0;
}



