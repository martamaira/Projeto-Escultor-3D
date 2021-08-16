#include "cutellipsoid.h"
#include <cmath>

cutEllipsoid::cutEllipsoid(int xcenter,int ycenter,int zcenter,int rx,int ry,int rz){
    this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter;

    this->rx = rx; this->ry = ry; this->rz = rz;
}

void cutEllipsoid::draw(Sculptor &s){
    int i, j, k;
    for(i=xcenter-rx; i<=xcenter+rx; i++){
        for(j=ycenter-ry; j<=ycenter+ry; j++){
            for(k=zcenter-rz; k<=zcenter+rz; k++){
                if((pow(i-xcenter,2)/pow(rx,2)) + (pow(j-ycenter,2)/pow(ry,2)) + (pow(k-zcenter,2)/pow(rz,2)) <= 1){
                    s.cutVoxel(i, j, k);
                }
            }
        }
    }
}
