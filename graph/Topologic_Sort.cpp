//Algorithm or logic: Topologic Sort Algoritmo de kahn
//Complexity: 
vector<int> topSort(vector<vector<int>>& g, vector<int>& inGrade) {
    int n = (int)inGrade.size();
    int unique = 1;
    vector<int> topSorted;
    queue<int> q;
    for(int i = 1; i <= n; i++) if(inGrade[i] == 0) q.push(i);
    while(q.size()){
        //if(q.size() > 1) unique = 0;
        int node = q.front(); q.pop();
        topSorted.push_back(node);
        for(int y: g[node]) if(--inGrade[y] == 0) q.push(y);
    }

    if((int)topSorted.size() < n) topSorted.clear();
    return topSorted;
}

/*
adj[i].push_back(k); inGrade[k]++;
*/
