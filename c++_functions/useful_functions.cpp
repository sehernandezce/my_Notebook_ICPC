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

//SET 
	-> Sets are containers that store unique elements following a specific order.
	-> The value of the elements in a set cannot be modified once in the container
	-> find O(log n) 
set<ll> st;
st.inset(a); // ll a;
st.find(a); // ss.find(a)!=ss.end() Exists a
st.size();

// STRING/CHAR
stricmp(&s1[0],&s2[0]); // string s1,s2 compare two strings without taking into account the case

//Vector
vector<ll> vec;
ll a(vector<int> &v, int &val) // refer (&) to a vector
vector<ll> vec(n, k); // Fill the vector with k