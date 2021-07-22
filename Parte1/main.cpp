#include <iostream>
#include "sculptor.h"

using namespace std;

int main()
{
    int x=100, y=100, z=100;
    Sculptor *TECLADO;
    //Sculptor  *TESTEB;
    //TESTEB = new Sculptor(x,y,z);
    TECLADO = new Sculptor(x,y,z);

    TECLADO->setColor(0,0,0,1.0); //preto
    TECLADO->putBox(0,53,0,20,0,6); //base
    TECLADO->cutBox(3,50,0,10,0,3); //corte
    TECLADO->setColor(1,1,1,1.0); // branco
    TECLADO->putBox(3,50,0,10,2,3); //teclas brancas
    TECLADO->setColor(0,0,0,1.0); // preto

    //# teclas pretas
    TECLADO->putBox(49,49,4,10,1,2);
    TECLADO->putBox(47,47,4,10,1,2);

    TECLADO->putBox(44,44,4,10,1,2);
    TECLADO->putBox(42,42,4,10,1,2);
    TECLADO->putBox(40,40,4,10,1,2);

    TECLADO->putBox(37,37,4,10,1,2);
    TECLADO->putBox(35,35,4,10,1,2);

    TECLADO->putBox(32,32,4,10,1,2);
    TECLADO->putBox(30,30,4,10,1,2);
    TECLADO->putBox(28,28,4,10,1,2);

    TECLADO->putBox(25,25,4,10,1,2);
    TECLADO->putBox(23,23,4,10,1,2);

    TECLADO->putBox(20,20,4,10,1,2);
    TECLADO->putBox(18,18,4,10,1,2);
    TECLADO->putBox(16,16,4,10,1,2);

    TECLADO->putBox(13,13,4,10,1,2);
    TECLADO->putBox(11,11,4,10,1,2);

    TECLADO->putBox(8,8,4,10,1,2);
    TECLADO->putBox(6,6,4,10,1,2);
    TECLADO->putBox(4,4,4,10,1,2);

    //display
    TECLADO->cutBox(21,32,14,17,0,0);
    TECLADO->setColor(0.1,0.1,0.5,1.0);
    TECLADO->putBox(21,32,14,17,1,1);

    //botons
    TECLADO->setColor(1,1,1,1.0); //branco
    TECLADO->putBox(17,18,17,18,0,0);
    TECLADO->putBox(17,18,14,15,0,0);
    TECLADO->setColor(0.2,1,1,1.0); //turquesa
    TECLADO->putBox(17,18,12,12,0,0);

    //saida de som
    TECLADO->cutBox(3,14,19,19,0,0);
    TECLADO->setColor(0.1,0.1,0.1,1.0);
    TECLADO->putBox(3,14,19,19,1,1);
    TECLADO->cutBox(39,50,19,19,0,0);
    TECLADO->putBox(39,50,19,19,1,1);

    //Botons rosa
    TECLADO->setColor(1,0.5,0.5,1.0);
    TECLADO->putVoxel(15,17,0);
    TECLADO->putVoxel(13,17,0);
    TECLADO->putVoxel(11,17,0);
    TECLADO->putVoxel(15,15,0);
    TECLADO->putVoxel(13,15,0);
    TECLADO->putVoxel(11,15,0);
    TECLADO->putVoxel(15,13,0);
    TECLADO->putVoxel(13,13,0);
    TECLADO->putVoxel(11,13,0);

    //Entradas p cabos
    TECLADO->setColor(0.8,0.1,0.1,1.0);
    TECLADO->cutVoxel(30,20,2);
    TECLADO->putVoxel(30,19,2);
    TECLADO->cutVoxel(28,20,2);
    TECLADO->putVoxel(28,19,2);
    TECLADO->cutVoxel(26,20,2);
    TECLADO->putVoxel(26,19,2);
    TECLADO->cutVoxel(24,20,2);
    TECLADO->putVoxel(24,19,2);

    TECLADO->putBox(50,51,17,17,0,0);

    TECLADO->setColor(1,1,1,1.0);
    TECLADO->putBox(47,48,16,16,0,0);
    TECLADO->putBox(47,48,14,14,0,0);
    TECLADO->putBox(47,48,12,12,0,0);

    TECLADO->setColor(0.2,1,1,1.0); //turquesa
    TECLADO->putBox(44,45,16,17,0,0);
    TECLADO->putBox(44,45,13,14,0,0);

    TECLADO->setColor(1,1,1,1.0); //branco
    TECLADO->putBox(41,42,16,16,0,0);
    TECLADO->putBox(41,42,14,14,0,0);
    TECLADO->putBox(41,42,12,12,0,0);

    TECLADO->setColor(0.2,1,1,1.0); //turquesa
    TECLADO->putBox(38,39,16,17,0,0);
    TECLADO->putBox(38,39,13,14,0,0);

    TECLADO->setColor(0.2,0.8,0.8,1.0);
    TECLADO->putBox(7,8,16,16,0,0);
    TECLADO->putBox(7,8,14,14,0,0);
    TECLADO->putBox(4,5,16,16,0,0);
    TECLADO->putBox(4,5,14,14,0,0);


    //y
    TECLADO->setColor(1,1,1,1.0); //branco
    TECLADO->putBox(0,0,2,3,3,3);
    TECLADO->putBox(0,0,4,5,2,2);
    TECLADO->putBox(0,0,4,5,4,4);




    // TESTAR OUTRAS FUNÇOES
    /*TESTEB->putBox(0,53,0,20,10,16); //BASE
    TESTEB->setColor(1, 0, 0, 1.0); //black
    TESTEB->putSphere(30, 5, 10, 5);
    //TESTEB->cutSphere(30, 5,10 , 5);
    TESTEB->setColor(0, 1, 0, 1.0); //
    TESTEB->putEllipsoid(15, 12, 8, 4, 5, 6);
    //TESTEB->cutEllipsoid(15, 12, 8, 4, 5, 6);*/

    TECLADO->writeOFF("TECLADO.off");
    //TESTEB->writeOFF("TESTEB.off");

    return 0;
}
