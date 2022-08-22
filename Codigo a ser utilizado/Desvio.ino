void desvio() {
    lerDistancia();
    parar();

    //recuo
    tras();
    delay(500);
    parar();

    //giro 90° a direita
    direita2();
    delay(1800);
    parar();

    //frente por meio segundo
    frente();
    delay(1500);
    parar();

    //girar 90° a esquerda
    esquerda2();
    delay(1800);
    parar();

    //ir para frente
    frente();
    delay(2600);
    parar();

    //girar 90° a equerda
    esquerda2();
    delay(1800);
    parar();

    //ir para frente
    frente();
    delay(1500);
    parar();

    //Girar 90° a direita
    direita2();
    delay(1800);
    parar();

    lerSensorDeLinha();
    lerDistancia();
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
