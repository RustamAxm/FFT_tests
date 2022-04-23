#include <iostream>
#include <random>
#include <numeric>

#include "log_duration.h"
#include "FFT_recursive.h"



using namespace std;

template <typename It>
void PrintRange(It begin, It end) {
    for (It it = begin; it != end; ++it) {
        std::cout << *it << std::endl;
    }
}

void FFT_printer(CArray data) {
    std::cout << "fft" << std::endl;
    for (int i = 0; i < 8; ++i)
    {
        std::cout << data[i] << std::endl;
    }
}

void TestFFT(const size_t numbers) {
    mt19937 generator;
    cout << numbers << endl;
    vector<int> test_vector(numbers);
    iota(test_vector.begin(), test_vector.end(), 1);
    shuffle(test_vector.begin(), test_vector.end(), generator);


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

int main() {
    TestFFT(pow(2, 18));
    return 0;
}
