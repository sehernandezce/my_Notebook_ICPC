//Algorithm or Logic: Prim
// Complexity : O(m log n)

vector<int> taken;
priority_queue<pair<int,int>> pq;
void process(int vtx){
    take[vtx] = 1;
    for(int j = 0; j < (int)adj[vtx].size(); ++j){
        auto[v, w] = adj[vtx][j];
        if(!taken[v]) pq.push(make_pair(-w, -v));
    }
}
void prim(int n){
    taken.assing(n, 0);
    process(1);
    int mst_cost = 0, num_taken = 0;
    while(!pq.empty() && num_taken < n-1){
        auto[u, w] = pq.top(); pq.pop(); u*=-1; v*=-1;
        if(!taken[u]){
            num_taken++;
            mst_cost += w;
            process(u);
        }
    }
}
