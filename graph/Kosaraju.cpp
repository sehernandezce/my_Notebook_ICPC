// Algorithm or Logic: Kosaraju’s algorithm
// Complexity: O(n+m)
vector<vector<int>> adjOri(N, vector<int>());
vector<vector<int>> adjInv(N, vector<int>());

vector<int> listNode;
vector<int> vis1(N, 0);
void dfs1(int u, vector<vector<int>>& adj){
    vis1[u] = 1;
    for(auto& v: adj[u]) if(!vis1[v]) dfs1(v, adj);
    listNode.push_back(u);
}

int numSCCC = 0;
vector<int> vis2(N, 0);
vector<int> idc(N, -1);
void dfs2(int u, vector<vector<int>>& adj){
    vis2[u] = 1;
    idc[u] = numSCCC;
    for(auto& v: adj[u]) if(!vis2[v]) dfs2(v, adj);
}

vector<int> vis(N, 0);
void dfs(int u, vector<vector<int>>& adj){
    vis[u] = 1;
    for(auto& v: adj[u]) if(!vis[v]) dfs(v, adj);
}

void kosaraju(int n){
    for(int i = 1; i <= n; i++){
        if(!vis1[i]) dfs1(i, adjOri);
    }
    
    reverse(all(listNode));
    for(auto& i: listNode){
        if(!vis2[i]) {
            numSCCC++;
            dfs2(i, adjInv);
        }
    }
}

// adjOri[u].pb(v);
// adjInv[v].pb(u);