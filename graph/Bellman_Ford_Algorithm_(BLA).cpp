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

// Note
// The code assumes that the graph is stored as an edge list edges (lista de aristas)
// A more advanced variant is the SPFA algorithm (“Shortest Path Faster Algorithm”)
// The Bellman–Ford algorithm can also be used to check if the graph contains a cycle with negative length

/*
    edges.push_back(make_tuple (i, j, w));
    graph[i].push_back(edges.size()-1);
    graph[j].push_back(edges.size()-1);
*/
/*
// Check

    // ? what type graph? 
    ll bfa(ll edg, ll m){
            if(m == 0) {
                if( edg == 0) return 0;
                else return oo;
            }
        }

        ll result = bfa(edg, m-1);

        for(auto neighbour: edges[edg]){
            ll now = neighbour.second + bfa(neighbour.first, m-1);
            result = min(result, now);
        }
        return result;
    }
*/