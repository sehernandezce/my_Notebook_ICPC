//Algorithm or Logic: Longest Common Subsequence
//Complexity: O(n*m)
string lcs(string& text1, string& text2)
{
    int n = (int)text1.size() + 1, m = (int)text2.size() + 1;
    int table[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
            else if (text1[i - 1] == text2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else
            {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    //return table[n - 1][m - 1];
    string s = "";
    int i = n - 1, j = m - 1;
    while(i > 0 && j > 0){
        if(text1[i-1] == text2[j-1]){
            s += text1[i-1];
            i--;
            j--;
        }
        else{
            if(table[i][j-1] > table[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    reverse(s.begin(),s.end());
    return table[n-1][m-1] == 0 ? "No match!": s;
}