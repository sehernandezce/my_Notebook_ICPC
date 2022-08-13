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
            for(ll j=i; j <= n/i; j++){
                is_prime_num[i*j]=-1;
            }
        }
        i++;
    }
}

/*
    ll n;
    cin >> n;
    prim(n);
    for(auto ele: prime) cout << ele << " ";
    cout << endl;
*/
