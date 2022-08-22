void rampa(){
  
  unsigned long tempo = millis();
  
  while(L < 15 || R < 15){
    lerSensorDeLinha();
    lerDistancia();
    lerCor();
    
    Motor1.setSpeed(250);
    Motor2.setSpeed(250);
    
    if(millis() - tempo > 10000 || F < 50){
      salaDeResgate();
    }

    if(B == 0 && C == 0){
      Motor1.run(FORWARD);
      Motor2.run(FORWARD);
    }
    
    if(B == 0 && C == 1){
      Motor1.setSpeed(180);
      Motor2.setSpeed(150);
      Motor1.run(FORWARD);
      Motor2.run(BACKWARD);
    }
    
    if(B == 1 && C == 0){
      Motor1.setSpeed(180);
      Motor2.setSpeed(150);
      Motor1.run(BACKWARD);
      Motor2.run(FORWARD);
    }
    
    if(B == 1 && C == 1){
      Motor1.run(FORWARD);
      Motor2.run(FORWARD);
    }
  }
  parar();
  delay(2000);
  lerSensorDeLinha();
  lerDistancia();
}
