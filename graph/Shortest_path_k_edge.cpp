
const ll oo = LLONG_MAX;
vector<vector<ll>> graph (110, vector<ll>(110, oo));
int n,m,k;

vector<vector<ll>> fx(vector<vector<ll>>& A, vector<vector<ll>>& B){
    vector<vector<ll>> C (110, vector<ll>(110, oo));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ll val = oo;
            for(int z = 1; z <= n; z++){
                if(A[i][z]  == oo || B[z][j] == oo) val = min(oo, val);
                else val = min(((A[i][z]) + (B[z][j])),val);
            }
            C[i][j] = val;
        }       
    }
    return C;
}

vector<vector<ll>> X (110, vector<ll>(110, oo));
void fastpow(){
    for(int i = 0; i <= n; i++) X[i][i] = 0;
    for(int e = (int)log2(k) + 1; e>=0; e--){
        X = fx(X,X);
        if(k & (1LL<<e)) X = fx(X,graph);
    }
}


// graph[i][j] = min(w, graph[i][j]);
// No existe camino si X[i][j] >= oo