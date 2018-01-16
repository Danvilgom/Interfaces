#ifndef _BOLA_H
#define _BOLA_H
#include <QColor>
#include <QPainter>
#include <QBrush>

class Bola {

public:

    static int diametro;
    const static int vidaInicial = 100;
    int vida;

    Bola(float x, float y, float vx, float vy);
    void mueve(int, int);

    float posX, posY, velX, velY;
    void pintar(QPainter &);
    QColor color;

    float distancia(Bola *);
    bool choca(Bola *);
};

#endif
