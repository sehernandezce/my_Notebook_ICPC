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
 
//Algorithm or Logic: Algorithm Krukal 
// Complexity : O(ElogE)
// Para grafos no dirigidos ponderado conexo.
// Calcula el menor numero de peso total de las aristas que se mantenga conexo.
vector<pair<ll,pair<int,int>>> listEdge;
ll kruskal(int n, int m){
    ll mst_cost = 0;
    int num_taken = 0, num_Set = n;
    sort(listEdge.begin(),listEdge.end());
    UnionFind uf(n);
    for(int i = 0; i < m && num_taken < n-1; i++){
        pair<ll, pair<int,int>> front = listEdge[i];
        int a = front.second.first, b = front.second.second;
        ll w = front.first;
        if(!uf.isSameSet(a, b)){
            num_taken++;
            mst_cost += w;
            num_Set--;
            uf.unionSet(a,b);
        }
    }
    return num_Set == 1? mst_cost: -1; //El # de conjuntos disyunto sera 1 si es posible.
}