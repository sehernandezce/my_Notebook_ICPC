const ll MOD = 1e9 + 7;
struct mod{
    ll m;
    mod() {};
    mod(const ll& o): m(o){};
    mod operator * (const mod& o) const{return 1LL * m * o.m % MOD; };
    mod operator + (const mod &o) const{return m + o.m < MOD ? m + o.m : m + o.m - MOD;};
    mod operator ^(ll e)const{
        if(e == 0) return 1;
        mod t = *this ^ (e/2);
        if(e & 1) return t * t * (*this);
        return t * t;
    }
    mod operator !() const {return *this ^(MOD - 2);}
    mod operator / (const mod &b) const {return *this * !b;};
};


// MOD
inline ll mod(ll a, const ll& mod) 
{
    if(a>=0) return a%mod;
    else 
    {
        ll k = (abs(a)+mod-1)/mod;
        return (a+(mod*k))%mod;
    }
}


ll phiEuler(ll n){
    ll ans = 0;
    for(ll i = 1; i<n; i++){
        if(__gcd(n,i) == 1) ans++;
    }
    return ans;
}
