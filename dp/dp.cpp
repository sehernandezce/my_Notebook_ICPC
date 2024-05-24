//1) Max 1D Range Sum 
//Algorithm or Logic: Kadane’s algorithm 
//Complexity: O(n)
int A[N];
void f1(int n){
    int best = -oo, sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = max(sum + A[i], A[i]);
        best = max(best, sum);
        // if(sum < 0) sum = 0;
    }
}
// find the maximum Range Sum Query (RSQ) between two indices i and j in [0..n-1], that is: A[i] + A[i+1] + +...+ A[j]


//2) Max 2D Range Sum 
//Algorithm or Logic: 
//Complexity: O(n^3)
int A[N][N], pref[N][N];
void f2(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {   
            if(j > 0) pref[i][j] = pref[i][j-1] + A[i][j];
            else pref[i][j] = A[i][j];
        }
    }
    int best = -oo;
    for(int l = 0; l < n; l++)
    {
        for(int r = l; r < n; r++)
        {
            int subSum = 0;
            for(int row = 0; row < n; row++)
            {
                if(l > 0) subSum = max(subSum + (pref[row][r] - pref[row][l-1]), pref[row][r] - pref[row][l-1]);
                else subSum = max(subSum + (pref[row][r]), pref[row][r]);
                // if(subSum < 0) subSum = 0;
                best = max(best, subSum); 
            }
        }
    }
}
//Given a 2-dimensional array of positive and negative integers, find the sub-rectangle with the largest sum.

//3) Longest Increasing Subsequence (LIS)
//Algorithm or Logic: LIS 
//Complexity: O(nlog K) Greedy + Divide and Conquer Algorithm 
// Where k is the length of the LIS

int p[N], A[N];
vector<int> L(N), L_id(N);
void print_lis(int i)
{   
    int ele = A[i];
    if(p[i] == -1) 
    {
        cout << ele << " ";
        return;
    }
    print_lis(p[i]);
    cout << ele << " ";
}
int lis(int n)
{
    int k = 0, lis_end = 0;
    for(int i = 0; i < n; i++) L[i] = L_id[i] = 0;
    for(int i = 0; i < n; i++) p[i] = -1;

    for(int i = 0; i < n; i++)
    {   
        int ele = A[i];
        int pos = lower_bound(L.begin(), L.begin()+k, ele) - L.begin();
        L[pos] = ele; 
        L_id[pos] = i;
        p[i] = (pos ? L_id[pos-1]: -1);
        if(pos == k)
        {
            k = pos+1;
            lis_end = i;
        }
    }
    // cout << k << '\n';
    // if(k > 0) {print_lis(lis_end); cout << '\n';}
    return k;
}

// Given a sequence {A[0], A[1],..., A[n-1]}, determine its Longest Increasing Subsequence (LIS)
// longest common subsequence in two Permutation of equal lenght both
// longest common increasing  subsequence.
/*
longest common subsequence in two Permutation of equal lenght both
Forma de relacionar dos permutaciones
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
        indA[A[i]] = i;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> B[i];
        AB[i] = indA[B[i]];
        // indB[B[i]] = i;
    }
Operamos con AB
*/
/*
There are other variants of this problem, e.g., the Longest Decreasing Subsequence and Longest Non
Increasing/Decreasing Subsequence. The increasing subsequences can be modeled as a Directed Acyclic
Graph (DAG) and finding the LIS is equivalent to finding the Longest Paths in the DAG
*/

//Algorithm or Logic: longest Increasing subsequence (LIS)
// Complexity: O(n^2)
int memo[N];
int lis(int i)
{
    if(i == 0) return 1;
    if(memo[i] != -1) return memo[i];
    int &r = memo[i];
    r = 1;
    for(int j = 0; j < i; j++)
    {
        if(A[j] < A[i]) 
        {
            r = max(r, lis(j) + 1);
        }
    }
    return r;
}
// memset(memo, -1, sizeof memo); lis(n-1);

//4)longest common subsequence (LCS)
//Algorithm or Logic: longest common subsequence (LCS)
// Complexity: O(n^2)
string lcs(string &s1, string &s2){
    int n = (int)s1.size() + 1, m = (int)s2.size() + 1; 
    int grid[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || j == 0) grid[i][j] = 0;
            else{
                if(s1[i-1] == s2[j-1]) grid[i][j] = grid[i-1][j-1] + 1;
                else grid[i][j] = max(grid[i][j-1], grid[i-1][j]);
            }
            //cout << grid[i][j] << " ";
        }
        //cout << endl;
    }
    string ans = "";
    int i = n-1, j = m-1;
    while(j > 0 && i > 0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
        }else{
            if(grid[i-1][j] > grid[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
// Con este algoritmo se puede reconstruir la respuesta


//5)0-1 Knapsack (Subset-Sum)
//Algorithm or Logic: 
//Complexity: O(nS)
int dp(int id, int remW)
{
    if((id == n) || (remW == 0)) return 0;
    int &ans = memo[id][remW];
    if(ans != -1) return ans;
    if(W[id] > remW) return ans = dp(id+1, remW);
    return ans = max(dp(id+1, remW), V[id]+dp(id+1,remW+W[id]));
}
/*
Given n items, each with its own value Vi and weight Wi, 8i 2 [0..n-1], and a
maximum knapsack size S
This is also known as the NP-complete Subset-Sum problem with a similar problem description: Given
a set of integers and an integer S, is there a (non-empty) subset that has a sum equal to S? 

En los problemas que se busca el valor y el peso es muy grande. Buscar la dp  que de el menor peso para un valor dado. Comprobar todos los valores y tomar el mejor.
*/

//6) Coin-Change (CC) - The General Version
//Algorithm or Logic: 
//Complexity: O(nV)
int dp(int type, int value) {
    if (value == 0) return 1; // one way, use nothing
    if ((value < 0) || (type == N)) return 0; // invalid or done
    int &ans = memo[type][value];
    if (ans != -1) return ans; // was computed before
    return ans = dp(type+1, value) + // ignore this type
    dp(type, value-coinValue[type]); // one more of this type
}

//6) Traveling-Salesman-Problem (TSP)
//Algorithm or Logic: Halmiton's Path  // Bitmask Dynamic Programming
//Complexity: O((n^2)*2^(n-1))
#define LSOne(x) ((x) & -(x)) //To get the value of the least significant bit of S that is on (first from the right)

int dist[21][21];
int n;

ll memo[21][(1<<(19))];
ll dp(int u, int mask)
{
    // if(mask == 0) return g[u][n-1];
    if(mask == 0) return dist[u][0];
    ll &r = memo[u][mask];
    if(r != -1) return r;
    // r = 0;
    r = oo;
    int m = mask;
    while(m > 0)
    {
        int two_pow_v = LSOne(m);
        int v = __builtin_ctz(two_pow_v)+1;
        m -= two_pow_v;
        r = min(r, dist[u][v] + dp(v, mask^two_pow_v));
        // if(g[u][v] > 0)
        // {
        //     r+=(dp(v, mask^two_pow_v)*g[u][v])%MOD;
        //     r%= MOD;
        // }
    }
    return r;
}
/*
Given n cities  and their pairwise distances in the form of a symmetric
matrix dist of size n ⇥ n, compute the minimum cost of making a tour44 that starts from
any city s, goes through all the other n  1 cities exactly once, and finally returns to the
starting city s

Tour: Such a tour is called a Hamiltonian tour, which is a cycle in an undirected graph which visits each vertex
exactly once and also returns to the starting vertex. Later in Book 2, we will learn that TSP is an NP-hard
optimization problem
*/

//7) UVa 10943 - How do you add? (Combinatory)
//Algorithm or Logic: 
//Complexity: O((n^2)*k)

ll dp(int a, int c)
{
    if(c == 1) return 1;
    ll &r = memo[a][c];
    if(r!=-1) return r;
    r = 0;
    for(int x = 0; x <= n; x++) 
    {
        if(a-x >= 0)
        {
            r += dp(a-x, c-1);
            r%=MOD;
        }
    }
    return r;
}

//8) UVa 10003 - Cutting Sticks (Cutting)
//Algorithm or Logic: Range Dp
//Complexity: O((n^3))

int cut[110];
ll memo[110][110];

ll dp(int lef, int rig)
{
    if(lef+1 == rig) return 0;
    ll &r = memo[lef][rig];
    if(r != -1) return r;
    r = oo;
    for(int i = lef+1; i < rig; i++)
    {
        r = min(r, dp(lef, i) + dp(i,rig) + (cut[rig] - cut[lef]));
    }
    return r;
}

/*
cut[0] = 0;
for(int i = 1; i <= n; i++) cin >> cut[i];
cut[n+1] = l;
ll ans = dp(0, n+1);
*/

//9) Knuth's Optimization - UVa 10003 - Cutting Sticks (Cutting)
//Algorithm or Logic: Range Dp with Knuth's Optimization
//Complexity: 
// optimize the time complexity O(n^3) => O(n^2)
// https://cp-algorithms.com/dynamic_programming/knuth-optimization.html

int l, n, A[55], memo[55][55];
int opt[55][55];

int cut(int left, int right) {
  if (left+1 >= right) {
    opt[left][right] = right;
    return 0;
  }
  int &ans = memo[left][right];
  if (ans != -1) return ans;
  ans = 2e9;
  cut(left,right-1);
  cut(left+1,right);
  for (int i = opt[left][right-1]; i <= opt[left+1][right]; ++i) {
    int value = cut(left, i) + cut(i, right) + (A[right]-A[left]);
    if ( value < ans ) {
      ans = value;
      opt[left][right] = i;
    }
  }
  return ans;
}

//10) Longest Path in a Directed Acyclic Graph (DAG)
//Algorithm or Logic: DP in DAG
//Complexity: O(n+m)
vector<int> adj[MAXN];
vector<int> dp(MAXN, -1);
void dfs(int p){
    dp[p] = 0;
    for(auto& u: adj[p]){
        if(dp[u] == -1) dfs(u);
        dp[p] = max(dp[p],dp[u]+1);
    }
} 


/*
Digit Dynamic Programming
Longest Palindromic Subsequence
k-enesimo possible paths from top left to bottom right corner of a matrix
Reconstruir la respuesta
Dynamic Programming on Trees
Counting Tilings
Optmización en Memoria - OK (Pendiente leer libro CP4)
*/

