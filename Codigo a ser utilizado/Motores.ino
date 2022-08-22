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
