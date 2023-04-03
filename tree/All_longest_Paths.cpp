//Algorithm or logic: All longest Paths
//Complexity: O(n)
// Distancia mas larga desde un nodo x

//Distance from x to any node dfs(x,-1)
void dfs(int u, int bef, vector<ll>& dis){
    if(bef != -1) dis[u] = dis[bef] + 1;    
    for(auto& v: adj[u]){
        if(v == bef) continue;
        dfs(v,u, dis);
    } 
}

vector<ll> disa(N, 0);
vector<ll> disb(N, 0);
void allLongestPath(int n){
    vector<ll> dis(n + 10, 0);  
    dfs(1,-1, dis);
    int a = 0;
    ll mxd = 0;
    for(int i = 1; i<= n; i++){
        // cout << i << " " << dis[i] << endl;
        if(mxd < dis[i]){
            a = i;
            mxd = dis[i];
        }
    }    
 
    dfs(a, -1, disa);
    int b = 0;
    ll diam = 0;
    for(int i = 1; i<= n; i++){
        if(diam < disa[i]){
            b = i;
            diam = disa[i];
        }
    }

    dfs(b, -1, disb);
}

// ll ans = max(disa[i], disb[i]);



// Forma 2
// Estudiar !!!
ll dismx[N];
ll dismx2[N];
ll tree[N];

void dfs(ll u, ll p){
    dismx[u] = 0;
    dismx2[u] = 0;
    for(auto& v: adj[u]){
        if(v == p) continue;
        dfs(v, u);
        if(dismx[v] +1 > dismx[u]){
            dismx2[u] = dismx[u];
            dismx[u] = dismx[v] + 1;
            tree[u] = v;
        }
        else if(dismx[v] + 1 > dismx2[u]){
            dismx2[u] = dismx[v] + 1;
        }
    }
}

void dfs2(ll u, ll p){
    for(auto& v: adj[u]){
        if(v == p) continue;
        if(tree[u] == v){
            if(dismx[v] < dismx2[u] + 1){
                dismx2[v] = dismx[v];
                dismx[v] = dismx2[u] + 1;
                tree[v] = u;
            }else{
                dismx2[v] = max(dismx2[v], dismx2[u] + 1);
            }
        }else{
            dismx2[v] = dismx[v];
            dismx[v] = dismx[u] + 1;
            tree[v] = u; 
        }
        dfs2(v, u);
    }
}

// ll ans = dismx[i]