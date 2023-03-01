//Algorithm or Logic: ExpoFAST in Matrix
//Complexity:?

vector<vector<ll>> multMat(vector<vector<ll>>& A, vector<vector<ll>>& B, int k){
    vector<vector<ll>> ans(70, vector<ll>(70,0));
    for(int i = 1; i<=k; i++){
        for(int j = 1; j<=k; j++){
            ll &sum = ans[i][j];
            for(int p = 1; p<=k; p++){
                mod(sum, (A[i][p]*B[p][j]), MOD);
            }
        }
    }
    /*
    cout << " === " << endl;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << " === " << endl;
    */
    return ans;
}

void expFastItr(vector<vector<ll>>& A, int k, ll b, vector<vector<ll>>& X){

    //vector<vector<ll>> X(k+1, vector<ll>(k+1,0));
    //for(int i = 1; i <= k; i++) X[k][k] = 1;

    for(int i = (int)log2(b)+1; i >=0; i--){
        X = multMat(X,X,k);
        if(b & (1LL << i)) X = multMat(X,A,k);
    }
    //return x;
}