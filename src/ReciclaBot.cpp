
#include "Arduino.h"
#include "ReciclaBot.h"

ReciclaBot::ReciclaBot()
{
   // pinMode(pinoTrigger, OUTPUT);
    //pinMode(pinoEcho, INPUT);
    //pinMode(pinoSensorLinha, INPUT);
}


ReciclaBot::configurarPinoSensorLinha(int pino)

    this->pinoSensorLinha = pino;
    pinMode(this->pinoSensorLinha, INPUT);
}

ReciclaBot::configurarPinoSensorDistancia(int pinoTriguer, int pinoEcho)

    this->pinoTriguer = pinoTriguer;
    this->pinoEcho = pinoEcho;
    pinMode(this->pinoTriguer, OUTPUT);
    pinMode(this->pinoEcho, INPUT);
}


int ReciclaBot::distancia()
{
    // Using the approximate formula 19.307°C results in roughly 343m/s which is the commonly used value for air.
    return distancia(19.307);
}

int ReciclaBot::distancia(float temperatura)
{
   if(this->pinoTriguer < 1 || this->pinoTriguer > 13 ){
       Serial.println("Valores para os pinos do sensor de distancia invalidos.");
       return ;
   }
      if(this->pinoEcho < 1 || this->pinoEcho > 13 ){
       Serial.println("Valores para os pinos do sensor de distancia invalidos.");
       return ;
   }
   
   
    digitalWrite(pinoTrigger, LOW);
    delayMicroseconds(2);
    digitalWrite(pinoTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinoTrigger, LOW);

    unsigned long duracaoPulso = pulseIn(pinoEcho, HIGH);

    double velocidadeDoSomEmCmMs = 0.03313 + 0.0000606 * temperatura;
    double distanciaCm = duracaoPulso / 2.0 * velocidadeDoSomEmCmMs;
    // if (distanciaCm == 0 || distanciaCm > 400) {
    if (distanciaCm > 400)
    {
        return -1.0;
    }
    else
    {
        return (int)distanciaCm;
    }
}

boolean ReciclaBot::refletiuLuz()
{
  if(this->pinoSensorLinha < 1 || this->pinoSensorLinha > 13 ){
      Serial.println("Valor para os pino do sensor seguidor de linha invalidos.");
      return ;
  }


    if (digitalRead(pinoSensorLinha) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ReciclaBot::avancar()
{
    analogWrite(pinoMotor1avanco, 0);
    analogWrite(pinoMotor1recuo, 255);
    analogWrite(pinoMotor2avanco, 255);
    analogWrite(pinoMotor2recuo, 0);
}

void ReciclaBot::recuar()
{
   analogWrite(pinoMotor1avanco, 255);
   analogWrite(pinoMotor1recuo, 0);
   analogWrite(pinoMotor2avanco, 0);
   analogWrite(pinoMotor2recuo, 255);
}
void girar(int graus)
{
    if (graus > 0)
    {
     analogWrite(pinoMotor1avanco, 255);
     analogWrite(pinoMotor1recuo, 0);
     analogWrite(pinoMotor2avanco, 255);
     analogWrite(pinoMotor2recuo, 0);
    }
    else
    {
     analogWrite(pinoMotor1avanco, 0);
     analogWrite(pinoMotor1recuo, 255);
     analogWrite(pinoMotor2avanco, 0);
     analogWrite(pinoMotor2recuo, 255);
    }
}

void parar()
{
    analogWrite(pinoMotor1avanco, 0);
    analogWrite(pinoMotor1recuo, 0);
    analogWrite(pinoMotor2avanco, 0);
    analogWrite(pinoMotor2recuo, 0);
}