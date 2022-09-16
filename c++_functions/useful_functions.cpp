// C++ useful functions

//
ll arr[n];
vector<ll> vec;
queue<ll> que;
set<ll> st;
pair<ll,ll> pa;

	//INPUT
// For an interactive problem
cout << "? " << q <<endl;
cout.flush();
//For read double
canf("%d %lf", &score, &c); 
printf("%.10f\n", c);
/*
u unsigned int
d int
f float
c char
s string
lf double
ld long long int
Lf long double
.9 precision 9 decimals	
string s;
scanf("%s", &n[0]);
printf("Hola %s\n", &n[0]);
*/



	// Structure
//SET 
	-> Sets are containers that store unique elements following a specific order.
	-> The value of the elements in a set cannot be modified once in the container
	-> find O(log n) 
	-> set is based on a balanced binary search tree and its operations work in O(log n) time
set<ll> st;
st.inset(a); // ll a;
st.find(a); // ss.find(a)!=ss.end() Exists a
auto s1_Iter = s1.begin( );  ll elem1= *s1_Iter; // get the first element
st.size();
*st.lower_bound(x)
unordered_set <ll> st; // -> unordered_set is based on a hash table and its operations work, on average in O(1) time
multiset <ll> stm;
unordered_multiset <ll> stum

//MAP
	-> Internally, the elements in a map are always sorted by its key
	-> map is based on a balanced binary search tree and accessing elements takes O(log n) time.
	-> unordered_map uses hashing and accessing elements takes O(1) time on average.
map <ll,ll> mp; // map <key,data> mp;
mp[k] = d; // ll k,d;
mp[i].first // key
mp[i].second //data
mp.count("Key") //The function count checks if a key exists in a map

//VECTOR
vector<ll> vec;
ll a(vector<int> &v, int &val) // refer (&) to a vector
vector<ll> vec(n, k); // Fill the vector with k

//ARRAY
void print (ll size, ll prin[])
memset(arr, k, sizeof arr); 
reverse(arr,arr+n); //  int n = sizeof(arr) / sizeof(arr[0]);

//QUEUE
	->  the elements in a C++ priority queue are sorted in decreasing order, and it is possible to find and remove the largest element in the queue.
		
priority_queue<ll> que;
priority_queue<int,vector<int>,greater<int>> que; // If we want to create a priority queue that supports finding and removing the smallest element
queue <ll> que;

	// Variable
	
//INT  ( -2*1e9 <= x <= 2*1e9) (4 bytes)


// Long (4 bytes) long long ( -9*1e18 <= x <= 9*1e18) (8 bytes)
const ll MOD = (1LL << 32) - 1; // For mod32

// FLOAT (4 bytes) Format IEEE 754
 +/- 3.4 e +/- 38 ~7 digits
// DOUBLE (8 bytes)
+/- 1.7e +/- 308 ~15 digits

// STRING/ CHAR (1 bytes)
stricmp(&s1[0],&s2[0]); // string s1,s2 compare two strings without taking into account the case // int cmpS = strcmp(&sax[0],&s2ax[0]); // a b -> cmpS -1 < 0 ; b a -> cmpS 1 > 0
replace(line.begin(),line.end(),x,y); // string line, x, y to replace x with y.
stoi(s1.substr(i)); //for string to int
s1.substr(i) // substring
string s1=to_string(l) // for int to string

	// MATH

sqrt(a,b); // Square root
floor(d); // Funcion piso
log10(x);
log(x); //Ln(x)
log2(x);
ceil(x); //Funcion techo
pow(a, b) //a ^ b = %f\n",
	
	
	
