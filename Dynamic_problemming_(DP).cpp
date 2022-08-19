//Algorithm or Logic: Dynamic problemming (DP)
//Complexity: O(?)
// Memoization: which means that we store each function value in an array directly after calculating it

// Example
/*
Problem we are given a set of coin values and our
task is to construct a sum of money using as few coins as possible.
*/
const ll MAXN = 1e5+10;

// Saving states with DP O(nk) k -> the number of coins n -> the taget sum
// Recursive functions
ll coins[MAXN];
ll dpValue[MAXN];
bool dpready[MAXN];
ll godp(ll value){
    if (value < 0) return oo;
    if(value == 0) return 0;
    ll best = oo; 
    for(auto c: coins){
        best = min (best, godp(value - c) + 1);
    }
    dpready[value] = true;
    dpValue[value] = best;
    return best;
}
// Iteratively
ll coins[MAXN];
ll dpValue[MAXN];
void godp(ll n){
    dpValue[0] = 0;
    foran(x,1,n+1){
        dpValue[x] = oo;
        for (auto c : coins) {
            if (x-c >= 0) {
            dpValue[x] = min(dpValue[x], dpValue[x-c]+1);
            }
        }
    }
}

// Is not efficient
ll coins[MAXN];
ll godp(ll value){
    if (value < 0) return oo;
    if(value == 0) return 0;
    ll best = oo; 
    for(auto c: coins){
        best = min (best, godp(value - c) + 1);
    }
    return best;
}

// Example 2
/*
Let us now consider another variant of the coin problem where our task is to calculate the total number of ways to produce a sum x using the coins
*/
ll coun[MAXN];
ll m = 1e9 + 7;
void dp(ll n){
    coun[0] = 1;
    foran(x, 1, n+1) {
        for (auto c : coins) {
            if (x-c >= 0) {
            coun[x] %= m; 
            coun[x] += coun[x-c];
            }
        }
    }
}

// Nota
/*
Busca guardar el resultado de ese subproblema y reutilizarlo varias veces para 
evitar calculos innecesarios.
*/