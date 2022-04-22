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

    {
        LOG_DURATION("FFT_standart");
        FFT(data);
    }

    {
        LOG_DURATION("FFT_async");
        FFT_acync(data);
    }
}

int main() {
    TestFFT(200000);
    return 0;
}
