/*

*/
#include "Arduino.h"

#ifndef ReciclaBot_H
#define ReciclaBot_H


class ReciclaBot {
 public:
    /**
     * 
     */
    ReciclaBot();

void configurarPinoSensorLinha(int pino);
void configurarPinoSensorDistancia(int pinoTrigger,int pinoEcho);
void configurarMotores(int pinoM1avanco, int pinoM1recuo, int pinoM2avanco, int pinoM2recuo);

    /**
     * Mensura a distância do sensor a um obstáculo. 
     * @return distância em centímetros.
     */
    int distancia();

    /**
     * Mensura a distância do sensor a um obstáculo. 
     * 
     * @param temperatura  Temperatura em graus celcius
     * @return distância em centímetros.
     */
    int distancia(float temperatura);

    void avancar(int distancia);
    void recuar(int distancia);
    void girar(int graus);
    boolean refletiuLuz();



 private:
    int pinoTriguer, pinoEcho, pinoSensorLinha;
    int pinoMotor1avanco;
    int pinoMotor1recuo;
    int pinoMotor2avanco;
    int pinoMotor2recuo;
};

#endif // ReciclaBot_H