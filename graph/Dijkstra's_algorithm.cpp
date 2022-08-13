//Algorithm or Logic: Dijkstra's algorithm
//Complexity: O(n + m log m)

// #1 the best
const ll MAXN=1e17+10;
const ll oo=1e17+10; // ll oo = LLONG_MAX;
vector <pair<ll,ll>> graph[MAXN]; //graph[ax].PB({bx,w}) 

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

/*
 
// #2 More fast less good // se parece mas a Shortest Path Faster Algorithm(SPFA)
#define MAX LLONG_MAX
const ll MAXN=1e17+10;
vector <pair<ll,ll>> graf[MAXN]; // graph[ax].PB({bx,w})

ll dijkstra (ll begin, ll end, ll n,ll x){ // n -> # Nodos; begin to end; x weight extra

    vector <ll> distance(n+1,  MAX);
    queue <ll> pending;

    pending.push(begin);
    distance[begin]=x; // distance[begin]=0;

    while(pending.size()>0){
        ll u = pending.front(),val;
        pending.pop();
        
        for(auto v: graf[u]){           
            val= distance[u] + v.second + x;            
            if(val < distance[v.first]){
               distance[v.first]=val;
               pending.push(v.first);
            }           
        }
    }


    return distance[end] == MAX ? -1 : distance[end];
}
*/
