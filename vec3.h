#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
    public:
        double e[3]; //instance variable (length 3 aray of doubles)

        //default constructor initializes e with (0,0,0)
        vec3() : e{0,0,0} {} 
        vec3(double e0, double e1, double e2) : e{e0,e1,e2} {} //constructor to manually set x y z

        double x() const { return e[0]; } // get x coord
        double y() const { return e[1]; } // get y coord
        double z() const { return e[2]; } // get z coord

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); } //overload negation 
        double  operator[](int i) const { return e[i]; } //get coord at index of e
        double& operator[](int i) { return e[i]; } //get coord at index e that can be modified with address

        //overloaded method for multiplying two vectors together
        vec3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }
        
        //overloaded method for adding two vectors together
        vec3& operator+=(const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        //overloaded method for dividing a vector by a vector
        vec3& operator/=(double t) {
            return *this *= 1/t;
        }

        //finds length of vector
        //const means it does not alter and variables
        double length() const {
            return sqrt(length_squared());
        }
        
        //finds length squared of vector
        //const means it does not alter and variables
        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;

// Vector utility funcitons
//(inline reduces overhead on function call)

//overloads << operator basically acts as a two string
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

//adds two vectors
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

//subtracts one vector from another
inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

//multiplies two vectors
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

//multiplies a vector by a constant
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

//multiplies a vector by a constant
inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

//divides a vector by a constant
inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

//returns dot product of two vectors
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

// returns cross product of two vectors
inline vec3 cross(const vec3& u, const vec3& v) {
     return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                 u.e[2] * v.e[0] - u.e[0] * v.e[2],
                 u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

//returns the unit vector
inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}




#endif