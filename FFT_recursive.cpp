//
// Created by rustam on 22.04.22.
//

#include "FFT_recursive.h"

void FFT(CArray& array) {
    const size_t N = array.size();
    if (N <= 1) {
        return;
    }

    CArray even = array[std::slice(0, N/2, 2)];
    CArray odd = array[std::slice(1, N/2, 2)];

    FFT(even);
    FFT(odd);

    for (size_t i = 0; i < N/2; ++i) {
        Complex tmp = std::polar(1.0, -2 * PI * i / N) * odd[i];
        array[i] = even[i] + tmp;
        array[i + N/2] = even[i] - tmp;
    }
}

//void FFT(std::execution::sequenced_policy& policy, CArray& array) {
//    return FFT(array);
//}
//
//void FFT(std::execution::parallel_policy& policy, CArray& array) {
//    return FFT(array, 0);
//}

void FFT_acync(CArray& array) {
    return FFT(array, 0);
}

void FFT(CArray& array, int depth = 0) {
    const size_t N = array.size();
    if (N <= 1) {
        return;
    }

    CArray even = array[std::slice(0, N/2, 2)];
    CArray odd = array[std::slice(1, N/2, 2)];

    ++depth;
    if (depth < MAX_DEPTH) {
        auto even_fixture = std::async([&](){ FFT(even, depth);});
        auto odd_fixture = std::async([&](){ FFT(odd, depth);});
    } else {
        FFT(even, depth);
        FFT(odd, depth);
    }

    for (size_t i = 0; i < N/2; ++i) {
        Complex tmp = std::polar(1.0, -2 * PI * i / N) * odd[i];
        array[i] = even[i] + tmp;
        array[i + N/2] = even[i] - tmp;
    }
}