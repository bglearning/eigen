#ifndef COVARIANCE_H
#define COVARIANCE_H
#include<iostream>
#include<vector>

class CovarianceMat{

        private:
                std::vector<std::vector<float> > matrix;
                std::vector<int> x;
                std::vector<int> y;

                float calculateMean(std::vector<int> vec);

        public:

            CovarianceMat(std::vector<int> _x,std::vector<int> _y):x(_x),y(_y){};

            float calculateCovariance(std::vector<int> a, std::vector<int> b);

            void constructMatrix();

            std::vector<std::vector<float> > getMatrix();

};

#endif
