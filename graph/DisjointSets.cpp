//Algorithm or Logic: UnionFind
// Complexity : O(?)
// Saber si existen ciclos en un grafo no dirigido conexo. O conocer los componentes.
// Para conjuntos disyuntos.
struct UnionFind{
    vector<int> p, rank; // p -> Who is father? // Rank -> La altura del arbol Desde el nodo i
    //vector<int> numSon; // El padre se cuenta asimismo :v
    UnionFind(int N){
        rank.assign(N+5,0); p.assign(N+5,0); //numSon.assign(N+5,1);
        for(int i = 1; i <=N; i++) p[i] = i;
    }
    int findSet(int i) {return (p[i]==i) ? i: (p[i]=findSet(p[i]));}
    bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
    void unionSet(int i, int j){
        if(!isSameSet(i,j)){
            int x = findSet(i), y = findSet(j);
            //int sumSon = numSon[x]+numSon[y]; numComp--;
            if(rank[x] > rank[y]) p[y] = x;
            else{
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
            //numSon[findSet(i)] = sumSon;
        }
        //mxSize = max(mxSize,numSon[findSet(j)]);
    }
};

// Union find Rapido de codear PROBADO
ll link[N], sz[N];
map<pair<ll,ll>, ll> mp;

ll find(ll x){
    while(x != link[x])  x = link[x];
    return x; // link[x] = x; // Para la optimización
}

bool same(ll a, ll b){
    return find(a) == find(b);
}

void unite(ll a, ll b, ll w){
    a = find(a);
    b = find(b);
    if(a == b) return;
    
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
    mp[make_pair(b,a)] = w;
    return;
}
// for(ll i = 1; i<N; i++) link[i] = i;
// for(ll i = 1; i<N; i++) sz[i] = 1;

// Busca el primer padre en comun
ll find2(ll x, ll y){

    set<pair<ll,ll>> stx;
    stx.insert(make_pair(x, 0));
    while(x != link[x]){
        auto w = mp[make_pair(x,link[x])];
        stx.insert(make_pair(link[x], w));
        x = link[x];
    }

    ll ww = 0;
    auto low = stx.lower_bound(make_pair(y, 0));
    if(low != stx.end()){
        auto [node, wx] = *low;
        if(node == y && wx != 0) ww = max(wx, 0LL); 
    }
    while(y != link[y]){
        auto w = mp[make_pair(y,link[y])];
        low = stx.lower_bound(make_pair(link[y], 0));
        if(low != stx.end()){
            auto [node, wx] = *low;
            if(node == link[y] && wx != w) ww = max(wx, w); 
        }
        y = link[y];
    }
    
    if(x != y) return oo;

    return ww;
}

// Union find Oman
int f[N], len[N];
int find(int x){ // log2(n)
    if(x == f[x]) return x;
    return f[x] = find(f[x]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    ig(a == b) return;
    if(len[a] > len[b]) swap(a,b); // En a queda el menor len
    len[b] += len[a];
    f[a]=b;
    return;
}

// Union find Oman, add, size, undo
int f[N], len[N];
stack<int> st;
int find(int x){ // log2(n)
    if(x == f[x]) return x;
    return find(f[x]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){
        st.push(-1);
        return;
    }
    if(len[a] > len[b]) swap(a,b); // En a queda el menor len
    len[b] += len[a];
    f[a]=b;
    st.push(a);
    return;
}
void undo(){
    int u = st.top(); st.pop();
    if(a != -1){
        int b = f[a];
        f[a] = a;
        len[b] -= len[a];
    }
    return;
}
