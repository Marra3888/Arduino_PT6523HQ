#include "PT6523.h"
#include <SPI.h>

PT6523 lcd;

char full[9] = "########";
char alphabet[27] = "AA";
char number[11] = "0123456789";
byte _address = 0x82;
byte screenn[15];
byte symbolss[5];
int _textSpeed = 500;
byte _chipEnabledPin = 10;

void _print(byte pAddress, byte pScreen[], byte pSymbols[]) 
{
  digitalWrite(_chipEnabledPin, LOW);
  // Address Data (A1- A8)
  SPI.transfer(pAddress);
  digitalWrite(_chipEnabledPin, HIGH);

  // Character Segment Data (D1- D120) 15 Byte
  for (byte i = 0; i <= 14; i++) {
    SPI.transfer(pScreen[i]);
  }

  // Symbol Segment Data (D121 - D156 & DR, SC, BU, X) 5 Byte
  for (byte i = 0; i <= 4; i++) {
    SPI.transfer(pSymbols[i]);
  }
  digitalWrite(_chipEnabledPin, LOW);
  delay(_textSpeed);
}  

void setup() 
{ 
//  Serial.begin(9600);
  lcd.begin(_chipEnabledPin, _address); 
  lcd.reset();
  lcd.clear();
  pinMode(2, INPUT_PULLUP);                 // подключаем кнопку 1 к пину и подтягиваем её к питанию
  pinMode(3, INPUT_PULLUP);                 // подключаем кнопку 2 к пину и подтягиваем её к питанию
  pinMode(4, INPUT_PULLUP);                 // подключаем кнопку 3 к пину и подтягиваем её к питанию
  Serial.begin(9600);
  
/*  for(byte j = 0; j < 15; j++)
  {
    for(int i = 0; i <= 255; i++)
    {
      screenn[j] = i;
      Serial.print(j);
      Serial.print("  ");            
      Serial.println(screenn[j]); 
      _print(_address, screenn, symbolss); 
    }    
    
  }
*/  


//for(byte i = 31; i < 32; i++)
//{ 
//  boolean sts = true;
//  lcd.symbol(CHART_DOT, sts);
//  bitWrite(_screen[0], 7, sts); 
//  _print(_address, 1, 1); 
//  lcd.speed(2);
//} 


//for(byte i = 0; i < 37; i++)
//{ 
//  boolean sts = false;
//  lcd.symbol(i, sts);
//}  


/*
  lcd.symbol(MUTE, sts);
  lcd.symbol(BLUETOOTH, sts);
  lcd.symbol(TRACK, sts);
  lcd.symbol(AUDIO_FILE_ICON, sts);
  lcd.symbol(PERSON_ICON, sts);
  lcd.symbol(BOOK_ICON, sts);
  lcd.symbol(EQ_BORDER, sts);
  lcd.symbol(EQ, sts);
  lcd.symbol(CLAS, sts);
  lcd.symbol(FLAT, sts);
  lcd.symbol(POP, sts);
  lcd.symbol(ROCK, sts);
  lcd.symbol(BLUETOOTH, sts);
  lcd.symbol(TP, sts);
  lcd.symbol(TA, sts);
  lcd.symbol(AF, sts);
  lcd.symbol(PTY, sts);
  lcd.symbol(EON, sts);
  lcd.symbol(RDM, sts);
  lcd.symbol(INT, sts);
  lcd.symbol(RPT, sts);
  lcd.symbol(LOUD, sts);
  lcd.symbol(MP3, sts);
  lcd.symbol(DISC, sts);
  lcd.symbol(TRACK, sts);

  lcd.volumeChart(1, 1);
  lcd.volumeChart(2, 1);
  lcd.volumeChart(3, 1);
  lcd.volumeChart(4, 1);
  lcd.volumeChart(5, 1);
  lcd.volumeChart(6, 1);
  lcd.volumeChart(7, 1);
  lcd.volumeChart(8, 1);
  lcd.volumeChart(9, 1);
  lcd.volumeChart(10, 1);
  lcd.volumeChart(11, 1);

//  lcd.volumeLevel(7);

*/ 

}


void loop() {

  
/*  
  lcd.reset();
  lcd.speed(50);
  lcd.text("SYMBOLS");
  boolean sts = true;
  lcd.symbol(CD_ICON, sts);
  lcd.symbol(MUTE, sts);
  lcd.symbol(MUSIC, sts);
  lcd.symbol(FOLDER_ICON, sts);
  lcd.symbol(AUDIO_FILE_ICON, sts);
  lcd.symbol(PERSON_ICON, sts);
  lcd.symbol(BOOK_ICON, sts);
  lcd.symbol(EQ_BORDER, sts);
  lcd.symbol(EQ, sts);
  lcd.symbol(CLAS, sts);
  lcd.symbol(FLAT, sts);
  lcd.symbol(POP, sts);
  lcd.symbol(ROCK, sts);
  lcd.symbol(BLUETOOTH, sts);
  lcd.symbol(TP, sts);
  lcd.symbol(TA, sts);
  lcd.symbol(AF, sts);
  lcd.symbol(PTY, sts);
  lcd.symbol(EON, sts);
  lcd.symbol(RDM, sts);
  lcd.symbol(INT, sts);
  lcd.symbol(RPT, sts);
  lcd.symbol(LOUD, sts);
  lcd.symbol(MP3, sts);
  lcd.symbol(DISC, sts);
  lcd.symbol(TRACK, sts);

  lcd.volumeChart(8, 1);
  lcd.volumeChart(9, 1);
  lcd.volumeChart(10, 1);
  lcd.volumeChart(11, 1);
  lcd.volumeLevel(7);
  delay(2500);
*/
//  lcd.clear();
//  lcd.speed(1000);
//  for (int i = 0; lcd.textLoopCount() < 1; i++) 
//  {
//    lcd.sChart(1);
//    lcd.sText(alphabet);
//  }
/*
  lcd.clear();
  lcd.speed(150);
  for (int i = 0; lcd.textLoopCount() < 1; i++) {
    lcd.sChart(1);
    lcd.sText(number);
  }

  lcd.reset();
  lcd.clear();
  lcd.speed(100);
  lcd.levelDirection(OUT);
  int r = 0;
  for (int i = 0; lcd.textLoopCount() < 2; i++) {
    r = random(0, 7);
    lcd.volumeLevel(r);
    lcd.sText("VOLUME LEVEL OUT RIGHT");
  }

  lcd.reset();
  lcd.clear();
  lcd.speed(100);
  lcd.levelDirection(IN);
  for (int i = 0; lcd.textLoopCount() < 2; i++) {
    r = random(0, 7);
    lcd.volumeLevel(r);
    lcd.sText("VOLUME LEVEL IN RIGHT");
  }
*/

  static byte  j = 0, d = 1, f = 0, k = 0;
  static byte i = 0;  
  int key = get_key();
  static  byte bbit = 1;
     

//    int key = 2;   
  if (key == 2)   
  { 
    delay(50);                               
    if (j < 17)
    { 
      if(i <= 7)
        {
            screenn[j] = bbit;
            Serial.print(j);
            Serial.print("  ");            
            Serial.print(screenn[j], BIN);
            Serial.print("  ");
            Serial.print(screenn[j], DEC); 
            Serial.print("   D");
            Serial.print(d, DEC);
            Serial.print("  ");
            Serial.print("bit ");
            Serial.println(i);
            bbit = (bbit << 1);
//              to_massiv(k, f, d, i);  
//              _print(CCB_address);
//            lcd.display();
            _print(_address, screenn, symbolss);
            i++;
            d++;            
        }
        else 
          {
            bbit = 1;
            i = 0;
            j++;
            
                      
          }               
/*          if(d > 9)  
              {
                d = 0;
                f++;
                  if(f > 9) 
                  {
                    f = 0;                    
                    k++;
                    if(k > 2)    k = 0;      
                  }          
              
              } */      
    }
      else {j = 0;}    
  }  

}

int get_key()   //Вывод нажатой клавиши
{
  if (digitalRead(4) == 0) return 1;
  if (digitalRead(3) == 0) return 2;
  if (digitalRead(2) == 0) return 3;
  return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------
/*PT6523 lcd;

char ss[2];
char sss[2];
int val = 0;
float volt;

void setup() {
  lcd.begin(10, 130);
  lcd.volumeStartValue(0);
  lcd.volumeEndValue(1023);
}

void loop() {
  lcd.speed(100);
  val = analogRead(0);
  volt = val * 0.005;
  dtostrf(volt, 4, 2, ss);
  sprintf(sss, "%s V", ss);
  lcd.text(sss);
  lcd.volumeLevel(val);
  // delay(70);
}
*/
