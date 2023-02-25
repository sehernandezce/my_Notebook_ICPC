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