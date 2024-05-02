//Algorithm or Logic: Sieve of Eratosthenes (criba de eratóstenes algoritmo)
//Complexity: O(n log(log n))
//

vector <ll> prime;
void prim(ll n){ // primes with n >= 2
    ll is_prime_num[n+5];
    is_prime_num[0]=-1;
    is_prime_num[1]=-1;
    for(ll i=2; i<=n; i++) is_prime_num[i]=i;

    ll i=2;
    while(i*i<n){ // i*i<n 2 to sqrt(n) // i<=n for all primes before n
        if(is_prime_num[i]!=-1){
            prime.push_back(i);
            for(ll j=i; j <= n/i; j++){ // for (int j = i * i; j <= n; j += i)
                is_prime_num[i*j]=-1;
            }
        }
        i++;
    }
}

const int N = 9e7 + 5;
ll prime[5000005]; // Calcula 5*10^5 primos
vector<bool> isprime(N, false);
void criba(int n){
    int k = 0;
    for(int i = 2; i <=n; i++){
        if(isprime[i]) continue;
        prime[k] = i;
        k++;
        if(k > 5000000) break;
        for(int j = i; j <= n; j+=i) isprime[j] = true;
    }
}
//int n = 90000000;

void criba(int n){
    for(int i = 2; i <= n; i++){
        if(isprime[i]) continue;
        prime.push_back(i);
        for(int j = i; j <= n; j+=i) isprime[j] = (ll)i;
    }
}


// Descomposicion prima
vector<ll> factors, ex;
ll id = 0, p = prime[id];
while(p*p <= n){
    if(n%p == 0) factors.push_back(p);
    ll power = 0;
    while(n%p == 0){
        n/= p;
        power++;
    }
    if(power) ex.push_back(power);
    p = prime[id++];
}
if(n!= 1) {factors.push_back(n); ex.push_back(1);}


ll phiEuler(ll n){
    ll ans = 0;
    for(ll i = 1; i<n; i++){
        if(__gcd(n,i) == 1) ans++;
    }
    return ans; // const ll phi = ans - 1;
} 
