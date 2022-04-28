//
// Created by rustam on 28.04.22.
//
#pragma once

#include <random>
#include <iostream>

#include "FFT_recursive.h"
#include "log_duration.h"

#include "support.h"

void Test_FFT(const size_t numbers) {
    vector<int> test_vector = generate_random_data(numbers);

    Complex test[test_vector.size()];
    for (size_t i = 0; i < test_vector.size(); ++i) {
        test[i] = test_vector[i];
    }
    CArray data(test, test_vector.size());

    CVector data_for_vec;
    for (size_t i = 0; i < test_vector.size(); ++i) {
        data_for_vec.push_back(test_vector[i]);
    }

    {
        LOG_DURATION_STREAM("FFT_standart", cerr);
        FFT(data);
    }
//    PrintRange(begin(data), end(data));
    {
        LOG_DURATION("iFFT_standart");
        iFFT(data);
    }

    {
        LOG_DURATION("FFT_async");
        FFT_async(data);
    }

    {
        LOG_DURATION("iFFT_async");
        iFFT_async(data);
    }

    {
        LOG_DURATION_STREAM("FFT_standart_vector", cerr);
        FFT_vector(data_for_vec);
    }

    {
        LOG_DURATION_STREAM("FFT_async_vector", cerr);
        FFT_async_vec(data_for_vec);
    }
}
void Test_FFT_small(const size_t numbers) {
    vector<int> test_vector = generate_random_data(numbers);

    Complex test[test_vector.size()];
    for (size_t i = 0; i < test_vector.size(); ++i) {
        test[i] = test_vector[i];
    }
    CArray data(test, test_vector.size());

    CVector data_for_vec;
    for (size_t i = 0; i < test_vector.size(); ++i) {
        data_for_vec.push_back(test_vector[i]);
    }

    FFT(data);

    PrintRange(begin(data), end(data));
}
