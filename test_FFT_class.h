//
// Created by rustam on 28.04.22.
//
#pragma once

#include <random>
#include <iostream>
#include <vector>

#include "FFT_class.h"
#include "log_duration.h"

#include "support.h"

void Test_class_impl(const size_t numbers) {
    vector<int> test_vector = generate_random_data(numbers);

    Complex test[test_vector.size()];
    for (size_t i = 0; i < test_vector.size(); ++i) {
        test[i] = test_vector[i];
    }
    CArray data(test, test_vector.size());

    LOG_DURATION("CArray");
    {
        class_FFT fft(data);
        CArray fft_data = fft.get_FFT();
    }

    LOG_DURATION("template Container");
    {
        class_FFT second_fft(test_vector);
        CArray second_fft_data = second_fft.get_FFT();
    }
}

void Test_class_impl_small(const size_t numbers) {
    vector<int> test_vector = generate_random_data(numbers);

    Complex test[test_vector.size()];
    for (size_t i = 0; i < test_vector.size(); ++i) {
        test[i] = test_vector[i];
    }
    CArray data(test, test_vector.size());

    PrintRange(begin(data), end(data));

    class_FFT fft(data);
    CArray fft_data = fft.get_FFT();
    PrintRange(begin(fft_data), end(fft_data));


    PrintRange(begin(test_vector), end(test_vector));

    class_FFT second_fft(test_vector);
    CArray second_fft_data = second_fft.get_FFT();
    PrintRange(begin(second_fft_data), end(second_fft_data));

    vector<double> real = second_fft.get_real();
    PrintRange(real.begin(), real.end());

    vector<double> im = second_fft.get_img();
    PrintRange(im.begin(), im.end());
}