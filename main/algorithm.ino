//define as variaveis

bool esquerda = true;
bool achouLinha = false;
unsigned int comeco = 0;
const int delaySemLinha = 200; // delei


void vira(int vel) 
{
  if (esquerda) turnLeft(vel);
  else turnRight(vel);

  esquerda = !esquerda;
}


void algorithm(){
  achouLinha = false;
  vira(70);
  comeco = millis(); // começa o "timer"
  while (stayOnBlackLine() || !achouLinha) {
    if (stayOnBlackLine()) {
      achouLinha = true;
    } else if (!achouLinha && (millis() - comeco) > delaySemLinha) {
      // Ainda não achou a linha e já tá a tempo demais sem achar
      stop(); // Só pra testar
      // // Vira até achar a linha.
      // vira(70);
      // while(!stayOnBlackLine());
      // achouLinha = true;
    }

    delay(1); // delei
  }
}
