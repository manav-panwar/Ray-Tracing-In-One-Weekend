#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.h"

class hit_record {
    public:
        point3 p;
        vec3 normal;
        double t; 
        bool front_face;

        void set_face_normal(const ray& r, const vec3& outward_normal) {
            // Sets the hit record normal vector
            // Outward normal is assumed to have unit length

            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        }
};

class hittable {
    public:
        // virtual so that both hittable and the object type are cleared
        // ~ to make a destructor
        // default because we don't need any special clean-up
        virtual ~hittable() = default;

        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const =  0;
        // = 0 because we are not defining this function and so that we can't do hittable h, we are promising that we will define this for the child object.
};

#endif