#define LED 3
int BRILLO;
#define POT A0
void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  BRILLO = analogRead(POT) / 4;
  analogWrite(LED, BRILLO);
}