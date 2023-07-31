//Algorithm or Logic: Z_Funtion
//Complexity: O(n)
vector<int> Z_funtion(const string &s){
    int n = (int)s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++){
        z[i] = max(0, min(z[i-l], r-i+1));
        while(i+z[i] < n && s[ z[i] ] == s[ i+z[i] ]){
            l = i, r = i+z[i], ++z[i];
        }
    }
    return z;
}
/*
p#t para string maching, si en el arreglo desde la posicion de t, las posiciones con 
valores seran maching con p

Por ejemplo:
    string s, pattern; cin >> s >> pattern;
    vector<int> z = Z_funtion(pattern+"#"+s);

    int ans = 0;
    for(int i = len(pattern)+1; i < len(z); ++i){
        ans += (z[i] == len(pattern));
    }     
    cout << ans << endl;

En caso que quiera buscar coincidencias en el mismo string 
pp
z[i] < m+1 donde m es el tamaño de p
*/