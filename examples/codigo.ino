#include <ReciclaBot.h>

ReciclaBot robo;
/*
 0 - Voltar para arena
 1 - Buscar inimigo
 2 - Atacar
*/
int estado = 0;
void setup() {
  robo.configurarPinoSensorLinha(11);
  robo.configurarPinoSensorDistancia(13, 12);
  robo.configurarPinosMotor1(4, 5);
  robo.configurarPinosMotor2(6, 7);
}

void loop() {
  if(!robo.refletiuLuz()){
    robo.girar(90);//graus
    robo.avancar(20);//cm
    robo.girar(90);
    robo.avancar(20);

    estado = 1;
  }

  if(estado==1){//busca
    robo.girar(45);

    if(robo.distancia() <= 20){
      estado = 2;
    }
  }

  if(estado==2){//ataque
    robo.avancar(80);
  }
}