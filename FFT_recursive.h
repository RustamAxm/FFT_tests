//
// Created by rustam on 22.04.22.
//
#pragma once

#include <cmath>
#include <complex>
#include <future>
#include <execution>
#include <valarray>
#include <vector>

const double PI = 3.14159265;
const int MAX_DEPTH = 4;

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

typedef std::vector<Complex> CVector;


void FFT(CArray& array);
void FFT_vector(CVector& vec);

void FFT_async(CArray& array);
void FFT_async(CArray& array, int depth);

void FFT_async_vec(CVector& array);
void FFT_async_vec(CVector& array, int depth);

void iFFT(CArray& array);
void iFFT_async(CArray& array);
void iFFT_vector(CArray& array);

