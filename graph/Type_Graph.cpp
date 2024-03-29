//Algorithm or Logic: Type Graph
//Complexity: O()

void graph(ll n){ // n node , m edges
    //Adjacency matrix O(n^2)
    ll graphM [n][n];

    /*
    Node i with node j with weight w. if (i,j) = 1 Node i-> Node j
    j ->     w
    i    0 0 1
         0 0 1
         1 1 0
    */

   //Adjacency lists O(n)
    vector <ll> graphAdj [n];
    graphAdj[i].push_back(j);
    graphAdj[j].push_back(i);

    vector <pair<ll,ll>> graphAdj [n]; // With weight w
    graphAdj[i].push_back({j,w});
    graphAdj[j].push_back({i,w});


    // List edges O(m)
    vector<ll> graphedg [n];
    
    vector<pair<ll,ll>> edges; 
    edges.push_back({i,j});
    graphedg[i].push_back(edges.size()-1);
    graphedg[j].push_back(edges.size()-1);

    vector<tuple<ll,ll,ll>> edges; // vector<pair<pair<ll,ll>,ll>> edges; // With weight w
    edges.push_back(make_tuple (i, j, w)); // auto e = edges[k] , tie(a, b, w) = e; // edges.push_back({{i,j},w});
    graphedg[i].push_back(edges.size()-1);
    graphedg[j].push_back(edges.size()-1);
}

////////////////////**********************
// Ejemplo de compresion de coordenadas 
    vector<ll> nodes;
    vector<pair<ll, ll>> edges;

    for(int i = 0; i < m; ++i){
        ll u,v; cin >> u >> v;
        nodes.pb(u);
        nodes.pb(v);
        edges.emplace_back(u,v);
    }
    sort(node.begin(), nodes.end());
    nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());

    vector<vector<int>> nwadj(nodes.size());
    for(auto& e: edges){
        int u = lower_bound(nodes.begin(), nodes.end(), e.first) - nodes.begin();
        int v = lower_bound(nodes.begin(), nodes.end(), e.second) - nodes.begin();
        nwadj[u].pb(v); // u -> v
    }


