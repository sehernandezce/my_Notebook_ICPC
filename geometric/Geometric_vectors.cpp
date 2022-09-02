// Complex number, Vector a+bi ,  sqrt(-1)=i
// Class complex 
typedef long long TD;
typedef long double C;
typedef complex<C> P;

#define X real ()
#define Y imag ()
struct segment{
    TD x, y, z;

    segment() {}
    segment(TD x,TD y, TD z): x(x), y(y), z(z) {}
    
    segment& operator +=(const segment &ax){
        x += ax.x;
        y += ax.y;
        z += ax.z;
        return *this;
    }

    segment& operator-=(const segment &t) {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }

    // k * V k es un escalar
    segment& operator*=(TD t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    segment& operator/=(TD t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }

    segment operator +(const segment &ax){
        return segment(*this) += ax;
    }   
    
    segment operator-(const segment &t) const {
        return segment(*this) -= t;
    }

    segment operator*(TD t) const {
        return segment(*this) *= t;
    }
    segment operator/(TD t) const {
        return segment(*this) /= t;
    }

    //Dot product
    TD dot(segment a, segment b){
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    TD norm(segment a) {
    return dot(a, a);
    }
    double abs(segment a) {
        return sqrt(norm(a));
    }
    double proj(segment a, segment b) {
        return dot(a, b) / abs(b);
    }
    double angle(segment a, segment b) {
        return acos(dot(a, b) / abs(a) / abs(b));
    }

    // Cross product
    segment cross(segment a, segment b) {
    return segment(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
    }

    TD triple(segment a, segment b, segment c) {
        return dot(a, cross(b, c));
    }
    
    // Line intersection
    segment intersect(segment a1, segment d1, segment a2, segment d2) {
       // return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
    }

    //Plane 
    segment intersect(segment a1, segment n1, segment a2, segment n2, segment a3, segment n3) {
        segment x(n1.x, n2.x, n3.x);
        segment y(n1.y, n2.y, n3.y);
        segment z(n1.z, n2.z, n3.z); 
        segment d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
        return segment(triple(d, y, z),
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
