//Algorithm or Logic: Recognize Type Edge 
// Recognize Cycles
vector<int> adj[MAXN];
vector<int> vis(MAXN,0); //0 UNVISITED 1 VISITED 2 EXPLORED
vector<int> treeP(MAXN,0);
vector<pair<int,int>> edgeCicle;
void dfs(int p){
    vis[p] = 2;
    for(auto& u: adj[p]){
        if(vis[u] == 0){ // Tree edge
            treeP[u] = p;
            dfs(u);
        }else if(vis[u] == 2){
            if(u != treeP[p]){ //back edge
                //cout << u << " " << p << endl;
                edgeCicle.push_back({u,p});
            }
            //else // two ways <->
        }
        // vis[u] == 1 //edge Forward/Cross
    }
    vis[p] = 1;
}