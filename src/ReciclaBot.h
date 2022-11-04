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

    void avancar(int distancia);
    void recuar(int distancia);
    void girar(int graus);
    void parar();
    bool refletiuLuz();
    bool absorveuLuz();



 private:
    int pinoTrigger, pinoEcho, pinoSensorLinha;
    int pinoMotor1avanco;
    int pinoMotor1recuo;
    int pinoMotor2avanco;
    int pinoMotor2recuo;
    int tempoInicial = 0;
    int tempoInicialCurva = 0;
    int tempoInicialRecuo = 0;
    
 };

#endif // ReciclaBot_H