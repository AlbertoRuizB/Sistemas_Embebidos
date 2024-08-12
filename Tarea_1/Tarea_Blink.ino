#define BAUDRAT 9600
#define LED 13
#define TIEMPO 1000
void setup() {
 Serial.begin(BAUDRAT); 
 pinMode(LED, OUTPUT);
}
void loop() {
 digitalWrite(LED, HIGH);
 delay(TIEMPO);
 digitalWrite(LED, LOW);
 delay(TIEMPO);
}
