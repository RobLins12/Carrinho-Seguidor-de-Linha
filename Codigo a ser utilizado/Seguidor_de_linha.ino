#include <Servo.h>
#include <ColorDetector.h>
#include <AFMotor.h>

//Microservos para resgate
Servo servo1;
Servo servo2;

//Define os motores com nome Motor1 e Motor2
AF_DCMotor Motor1 (3); 
AF_DCMotor Motor2 (4);

//Define os pinos para o sensor de cor
ColorD sensorCorDireito(26, 27, 30, 31, 32);
ColorD sensorCorEsquerdo(29, 28, 33, 34, 35);

int desbloqueio = 0; //Servirá mais pra frente para n travar o carro
bool teste = true;

int F, R, L, X, Y; //Variáveis para utilizar o sensor de distância infravermelho e de cor

//Seguidor de linha
#define L1 22
#define L2 23
#define L3 24
#define L4 25
#define aux 30// Vê para que serve essa porta?

//Sensor IR - Distância
#define irf A8 // sensor para medir a distancia do obstaculo frente
#define irr A9// direita
#define irl A10//esquerda

int limiar = 30;
int vel = 115; //valor da "velocidade" dos motor
byte A, B, C, D; //Receber a leitura do sensor ifr seguidor de linha
// 1- Preto e 0 - Branco

void setup() {
  Serial.begin(9600);
  pinMode(L1, INPUT);
  pinMode(L2, INPUT);
  pinMode(L3, INPUT);
  pinMode(L4, INPUT);
  pinMode(irf, INPUT);
  pinMode(irr, INPUT);
  pinMode(irl, INPUT);
  servo1.attach(40);
  servo2.attach(41);
  Motor1.setSpeed(vel);// definir a velocidade dos motores
  Motor2.setSpeed(vel);

  //Verificação dos servos
  sobeGuarra();
  
}

void loop() {
  lerSensorDeLinha();
  lerDistancia();
  if (F == 5) {
    desvio();
  }
  if(L < 15 && R < 15){
    rampa();
  }
  seguidor();
}
