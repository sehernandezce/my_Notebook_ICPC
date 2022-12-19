
//Algorithm or Logic: Depth-first search (DFS)
//Complexity: O(n + m)

const ll MAXN= 1e17+10;
vector <ll> graph[MAXN]; //graph[ax].PB(bx), graph[bx].PB(ax);

bool visited [MAXN];
void dfs(ll begin){
    visited[begin] = true;
    for (auto u: graph[begin]){
        if(!visited[u]) dfs(u);
    }
}

// Note
// n is the number of nodes
// It does not compute minimum changes, it makes deep tours

//Longest Path
vector<int> dp(MAXN, -1);
void dfs(int p){
    dp[p] = 0;
    for(auto& u: adj[p]){
        if(dp[u] == -1) dfs(u);
        dp[p] = max(dp[p],dp[u]+1);
    }
} 
