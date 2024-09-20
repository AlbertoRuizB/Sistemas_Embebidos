#include <EEPROM.h>
#define LED1 8
#define LED2 9
#define LED3 10
#define PULS 2
#define PULS1 3
#define PASO 1
#define BAUDRATE 9600
volatile unsigned long TiempoPasado = 0;
volatile unsigned long debounceDelay = 50;
unsigned int cont;
int MAXVAL = 10;
int MINVAL = 0;
int TIEMPO = 0;
int DIREC = 0;
void setup() {
  Serial.begin(BAUDRATE);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  cont = EEPROM.read(DIREC);
  if (cont > MAXVAL || cont < MINVAL) {
    cont = MINVAL;
  }
  pinMode(PULS, INPUT);
  pinMode(PULS1, INPUT);
  attachInterrupt(digitalPinToInterrupt(PULS), INCREMENTAR, FALLING);
  attachInterrupt(digitalPinToInterrupt(PULS1), DECREMENTAR, FALLING);
}
void loop() {
  if (millis() - TiempoPasado > debounceDelay) {
    if (digitalRead(PULS) == 1 && digitalRead(PULS1) == 1) {
      cont = 0;
      TiempoPasado = millis();
      EEPROM.write(DIREC, cont);
      Serial.println(cont);
    }
    delay(TIEMPO);
  }
}
void INCREMENTAR() {
  if (millis() - TiempoPasado > debounceDelay) {
    if (cont < MAXVAL) {
      digitalWrite(LED1,HIGH);
      cont += PASO;
      TiempoPasado = millis();
      EEPROM.write(DIREC, cont);
      Serial.println(cont);
    }
  }
   /*
  if(PULS1 == MAXVAL){
    digitalWrite(LED1, HIGH);
      }
       */
}
void DECREMENTAR() {
  if (millis() - TiempoPasado > debounceDelay) {
    if (cont > MINVAL) {
      digitalWrite(LED1, LOW);
      cont -= PASO;
      TiempoPasado = millis();
      EEPROM.write(DIREC, cont);
      Serial.println(cont);
    }
  }
  /*
   if(PULS == MINVAL){
    digitalWrite(LED1, LOW);
    }
    */
}
