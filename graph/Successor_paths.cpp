//Algorithm or logic: Successor paths/ functional graphs
// Complexity: O(Nlogk) queries: log(k)
// Solo funciona en grafos dirigido con outdegree == 1 para todos los nodos
int memo[N][31];
int succ(int x, int i){ // 2^i
    if(i == 0) return memo[x][0];
    int &r = memo[x][i];
    if(r == 0){
        r = succ(succ(x,i-1),i-1);
    }
    return r;
}

// succ(n,30); // log2 (1e9) + 1
/*
        int ans = x;
        for(int i = (int)(log2(k)+1); i>=1; i--){
            if(k & (1 << (i-1))){
                ans = succ(ans,i-1);
            }
        }
*/


// Enconrar ciclos y su tamaño en un grafo dirigido con outdegree == 1
ll cal(int x){
    // Encontrar el ciclo
    int a = succ(x, 0), b = succ(succ(x, 0), 0);
    while(a != b){
        a = succ(a, 0);
        b = succ(succ(b, 0), 0);
    }

    // Encontrar el inicio del ciclo
    a = x;
    while(a != b){
        a = succ(a, 0);
        b = succ(b, 0);
    }
    //Encontrar el tamanio del ciclo
    ll lenght = 1;
    b = succ(a, 0);
    while(a != b){
        b = succ(b, 0);
        lenght++;
    }
    return lenght;
}
