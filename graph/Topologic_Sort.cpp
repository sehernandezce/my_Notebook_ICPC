//Algorithm or logic: Topologic Sort Algoritmo de kahn
//Complexity: 
vector<int> topSort(vector<vector<int>>& g, vector<int>& inGrade) {
    int n = (int)inGrade.size();
    int unique = 1;
    vector<int> topSorted;
    queue<int> q;
    for(int i = 1; i <= n; i++) if(inGrade[i] == 0) q.push(i);
    while(q.size()){
        //if(q.size() > 1) unique = 0;
        int node = q.front(); q.pop();
        topSorted.push_back(node);
        for(int y: g[node]) if(--inGrade[y] == 0) q.push(y);
    }

    if((int)topSorted.size() < n) topSorted.clear();
    return topSorted;
}

/*
adj[i].push_back(k); inGrade[k]++;
*/

// Todos los ordenes topologicos
void findAllTopoOrders(vector<vector<int>>& g, vector<int>& inGrade ,vector<int>& path, vector<bool>& discovered, int n){
    for(int v = 0; v < n; v++){
        if(inGrade[v] == 0 && !discovered[v]){
            for(auto u: g[v]){
                inGrade[u]--;
            }
            path.push_back(v);
            discovered[v] = true;

            findAllTopoOrders(g, inGrade, path, discovered, n);
            for(auto u: g[v]){
                inGrade[u]++;
            }

            path.pop_back();
            discovered[v] = false;
        }
    }

    if(path.size() == n){
        // Nuevo orden topologico
    }
}

void goAllTopoOrders(vector<vector<int>>& g, vector<int>& inGrade, int n){
    vector<bool> discovered(n);

    vector<int> path;
    findAllTopoOrders(g, inGrade, path, discovered, n);
}


// Con dfs

int vis[N];
vector<int> ans;

bool dfs(int u)
{   
    if(vis[u] == 1) return 0;

    vis[u] = 2;
    int r = 0;
    for(auto v: adj[u])
    {
        if(vis[v] == 0) r |= dfs(v);
        else if(vis[v] == 2) r = 1;
    }
    ans.push_back(u);
    vis[u] = 1;
    return r;
}

    bool chk = 0; // Si es 1 no existe orden topologico
    for(int i = 1; i <= n; i++)
    {
        chk |= dfs(i);
    }
