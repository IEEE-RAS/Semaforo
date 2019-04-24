#include<LiquidCrystal.h>
#define tempoBuzzer 10
float CalcularVelocidade();
void SmartSemaforo(double tempoSemaforo);


LiquidCrystal displayAviso(49,47,31,32,51,53);
int ledVerde = 26;
int ledAmarelo = 22;
int ledVermelho = 24;
int pino_sensor = 36;
int pino_sensor2 = 38;


int frequencia = 0;
int Pinofalante = 40;

float deltaD = 0.075; //7,5 cm em m
int estado_sensor = 0;
int estado_sensor2 = 0;
float s = 0.30; //30 cm em m  //Distância

void setup() {
  pinMode(Pinofalante,OUTPUT);
  Serial.begin(9600);
  displayAviso.begin(16,2);
  displayAviso.setCursor(0,0);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(pino_sensor, INPUT);
  pinMode(pino_sensor2, INPUT);
  
}

void loop() {
  displayAviso.clear();
  displayAviso.print("Semaforo aberto!");
  
  digitalWrite(ledVerde, HIGH);
  delay(6000);
  digitalWrite(ledVerde, LOW);
  
  digitalWrite(ledAmarelo, HIGH);
  delay(1000);
  digitalWrite(ledAmarelo, LOW);
 
  double tempo = millis();
  digitalWrite(ledVermelho, HIGH);
  while(millis() < tempo + 30000){
    SmartSemaforo(tempo+30000 - millis());
  }
  digitalWrite(ledVermelho, LOW);

}

void SmartSemaforo(double tempoSemaforo){
    displayAviso.clear();
    displayAviso.print("TRANSITO SEGURO");
    float velocidade = CalcularVelocidade(); 
    float tempCarro = s/(velocidade);    // Descobrir o tempo atraves da velocidade constante e com distancia ate a faixa determinada em 30 cm ou o.30 m
    velocidade = (velocidade * 3.6);
    float distancia = ((velocidade * velocidade) / (250 * 0.6));
    if(distancia > 0.30){                    //Caso de perigo, onde o tempo para o pedestre atravessar é menos que 5 segundos
       displayAviso.clear();
       float instante = millis();
       displayAviso.setCursor(0,0);
       displayAviso.print("Atencao: Perigo!");
      tone(Pinofalante, 1800, 3000);
      delay(1);
       
       while(instante + 3000 > millis()){
       }
    }
    else{ 
        displayAviso.clear();                
        displayAviso.print("TRANSITO SEGURO");
    }
}
  


float CalcularVelocidade(){
  float tempo = 0;
  int primeiraDeteccao = 0;
  int segundaDeteccao = 0;
  estado_sensor = digitalRead(pino_sensor);
  if(estado_sensor != 0)
  {
    Serial.println("Movimento não detectado!");
    return 0;
  }
  else 
  {
    primeiraDeteccao = millis();
    for(int i = 0; digitalRead(pino_sensor2) != 0; i++){
    }
    segundaDeteccao = millis();
    if(digitalRead(pino_sensor2) != digitalRead(pino_sensor)){
      tempo = (float)segundaDeteccao - primeiraDeteccao;
      tempo = tempo/1000;
      float velocidade = (deltaD/tempo);
      return velocidade;
      delay(100);
    }else{
      return 0;
    }
  }
}
