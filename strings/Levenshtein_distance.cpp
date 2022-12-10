//Algorithm or Logic: Levenshtein distance or Edit distance
//Complexity: O(n*m)
int editDist (string& s1, string &s2){
int n = 1 + (int)s1.size(), m = 1 + (int)s2.size(); 
    int dp[n][m];
    for(int i = 0; i < m; i++){dp[0][i] = i;}
    for(int i = 0; i < n; i++){dp[i][0] = i;}
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            int is = 1;
            if(s1[i-1] == s2[j-1]) is = 0;
            dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1] + 1, dp[i-1][j-1] + is});
        }
    }
    //for(int i = 0; i < n; i++){
    //    for(int j = 0; j < m; j++){
    //        cout << dp[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    return dp[n-1][m-1];
}