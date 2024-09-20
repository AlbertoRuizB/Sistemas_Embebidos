#define LED1 13
#define LED2 12
#define PUL  3
#define TIME 1000

volatile bool flag = false;
volatile int cont = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(PUL, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(PUL), interrumpir, FALLING);
}

void loop() {
  digitalWrite(LED1, HIGH);
  delay(TIME);
  digitalWrite(LED1, LOW);
  delay(TIME);
  
  // Mostrar el contador en el monitor serial
  Serial.print("Pulsaciones: ");
  Serial.println(cont);
  delay(1000); // Espera un segundo antes de actualizar de nuevo
}

void interrumpir() {
  flag != flag;
  
  if (flag) {
    digitalWrite(LED2, LOW);
    cont++;
    flag = false;
  } else {
    digitalWrite(LED2, HIGH);
    flag = true;
  }
}
