//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: FILIPEFLOP
 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float tempo = 50;
  double cmIn, cmFn, deslocamento, v;
  long microsec = ultrasonic.timing();
  cmIn = ultrasonic.convert(microsec, Ultrasonic::CM);
  delay(tempo);
  microsec = ultrasonic.timing();
  cmFn = ultrasonic.convert(microsec, Ultrasonic::CM);
  deslocamento= (cmIn - cmFn) / 100;  // deslocamento convertido de cm para m
  tempo = tempo / 1000;  //converter milissegundos em segundos
  v =(double) deslocamento / tempo;
  Serial.print("\n Velocidade: ");
  Serial.print(v);
  Serial.print("m/s");

  delay(1000);
}
