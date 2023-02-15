//Algorithm or logic: k shortest paths with Dijkstra's algorithm
//Complexity: O(km log km)
//Tutorial: https://codeforces.com/blog/entry/102085

int n, m, k;
vector<pair<ll,ll>> adj[MAXN];
vector<ll> dist;
void go(ll ini, ll end){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pending;
    vector<ll> count(n+5, 0);
    count[ini] = 0;
    pending.push({0,ini});
    while(count[end]<k && pending.size()){
        auto [l,u] = pending.top(); pending.pop();
        //cout << l << " " << u << endl;
        if(count[u] == k) continue;
        count[u]+=1;
        if(u == end) dist.push_back(l);
        for(auto v: adj[u]){
            pending.push({(l+v.second), v.first});
        }
    }
}