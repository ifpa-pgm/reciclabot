
#include "Arduino.h"
#include "ReciclaBot.h"

ReciclaBot::ReciclaBot()
{
}

void ReciclaBot::configurarPinosMotor1(int pinoRecuo,int pinoAvanco)
{
    pinMode(pinoAvanco, OUTPUT);
    pinMode(pinoRecuo, OUTPUT);
    this->pinoMotor1avanco = pinoAvanco;
    this->pinoMotor1recuo = pinoRecuo;
}

void ReciclaBot::configurarPinosMotor2(int pinoRecuo,int pinoAvanco)
{
    pinMode(pinoAvanco, OUTPUT);
    pinMode(pinoRecuo, OUTPUT);
    this->pinoMotor2avanco = pinoAvanco;
    this->pinoMotor2recuo = pinoRecuo;
}

void ReciclaBot::configurarPinoSensorLinha(int pino)
{

    this->pinoSensorLinha = pino;
    pinMode(this->pinoSensorLinha, INPUT);
}

void ReciclaBot::configurarPinoSensorDistancia(int pinoTrigger, int pinoEcho)
{
    this->pinoTrigger = pinoTrigger;
    this->pinoEcho = pinoEcho;
    pinMode(this->pinoTrigger, OUTPUT);
    pinMode(this->pinoEcho, INPUT);
}

int ReciclaBot::distancia()
{
    // Using the approximate formula 19.307°C results in roughly 343m/s which is the commonly used value for air.
    return distancia(19.307);
}

int ReciclaBot::distancia(float temperatura)
{
    if (this->pinoTrigger < 1 || this->pinoTrigger > 13)
    {
        Serial.println("Valores para os pinos do sensor de distancia invalidos.");
        return -1;
    }
    if (this->pinoEcho < 1 || this->pinoEcho > 13)
    {
        Serial.println("Valores para os pinos do sensor de distancia invalidos.");
        return -1;
    }

    digitalWrite(this->pinoTrigger, LOW);
    delayMicroseconds(2);
    digitalWrite(this->pinoTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->pinoTrigger, LOW);

    unsigned long duracaoPulso = pulseIn(pinoEcho, HIGH);

    double velocidadeDoSomEmCmMs = 0.03313 + 0.0000606 * temperatura;
    double distanciaCm = duracaoPulso / 2.0 * velocidadeDoSomEmCmMs;
    // if (distanciaCm == 0 || distanciaCm > 400) {
    if (distanciaCm > 400)
    {
        return -1;
    }
    else
    {
        return (int)distanciaCm;
    }
}

bool ReciclaBot::refletiuLuz()
{
    if (this->pinoSensorLinha < 1 || this->pinoSensorLinha > 13)
    {
        Serial.println("Valor para os pino do sensor seguidor de linha invalidos.");
        exit(-1);
    }

    if (digitalRead(this->pinoSensorLinha) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool ReciclaBot::absorveuLuz(){
    if (this->pinoSensorLinha < 1 || this->pinoSensorLinha > 13)
    {
        Serial.println("Valor para os pino do sensor seguidor de linha invalidos.");
        exit(-1);
    }

  
    return digitalRead(this->pinoSensorLinha) ;
     
}


void ReciclaBot::avancar(int velocidade)
{

   // double velocidade = 0.02166;
    //double tempo = distancia / velocidade;

    //unsigned long currentMillis = millis();
    

    //if (currentMillis - this->tempoInicial >= (tempo)) {

     //this->tempoInicial = currentMillis;


        digitalWrite(this->pinoMotor1avanco, velocidade);
        digitalWrite(this->pinoMotor1recuo, LOW);
        digitalWrite(this->pinoMotor2avanco, velocidade);
        digitalWrite(this->pinoMotor2recuo, LOW);

   
 //   }

}

void ReciclaBot::recuar(int velocidade)
{


   // double velocidade = 0.02166;
    //double tempo = distancia / velocidade;

    //unsigned long currentMillis = millis();
    //Serial.println(tempo);
    //if (currentMillis - this->tempoInicialRecuo >= (tempo)) {

   //  this->tempoInicialRecuo = currentMillis;


        digitalWrite(this->pinoMotor1avanco, LOW);
        digitalWrite(this->pinoMotor1recuo, velocidade);
        digitalWrite(this->pinoMotor2avanco, LOW);
        digitalWrite(this->pinoMotor2recuo, velocidade);

   
  //  } 


}
void ReciclaBot::girar(int velocidade)
{
    // double velocidade = 5.83333;
  //  double tempo = graus * velocidade;
   

    //unsigned long currentMillis = millis();

   // if (currentMillis - this->tempoInicialCurva >= tempo) {

    // this->tempoInicialCurva = currentMillis;
        if (velocidade > 0)
        {
            digitalWrite(this->pinoMotor1avanco, LOW);
            digitalWrite(this->pinoMotor1recuo, velocidade);
            digitalWrite(this->pinoMotor2avanco, velocidade);
            digitalWrite(this->pinoMotor2recuo, LOW);
            

        }else
        {
            velocidade = velocidade * -1;

            digitalWrite(this->pinoMotor1avanco, velocidade);
            digitalWrite(this->pinoMotor1recuo, LOW);
            digitalWrite(this->pinoMotor2avanco, LOW);
            digitalWrite(this->pinoMotor2recuo, velocidade);
        }

 
   
    //}

  
}

void ReciclaBot::parar()
{
    digitalWrite(this->pinoMotor1avanco, LOW);
    digitalWrite(this->pinoMotor1recuo, LOW);
    digitalWrite(this->pinoMotor2avanco, LOW);
    digitalWrite(this->pinoMotor2recuo, LOW);
    //delay(100);
}