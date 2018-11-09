// Programa: Sensor infravermelho Arduino
// Autor: FILIPEFLOP
float deltaD = 0.7500;

int pino_sensor = 9;
int pino_sensor2 = 10;
 
int estado_sensor = 0;
 
int estado_sensor2 = 0;
 
void setup()
{
  Serial.begin(9600);
  // Define o pino do sensor como entrada
  pinMode(pino_sensor, INPUT);
  pinMode(pino_sensor2, INPUT);
  // Define os pinos dos leds e buzzer como saida
  Serial.println("Teste sensor infravermelho Arduino");
}
 
void loop()
{
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
    float velocidade = deltaD/tempo; 
    Serial.println("Velocidade:");
    Serial.print(velocidade);
     Serial.println("m/s");
    delay(500);
  }
  
  
  delay(100);
}
