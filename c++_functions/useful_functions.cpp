// C++ useful functions
//In windows
//g++ -DLOCALNZN -std=c++11 -O2 -Wconversion -Wshadow -Wall -Wextra -o "main" "main.cpp" && main <input.txt> output.txt
//g++ -DLOCALNZN -std=c++11 -g -O2 -Wconversion -Wshadow -Wall -Wextra -D_GLIBCXX_DEBUG -o "main" "main.cpp" && main <input.txt> output.txt
//In linux
//g++ -DLOCAL -std=c++11 -g -O2 -Wconversion -Wshadow -Wall -Wextra -D_GLIBCXX_DEBUG -o "%e" "%f"
//g++ -DLOCAL -std=c++11 -g -O2 -Wconversion -Wshadow -Wall -Wextra -D_GLIBCXX_DEBUG -c "%f"
//g++ -DLOCALNZN -std=c++11 -g -O2 -Wconversion -Wshadow -Wall -Wextra -D_GLIBCXX_DEBUG -o "main" "main.cpp" && ./main <input.in> output.out
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

//Input
for (int& t: x) cin >> t;


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

bool cmp(const Edge& x, const Edge& y) { return x.w < y.w; }
set<Edge,bool(*)(const Edge&,const Edge&)> v(cmp); // Set with function comp

	//Policy - Based Data Structures
	//https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/
	//https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/
// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
ordered_set orset;

orset.find_by_order();
orset.order_of_key();

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
	//https://codeforces.com/blog/entry/74684
vector<ll> vec;
ll a(vector<int> &v, int &val) // refer (&) to a vector
vector<ll> vec(n, k); // Fill the vector with k
ump.insert({s,0});
accumulate(vec.begin(),vec.end(), 0LL);

// removes consecutive duplicates and returns the end of the resulting iterator range
sort(all(vec)); 
vec.resize(unique(all(vec)) - vec.begin()); // Funciona para vectores y strings

//if you need to fill it by consecutive numbers, you can use
 iota(all(vec), 0);

//where you need sometimes to cyclically shift a vector by k
rotate(vec.begin(), vec.begin() + k, vec.end()); // rotate(begin, middle, end)

//Merge two vector
//akes 5 arguments: begin and end of one interval to merge, 
//begin and end of the second interval to merge, and where to write the result. 
nodes[v].resize(nodes[2 * v].size() + nodes[2 * v + 1].size()); 
merge(all(nodes[2 * v]), all(nodes[2 * v + 1]), nodes[v].begin());

//ARRAY max size <= 1e6
void print (ll size, ll prin[])
memset(arr, k, sizeof arr);  // k = 0 ó -1 
fill(arr,arr+n,val); // Assigns val to all the elements in the range [first,last).
reverse(arr,arr+n); //  int n = sizeof(arr) / sizeof(arr[0]);
auto r = equal_range (arr, arr+n, x); // Returns a range containing all elements equivalent to value in the range [first, last).
random_shuffle(arr,arr+n);
accumulate (numbers, numbers+n, init, myfunction);

//QUEUE
	->  the elements in a C++ priority queue are sorted in decreasing order, and it is possible to find and remove the largest element in the queue.
		
priority_queue<ll> que;
priority_queue<int,vector<int>,greater<int>> que(data.begin(), data.end()); // priority_queue<int, vector<int>, decltype(cmp)> 
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

//Tuple
tuple<type1, type2, ..., typeN> t;
make_tuple(a, b, c, ..., d) //Returns a tuple with values written in the brackets.
get<i>(t); // Returns the i'th element of the tuple t. Can also be used to change the element of a tuple.
tie(a, b, c, ..., d) = t // Assigns a, b, c, ..., d to the elements of the tuple $t$ accordingly.
	
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
(char)tolower(s1[0]) // convert to lowercase the char s1[0]
(char)toupper(s1[0]) // convert to uppercase the char s1[0]
strlwr(&s1[0]) // convert to lowercase
isupper(s[0]) // is uppercase? 1 yes  | 0 no
s1.append(s2); // Extends the string by appending additional characters at the end of its current value
find(c); // Finds the position of the firt ocurrence of a substring c.

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
int x = min({a, b, c, d});
	
	//Timer
auto start = chrono::steady_clock::now();
 auto end = chrono::steady_clock::now();
    cout << "Elacpsed time in milliseconds :"
         <<chrono::duration_cast<chrono::milliseconds>(end-start).count()
         << " ms"<< endl;

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
	bool operator< (const Point3D &p){
		return true;
	}
};
	
	//Sort ans function cmp
bool cmp(pair<int,int> x, pair<int,int> y) {return x.second < y.second;}
sort(movie.begin(),movie.end(),cmp);

	//for each
for(auto& c: mp){}

// Function lambda
auto pref = [&](int i, int j) -> ll{return ar[j] - ar[i-1];}; 
sort(begin(v),end(v),[](const Edge& x, const Edge& y) { return x.w < y.w; });

function<void(int)> dfs = [&](int p) -> void{
        vis[p] = 1;
        for(auto u: adj[p]){
            if(vis[u] == 0) dfs(u);
        }
    };
//
int last_true(int lo, int hi, function<bool(int)> f){}
last_true(1, 2e9, [&](int x) {
		// Returns true if the median can be raised to x
		long long ops_needed = 0;
		for (int i = (size - 1) / 2; i < size; i++) {
			ops_needed += max(0, x - arr[i]);
		}
		return ops_needed <= max_ops;
	})
//Assert
assert(x == 1); // Finaliza el programa si la expresion retorna 0
	
cout << fixed << setprecision(6) << ans << endl;
