int gas_sensor = A0;
int buzzer = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(gas_sensor,INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop()
{
  int sen_val;
  sen_val = analogRead(gas_sensor);
  if(sen_val>= 450)
  {
    Serial.println("Smoke detected.");
    digitalWrite(buzzer,HIGH);
    delay(100);
  }
  else
  {
    Serial.println("Smoke not detected.");
    digitalWrite(buzzer,LOW);
    delay(100);
  }
}