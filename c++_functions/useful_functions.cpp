// C++ useful functions
//g++ -o main main.cpp -Wall -Wextra -Wshadow
//./main input.txt output.txt
//In linux
//./main <input.txt> output.txt
//diff output.txt isoutput.txt
//diff -y --suppress-common-lines -b output.txt isoutput.txt
//diff --suppress-common-lines -b output.txt isoutput.txt // Compare changes without considering spaces
//https://geekland.eu/comparar-directorios-y-archivos-comando-diff-linux/

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
multiset <ll> stm; // Can contain multiple instances of an element
unordered_multiset <ll> stum
s.count(k) //  how many k are there
st.erase(n);// Remove all instances of an element
st.erase(s.find(n)); // Only one instance should be removed

//MAP
	-> Internally, the elements in a map are always sorted by its key
	-> map is based on a balanced binary search tree and accessing elements takes O(log n) time.
	-> unordered_map uses hashing and accessing elements takes O(1) time on average.
map <ll,ll> mp; // map <key,data> mp;
mp[k] = d; // ll k,d;
mp[i].first // key
mp[i].second //data
mp.count("Key") //The function count checks if a key exists in a map
unordered_map <ll, ll> ump; // Cannot declare a pair as a key
ump.find(s) != ump.end() // to know if the key exists 

//VECTOR
vector<ll> vec;
ll a(vector<int> &v, int &val) // refer (&) to a vector
vector<ll> vec(n, k); // Fill the vector with k
ump.insert({s,0});

//ARRAY
void print (ll size, ll prin[])
memset(arr, k, sizeof arr);  // k = 0 ó -1 
fill(arr,arr+n,val); // Assigns val to all the elements in the range [first,last).
reverse(arr,arr+n); //  int n = sizeof(arr) / sizeof(arr[0]);
auto r = equal_range (arr, arr+n, x); // Returns a range containing all elements equivalent to value in the range [first, last).
random_shuffle(arr,arr+n);

//QUEUE
	->  the elements in a C++ priority queue are sorted in decreasing order, and it is possible to find and remove the largest element in the queue.
		
priority_queue<ll> que;
priority_queue<int,vector<int>,greater<int>> que; // priority_queue<int, vector<int>, decltype(cmp)> 
// If we want to create a priority queue that supports finding and removing the smallest element
queue <ll> que;

//DEQUE
deque<int> d;
d.push_back(5); // [5]
d.push_back(2); // [5,2]
d.push_front(3); // [3,5,2]
d.pop_back(); // [3,5]
d.pop_front(); // [5]

//STACK
 

//BISET
	-> A bitset is an array whose each value is either 0 or 1.
	-> bitset only requires n bits of memory
	-> Can to use bit operations: | & ^

bitset<10> bst; //
bst[3] = 1; //
bitset<10> bst(string("0010011010")); // from right to left
cout << bst[4] << "\n"; // 1
cout << bst[5] << "\n"; // 0
bst.count() // The function count returns the number of ones in the bitset
	
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
s1.substr(i,k);// posittion i and has lenght k
string s1=to_string(l) // for int to string
c.compare("V") // Compare two strings
a = count(s1.begin(), s1.end(), X); // string x = 's' 
tolower(s1[0]) // convert to lowercase
strlwr(&s1[0]) // convert to lowercase
isupper(s[0]) 

fint(c); // Finds the position of the firt ocurrence of a substring c.

	// MATH

sqrt(a,b); // Square root
floor(d); // Funcion piso
ceil(x); //Funcion techo
round(x); // Redondea a siguiente
trunc(x); // redondea a cero
value   round   floor   ceil    trun
3.8     4.0     3.0     4.0     3.0
5.5     6.0     5.0     6.0     5.0

log10(x);
log(x); //Ln(x)
log2(x);
pow(a, b) //a ^ b = %f\n",
hypot(a,b) // hypotenuse

	//Templates
//https://cplusplus.com/doc/oldtutorial/templates/
//Function templates are special functions that can operate with generic types. 
//This allows us to create a function template whose functionality can be adapted to more than one type or class without repeating the entire code for each type.
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
	
template<class T>
struct Point3D {
	T x;
	T y;
	T z;
};
	
	
