//Algorithm or logic: PrefixSum 2D
//Complexity: O(N*M)

//ll pref2D[1005][1005]; ll val[1005][1005];
vector<vector<ll>> pref2D(1005, vector<ll>(1005));
vector<vector<ll>> val(1005, vector<ll>(1005));
for(int i =0; i<=1000; i++){for(int j =0; j<=1000; j++){ pref2D[i][j] = 0; val[i][j] = 0;}}
	for(int i = 0; i<n; i++){
            ll h,w; cin >> h >> w;
            val[h][w] += h*w;
        }
        for(int i = 1; i<=1000; i++){
            for(int j = 1; j<=1000; j++){ 
                pref2D[i][j] = val[i][j] + pref2D[i-1][j] + pref2D[i][j-1] - pref2D[i-1][j-1];
            }
       }
        
// ll hs,ws,hb,wb; cin >> hs >> ws >> hb >> wb;
// ll ans = pref2D[hb][wb] - pref2D[hs-1][wb] - pref2D[hb][ws-1] + pref2D[hs-1][ws-1];
