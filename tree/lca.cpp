// Algorithm or logic: Lowest common Ancestor
// Complexity: O(nlogn) Query: (log (2*n))
// Tree
int id[N];
int depth[N];
int rec[2*N];
int sz = 0;
void dfs(int u, int bef){
    if(bef == -1) {rec[sz] = u; sz++; depth[u] = 1;}
    for(auto& v: adj[u]){
        if(v == bef) continue;
        rec[sz] = v; sz++;
        depth[v] = depth[u] + 1;
        dfs(v,u);
    }
    if(bef != -1) {rec[sz] = bef; sz++;}
}

// Segment Tree
typedef long long T;
T segTree[8*N];
T neutro = oo;

T mrg(T d1, T d2){
    if(depth[d1] <= depth[d2]) return d1;
    return d2;
}

void update(int p, int l, int r, T newVal, int pos){
    if(l == r){
        segTree[p] = newVal;
        return;
    }
    int mid = l + ((r-l)>>1);
    int lef = (p << 1), rig = (p<<1) + 1;
    if(mid < pos) update(rig,mid+1,r, newVal, pos);
    else update(lef, l, mid, newVal, pos);
    segTree[p] = mrg(segTree[lef], segTree[rig]);
    return;
}

T query(int p, int l, int r, int i, int j){
    if(l >= i && j >= r) return segTree[p];
    if(l > j  || r < i) return neutro;

    int mid = l + ((r-l)>>1);
    int lef = (p << 1), rig = (p<<1) + 1;
    T vlef = query(lef, l, mid, i, j);
    T vrig = query(rig, mid+1, r, i, j);
    
    if(vlef == neutro) return vrig;
    if(vrig == neutro) return vlef;

    return mrg(vlef, vrig);
}
//

// Lowest Common Ancestor
void lca(int rot){
    dfs(rot,-1);
    memset(id, -1, sizeof id);
    for(int i = 0; i < sz; i++){
        if(id[rec[i]] == -1) id[rec[i]] = i;
        update(1, 0, sz-1, rec[i], i);
    }
} // lca(1);

int lcaQuery(int a, int b){
    int i = min(id[a], id[b]), j = max(id[a],id[b]);
    int ancLCA = (int)query(1, 0, sz-1, i, j);
    return ancLCA;
} // cout << lcaQuery(a,b) << endl;


// Distance between node
ll disTree(int a, int b){
    int c = lcaQuery(a,b);
    return depth[a] + depth[b] - 2*depth[c];
}