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

    /**
     * Mensura a distância do sensor a um obstáculo. 
     * @return distância em centímetros.
     */
    float distanciaAdversario();

    /**
     * Mensura a distância do sensor a um obstáculo. 
     * 
     * @param temperatura  Temperatura em graus celcius
     * @return distância em centímetros.
     */
    float distanciaAdversario(float temperatura);

    void avancar(int distancia);
    void recuar(int distancia);
    void girar(int graus);
    boolean estaNaBorda();



 private:
    int pinoTriguer, pinoEcho, pinoSensorLinha;
    int pinoMotor1avanco;
    int pinoMotor1recuo;
    int pinoMotor2avanco;
    int pinoMotor2recuo;
};

#endif // ReciclaBot_H