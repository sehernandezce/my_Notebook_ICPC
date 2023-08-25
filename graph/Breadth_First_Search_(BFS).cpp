//Algorithm or Logic: Breadth First Search (BFS)
//Complexity: O(m+n)
//Compute shortest paths.

const ll MAXN= 1e17+10;
vector <ll> graph[MAXN]; //graph[ax].PB(bx), graph[bx].PB(ax);
//vector<ll> distance(MAXN);
 
void bfs(ll begin, ll n){
 
    queue<ll> pending;
    vector<ll> distance(n, -1);  

    pending.push(begin); //pending.push(0);
    distance[begin]=0; //  distance[0]=0;
 
    while(pending.size() > 0){
        ll now = pending.front();
        pending.pop();

        for(auto neighbor: graph[now]){
            if(distance[neighbor]==-1){
                distance[neighbor]=distance[now]+1;                
                pending.push(neighbor);                                                    
            }
        }       
    }
}


/* BFS 0-1
vector<int> d(n, INF);
d[s] = 0;
deque<int> q;
q.push_front(s);
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto edge : adj[v]) {
        int u = edge.first;
        int w = edge.second;
        if (d[v] + w < d[u]) {
            d[u] = d[v] + w;
            if (w == 1)
                q.push_back(u);
            else
                q.push_front(u);
        }
    }
}

*/
