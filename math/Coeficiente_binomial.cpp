//Algorithm or Logic: Coeficiente binomial
//Complexity: O(N)

ll fac[N], inv[N], facInv[N];

void bino_ini(ll n){
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    facInv[0] = facInv[1] = 1;

    for(ll i = 2;  i< n; i++){
        fac[i] = (fac[i-1]*i)%MOD;
        inv[i] = MOD - (ll)(MOD/i) * inv[(ll)(MOD%i)]%MOD;
        facInv[i] = (facInv[i-1]*inv[i])%MOD;
    }
}

ll binom(ll n, ll r){
    if(n<r || n<0 || r<0) return 0;
    return (((fac[n]*facInv[r])%MOD)*(facInv[n-r]))%MOD;
}


///Con el triangulo de pascal

const int limit = 20;

ll pascal[N][limit];

int bino(int n){
    pascal[0][0] = 1;
    for(int i = 1; i < n; i++){
        pascal[i][0] = 1;
        if(i < limit) pascal[i][i] = 1;
        for(int j = 1; j < min(i, limit); j++){
           pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
           if(pascal[i][j] > oo){
              pascal[i][j] = oo;
           }
           if(pascal[i][2] > oo){
                // cout << i << " " << j << " " << pascal[i][2] << " " << pascal[i][j] << endl; // 44722
                return i;
           }
        }
    }
    return n;
}
