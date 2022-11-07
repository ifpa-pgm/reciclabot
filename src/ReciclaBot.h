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
void configurarPinosMotor1(int pinoRecuo,int pinoAvanco);
void configurarPinosMotor2(int pinoRecuo,int pinoAvanco);

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

    void avancar(int velociadade);
    void recuar(int velociadade);
    void girar(int velocidade);
    void parar();
    bool refletiuLuz();
    bool absorveuLuz();



 private:
    int pinoTrigger, pinoEcho, pinoSensorLinha;
    int pinoMotor1avanco;
    int pinoMotor1recuo;
    int pinoMotor2avanco;
    int pinoMotor2recuo;
    unsigned long tempoInicial = 0;
    unsigned long tempoInicialCurva = 0;
    unsigned long tempoInicialRecuo = 0;
    
 };

#endif // ReciclaBot_H