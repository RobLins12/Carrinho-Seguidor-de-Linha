#include <AFMotor.h>
AF_DCMotor Motor1 (3);
AF_DCMotor Motor2 (4);
int desbloqueio = 0;
bool teste = true;
int F, R, L;

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
int vel = 120; //valor da "velocidade" dos motor
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
  if (F >= 5 && F <= 8) {
    desvio();
  }
  seguidor();
}

void lerSensorDeLinha() {
  A = digitalRead(L1);
  B = digitalRead(L2);
  C = digitalRead(L3);
  D = digitalRead(L4);
  Serial.print("A = ");
    Serial.print(A);
    Serial.print(" | B = ");
    Serial.print(B);
    Serial.print(" | C = ");
    Serial.print(C);
    Serial.print(" | D = ");
    Serial.println(D);
 
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
      delay(10);
      desbloqueio++;
    }
  }
  if (A == 0 && B == 1 && C == 1 && D == 1) {
    desbloqueio = 0;
    while (!(A == 0 && B == 0 && C == 0 && D == 0) || desbloqueio == 20) {
      frente();
      desbloqueio++;
    }
    desbloqueio = 0;
    while (C == 0 || desbloqueio < 20) {
      esquerda2();
      desbloqueio++;
    }
  }
  if (A == 1 && B == 1 && C == 0 && D == 0) {
    desbloqueio = 0;
    while (!(A == 0 && B == 0 && C == 0 && D == 0) || desbloqueio == 20) {
      frente();
      desbloqueio++;
    }
    desbloqueio = 0;
    while (C == 0 || desbloqueio < 20) {
      direita2();
      desbloqueio++;
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
//Sem uso no momento

void lerDistancia() {
  F = sensorIR(irf);// sensorIR é uma função que retorna um inteiro
  R = sensorIR(irr);
  L = sensorIR(irl);
  /*
   Serial.print("F = ");
  Serial.print(F);
  Serial.print(" | R = ");
  Serial.print(R);
  Serial.print(" | L = ");
  Serial.println(L);
  */
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

void arcoDireita() {
  Motor1.setSpeed(60);
  Motor2.setSpeed(120);
  Motor1.run(BACKWARD);
  Motor2.run(FORWARD);
  delay(10);
  lerSensorDeLinha();
  lerDistancia();
}

void arcoDireita2() {
  Motor1.setSpeed(40);
  Motor2.setSpeed(200);
  Motor1.run(FORWARD);
  Motor2.run(FORWARD);
  delay(10);
  lerSensorDeLinha();
  lerDistancia();
}

void desvio() {
  lerDistancia();
  if (F < 8) {
    while (F < 9) {
      tras();
    }
    parar();
    while (R > 12) {
      esquerda();
    }
    parar();
    while (R <= 15) {
      //frente();
      arcoDireita2();
      if (R > 15) {
        arcoDireita2();
        delay(25);
      }
    }
    parar();
    arcoDireita();
    delay(800);
    arcoDireita2();
    delay(200);
    while (!(A == 1)) {
      arcoDireita();
      //--------------------------------------------
      if (A == 1 || B == 1 || C == 1 || D == 1) {
        desbloqueio = 0;
        while (!(A == 0 && B == 0 && C == 0 && D == 0) || desbloqueio == 20) {
          frente();
          desbloqueio++;
        }
        desbloqueio = 0;
        while (B == 0 || desbloqueio == 20) {
          esquerda2();// 90 graus
          desbloqueio++;
          if (B == 1 || C == 1 || D == 1) {
            break;
          }
        }
        parar();
        seguidor();
        break;
      }
      //-------------------------------------------------------------
    }
    parar();
    seguidor();
  }
}

int lado()
{
  int aleatorio = random(1, 1000);
  if (aleatorio % 2 == 0) {
    aleatorio = 2;
  } else if (aleatorio % 2 == 1) {
    aleatorio = 1;
  }
  Serial.println(aleatorio);
  return aleatorio;
}