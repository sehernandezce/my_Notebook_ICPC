// Algorithm or logic:Longest path for undirected acyclic graph
// Complexity: O(N+M)
// Aplicamos bfs a cualquier nodo v y luego buscamos el nodo mas alejado w
// Aplicamos bfs de nuevo a w y el nodo mas alejado x
// La distancia mas larga sera la distancia entre w y x
ll bfs(ll ini,int n, ll &dist){
    queue<ll> pending;
    vector<ll> distance(n+5,-1);    
    distance[ini] = 0;
    pending.push(ini);

    while(pending.size()){
        ll u = pending.front(); pending.pop();
        for(auto& v: tree[u]){
            if(distance[v] == -1){
                distance[v] = distance[u] +1;
                pending.push(v);
            }
        }
    }

    ll ans = 0, mx = 0;
    for(int i = 1; i <= n; i++){
        if(mx < distance[i]) {ans = i; mx = distance[i];}
    }
    dist = mx;
    return ans;
}


//Longest Path for DAG
vector<int> dp(MAXN, -1);
void dfs(int p){
    dp[p] = 0;
    for(auto& u: adj[p]){
        if(dp[u] == -1) dfs(u);
        dp[p] = max(dp[p],dp[u]+1);
    }
} 