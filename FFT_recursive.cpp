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

void FFT_async(CArray& array) {
    return FFT_async(array, 0);
}

void FFT_async(CArray& array, int depth = 0) {
    const size_t N = array.size();
    if (N <= 1) {
        return;
    }

    CArray even = array[std::slice(0, N/2, 2)];
    CArray odd = array[std::slice(1, N/2, 2)];

    ++depth;
    if (depth < MAX_DEPTH) {
        auto even_future = std::async([&](){ FFT_async(even, depth); });
        auto odd_future = std::async([&](){ FFT_async(odd, depth); });
    } else {
        FFT_async(even, depth);
        FFT_async(odd, depth);
    }

    for (size_t i = 0; i < N/2; ++i) {
        Complex tmp = std::polar(1.0, -2 * PI * i / N) * odd[i];
        array[i] = even[i] + tmp;
        array[i + N/2] = even[i] - tmp;
    }
}

void FFT_vector(CVector& vec) {
    const size_t N =  vec.size();
    if (N <= 1) {
        return;
    }

    CVector even(N/2);
    CVector odd(N/2);

    for (size_t i = 0; i < N/2; ++i) {
        odd[i] = vec[2 * i];
        even[i] = vec[2 * i + 1];
    }

    FFT_vector(even);
    FFT_vector(odd);

    for (size_t i = 0; i < N/2; ++i) {
        Complex tmp = std::polar(1.0, -2 * PI * i / N) * odd[i];
        vec[i] = even[i] + tmp;
        vec[i + N/2] = even[i] - tmp;
    }
}

void FFT_async_vec(CVector& vec) {
    return FFT_async_vec(vec, 0);
}

void FFT_async_vec(CVector& vec, int depth) {
    const size_t N =  vec.size();
    if (N <= 1) {
        return;
    }

    CVector even(N/2);
    CVector odd(N/2);

    for (size_t i = 0; i < N/2; ++i) {
        odd[i] = vec[2 * i];
        even[i] = vec[2 * i + 1];
    }
    ++depth;
    if (depth < MAX_DEPTH) {
        auto even_future = std::async([&]() { FFT_async_vec(even, depth);});
        auto odd_future = std::async([&]() { FFT_async_vec(odd, depth);});
    } else {
        FFT_vector(even);
        FFT_vector(odd);
    }

    for (size_t i = 0; i < N/2; ++i) {
        Complex tmp = std::polar(1.0, -2 * PI * i / N) * odd[i];
        vec[i] = even[i] + tmp;
        vec[i + N/2] = even[i] - tmp;
    }
}

void iFFT(CArray& array) {
    array = array.apply(std::conj);
    FFT(array);
    array = array.apply(std::conj);
    array /= array.size();
}

void iFFT_async(CArray& array) {
    array = array.apply(std::conj);
    FFT_async(array, 0);
    array = array.apply(std::conj);
    array /= array.size();
}
