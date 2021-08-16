#include "putsphere.h"
#include <cmath>

putSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a)
{
    this->xcenter=xcenter; this->ycenter=ycenter; this->zcenter=zcenter;
    this->radius=radius;

    this->r=r; this->g=g; this->b=b;
    this->a=a;
}

void putSphere::draw(Sculptor &s){
    s.setColor(r,g,b,a);
    int i, j, k;
    for(i=xcenter-radius; i<=xcenter+radius; i++){
        for(j=ycenter-radius; j<=ycenter+radius; j++){
            for(k=zcenter-radius; k<=zcenter+radius; k++){
                if(((pow(i-xcenter, 2)) + (pow(j-ycenter, 2)) + (pow(k-zcenter, 2))) <= pow(radius, 2)){
                    s.putVoxel(i, j, k);
                }
            }
        }
    }
}
