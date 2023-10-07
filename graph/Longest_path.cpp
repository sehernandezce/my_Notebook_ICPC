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
vector<int> dp(MAXN,-1), vis1(MAXN,0), visn(MAXN,0);
void dfsLP(int u){
    dp[u] = 0;
   //cout << " +NODE+ " << u << endl;
    for(auto& v: adj[u]){
        //cout << "NODE " << u << " -> " << v << endl;
        //if(!vis1[v] || !visn[v]) continue;
        if(dp[v] == -1) {dfsLP(v);}
        if(dp[u] < dp[v] + 1){
            dp[u] = dp[v] + 1;
            //tree[u] = v;
        }
    }
    //cout << " -NODE- " << u << endl;
}


// Longest Path in Directed Graph
for(int i = 0; i < (int)topSort.size(); i++)    
{   
    int u = topSort[i];
    for(auto& v: G[u])
    {
        if(cost[v] < cost[u]+1) cost[v] = cost[u]+1;
    }
}
