// Algorithm or Logic: Kosaraju’s algorithm
// Complexity: O(n+m)
vector<vector<int>> adjOri(N, vector<int>());
vector<vector<int>> adjInv(N, vector<int>());

vector<int> listNode;
vector<int> vis1(N, 0);
void dfs1(int u, vector<vector<int>>& adj){
    vis1[u] = 1;
    for(auto& v: adj[u]) if(!vis1[v]) dfs1(v, adj);
    listNode.push_back(u); // tiempo de salida
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
    // Permite encontrar el orden topologico de las componentes
    for(int i = 1; i <= n; i++){
        if(!vis1[i]) dfs1(i, adjOri);
    }
    reverse(all(listNode));

    //El nodo con mayor tiempo de salida sera el nodo representante de esa componentes.
    for(auto& i: listNode){
        if(!vis2[i]) {
            numSCCC++;
            dfs2(i, adjInv);
        }
    }

    // Nuevo grafo DAG, formado por la componentes. 
    vector<vector<int>> nwadj(numSCCC+5);
    for(int i = 1; i <= n; i++){
        for(int j: adj[i]){
            if(idc[i] != idc[j]) nwadj[dic[i]].pb(idc[j]);
        }
    }
}

// adjOri[u].pb(v);
// adjInv[v].pb(u);
