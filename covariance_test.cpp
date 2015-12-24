#include<iostream>
#include<vector>
#include"covariance.h"

int main(){

        std::vector<int> x = {-10,-7,-6,-6,1,1,2,8,9,10};
        std::vector<int> y = {-5,-5,-4,-3,-2,1,2,2,3,8};

        CovarianceMat cm(x,y);
        cm.constructMatrix();

        std::vector<std::vector<float> > covMat = cm.getMatrix();

        for(int i = 0; i<2;i++){
                for(int j=0;j<2;j++){

                        std::cout<<covMat[i][j]<<" ";

                }
                std::cout<<std::endl;
        }

        return 0;
}

