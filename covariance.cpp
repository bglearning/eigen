#include<iostream>
#include"covariance.h"

float CovarianceMat::calculateMean(std::vector<int> vec){

        float sum = 0;

        for(int i=0;i<vec.size();i++){
                sum += vec[i];
        }

        return (sum/vec.size());

}

float CovarianceMat::calculateCovariance(std::vector<int> a, std::vector<int> b){

        float a_mean = calculateMean(a);
        float b_mean = calculateMean(b);

        float sum = 0;

        for(int i=0;i<a.size();i++){
                sum += ((a[i] - a_mean) * (b[i] - b_mean));
        }

        return sum/(a.size()-1);

}


void CovarianceMat::constructMatrix(){

        std::vector<float> firstRow,secondRow;

        float xy_covariance = calculateCovariance(x,y);

        firstRow.push_back(calculateCovariance(x,x));
        firstRow.push_back(xy_covariance);

        secondRow.push_back(xy_covariance);
        secondRow.push_back(calculateCovariance(y,y));

        matrix.push_back(firstRow);
        matrix.push_back(secondRow);

}

std::vector<std::vector<float> > CovarianceMat::getMatrix(){
        return matrix;
}
