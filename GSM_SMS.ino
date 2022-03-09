#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

String inputString = "";
boolean RX_ST_Flag = false;
int i;
char Mb_Num1[]="7904468906";

void setup() 
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("GSM TEST"); 
  delay(4000); 
 
  Serial.begin(9600);
  delay(1000);
  GSM_Init();
  delay(1000);
  GSM_Send_SMS(Mb_Num1,"WELCOME TO ELECTRONICS");
  delay(1000);  
}

void loop() 
{
 
}


void GSM_Init()
{
  Serial.print("AT\r");
  delay(500);  
}

void GSM_Send_SMS( char *Mb_Num1, char *SMS )
{
  delay(500);
  Serial.print("AT+CMGS=\"");
  delay(500);
  for(i=0; Mb_Num1[i] != '\0'; i++)
  {
    Serial.print((char)Mb_Num1[i]);
    delay(50);
  }
  Serial.println("\"");
  delay(500);
  Serial.print("\r");
  for(i=0; SMS[i] != '\0'; i++)
  {
    Serial.print(SMS[i]);
    delay(50);
  }
  delay(500);
  Serial.write(0x1A);
  delay(4000);
}
