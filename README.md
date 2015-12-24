## Eigen  

Assignment code for 2 to 1 dimension reduction using eigen vectors. 
[ Power iteration method ] (https://en.wikipedia.org/wiki/Power_iteration) has been used to find one of the eigen value with the greatest absolute value.

###Compilation
```
g++ covariance.h covariance.cpp eigen.h eigen.cpp eigen_test.cpp -o eigen --std=c++11
```

###Format for input.txt
The number of 2D points on the first line.
All x-coordinates on the second line.
All y-coordinates on the third line.
```
10
15  17  20  21  24  25  29  30  32  35
144 153 163 168 165 172 169 171 174 167
```

###Running
```
./eigen < input.txt
```

