//define as variaveis

bool esquerda = true;
bool achouLinha = false;
unsigned int comeco = 0;
const int delayFora = 175;

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

// O CÓDIGO QUE DEU CERTO!!!!
void algorithm(){
  setVelocity(0, 70);
  setVelocity(1, 70);
  achouLinha = false;
  esquerda = !esquerda;

  while (stayOnBlackLine() || !achouLinha || ((millis() - comeco) < delayFora)) {
    if (esquerda) turnLeft();
    else turnRight();
    if (stayOnBlackLine()) {
      achouLinha = true;
      comeco = millis();
    }
    delay(10);
  }
}
