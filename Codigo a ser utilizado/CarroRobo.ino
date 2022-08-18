#include <ColorDetector.h>
#include <AFMotor.h>

//Define os motores com nome Motor1 e Motor2
AF_DCMotor Motor1 (3); 
AF_DCMotor Motor2 (4);

//Define os pinos para o sensor de cor
ColorD sensorCorDireito(26, 27, 30, 31, 32);
ColorD sensorCorEsquerdo(29, 28, 33, 34, 35);

int desbloqueio = 0; //Servirá mais pra frente para n travar o carro
bool teste = true;

int F, R, L, X, Y; //Variáveis para utilizar o sensor de distância infravermelho

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
int vel = 110; //valor da "velocidade" dos motor
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
  Motor1.setSpeed(vel);// definir a velocidade dos motores
  Motor2.setSpeed(vel);
}

void loop() {
  lerSensorDeLinha();
  lerDistancia();
  if (F == 5) {
    lado();
  }
  seguidor();
}

void lerSensorDeLinha() {
  A = digitalRead(L1);
  B = digitalRead(L2);
  C = digitalRead(L3);
  D = digitalRead(L4);
  /*
  Serial.print("A = ");
    Serial.print(A);
    Serial.print(" | B = ");
    Serial.print(B);
    Serial.print(" | C = ");
    Serial.print(C);
    Serial.print(" | D = ");
    Serial.println(D);
 */
}

void lerCor(){
  //Função para ler cor
  X = sensorCorDireito.detectColor();
  Y = sensorCorEsquerdo.detectColor();

  Serial.print("X = ");
  Serial.print(X);
  Serial.print(" Y = ");
  Serial.println(Y); 
}

void lado(){
    int maior = lerDistancia();
    if(maior == 1){
        desvioEsquerda();
    }
    if(maior == 2){
        desvioDireita();
    }
}

int lerDistancia() {
  int maior;
  F = sensorIR(irf);// sensorIR é uma função que retorna um inteiro
  R = sensorIR(irr);
  L = sensorIR(irl);
  
  if(R > L){
    maior = 1;
  }

  if(L > R){
    maior = 2;
  }

  if(R == L){
    maior = 2;
  }

  /*
  Serial.print("F = ");
  Serial.print(F);
  Serial.print(" | R = ");
  Serial.print(R);
  Serial.print(" | L = ");
  Serial.println(L);
  */
  return maior;

}

//Função para ler as distâncias

int sensorIR(int pino) {
  unsigned int distancia = 12 * pow((analogRead(pino) * 0.0048828125), -1);
  if (distancia < 5) {
    distancia = 5;
  } else if (distancia > 80) {
    distancia = 80;
  }
  return distancia;
}

void parar() {
  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  lerSensorDeLinha();
  lerDistancia();
}

void frente() {
  Motor1.setSpeed(vel);
  Motor2.setSpeed(vel);
  Motor1.run(FORWARD);
  Motor2.run(FORWARD);
  lerSensorDeLinha();
  lerDistancia();
}

void tras() {
  Motor1.setSpeed(vel);
  Motor2.setSpeed(vel);
  Motor1.run(BACKWARD);
  Motor2.run(BACKWARD);
  lerSensorDeLinha();
  lerDistancia();
}

void esquerda() {
  Motor1.setSpeed(vel + limiar);
  Motor2.setSpeed(vel - limiar);
  Motor1.run(FORWARD);
  Motor2.run(BACKWARD);
  lerSensorDeLinha();
  lerDistancia();
}

void direita() {
  Motor1.setSpeed(vel - limiar);
  Motor2.setSpeed(vel + limiar);
  Motor1.run(BACKWARD);
  Motor2.run(FORWARD);
  lerSensorDeLinha();
  lerDistancia();
}

void direita2() {
  Motor1.setSpeed(vel);
  Motor2.setSpeed(vel);
  Motor1.run(BACKWARD);
  Motor2.run(FORWARD);
  lerSensorDeLinha();
  lerDistancia();
}

void esquerda2() {
  Motor1.setSpeed(vel);
  Motor2.setSpeed(vel);
  Motor1.run(FORWARD);
  Motor2.run(BACKWARD);
  lerSensorDeLinha();
  lerDistancia();
}

void seguidor() {
  lerSensorDeLinha();
  lerCor();

  if(X == 3 && Y != 3){
    parar();
    delay(50);
    if(C == 1 || D == 1){
      esquerda2();
      delay(2000);
      }
  }

  if(X != 3 && Y == 3){
    parar();
    delay(50);
    if(A == 1 || B == 1){
      direita2();
      delay(2000);
      }
  }

  if(X == 3 && Y == 3){
    parar();
    while(!(A == 0 && B == 0 && C == 0 && D == 0)){
      frente();  
    }
    while(C == 0 || B == 0){
      direita2();
      }
  }
  
  if ((A == 0 && B == 0 && C == 0 && D == 0) || (A == 1 && B == 1 && C == 1 && D == 1)) {
    frente();
  }

  if (A == 0 && B == 0 && C == 1 && D == 1) {
    desbloqueio = 0;
    while (!(A == 0 && B == 0 && C == 0 && D == 0) || desbloqueio == 20) {
      frente();
      desbloqueio++;
    }
    desbloqueio = 0;
    while (B == 0 || desbloqueio < 20) {
      esquerda2(); // 90 graus;
      desbloqueio++;
    }
  }

  if (A == 0 && B == 1 && C == 1 && D == 1) {
    while (B == 0) {
      esquerda2();
    }
  }

  if (A == 1 && B == 1 && C == 0 && D == 0) {
    while (C == 0) {
      direita2();
    }
  }

  if (A == 1 && B == 1 && C == 1 && D == 0) {
    desbloqueio = 0;
    while (!(A == 0 && B == 0 && C == 0 && D == 0) || desbloqueio == 20) {
      frente();
      desbloqueio++;
    }
    desbloqueio = 0;
    while (B == 0 || desbloqueio < 20) {
      direita2();// 90 graus
      desbloqueio++;
    }
  }
  
  if ((A == 1 && B == 0 && C == 0 && D == 0) || (A == 0 && B == 1 && C == 0 && D == 0)) {
    direita();
  }
  if ((A == 0 && B == 0 && C == 0 && D == 1) || (A == 0 && B == 0 && C == 1 && D == 0)) {
    esquerda();
  }
}

void desvioDireita() {
    lerDistancia();
    parar();

    //recuo
    tras();
    delay(700);
    parar();

    //giro 90° a direita
    direita2();
    delay(1800);
    parar();

    //frente por meio segundo
    frente();
    delay(1800);
    parar();

    //girar 90° a esquerda
    esquerda2();
    delay(1800);
    parar();

    //ir para frente
    frente();
    delay(2800);
    parar();

    //girar 90° a equerda
    esquerda2();
    delay(1800);
    parar();

    //ir para frente
    while(A != 1 || B != 1 || C != 1 || D != 1){
      frente();
    }
    frente();
    delay(70);
    parar();

    //Girar 90° a direita
    
    lerSensorDeLinha();
    while(C == 0){
      direita2();
     }
    lerDistancia();
}

void desvioEsquerda(){

  tras ();
  delay(700);
  parar();
  
  esquerda2();
  delay(1800);
  parar();
  
  frente();
  delay(1750);
  parar();
  
  direita2();
  delay(1800);
  parar();
  
  frente();
  delay(3500);
  parar();
  
  direita2();
  delay(1800);
  parar();
  
  //ir para frente
    while(A != 1 || B != 1 || C != 1 || D != 1){
      frente();
    }
    frente();
    delay(70);
    parar();

  
  lerSensorDeLinha();
  while(B == 0){
    esquerda2();
  }
  
  lerDistancia();
 }