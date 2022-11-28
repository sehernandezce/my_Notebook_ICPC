//Algorithm or Logic: Tarjan's Strongly Connected Component (SCC)
//Complexity: O(m + n)

const int MAXN = 10010;
vector<int> adj[MAXN];
set <int> scc;
stack <int> stk;
int ids[MAXN], low[MAXN], onStack[MAXN];
int id = 0, numSCCCount = 0;

void dfs(int at){
    stk.push(at); 
    onStack[at] = 1;
    ids[at] = low[at] = id++; // Se asigna id de componente
    for(auto to: adj[at]){
        if(ids[to] == -1) dfs(to);
        if(onStack[to]) low[at] = min(low[at], low[to]); // Se toma el menor id componente entre el padre y el hijo o vecino.
    }
    /* Si ya se recorrio todo desde ese punto y el menor id componente
    es el mismo id del node entonces revise la pila haber si exite un
    id componente menor que el propio.
    La pila permite colocar los nodos que estan en la misma componente, 
    estos seran todo los nodos que estan por encima de at, en ese momento.
    */
    scc.insert(low[at]);
    if(ids[at] == low[at]){ 
        while(stk.size()){
            int node = stk.top();
            stk.pop(); onStack[node] = false;
            low[node] = ids[at];
            if(node == at) break;
        }
        numSCCCount++; 
    }
}

void tarjan(int n){
    memset(ids,-1, sizeof ids);
    for(int i = 1; i <= n; i++){
        if(ids[i] == -1) dfs(i);
    }
}

