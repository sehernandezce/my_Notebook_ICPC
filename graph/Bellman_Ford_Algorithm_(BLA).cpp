//Algorithm or Logic: Bellman–Ford Algorithm (BLA)
//Complexity: O(n*m)

const ll oo = 1*1e9+10;
const ll MAXN = 1e5+10;
vector<tuple<ll,ll,ll>> edges;

ll dist [MAXN]; 
void bfa(ll begin, ll m){ // m edges
    memset(dist, oo, sizeof dist);

    dist[begin] = 0;
    for (int i = 1; i <= m-1; i++) {
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = min(dist[b], dist[a]+w);
        }
    }
}

// 2
vector<int> tree(MAXN,-1);
vector<ll> dist(MAXN,oo);
void bellman(int p){
    dist[p] = 0;
    tree[p] = 0;
    for(int i = 0; i < n-1; i++){
        for(int node = 1; node <= n; node++){
            for(auto& u: adj[node]){
                if(dist[u.second]>dist[node] + u.first) tree[u.second] = node;
                dist[u.second] = min(dist[u.second], dist[node] + u.first);
            }
        }
    }
}

bool isCycleNeg(){
    //bool hasNegCycle = false;
    for(int node = 1; node<=n; node++){
        for(auto& u: adj[node]){
            if(dist[u.second] > dist[node]+u.first){
                //hasNegCycle = true;
                return 1;
            }
        }
    }
    return 0;
}

// Note
// The code assumes that the graph is stored as an edge list edges (lista de aristas)
// A more advanced variant is the SPFA algorithm (“Shortest Path Faster Algorithm”)
// The Bellman–Ford algorithm can also be used to check if the graph contains a cycle with negative length

//3
vector<int> tree(MAXN,-1);
vector<ll> dist(MAXN,oo);
int bellman(){
    int x;
    for(int i = 1; i <= n; i++){
        x =-1;
        for(auto& e: listEdge){
            int u = e.second.first, v = e.second.second;
            ll w = e.first;
            if(dist[u]+w < dist[v]){
                dist[v] = w+dist[u];
                tree[v] = u;
                x = v;
            }
        }
    }
    return x;
}

/* Obtener el camino de un ciclo Negativo
int is = bellman();
    if(is == -1) cout << "NO" << endl;
    else {
        for(int i = 1; i <= n; ++i)
		{
			is = tree[is];
		}
        vector<int> cycle;
        for(int v = is; ; v = tree[v]){
            cycle.push_back(v);
            if(v == is && cycle.size() > 1) break;
        }
		reverse(cycle.begin(), cycle.end());
        cout << "YES" << endl;
        for(auto& e: cycle){
            cout << e << " ";
        }
        cout << endl;
    }

*/
