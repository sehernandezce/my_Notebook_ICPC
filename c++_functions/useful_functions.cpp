// C++ useful functions

//
ll arr[n];
vector<ll> vec;
queue<ll> que;
set<ll> st;

pair<ll,ll> pa;

//
vector<ll> vec(n, k); // Fill the vector with k
memset(arr, k, sizeof arr); // Fill the array with k

	// Structure
//SET 
	-> Sets are containers that store unique elements following a specific order.
	-> The value of the elements in a set cannot be modified once in the container
	-> find O(log n) 
set<ll> st;
st.inset(a); // ll a;
st.find(a); // ss.find(a)!=ss.end() Exists a
auto s1_Iter = s1.begin( );  ll elem1= *s1_Iter; // get the first element
st.size();

//MAP
	-> Internally, the elements in a map are always sorted by its key
map <ll,ll> mp; // map <key,data> mp;
mp[k] = d; // ll k,d;
mp[i].first // key
mp[i].second //data

//VECTOR
vector<ll> vec;
ll a(vector<int> &v, int &val) // refer (&) to a vector
vector<ll> vec(n, k); // Fill the vector with k

//ARRAY
void print (ll size, ll prin[])
memset(arr, k, sizeof arr); 

	// Variable
	
//INT  ( 2*1e-9 <= x <= 2*1e9) (4 bytes)
// Long (4 bytes) long long ( 9*1e-18 <= x <= 9*1e18) (8 bytes)
// STRING/ CHAR (1 bytes)
stricmp(&s1[0],&s2[0]); // string s1,s2 compare two strings without taking into account the case
