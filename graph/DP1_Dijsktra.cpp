//Algorithm: DP1 Dijsktra's
//Complexity: 
void dijkstra(ll p){
    vector<ll> dis(N,oo);
    priority_queue<pii, vector<pii>, greater<pii>> pend;
    dis[p] = 0;
    pend.push({0,p});
 
    //DP
    vector<ll> iRoute(N,0);
    vector<ll> mnNode(N,oo);
    vector<ll> mxNode(N,-1);
    iRoute[p] = 1;
    mnNode[p] = 0;
    mxNode[p] = 0;
    //
 
    while(pend.size()){
        auto [acum,u] = pend.top(); pend.pop();
 
        if(acum > dis[u]) continue;
 
        for(auto& node: adj[u]){
            auto [v,w] = node;
            //if(acum > dis[v]) continue;
            
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pend.push({dis[v], v});
 
                mnNode[v] = mnNode[u] + 1;
                mxNode[v] = mxNode[u] + 1;
                iRoute[v] = iRoute[u];
            }
            else if(dis[v] == dis[u] + w){
                iRoute[v] += iRoute[u]; iRoute[v]%=MOD;
                mnNode[v] = min(mnNode[v], mnNode[u] + 1);
                mxNode[v] = max(mxNode[v], mxNode[u] + 1);
            }
        }
 
    }
    cout << dis[n] << " " << iRoute[n] << " " << mnNode[n] << " " << mxNode[n] << endl;
}

/*
what is the minimum price of such a route?
how many minimum-price routes are there? (modulo 109+7)
what is the minimum number of flights in a minimum-price route?
what is the maximum number of flights in a minimum-price route?

*/