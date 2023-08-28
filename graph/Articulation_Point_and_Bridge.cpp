// Algorithm or logic: Articulation Point and Bridge
// Complexity: O(N+M)
// Reconocer puntos de articulacion o puentes en un grafo no dirigido 
ll dfs_low[MAXN],dfs_num[MAXN], articulation_vertex[MAXN], treep[MAXN];
int dfsnumCnt = 0; ll countbridge = 0;
void artiANDbridge(ll u){
    dfs_low[u] = dfs_num[u] = dfsnumCnt++;
    for(auto v: adj[u]){
        if(dfs_num[v] == 0){ // unvisited
            treep[v] = u;
            //if(u == dfsRoot) rootChildren++;
            artiANDbridge(v);

            //if(dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = 1;
            if(dfs_low[v] > dfs_num[u]){
                edgelist.push_back({u,v});
                countbridge++;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }else if(v != treep[u]){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}
// En el main
/*  
    for(int i = 1; i<=n; i++){
        if(dfs_num[i] == 0){
            dfsRoot = i; rootChildren = 0; 
            artiANDbridge(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1);
        }
    }
    //Tener cuidado con las mismas  aristas repetidas en los bridge
   
*/
