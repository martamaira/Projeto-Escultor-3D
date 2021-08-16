#include "cutsphere.h"
#include <cmath>

cutSphere::cutSphere(int xcenter, int ycenter, int zcenter, float radius){
    this->xcenter=xcenter; this->ycenter=ycenter; this->zcenter=zcenter;
    this->radius=radius;
}

void cutSphere::draw(Sculptor &s){
    int i, j, k;
    for(i=xcenter-radius; i<=xcenter+radius; i++){
        for(j=ycenter-radius; j<=ycenter+radius; j++){
            for(k=zcenter-radius; k<=zcenter+radius; k++){
                if(((pow(i-xcenter, 2)) + (pow(j-ycenter, 2)) + (pow(k-zcenter, 2))) <= pow(radius, 2)){
                    s.cutVoxel(i, j, k);
                }
            }
        }
    }
}
