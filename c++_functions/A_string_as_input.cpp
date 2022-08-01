// Algorithm or Logic: A string as input
// Complexity:  O()

void s_cin(){
    string line;
    getline(cin, line);
    stringstream sc(line);

    ll x;
    while (sc >> x){
        // process x
    }
}

/*
#include <bits/stdc++.h>

using namespace std;

int main(){
    string line;
    getline(cin, line);
    cout << line << endl;
    replace(line.begin(),line.end(),"."," "); // para remplazar . por espacios.
    stringstream ss(line);

    int x;
    while (ss >> x){ // mientras haya elementos sacar elementos
        cout << x << endl;
    }
    
}
*/