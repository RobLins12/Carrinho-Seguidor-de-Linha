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

  Serial.print("F = ");
  Serial.print(F);
  Serial.print(" | R = ");
  Serial.print(R);
  Serial.print(" | L = ");
  Serial.println(L);

  return maior;

}