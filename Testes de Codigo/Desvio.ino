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