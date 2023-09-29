// Optimizacion 
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>
using namespace std;

// #define int long long int
#define pb push_back
#define all(s) s.begin(),s.end()
#define len(s) (int)s.size()
#define precise(ans,k) fixed << setprecision(k) << ans //k digit
#define MAX LLONG_MAX // INT_MAX
#define MIN LLONG_MIN // INT_MIN
#define forn(i, n) for (int i = 0; i < n; i++)
#define forn2(i, n) for (int i = n-1; i >= 0; i--)
#define fore(i, a, b) for (int i = a; i <= b; i++)
#define fore2(i, a, b) for (int i = b; i >= a; i--)
#define ff first
#define ss second
#define mkp make_pair
#define mkt make_tuple

typedef long long ll;
typedef double lf;

typedef pair<ll, ll> pii;
typedef vector<ll> vii;

const ll oo = 1e18;
const lf PI = acos(-1);//3.141592653589793;
const lf eps= 1e-9;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 5;

//MOD
inline ll add(ll a, ll b, const ll& mod) { return a+b >= mod ? a+b-mod : a+b; }
inline ll sbt(ll a, ll b, const ll& mod) { return a-b < 0 ? a-b+mod : a-b; }
inline ll mul(ll a, ll b, const ll& mod) { return 1ll*a*b%mod; }
//

// Primes
// const int N2 = 9e7 + 5;
// ll prime[5000005]; // Calcula 5*10^5 primos
// vector<bool> isprime(N2, false);
// void criba(int n){
//     int k = 0;
//     for(int i = 2; i <=n; i++){
//         if(isprime[i]) continue;
//         prime[k] = i;
//         k++;
//         if(k > 5000000) break;
//         for(int j = i; j <= n; j+=i) isprime[j] = true;
//     }
// }
/*
int n = 90000000;
criba(n);
*/
//

// Numero de divisores
// int numDiv[N];
// void fNumDiv(int n){
//     for(int i = 1; i <=n; i++){
//         for(int j = i; j <=n; j += i) numDiv[j]++;
//     }
// }
//

// Inverso FAST
// ll inv[N];
// void fastInv(int n){
//     inv[1] = 1;
//     for(ll i = 2;  i< n; i++){
//         inv[i] = MOD - (ll)(MOD/i) * inv[(ll)(MOD%i)]%MOD;
//     }
// }

// Factorial modulo p
// ll fac[N], facInv[N];
// void bino_ini(ll n){
//     fac[0] = fac[1] = 1;
//     facInv[0] = facInv[1] = 1;
    
//     for(ll i = 2;  i< n; i++){
//         fac[i] = (fac[i-1]*i)%MOD;
//         inv[i] = MOD - (ll)(MOD/i) * inv[(ll)(MOD%i)]%MOD;
//         facInv[i] = (facInv[i-1]*inv[i])%MOD;
//     }
// }
//

// Exponenciación fast :v
ll expfast(ll b, ll e){
    if(e == 0LL) return 1;
    if(e & 1LL) return (expfast(b*b,e >> 1) * b);
    return expfast(b*b, e >> 1);
}

ll expFastItr(ll a, ll b){ // Modulo MOD
    ll x = 1LL;
    for(int i = (int)log2(b)+1; i >=0; i--){
        x = mul(x,x, MOD);
        if(b & (1LL << i)) x = mul(x,a, MOD);
    }
    return x;
}
//

int dx[] = {1,-1,0, 0,1,-1,-1, 1};
int dy[] = {0, 0,1,-1,1, 1,-1,-1};

bool insLim(int i, int j, int n, int m){
    return i >= 0 && i < n && j >= 0 && j < m;
}


// int32_t main(){
int main(){
    #ifdef LOCALNZN
       freopen("input.txt", "r", stdin); 
       //freopen("output.txt", "w", stdout);  
    #else
        #define endl '\n'
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
