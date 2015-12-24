#include<iostream>
#include<vector>
#include<iomanip>
#include"covariance.h"
#include"eigen.h"

void printVector(std::vector<float> vec){

        for(int i=0;i<vec.size();i++){
        std::cout<<std::setw(9)<<std::setprecision(6)<<vec[i]<<"  ";
        }
        std::cout<<std::endl;
}

float dotProduct(std::vector<float> vec1, std::vector<float> vec2){

        float val = 0;

        for(int i=0; i < vec1.size() ;i++){
                val += vec1[i] * vec2[i];
        }

        return val;

}

std::vector<float> scalarProduct(float scalarValue, std::vector<float> vec){
        std::vector<float> retVec;
        for(int i = 0; i<vec.size();i++){
                retVec.push_back(scalarValue * vec[i]);
        }

        return retVec;
}
                


int main(){

        int valueCount;

        std::cin>>valueCount;
        std::vector<int> x;
        std::vector<int> y;

        for(int i=0;i<valueCount;i++){
                int temp;
                std::cin>>temp;
                x.push_back(temp);
        }

        for(int i=0;i<valueCount;i++){
                int temp;
                std::cin>>temp;
                y.push_back(temp);
        }

        //std::vector<int> x = {-10,-7,-6,-6,1,1,2,8,9,10};
        //std::vector<int> y = {-5,-5,-4,-3,-2,1,2,2,3,8};

        CovarianceMat cm(x,y);
        cm.constructMatrix();

        std::vector<std::vector<float> > covMat = cm.getMatrix();

        Eigen egn(covMat,2);
        egn.calculateEigenProperties();

        float egnValue = egn.getEigenValue();

        std::vector<float> egnVec = egn.getEigenVector();

        std::cout<<"Eigen value: "<<egnValue<<std::endl;
        std::cout<<"Eigen vector: ";

        printVector(egnVec);

        std::vector<float> normalizedEigenVector = egn.getNormalizedEigenVector();
        std::cout<<"Normalized Eigen vector: ";
        printVector(normalizedEigenVector);

        std::cout<<"Final projection points: \n";

        std::vector<float > finalPoints_x;
        std::vector<float > finalPoints_y;

        for(int i=0;i<x.size();i++){
                std::vector<float> point;
                point.push_back(x[i]);
                point.push_back(y[i]);
                std::vector<float> newPoint = scalarProduct(dotProduct(point,normalizedEigenVector),normalizedEigenVector);

                finalPoints_x.push_back(newPoint[0]);
                finalPoints_y.push_back(newPoint[1]);

        }

        printVector(finalPoints_x);
        printVector(finalPoints_y);

        return 0;
}

