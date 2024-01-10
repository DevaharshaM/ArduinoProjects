int x_val,y_val;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  x_val = analogRead(A0);
  y_val = analogRead(A1);
  
  Serial.print("X Value:");
  Serial.println(x_val); 
  delay(500);
  Serial.print("Y Value:");
  Serial.println(y_val);
  delay(1000);
}