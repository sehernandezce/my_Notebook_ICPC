//Algorithm or logic: Topologic Sort Revisar!
//Complexity: 
vector<int> topSort(vector<vector<int> g, vector<int> inGrade) {
    int n = inGrade.size();
    vector<int> topSorted;
    queue<int> q;
    for(int i = 0; i < n; i++) if(inGrade[i] == 0) q.push(i);
    while(q.size()){
        int node = q.front(); q.pop();
        topSorted.push_back(node);
        for(int y: g[node]) if(--inGrade[y] == 0) q.push(y);
    }

    if(topSorted.size() < n) topSorted.clear();
    return topSorted;
}