#ifndef EIGEN_H
#define EIGEN_H

#include<iostream>
#include<vector>
#include"covariance.h"

class Eigen{

        private:
            std::vector< std::vector<float> > covMat;
            int n;
            std::vector< float > eigenVector;
            float eigenValue;

            const float acceptableError = 0.01;
            const int maxIter = 20;

            float max(std::vector<float> vec);

        public:
            Eigen( std::vector< std::vector<float> > cm ,int _n):covMat(cm),n(_n){}

            void calculateEigenProperties();

            std::vector<float> getEigenVector();
            std::vector<float> getNormalizedEigenVector();

            float getEigenValue();

};

#endif
