void salaDeResgate(){

    while (F > 40){
      Motor1.setSpeed(250);
      Motor2.setSpeed(250);
      Motor1.run(FORWARD);
      Motor2.run(FORWARD);
    }
    parar();
    delay(2000);
    desceGuarra();  
    lerDistancia();
    
    if(L > R){
      direita2();
      delay(1800);
    }
    
    if(R > L){
      esquerda2();
      delay(1800);
    }
    
}
