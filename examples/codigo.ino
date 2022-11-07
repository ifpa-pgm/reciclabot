#include <ReciclaBot.h>

ReciclaBot robo;
/*
 1 - Buscar inimigo
 2 - Atacar
*/
int estado = 0;
void setup() {
  robo.configurarPinoSensorLinha(3);
  robo.configurarPinoSensorDistancia(13, 12);
  robo.configurarPinosMotor1(6, 7);
  robo.configurarPinosMotor2(9, 10);
  Serial.begin(9600);
}

void loop() {
  if (robo.refletiuLuz()) {//VOLTAR P ARENA
    robo.recuar(255);
    delay(100);
  }


  if (estado == 1) {  //busca inimigo
    robo.avancar(120);
    delay(100);

    robo.girar(200);
    delay(100);

    robo.avancar(120);
    delay(100);

    robo.girar(-200);
    delay(100);
  }
  if (robo.distancia() <= 20) {  // Achou inimigo
    estado = 2;
  } else {  // continuar procurando
    estado = 1;
  }

  if (estado == 2) {  //Atacar
    robo.avancar(255);
    delay(100);
  }
}