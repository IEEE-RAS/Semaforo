int ledVerde = 13;
int ledAmarelo = 12;
int ledVermelho = 11;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {

  digitalWrite(ledVerde, HIGH);
  delay(4000);
  digitalWrite(ledVerde, LOW);

  digitalWrite(ledAmarelo, HIGH);
  delay(2000);
  digitalWrite(ledAmarelo, LOW);

  digitalWrite(ledVermelho, HIGH);
  delay(4000);
  digitalWrite(ledVermelho, LOW);

}


