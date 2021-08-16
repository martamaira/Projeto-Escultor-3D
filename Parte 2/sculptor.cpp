#include "sculptor.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    int i, j, k;
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = (Voxel***)malloc(nx * sizeof(Voxel**));
    v[0] = (Voxel**)malloc(nx * nz * sizeof(Voxel*));

    for (k=1; k<nz; k++){
        v[k] = v[k-1] + nx;
    }

    v[0][0] = (Voxel*)malloc(nx * ny * nz * sizeof(Voxel));

    int n = 0;
    for (k=0; k<nz; k++){
        for(i=0; i<nx; i++){
            v[k][i] = v[0][0] + n*ny;
            n++;
        }
    }
}

Sculptor::~Sculptor(){
    free(v[0][0]);
    free(v[0]);
    free(v);
}

void Sculptor::setColor(float _r, float _g, float _b, float _a){ //Define a cor atual de desenho.

    //tratamento de parametros
    //red
    if(_r < 0 || _r > 1){
        r = 0;
    } else{
        r = _r;
    }
    //green
    if(_g < 0 || _g > 1){
        g = 0;
    } else{
        g = _g;
    }
    //blue
    if(_b < 0 || _b > 1){
        b = 0;
    } else{
        b = _b;
    }
    //transparency
    if(_a < 0 || _a > 1){
        a = 0;
    } else{
        a = _a;
    }
}

void Sculptor::putVoxel(int x, int y, int z){
    //Ativa o voxel na posição (x,y,z) (fazendo isOn = true) e atribui ao mesmo a cor atual de desenho

    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    //Desativa o voxel na posição (x,y,z) (fazendo isOn = false)

    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
     //Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho

    int i,j,k;
    for(i=x0; i<=x1; i++){
        for(j=y0; j<=y1; j++){
            for(k=z0; k<=z1; k++){
                putVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
     //Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1]
    int i, j, k;

    for(k = z0; k <= z1; k++){
        for(j = y0; j <= y1; j++){
            for(i = x0; i <= x1; i++){
                cutVoxel(i, j, k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    //Ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho (r,g,b,a)
    // R² = (X-X0)²+(Y-Y0)²+(Z-Z0)² // FORMULA DA ESFERA

    int i,j,k;
    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
               if((pow(i-xcenter,2)+pow(j-ycenter,2)+pow(k-zcenter,2)) <= pow(radius,2)){
                    putVoxel(i,j,k);
               }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
     //Desativa todos os voxels que satisfazem à equação da esfera

    int i,j,k;
    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
               if((pow(i-xcenter,2)+pow(j-ycenter,2)+pow(k-zcenter,2)) <= pow(radius,2)){
                    cutVoxel(i,j,k);
               }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    //Ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho
    // (x²/a²)+(y²/b²)+(z²/c²) = 1

    int i,j,k;
    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
               if( ( (pow(i-xcenter,2))/pow(rx,2) + (pow(j-ycenter,2))/pow(ry,2) + (pow(k-zcenter,2))/pow(rz,2) ) <= 1 ){
                    putVoxel(i,j,k);
               }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
     //Desativa todos os voxels que satisfazem à equação do elipsóide
    int i,j,k;
    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
               if( ( (pow(i-xcenter,2))/pow(rx,2) + (pow(j-ycenter,2))/pow(ry,2) + (pow(k-zcenter,2))/pow(rz,2) ) <= 1 ){
                    cutVoxel(i,j,k);
               }
            }
        }
    }
}

void Sculptor::writeOFF(char *filename){
    //Grava a escultura no formato OFF no arquivo filename

    ofstream saida;

    fixed(saida);

    int aux = 0, cont=0;
    int i, j, k;

    saida.open(filename);

    if(saida.is_open()){
        cout << "Carregando...\n";
    }else{
        cout << "O arquivo OFF foi nao aberto\n";
        exit(1);
    }

    for(i=0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    cont++;
                }
            }
        }
    }

    saida << "OFF" << endl;
    saida << cont*8<< " " << cont*6 << " 0" << endl;

    for(i=0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    saida << i-0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                    saida << i-0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                    saida << i+0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                    saida << i+0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                    saida << i-0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                    saida << i-0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                    saida << i+0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                    saida << i+0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                }
            }
        }
    }

    for(i=0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    saida << "4 " << aux << " " << aux + 3 << " " << aux + 2 << " " << aux + 1 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    saida << "4 " << aux + 4 << " " << aux + 5 << " " << aux + 6 << " " << aux + 7 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    saida << "4 " << aux << " " << aux + 1 << " " << aux + 5 << " " << aux + 4 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    saida << "4 " << aux << " " << aux + 4 << " " << aux + 7 << " " << aux + 3 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    saida << "4 " << aux + 3 << " " << aux + 7 << " " << aux + 6 << " " << aux + 2 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    saida << "4 " << aux + 1 << " " << aux + 2 << " " << aux + 6 << " " << aux + 5 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    aux+=8;
                }
            }
        }
    }

    if(saida.is_open()){
        cout << "\nO arquivo.OFF foi salvo com sucesso!"<<endl;
    }
}
