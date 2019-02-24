
unsigned long start=0, finish=0;
int startPin=4, finishPin=8, done=0;
float distance=218.0, interval, velocity;

void setup() {
pinMode(startPin, INPUT_PULLUP);
pinMode(finishPin, INPUT_PULLUP);
Serial.begin(9600);
// Adicione a configuração da porta seria ou 
// o lugar pra onde quer enviar a velocidade calculada (Display LCD por exemplo)
}

void loop() {
  done = 0;
  while(!start) {
    if(digitalRead(startPin) == HIGH)
      start = micros();
  }
  while(!finish) {
    if(digitalRead(finishPin) == HIGH)
      finish = micros();
  }
  while(!done) {
    interval = float(finish-start);
    velocity = distance*1000*3.28/interval;
    Serial.print(velocity);
    // Aqui vc pode enviar a velocidade via serial, 
    //basta adicionar o seu código abaixo
    done = 1;
  }
}
