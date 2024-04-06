//Algorithm or Logic: Dijkstra's algorithm
//Complexity: O(n + m log m)

// #1 the best
const ll MAXN=1e17+10;
const ll oo=1e17+10; // ll oo = LLONG_MAX;
vector <pair<ll,ll>> graph[MAXN]; //graph[ax].PB({bx,w}) 

// FALSE !! NO USE
vector <ll> dijkstra (ll begin, ll n){ 

    priority_queue<pair<ll,ll>> pending; // (−d, x) the current distance to node x is d
    vector <bool> processed (n+1,  false);
    vector <ll> distance(n+1,  oo);

    distance[begin]=0;
    pending.push({0,begin});

    while(!pending.empty()){
      ll u = pending.top().second;
      pending.pop();
      if (processed[u]) continue;
      processed[u] = true;

      for (auto v : graph[u]) {
        ll vx = v.first, w = v.second;
        if (distance[u]+w < distance[vx]) {
          distance[vx] = distance[u]+w;
          pending.push({-distance[vx],vx});
        }
      }
    }

return distance;
}

// THIS IS GOD!!
vector<ll> dist(MAXN,oo);
void dijkstra(int p){
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pending;
    // vector <int> processed (n+1,  0);
    dist[p] = 0;
    pending.push({0,p});

    while(pending.size()){
        pair<ll,int> front = pending.top(); pending.pop();
        int node = front.second; ll w = front.first;
        if(w > dist[node]) continue; // processed[u]
        for(auto& u: adj[node]){
            if(dist[node]+u.first < dist[u.second]){
                dist[u.second] = dist[node]+u.first;
                pending.push({dist[u.second],u.second});
            }
        }
    }
}

//longest path
vector<int> tree(MAXN,0);
vector<ll> dist(MAXN,oo);
void dijkstra(int p){
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pending;
    // vector <int> processed (n+1,  0);
    dist[p] = 0;
    pending.push({0,p});

    while(pending.size()){
        pair<ll,int> front = pending.top(); pending.pop();
        int node = front.second; ll w = front.first;
        if(w > dist[node]) continue; // processed[u]
        for(auto& u: adj[node]){
            if(dist[node]+u.first < dist[u.second]){
                tree[u.second] = node;
                dist[u.second] = dist[node]+u.first;
                pending.push({dist[u.second],u.second});
            }
        }
    }
}


// Note
// Finds shortest paths from the starting node to all nodes of the graph
// minimum path with weights of begin (u) to end (v)
// the algorithm requires that there are no negative weight edges in the graph
// Also note that while there may be several instances of a node in the priority queue, only the instance with the minimum distance will be processed.
// More info:
// 2017_Book_GuideToCompetitiveProgramming.pdf pag 91
// https://cp-algorithms.com/graph/dijkstra.html
// https://brilliant.org/wiki/dijkstras-short-path-finder/
// https://rosettacode.org/wiki/Dijkstra%27s_algorithm
