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
