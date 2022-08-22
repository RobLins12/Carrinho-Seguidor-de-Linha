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

void lerDistancia() {
  F = sensorIR(irf);// sensorIR é uma função que retorna um inteiro
  R = sensorIR(irr);
  L = sensorIR(irl);

  
  Serial.print("F = ");
  Serial.print(F);
  Serial.print(" | R = ");
  Serial.print(R);
  Serial.print(" | L = ");
  Serial.println(L);
  

}

void lerCor(){
  //Função para ler cor
  X = sensorCorDireito.detectColor();
  Y = sensorCorEsquerdo.detectColor();

  /*
  Serial.print("X = ");
  Serial.print(X);
  Serial.print(" Y = ");
  Serial.println(Y);
  */ 
}

int sensorIR(int pino) {
  unsigned int distancia = 12 * pow((analogRead(pino) * 0.0048828125), -1);
  if (distancia < 5) {
    distancia = 5;
  } else if (distancia > 80) {
    distancia = 80;
  }
  return distancia;
}
