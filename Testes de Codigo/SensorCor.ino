void lerCor(){
  //Função para ler cor
  X = sensorCorDireito.detectColor();
  Y = sensorCorEsquerdo.detectColor();

  Serial.print("X = ");
  Serial.print(X);
  Serial.print(" Y = ");
  Serial.println(Y); 
}

//Dentro da rotinha seguidor de linha

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