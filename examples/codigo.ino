#include <ReciclaBot.h>

ReciclaBot robo;
/*
 0 - Voltar para arena
 1 - Buscar inimigo
 2 - Atacar
*/
int estado = 0;
void setup() {
  robo.configurarPinoSensorLinha(3);
  robo.configurarPinoSensorDistancia(13, 12);
  robo.configurarPinosMotor1(6, 7);
  robo.configurarPinosMotor2(9, 10);
}

void loop() {
  if(robo.refletiuLuz()){
    robo.girar(90);//graus
    robo.avancar(10);//cm
    robo.girar(90);
    robo.avancar(10);

    estado = 1;
  }

  if(estado==1){//busca inimigo
    robo.girar(45);

    if(robo.distancia() <= 20){
      estado = 2;
    }
  }

  if(estado==2){//Atacar
    robo.avancar(80);
  }
}