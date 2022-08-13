
//Algorithm or Logic: Depth-first search (DFS)
//Complexity: O(n + m)

const ll MAXN= 1e17+10;
vector <ll> graph[MAXN]; //graph[ax].PB(bx), graph[bx].PB(ax);

vector <bool> visited(MAXN,false);
void dfs(ll begin){
    visited[begin] = true;
    for (auto u: graph[begin]){
        if(!visited[begin]) dfs(u);
    }
}

// Note
// n is the number of nodes
// It does not compute minimum changes, it makes deep tours