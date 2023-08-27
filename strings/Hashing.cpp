//Algorithm or Logic: Hashing
//Complexity: ?
//From:https://github.com/ahoraSoyPeor/notebook_descomUNAL/blob/master/Strings/Hashing.cpp
//
const int MAXN = 200020;
typedef pair<int, int> mint;
/// 1000234999, 1000567999, 1000111997, 1000777121
const int MODS[] = { 1001864327, 1001265673 };
const mint BASE(256, 256), ZERO(0, 0), ONE(1, 1);
inline int add(int a, int b, const int& mod) { return a+b >= mod ? a+b-mod : a+b; }
inline int sbt(int a, int b, const int& mod) { return a-b < 0 ? a-b+mod : a-b; }
inline int mul(int a, int b, const int& mod) { return 1ll*a*b%mod; }
inline ll operator ! (const mint a) { return (ll(a.first)<<32)|ll(a.second); }
inline mint operator + (const mint a, const mint b) {
  return {add(a.first, b.first, MODS[0]), add(a.second, b.second, MODS[1])};
}
inline mint operator - (const mint a, const mint b) {
  return {sbt(a.first, b.first, MODS[0]), sbt(a.second, b.second, MODS[1])};
}
inline mint operator * (const mint a, const mint b) {
  return {mul(a.first, b.first, MODS[0]), mul(a.second, b.second, MODS[1])};
}
mint base[MAXN];
void prepare() {
  base[0] = ONE;
  for(int i = 1; i < MAXN; i++) base[i] = base[i-1]*BASE;
}
template <class type>
struct hs {
  vector<mint> code;
  hs() {};
  hs(type &t) {
    code.resize(t.size()+1);
    code[0] = ZERO;
    for (int i = 1; i < code.size(); ++i)
      code[i] = code[i-1]*BASE + mint{t[i-1], t[i-1]};
  }
  mint query(int l, int r) {
    return code[r+1] - code[l]*base[r-l+1];
  }
};
//
// prepare();
// hs<vector<int>>(cur);
// or
/*
    prepare();
    string s; cin >> s; // kkholapop
    hs<string> myHs (s);
    cout << myHs.query(0, len(s)-1) << endl;
    mint pp = {750268378, 750867032}; // hola
    cout << (myHs.query(2, 5) == pp) << endl;
*/