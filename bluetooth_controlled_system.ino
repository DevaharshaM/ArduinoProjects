#include <SoftwareSerial.h>

SoftwareSerial BT(4, 2);
String command = "";

void setup()
{
	Serial.begin(9600);
	BT.begin(9600);
	delay(1000);
	Serial.println("Configuracion bluetooth");
}

void loop()
{
	if (BT.available()>0)
		{
			command = BT.readString();
			Serial.println(command);
		}

	if (Serial.available()>0)
		{
			String S = Serial.readStringUntil('\n');
			Serial.println("---> " + S);
			BT.print(S);
			BT.print('\n');
			Serial.println("");
		}
}


