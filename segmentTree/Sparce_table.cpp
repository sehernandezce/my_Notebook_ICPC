// Algorithm or logic: Sparce table, Revisar!
//Complexity: O(NM)
// Para RMQ(i,j)
void st_init(int M[MAXN][LOGMAXN], int A[MAXN], int N){
    int i, j;
    //initialize M for the intervals with length 1
    for(i = 0; i<N i++) M[i][0] = 1;
    //compute values from smaller to bigger intervals

    for(j = 1; 1<< j <= N; j++){
        for(i=0; i + (1<<j)-1 < N; i++){
            if(A[M[i][j - 1]] < A[M[i+ (1 << (j-1))][j-1]]){
                M[i][j] = M[i][j-1];
            }else{
                M[i][j] = M[i+ (1 << (j-1))][j-1];
            }
        }
    }
}
//Falta la consulta