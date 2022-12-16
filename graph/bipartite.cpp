//Algorithm or Logic: bipartite of graph
// Check if it is bipartite and give the solution

vector<int> adj[MAXN];
vector<int> color(MAXN,-1);
bool bfs(int node){
    queue<int> pending;
    bool is_bipartite = 1;
 
    pending.push(node);
    color[node] = 1;
    while(pending.size()){
        int p = pending.front();
        pending.pop();
        for(auto& u: adj[p]){
            if(color[u] == -1){
                color[u] = 3 - color[p];
                pending.push(u);
            }else if(color[p] == color[u]){
                return is_bipartite = 0;
            }
        }
    }
    return is_bipartite;
}