#define vRef  5.015
#define tRef  25+273.15
#define resistorRef  22000
#define rRef 20000
#define pinResistor A0
#define redPin 8
#define betaFactor 3950 // Fator necessario para equation Factor Beta (unidade em Kelvin)
#include <math.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue  =  analogRead(pinResistor);
  double vTherm =  (vRef*sensorValue) / 1024.000;
  double reTherm   =  (vRef/vTherm - 1.0) * resistorRef;
  double temperature = ( betaFactor / log(reTherm / (rRef * exp(-betaFactor/(tRef) ) ) ) ) - 273.15;
  Serial.print(vTherm);
  Serial.print(" ");
  Serial.print(reTherm);
  Serial.print(" ");
  Serial.print("Temp = ");
  Serial.println(temperature);

  if ( temperature > 22 & temperature < 25) digitalWrite(redPin,HIGH);

  delay(1000);

}
