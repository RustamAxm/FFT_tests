//
// Created by rustam on 28.04.22.
//
#pragma once

#include <random>
#include <iostream>
#include <vector>

using namespace std;

template <typename It>
void PrintRange(It begin, It end) {
    for (It it = begin; it != end; ++it) {
        std::cout << *it << std::endl;
    }
}

vector<int> generate_random_data(const size_t numbers) {
    mt19937 generator;
    cout << numbers << endl;
    vector<int> test_vector(numbers);
    iota(test_vector.begin(), test_vector.end(), 1);
    shuffle(test_vector.begin(), test_vector.end(), generator);
    return test_vector;
}
