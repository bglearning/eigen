#include<iostream>
#include<vector>
#include<cmath>
#include"covariance.h"
#include"eigen.h"

float Eigen::max(std::vector<float> vec){

        float max = fabs(vec[0]);

        for(int i = 0; i<vec.size();i++){
                if(fabs(vec[i]) > max) max = fabs(vec[i]);
        }

        return max;

}

void Eigen::calculateEigenProperties(){

        std::vector<float> approxEigenVector;
        int itr;

        approxEigenVector.push_back(1.0);
        for(int i=1;i<n;i++){ approxEigenVector.push_back(0.0); }

        float approxEigenValue = 1.0;

        for(itr = 1; itr <= maxIter; itr++){

                std::vector<float> newEigenVector;

                /* Loop to multiply the matrices covMat and approxEigenVector */

                for(int i = 0;i<n ;i++){

                        float sum = 0;

                        for(int k =0;k<n;k++){
                                sum += covMat[i][k] * approxEigenVector[k];
                        }

                        newEigenVector.push_back(sum);
                }

                float newEigenValue = max(newEigenVector);

                //Difference vector to find out max error
                std::vector<float> vecDiff;

                for(int i = 0;i<n;i++){ 
                        newEigenVector[i] = newEigenVector[i]/newEigenValue; 
                        //Find out the difference
                        vecDiff.push_back(approxEigenVector[i] - newEigenVector[i]);
                        //Prepare for the next iteration
                        approxEigenVector[i] = newEigenVector[i];
                }

                float maxError = max(vecDiff);

                float maxValueError = fabs(newEigenValue - approxEigenValue);

                approxEigenValue = newEigenValue;

                if((maxError <= acceptableError) and (maxValueError <= acceptableError)){
                        break;
                }
        }

        if(itr <= maxIter){
            eigenVector = approxEigenVector;
            eigenValue = approxEigenValue;
        }else{
                std::cout<<"Error: Max iteration exceeded!\n";
        }

}
            

std::vector<float> Eigen::getEigenVector(){

        return eigenVector;

}

std::vector<float> Eigen::getNormalizedEigenVector(){

        float normValue = 0;
        for(int i=0;i<eigenVector.size();i++){
                normValue += eigenVector[i] * eigenVector[i];
        }

        normValue = sqrt(normValue);

        std::vector<float> normalizedEigenVector;

        for(int i=0;i<eigenVector.size();i++){
                normalizedEigenVector.push_back(eigenVector[i]/normValue);
        }

        return normalizedEigenVector;

}

float Eigen::getEigenValue(){

        return eigenValue;

}
