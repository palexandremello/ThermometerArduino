#define vcc 5.00
#define t25 273.15 + 25.00
#define R0 22000.00
#define R25 20000.00
#define pinRF A0
#define redPin 8
#define yellowPin 9
#define bluePin 10
#define beta 3950.00

#include <math.h>
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

pinMode(redPin,OUTPUT);
pinMode(yellowPin,OUTPUT);
pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    int sensor = analogRead(pinrf);
    double vt = (5*sensor)/1024.00;
    double rterm = ((vrf/vt)-1)*rrf;
    double den = log(rterm/(r25*exp(-beta/(trf))));
    double temp = beta/den -273.15;
    Serial.println(temp);
   
    if (temp < 0 || temp => 26 ) {
      digitalWrite(redPin,HIGH);
      delay(100);
      digitalWrite(redPin,LOW);
      delay(100);
      digitalWrite(yellowPin,LOW);
      digitalWrite(bluePin,LOW);
      Serial.println("Alerta Vermelho");
   
    } else if (temp > 20 & temp < 25) {
      digitalWrite(redPin,LOW);
      digitalWrite(yellowPin,HIGH);
      digitalWrite(bluePin,LOW);
      Serial.println("Alerta Amarelo");
     
    } else if (temp > 0 & temp < 19) {
      digitalWrite(redPin,LOW);
      digitalWrite(yellowPin,LOW);
      digitalWrite(bluePin,HIGH);
      Serial.println("Alerta Azul");
     
    }
   
    delay(1000);
   

}
