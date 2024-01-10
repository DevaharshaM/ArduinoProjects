#include <IRremote.h>
#include <LiquidCrystal.h>

const int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);

decode_results result;
LiquidCrystal lcd(6,7,8,9,10,11);

void setup()
{
  irrecv.enableIRIn();
  lcd.begin(16,2);
  lcd.print("WELCOME");
  pinMode(3,OUTPUT);
}

void loop()
{
  if (irrecv.decode(&result))
  {
    int res = result.value;
    switch(res)
    {
		case 2295:
			lcd.clear();
			digitalWrite(3,HIGH);
			lcd.print("Light:");
			lcd.setCursor(0,3);
			lcd.print("Switched ON.");
			break;
		case 12495:
			lcd.clear();
			digitalWrite(3,LOW);
			lcd.print("Light:");
			lcd.setCursor(0,3);
			lcd.print("Switched OFF.");
			break;
		default: 
			lcd.clear();
			lcd.print("No function.");
     }
    irrecv.resume();
  }
}