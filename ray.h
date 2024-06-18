#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:
        ray() {} //default constructor
        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {} //constructor with origin and direction initialized

        //returns unmutable references
        const point3& origin() const { return orig; }
        const vec3& direction() const { return dir; }

        point3 at(double t) const { //get position of 3D position
            return orig + t*dir;
        }

    private:
        point3 orig;
        vec3 dir;
};

#endif