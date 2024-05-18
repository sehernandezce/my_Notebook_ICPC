// Dp para reconocer conocer si un substring de l a r es palindromo
for(int i = n-1; i >= 0; i--)
    {
        isPal[i][i] = 1;
        for(int j = i+1; j < n; j++)
        {
            isPal[i][j] = isPal[i+1][max(i+1, j-1)] & (s[i] == s[j]);
        }
    }