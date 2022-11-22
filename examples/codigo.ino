#include <ReciclaBot.h>

ReciclaBot robo;

void setup() {
  robo.configurarPinoSensorLinha(3);
  robo.configurarPinoSensorDistancia(13, 12);
  robo.configurarPinosMotor1(6, 7);
  robo.configurarPinosMotor2(9, 10);
  Serial.begin(9600);
}

void loop() {
  if (robo.refletiuLuz()) {  //Voltar para arena
    robo.recuar(255);
    delay(100);
    
  } else if (robo.distancia() <= 20) {  //atacar
    robo.avancar(255);
    delay(100);

  } else {  //busca inimigo
    robo.avancar(120);
    delay(200);

    robo.girar(200);
    delay(200);

    robo.avancar(120);
    delay(200);

    robo.girar(-200);
    delay(200);
  }
}
