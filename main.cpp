
#include "test_FFT_function.h"
#include "test_FFT_class.h"



int main() {
    size_t N = pow(2, 16);
    size_t N_small = pow(2, 3);

    Test_FFT_small(N_small);
    Test_class_impl_small(N_small);
    Test_FFT(N );
    Test_class_impl(N );
    return 0;
}
