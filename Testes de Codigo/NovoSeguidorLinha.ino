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
    desbloqueio = 0;
    while (!(A == 0 && B == 0 && C == 0 && D == 0) || desbloqueio == 20) {
      frente();
      desbloqueio++;
    }
    desbloqueio = 0;
    while (B == 0 || desbloqueio < 20) {
      direita();
      desbloqueio++;
    }
  }
  if ((A == 0 && B == 0 && C == 0 && D == 1) || (A == 0 && B == 0 && C == 1 && D == 0)) {
    desbloqueio = 0;
    while (!(A == 0 && B == 0 && C == 0 && D == 0) || desbloqueio == 20) {
      frente();
      desbloqueio++;
    }
    desbloqueio = 0;
    while (B == 0 || desbloqueio < 20) {
      esquerda();
      desbloqueio++;
    }
  }
}