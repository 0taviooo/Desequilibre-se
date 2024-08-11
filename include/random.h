#ifndef RANDOM_H

#define RANDOM_H

#include <cmath>
#include <random>
#include <unordered_map>

struct Random {
    static int gen(int min, int max) {
        static mt19937 generator;
        uniform_int_distribution<int> distribution(min, max);
        int result = distribution(generator);
        return result;
    }
};

#endif
