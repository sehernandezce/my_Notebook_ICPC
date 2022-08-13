//Algorithm or Logic: Breadth First Search (BFS)
//Complexity: O(m+n)
//Compute shortest paths.

const ll MAXN= 1e17+10;
vector <ll> graph[MAXN]; //graph[ax].PB(bx), graph[bx].PB(ax);
//vector<ll> distance(MAXN);
 
void bfs(ll begin, ll n){
 
    queue<ll> pending;
    vector<ll> distance(n, -1);  

    pending.push(begin); //pending.push(0);
    distance[begin]=0; //  distance[0]=0;
 
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
