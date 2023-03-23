//Algorithm or logic: Contar el numero de caminos de i a j con exactamente k vertices
//Complexity: 

vector<vector<ll>> graph (110, vector<ll>(110, 0));
int n,m,k;

vector<vector<ll>> mul(vector<vector<ll>>& A, vector<vector<ll>>& B){
    vector<vector<ll>> C (110, vector<ll>(110, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int z = 1; z <= n; z++){
                C[i][j] += ((A[i][z]%MOD)*(B[z][j]%MOD)%MOD);
                C[i][j] %= MOD;
            }
        }        
    }
    return C;
}

vector<vector<ll>> X (110, vector<ll>(110, 0));
void fastpow(){
    for(int i = 0; i <= n; i++) X[i][i] = 1;
    for(int e = (int)log2(k) + 1; e>=0; e--){
        X = mul(X,X);
        if(k & (1LL<<e)) X = mul(graph,X);
    }
}

//graph[i][j] += 1;