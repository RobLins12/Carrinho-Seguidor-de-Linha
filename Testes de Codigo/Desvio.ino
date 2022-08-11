void desvio() {
    lerDistancia();
    parar();

    //recuo
    tras();
    delay(30);
    parar();

    //giro 90° a direita
    direita2();
    delay(60);
    parar();

    //frente por meio segundo
    frente();
    delay(500);
    parar();

    //girar 90° a esquerda
    esquerda2();
    delay(60);
    parar();

    //ir para frente
    frente();
    delay(1000);
    parar();

    //girar 90° a equerda
    esquerda2();
    delay(60);
    parar();

    //ir para frente
    frente();
    delay(500);
    parar();

    //Girar 90° a direita
    direita2();
    delay(60);
    parar();

    lerSensorDeLinha();
    lerDistancia();
}