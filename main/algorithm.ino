//define as variaveis

bool esquerda = true;
bool achouLinha = false;
unsigned int comeco = 0;
const int delayForaDaLinha = 50;

void perdi_a_linha() {
  int achou = stayOnBlackLine();
  while(!achou) {
    unsigned long t1 = millis(); // tempo inicial antes da curva
    
    // procura um pouco aa esquerda
    if (!achou) turnLeft();
    while(millis() < t1 + 1000 && (!achou)) {
      if(stayOnBlackLine()) {
        achou = 1;
        stop();
      }
      //Serial.println("achei a linha aa esquerda");
    }

    t1 = millis(); // atualiza o tempo inicial pra a curva direita, se necessaria
    if (!achou) turnRight();
    while(millis() < t1 + 2000 && (!achou)) { // volta e procura um pouco aa direita, se ainda nao achou a linha
      if(stayOnBlackLine()) {
        achou = 1;
        stop();
      }
      //Serial.println("achei a linha aa direita");
    }

    if(!achou) printf("nao achei :(\n");
  }
}

void vira() {
   if (esquerda) turnRight(70);
   else turnLeft(70);
   esquerda = !esquerda;
}

void algorithm(){
  // Pinguim
  vira();
  while(stayOnBlackLine() || !achouLinha || millis()-comeco <= delayForaDaLinha) {
    if (stayOnBlackLine()) {
      achouLinha = 1;
      comeco = millis(); // recomeça o contador
    }
  }   
  //perdi_a_linha();
}
