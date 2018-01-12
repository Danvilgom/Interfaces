#ifndef _BOLA_H
#define _BOLA_H

class Bola {

public:
    Bola(float x, float y, float vx, float vy);
    float posX, posY, velX, velY;
    void mueve(int, int);
    static int diametro;
};

#endif
