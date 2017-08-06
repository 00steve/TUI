double x = 0;
double y = 0;


void setup() {
  // put your setup code here, to run once:
  setPinMode(11,HIGH);
  setPinMode(12,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
    
  x = analogRead(A12);
  y = analogRead(A13);

  Serial.print(x);
  Serial.print(" ");
  Serial.println(y);
}
