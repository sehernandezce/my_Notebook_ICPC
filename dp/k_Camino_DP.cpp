// En un arreglo el menor costo del k-camino
// Viaje optimo en matriz y reconstruccion

1 7 9 2
8 6 3 2
1 6 7 8
2 9 8 2


int val[N][N];
int n,m;

int dp[N][N];
int f(int i, int j){
    if(i==n-1 && j==m-1){
        return val[i][j];
    }
    int &r = dp[i][j];
    if(r==-1){
        r = INT_MAX;
        if(i+1 <n){
            r = min(r,f(i+1,j))+val[i][j];
        }
        if(j+1 <m){
            r = min(r,f(i,j+1))+val[i][j];
        }
    }
    return r;
}

int dp2[N][N];
int g(int i, int j){
    if(i==n-1 && j==m-1){
        return 1;
    }
    int &r = dp[i][j];
    int &z = dp2[i][j];
    if(z==-1){
        z = 0;
        if(i+1 <n && r == f(i+1, j) + val[i][j]){
            z+= dp2[i+1][j];
        }
        if(j+1 <m && r == f(i, j+1) + val[i][j]){
            z+= dp2[i][j+1];
        }
    }
    return z;
}

string ans;
void build(int i, int j, int k){
    if(i==n-1 && j==m-1){
        return;
    }

    if(i+1<n && k<=g(i+1,j)){
        ans.push_back('A');
        build(i+1,j,k);
        return;
    }
    k -= g(i+1,j);
    if(j+1<m && k<=g(i,j+1)){
        ans.push_back('D');
        build(i,j+1,k);
        return;
    }
    assert(false);
}


// Iterativa
int dp3[2][N];
void dpitr()
{   
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int &r = dp3[i&1][j];
            if (i == n - 1 && j == m + 1)
            {
                r = val[i][j];
                continue;
            }
            r = INT_MAX;
            if (i + 1 < n)
            {
                r = min(r, dp3[(i + 1)&1][j]) + val[i][j];
            }
            if (j + 1 < m)
            {
                r = min(r, dp3[i][j+1]) + val[i][j];
            }
        }
    }
}
