
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}
void loop() {
  while (Serial.available() > 0) {
    if (Serial.read() == 'a') 
    {
      digitalWrite(LED_BUILTIN,HIGH);
      delay(1000);
    }
    else if (Serial.read() == 'b')
    {
      digitalWrite(LED_BUILTIN,LOW);
      delay(1000);
    }
  }
}








