//Algorithm or logic: Diameter
//Complexity: O(n)

//With DP
int treeP[N];
int leaf[N];
	//La maxima longitud de una camino desde x a cualquier hoja
void toLeaf(int u, int bef){
    int &r = leaf[u] = 0;
    int mxleaf = 0;
    for(auto& v: adj[u]){
        if(v == bef) continue;
        toLeaf(v,u);
        treeP[v] = u;
        mxleaf = max(mxleaf, leaf[v]);
        r = mxleaf+1;
    }
}

	//La maxima longitud de un camino cuyo highest point es x
int mxLen[N];
void maxLength(int n){
    for(int u = 1; u<= n; u++){
        vector<int> allToLeaf;
        for(auto& v: adj[u]){
            if(treeP[u] == v) continue;
            allToLeaf.pb(-leaf[v]);
        }
        sort(allToLeaf.begin(), allToLeaf.end());
        if((int)allToLeaf.size() == 0) mxLen[u] = 0;
        else if((int)allToLeaf.size() == 1) mxLen[u] = (-1*allToLeaf[0])+1;
        else mxLen[u] = (-1*allToLeaf[0])+(-1*allToLeaf[1])+2;
    }
}

int diam(int n){
    int d = 0;
    for(int i = 1; i <= n; i++){
        // cout << i << " l: " << leaf[i] << " mx: " << mxLen[i] << endl;
        d = max(d, mxLen[i]);
    }
    return d;
}

//With dfs
//Distance from x to any node dfs(x,-1)
int dis[N];
void dfs(int u, int bef){
    if(bef != -1) dis[u] = dis[bef] + 1;    
    for(auto& v: adj[u]){
        if(v == bef) continue;
        dfs(v,u);
    } 
}
