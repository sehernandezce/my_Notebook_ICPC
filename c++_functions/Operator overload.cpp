// Algorithm or Logic: Operator overload
// Complexity: ?

struct ejem{
    ll b,c;
};

ll operator+(ejem &a){
    return a.b - a.c;
}

// more info: https://docs.microsoft.com/es-es/cpp/cpp/operator-overloading?view=msvc-170
