//Sebastian "Seishi" GG
/*
TRIE
REVISAR!
*/

int trie[N][26];
bool finish[N];
int cnt[N];
int node = 1;

void add(string& s, int val){
    int cur = 0;
    for(char c: s){
        int v = c - 'a';
        if(trie[cur][v] == 0){ // Si no existe la conexion
            trie[cur][v] = nodes;
            nodes++;
        }
        cur = trie[cur][v];
        cnt[cur] += val;
    }
    if(val == 1) end[cur] = 1;
    else end[cur] = 0;
}

bool find(string& s, int val){ 
    int cur = 0;
    for(char c: s){
        int v = c - 'a';
        if(trie[cur][v] == 0){ // Si no existe la conexion
            return false;
        }
        cur = trie[cur][v];
        if(cnt[cur] == 0) return false;
    }
    if(end[cur]) return true;
    else return false;
}


/// Con struct
#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

typedef long long ll;

const int MAXN = 1000010;
ll oo = (1LL << 62) - 1LL;

const int TRIE_LEN = 40005, LEN_ABC = 26;
struct Trie{
    int idNode = 0, trie[TRIE_LEN][LEN_ABC], end_word[TRIE_LEN];

    void insert (string& str){
        int cur = 0, len = str.length();
        for(int i = 0; i < len; i++){
            int c = str[i] - 'a';
            if(!trie[cur][c]) trie[cur][c] = ++idNode;
            cur = trie[cur][c];
            if(i + 1 == len) end_word[cur]++;
        }
    }
    
    bool serch(string& word){
        int cur = 0, len = word.length(); 
        for(int i = 0; i < len; i++){
            int c = word[i] - 'a';
            if(!trie[cur][c]) {
                return false; 
            }
            cur = trie[cur][c];
        }
        return end_word[cur];
    }

    bool serchPref(string& word){
        int cur = 0, len = word.length(); 
        for(int i = 0; i < len; i++){
            int c = word[i] - 'a';
            if(!trie[cur][c]) {
                return false; 
            }
            cur = trie[cur][c];
        }
        return true;
    }
};




int main(){
    IO;
    Trie myTrie;
    string s = "abc";
    myTrie.insert(s);
    s = "abc" ,myTrie.insert(s);
    s = "adc" ,myTrie.insert(s);
    s = "xzy" ,myTrie.insert(s);

    s = "adc";
    cout << myTrie.serch(s) << endl;
    cout << myTrie.serchPref(s) << endl;

    return 0;
}

/// Revisar!!!
//
struct trie
{
    bool end;
    map<char,trie> son;
    trie () { end = false;}

    void insert(string &s){
        Trie *t = this;
        for(auto& c: s){
            t = &t->son[c];
        }
        t->end = true;
    }

    bool search(string &s){
        Trie *t = this;
        for(auto& c: s){
            if(t->son.find(c) != t->son.end()) t = &t->son[c];
            else return false;
        }
        return t->end;
    }
};
//
