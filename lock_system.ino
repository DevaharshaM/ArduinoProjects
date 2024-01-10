#include <Keypad.h>

const byte rows=4;
const byte columns=4;

char key[rows][columns] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowpin[rows]={7,6,5,4};
byte colpin[columns]={8,9,10,11};

Keypad keypad = Keypad(makeKeymap(key),rowpin,colpin,rows,columns);

char* password="1234";
int current=0,incorrect=0;
int buzz=12;

void setup()
{
	Serial.begin(9600);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(buzz, OUTPUT);
}

void loop()
{
	char code=keypad.getKey();
  
	if (code==password[current])
	{
		++current;
		if(current==4)
			{
				Serial.println("Access granted.");
 				digitalWrite(3,HIGH);
  				delay(500);
  				digitalWrite(3,LOW);
  				delay(500);
				current=0;
			}

	}
}
