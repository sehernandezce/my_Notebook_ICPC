// Algorithm or logic: Geometry general 2D 
//
typedef long long T;
const lf pi = 3.14159265358979323846;
struct pt{
    T x,y;
    pt operator - (const pt &o) const { return {x - o.x, y - o.y}; }

    bool operator == (pt b) { return x == b.x && y == b.y; }
    bool operator != (pt b) { return !(*this == b); }
    bool operator < (const pt &o) const{ return x < o.x || (x == o.x && y < o.y); }
    bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }
};

T dot(pt a, pt  b){
    return a.x * b.x + a.y * b.y;
}

T cross(pt a, pt b){  // si cross(a,b) == 0 Son vectores paralelos
    return a.x*b.y - a.y*b.x;
}

T orient(pt a, pt b, pt c){
    return cross(b-a, c-a);
}

bool in_angle(pt a, pt b, pt c){
    if(orient({0,0}, a, b) > 0) swap(a,b);
    // a esta ala izq de b
    return orient({0,0}, a, c) * orient({0,0}, b, c) < 0;
}

double area(vector<pt>& p){
    T ans = 0;
    int n = (int)p.size();
    for(int i = 0; i < n; i++){
        ans += cross(p[i], p[(i+1)%n]);
    }
    // ans > 0 -> clockwise  ans < 0 -> counterclockwise
    return (double)abs(ans) / 2.0;
}

int side(pt p){ // false si esta en la parte de arriba
    assert(p.x != 0 && p.y != 0);
    return !(p.y > 0 || (p.y == 0 && p.x < 0));
}

pt o = {0,0};
bool polar_cmp(const pt &a, const pt &b){
    return make_tuple(side(a-o), 0) < make_tuple(side(b-o), cross(b-o,a-o));
}

// O(nlogn)
vector<pt> convex_hull(vector<pt>& p){
    sort(p.begin(), p.end());
    vector<pt> ch;
    int n = (int)p.size();
    for(int it = 0; it < 2; it++){
        int sz = (int)ch.size();
        for(int i = 0; i<n; i++){
            while((int)ch.size() >= sz+2 && orient(ch[(int)ch.size()-2], ch[(int)ch.size()-1], p[i]) > 0){ // Si yo quiero los puntos coliniales lo dejo asi, si no los quiero >=0 
                ch.pop_back();
             }
            ch.push_back(p[i]);
        }
        ch.pop_back();
        reverse(p.begin(),p.end());
    }
    // Tener cuidado con casos n < 3
    if((int)ch.size() == 2 && ch[0] == ch[1]) ch.pop_back();
    return ch;
}

T norm(pt a){return a.x*a.x + a.y*a.y;}

lf abs(pt a){return sqrt((lf)norm(a));}

lf angle(pt a, pt b){
    lf ad = abs(a), op = abs(b);
    return atan(op/ad)*(180.0/pi);
}

lf angle2(pt c1, pt c2, pt c3)
{   
    pt a = c2 - c1;
    pt b = c3 - c1;
    T dt = dot(a,b);
    lf ma = abs(a), mb = abs(b);
    lf theta = dt/(ma*mb);
    return acos(theta)*(180.0/pi);
}

//
/*
pt a {1, 2};
*/

// Area de un triangualo dado tres puntos
// Función para calcular la distancia entre dos puntos
double distancia(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Función para calcular el área de un triángulo dado tres puntos
double areaT2(pair<lf,lf> aa, pair<lf,lf> bb, pair<lf,lf> cc) {
    auto[x1,y1] = aa;
    auto[x2,y2] = bb;
    auto[x3,y3] = cc;

    // Calcular las longitudes de los lados del triángulo
    double a = distancia(x1, y1, x2, y2);
    double b = distancia(x2, y2, x3, y3);
    double c = distancia(x3, y3, x1, y1);

    // Calcular el semiperímetro
    double s = (a + b + c) / 2.0;

    // Aplicar la fórmula de Néron para calcular el área
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
