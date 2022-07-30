//Algorithm or Logic: Breadth First Search (BFS)
//Complexity: O(m+n)
//Compute shortest paths.

const ll MAXN= 1e17+10;
vector <ll> graph[MAXN];
//vector<ll> distance(MAXN);
 
void bfs(ll n,ll p){
 
    queue<ll> pending;
    vector<ll> distance(n, -1);  

    pending.push(p); //pending.push(0);
    distance[p]=0; //  distance[0]=0;
 
    while(pending.size() > 0){
        ll now = pending.front();
        pending.pop();

        for(ll neighbor: graph[now]){
            if(distance[neighbor]==-1){
                distance[neighbor]=distance[now]+1;                
                pending.push(neighbor);                                                    
            }
        }       
    }
}
