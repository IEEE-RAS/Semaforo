#include<LiquidCrystal.h>
float CalcularVelocidade();
LiquidCrystal displayAviso(12,11,5,4,3,2);
int ledVerde = 13;
int ledAmarelo = 12;
int ledVermelho = 14;
int buzzer = 15;
int pino_sensor = 9;
int pino_sensor2 = 10;

float deltaD = 0.075; //7,5 cm em m
int estado_sensor = 0;
int estado_sensor2 = 0;
float s = 0.30; //30 cm em m  //Distância

void setup() {
  displayAviso.begin(16,2);
  displayAviso.setCursor(0,0);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(pino_sensor, INPUT);
  pinMode(pino_sensor2, INPUT);
}

void loop() {

  int tempo = millis();
  digitalWrite(ledVerde, HIGH);
  while(millis() < tempo + 60000);{
     CalcularVelocidade();
  }
  
  digitalWrite(ledVerde, LOW);
  
  tempo = millis();
  digitalWrite(ledAmarelo, HIGH);
  while(millis() < tempo + 3000);{
    SmartSemaforo();
  }
  digitalWrite(ledAmarelo, LOW);
 
  tempo = millis();
  digitalWrite(ledVermelho, HIGH);
  while(millis() < tempo + 60000);{
    SmartSemaforo();
  }
  digitalWrite(ledVermelho, LOW);

}

void SmartSemaforo(){
  displayAviso.clear();
    float velocidade = CalcularVelocidade();  
    float tempFaixa = s/(velocidade/3.6);    // Descobrir o tempo atraves da velocidade constante e com distancia ate a faixa determinada em 30 cm ou o.30 m
    Serial.println("Tempo para o carro chegar na faixa de pedestre:");
    displayAviso.setCursor(0,1);
    
    if(tempFaixa < 5){                    //Caso de perigo, onde o tempo para o pedestre atravessar é menos que 5 segundos
      displayAviso.print("PERIGOOO!");
      tone(buzzer,1800);
      delay(tempFaixa*1000);
    }
    else{                 
      displayAviso.print("TRÂNSITO SEGURO");
    }


    
  delay(100);  
  }
  


float CalcularVelocidade(){
    float tempo = 0;
    int primeiraDeteccao = 0;
    int segundaDeteccao = 0;
    estado_sensor = digitalRead(pino_sensor);
    if(estado_sensor != 0)
    {
      // Sem movimento, mantem led verde ligado
      Serial.println("Movimento não detectado!");
    }
    else 
    {
      primeiraDeteccao = millis();
      for(int i = 0; digitalRead(pino_sensor2) != 0; i++){
      }
      segundaDeteccao = millis();
      tempo = (float)segundaDeteccao - primeiraDeteccao;
      Serial.println("Tempo de movimento:");
      tempo = tempo/1000;
      Serial.println(tempo);
      float velocidade = (deltaD/tempo)*3.6; 
      displayAviso.print("Velocidade:");
      displayAviso.setCursor(11, 0);
      displayAviso.print(velocidade);
      Serial.println("km/h");
      return velocidade;
    }
}
