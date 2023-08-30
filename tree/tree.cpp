//Algorithm or logic: Tree
//Complexity: O(n)

//Distance from x to any node dfs(x,-1)
int dis[N];
void dfs(int u, int bef){
    if(bef != -1) dis[u] = dis[bef] + 1;    
    for(auto& v: adj[u]){
        if(v == bef) continue;
        dfs(v,u);
    } 
}

/// Tree SubTree Queries
int tin[N], tout[N], lenSubT[N];
int t = 0;
void dfs(int u, int p){
    tin[u] = t++;
    lenSubT[u] = 1;
    for(auto& v: adj[u]){
        if(v == p) continue;
        dfs(v, u);
        lenSubT[u] += lenSubT[v];
    }
    tout[u] = t-1;
}

// u -> v // In tree ancestor
bool isAns(int u, int v){ 
    return in[u] <= in[v] && out[u] >= out[v];
}

//Count nodes of Subtree
int cnt[N];
void dfs2(int u, int bef){
    cnt[u] = 1;
    for(auto& v: adj[u]){
        if(v == bef) continue;
        dfs2(v, u);
        cnt[u] += cnt[v];
    }
}

//k-th Ancestors from node x
int memo[N][31];
int anc(int x, int k){
    if(k == 0) return memo[x][k]; 
    int &r = memo[x][k];
    if(r == -1){
        r = anc(anc(x,k-1), k-1);
    }
    return r;
}
/*
memset(memo, -1, sizeof memo);
memo[0][0] = 0;
memo[1][0] = 0;

anc(n,30);
int ans = x;
        for(int i = 30; i >= 0; i--){
            if(k & (1<<i)){
                ans = anc(ans, i);
            }
        }
        if(ans == 0) ans = -1;
*/
