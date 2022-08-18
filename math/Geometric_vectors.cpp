// Complex number, Vector a+bi ,  sqrt(-1)=i
// Class complex 
typedef long long TD;
typedef long double C;
typedef complex<C> P;

#define X real ()
#define Y imag ()

struct points{
    TD x, y, z;

    points() {}
    points(TD x,TD y, TD z): x(x), y(y), z(z) {}
    points& operator +=(const points &ax){
        x += ax.x;
        y += ax.y;
        z += ax.z;
        return *this;
    }

    points& operator-=(const points &t) {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }

    // k * V k es un escalar
    points& operator*=(TD t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    points& operator/=(TD t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }

    points operator +(const points &ax){
        return points(*this) += ax;
    }   
    
    points operator-(const points &t) const {
        return points(*this) -= t;
    }

    points operator*(TD t) const {
        return points(*this) *= t;
    }
    points operator/(TD t) const {
        return points(*this) /= t;
    }

    //Dot product
    TD dot(points a, points b){
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    TD norm(points a) {
    return dot(a, a);
    }
    double abs(points a) {
        return sqrt(norm(a));
    }
    double proj(points a, points b) {
        return dot(a, b) / abs(b);
    }
    double angle(points a, points b) {
        return acos(dot(a, b) / abs(a) / abs(b));
    }

    // Cross product
    points cross(points a, points b) {
    return points(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
    }

    TD triple(points a, points b, points c) {
        return dot(a, cross(b, c));
    }
    
    // Line intersection
    points intersect(points a1, points d1, points a2, points d2) {
       // return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
    }

    //Plane 
    points intersect(points a1, points n1, points a2, points n2, points a3, points n3) {
        points x(n1.x, n2.x, n3.x);
        points y(n1.y, n2.y, n3.y);
        points z(n1.z, n2.z, n3.z); 
        points d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
        return points(triple(d, y, z),
                    triple(x, d, z),
                    triple(x, y, d)) / triple(n1, n2, n3);
    }
};

// Nota
/*
P p = {4, 2};
p.X , p.Y to access of the data
P v,u,s; s=v+u; 

Calculate the lenght |v| of a vector v = (x,y)
abs(v); 

The distance between two points 
abs(v,u)

Calculate the angle in radian of a vector with respect to the x-axis
arg(v)

Construct a vector POLAR
polar(s,a); length is s and angle is a
*/

/*
Dor product a . b
a.b = |a|Cos(O)*|b| = x1x2 + y1y2 + z1z2
Properties
a.b=b.a
(q.a).b = q . (a.b)
(a+b).c=a.c+b.c



Cross product a X b
a=(x1,y1) b=(x2,y2);
a X b = x1y2 - x2y1
The direction to which b turn when it is placed directly after a.

a X b = (conj(a)*b).Y; // conj(a) = (x1,-y1)
Properties
a X b = -b X a
()


*/
