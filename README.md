# FFT_tests
First test for valarray 
FFT without and with async MAX_DEPTH = 4;  

### 200000 int

After convert to Complex data

Result: 

FFT_standart: 145 ms

FFT_async: 88 ms

### 500000 int

FFT_standart: 404 ms

iFFT_standart: 434 ms

FFT_async: 151 ms

iFFT_async: 177 ms

### vector implementation 
262144

FFT_standart: 233 ms

iFFT_standart: 243 ms

FFT_async: 90 ms

iFFT_async: 113 ms

FFT_standart_vector: 283 ms

FFT_async_vector: 71 ms
