#include <stdlib.h>
#include <math.h>
#include "Bola.h"

int Bola::diametro;

Bola::Bola(float x, float y, float vx, float vy):
        posX(x), posY(y), velX(vx), velY(vy) {
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
  if (posY < 0) {
    velY = fabs(velY);
  }
}
