
#include "Arduino.h"
#include "ReciclaBot.h"

ReciclaBot::ReciclaBot()
{
    pinMode(pinoTrigger, OUTPUT);
    pinMode(pinoEcho, INPUT);
    pinMode(pinoSensorLinha, INPUT);
}

float ReciclaBot::distanciaAdversario()
{
    // Using the approximate formula 19.307°C results in roughly 343m/s which is the commonly used value for air.
    return distanciaAdversario(19.307);
}

float ReciclaBot::distanciaAdversario(float temperatura)
{
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
        return distanciaCm;
    }
}

boolean ReciclaBot::estaNaBorda()
{
    if (digitalRead(pinoSensor) == 0)
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