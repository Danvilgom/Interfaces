#include <stdlib.h>
#include <math.h>
#include "Bola.h"

int Bola::diametro;

Bola::Bola(float x, float y, float vx, float vy):
        posX(x), posY(y), velX(vx), velY(vy) {

          vida = vidaInicial;
          color = QColor(rand()%256,rand()%256,rand()%256);
}

void Bola::mueve(int anchura, int altura) {

  posX = posX + velX;
  posY = posY + velY;

  if (posX > anchura -40 ) {
    velX = -fabs(velX);
  }
  if (posY > altura -40) {
    velY = -fabs(velY);
  }

  if (posX < 0) {
    velX = fabs(velX);
  }
  if (posY < 25) {
    velY = fabs(velY);
  }
}

float Bola::distancia(Bola * otra){
  float dist;
  dist = sqrtf( powf((posX+diametro/2) - (otra->posX+otra->diametro/2),2) +
                powf((posY+diametro/2) - (otra->posY+otra->diametro/2),2 ) );
  return dist;
}

bool Bola::choca(Bola * otra) {
  if (this == otra) return false;
    if ( distancia (otra) >  ( diametro  + otra->diametro ) / 2  )
        return false;

    bool apuesta = false;
    Bola * izquierda, *derecha ;
    Bola * arriba, * abajo ;

    if (posX <  otra->posX )  {
        izquierda = this;
        derecha = otra;
    } else {
        izquierda = otra;
        derecha = this;
    }
    if (posY <  otra->posY )  {
        arriba = this;
        abajo = otra;
    } else {
        arriba = otra;
        abajo = this;
    }

    if ( izquierda->velX > derecha->velX ) {
        float aux = derecha->velX;
        derecha->velX=izquierda->velX;
        izquierda->velX = aux;
        apuesta = true;
    }
    if ( arriba->velY > abajo->velY ) {
        float aux = arriba->velY;
        arriba->velY = abajo->velY;
        abajo->velY = aux;
        apuesta = true;
    }

    return apuesta;
}

void Bola::pintar(QPainter& pintor){
    pintor.setBrush(color);
    pintor.drawEllipse(posX,posY,diametro,diametro);

    int  ancho = diametro;
    float anchoVerde= (((float)vida) / vidaInicial) * (float)ancho;
    float anchoRojo = (ancho - (float)anchoVerde);
    pintor.setBrush(Qt::green);
    pintor.drawRect(posX,posY,anchoVerde,3);
    pintor.setBrush(Qt::red);
    pintor.drawRect(posX + anchoVerde,posY,anchoRojo,3);

    pintor.drawText(posX+10,posY+25,QString::number(vida));
}
