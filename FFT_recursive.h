//
// Created by rustam on 22.04.22.
//
#pragma once

#include <cmath>
#include <complex>
#include <future>
#include <execution>
#include <valarray>

const double PI = 3.14159265;
const int MAX_DEPTH = 8;

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

void FFT(CArray& array);
//void FFT(std::execution::sequenced_policy& policy, CArray& array);
//void FFT(std::execution::parallel_policy& policy, CArray& array);
void FFT_acync(CArray& array);
void FFT(CArray& array, int depth);