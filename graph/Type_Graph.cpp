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
