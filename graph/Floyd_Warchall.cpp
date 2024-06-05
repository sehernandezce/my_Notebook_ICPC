//Algorithm or Logic: Floyd Warchall
//Complexity: O(N^3)


ll matrixAdj[MAXN][MAXN];
int n, m;
 
void FloydW(){
    // Previamente fill(matrixAdj,matrixAdj+510,oo);  for(int i = 0; i < 510; i++){matrixAdj[i][i] = 0;}
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){ 
                matrixAdj[i][j] = min(matrixAdj[i][j],matrixAdj[i][k]+matrixAdj[k][j]);
            }
        }
    }
}

// matrixAdj[ax][bx] = min(w,matrixAdj[ax][bx]);
// matrixAdj[bx][ax] = min(w,matrixAdj[ax][bx]);

//
ll matrixAdj[N][N];
int p[N][N];
int n, m;
 
void FloydW(){
    // Previamente fill(matrixAdj,matrixAdj+510,oo);  for(int i = 0; i < 510; i++){matrixAdj[i][i] = 0;}
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){ 
                // matrixAdj[i][j] = min(matrixAdj[i][j],matrixAdj[i][k]+matrixAdj[k][j]);
                if(matrixAdj[i][k]+matrixAdj[k][j] < matrixAdj[i][j]){
                    matrixAdj[i][j] = matrixAdj[i][k]+matrixAdj[k][j];
                    p[i][j] = p[k][j]; 
                }
            }
        }
    }
}

bool FloydWCicleNeg(){
    for(int u = 1; u <= n; u++)
    {
        if(matAdj[u][u] < 0) return true;
    }
    return false;
}

/*
// Previamente 
fill(matrixAdj,matrixAdj+510,oo);  for(int i = 0; i < 510; i++){matrixAdj[i][i] = 0;}
memset(p, -1, sizeof p);

matrixAdj[ax][bx] = min(w,matrixAdj[ax][bx]);
matrixAdj[bx][ax] = min(w,matrixAdj[ax][bx]);
p[ax][bx] = ax;
p[bx][ax] = bx;

//Reconstruir camino de a => b
cout << b << endl;
while(a != b){
    int x = p[a][b];
    cout << x << " ";
    b = x;
}
*/
