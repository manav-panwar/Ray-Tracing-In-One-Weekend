#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <cstdlib>
#include <random>

// C++ std usings
using std::shared_ptr;
using std::make_shared;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    static std::mt19937_64 rng(std::random_device{}());
    static std::uniform_real_distribution<double> dist(0.0, 1.0);

    // Returns a random real in [0,1).
    return dist(rng);
}

inline double random_double(double min, double max) {
    static std::mt19937_64 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(min, max);

    // Returns a random real in [min,max).
    return dist(rng);
}

// Common headers

#include "vec3.h"
#include "interval.h"
#include "color.h"
#include "ray.h"

#endif

