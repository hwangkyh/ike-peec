//code DS1307_RTCV03_ and RGB_LED

#include <RTClib.h>
#include <Wire.h>
#include <DS1307.h>

DS1307 clock;//define a object of DS1307 class

#define BLUE 11
#define GREEN 10
#define RED 9

int hour = 0, minute = 0, second = 0;
int timeMinutes = 0;
double delayTime = 0.0;

// define RGB_LED variables
int redValue;
int greenValue;
int blueValue;

void setup()
{
  Serial.begin(9600);
  clock.begin();
  clock.fillByYMD(2020,06,04);//Jun 04, 2020
  clock.fillByHMS(14,35,00);//14:35 00"
  clock.fillDayOfWeek(THU);//Thursday
  //clock.setTime();//write time to the RTC chip 

  //RGB_LED setup
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);

  
}

void loop()
{
  printTime();
  colorChangeIf();
//  fadeLed();

  
} //close void loop


/*Function: Display time on the serial monitor*/
void printTime()
{
  clock.getTime();
  Serial.print(clock.hour, DEC);
  Serial.print(":");
  Serial.print(clock.minute, DEC);
  Serial.print(":");
  Serial.print(clock.second, DEC);
  Serial.print("  ");
  Serial.print(clock.month, DEC);
  Serial.print("/");
  Serial.print(clock.dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(clock.year+2000, DEC);
  Serial.print(" ");
  Serial.print(clock.dayOfMonth);
  Serial.print("*");
  switch (clock.dayOfWeek)//printout weekday
    {
      case MON:
        Serial.print("MON");
      break;
      case TUE:
        Serial.print("TUE");
      break;
      case WED:
        Serial.print("WED");
      break;
      case THU:
        Serial.print("THU");
      break;
      case FRI:
        Serial.print("FRI");
      break;
      case SAT:
        Serial.print("SAT");
      break;
      case SUN:
        Serial.print("SUN");
      break;
    }
    Serial.println(" ");
} //close printTime method


void colorChangeIf()
{

  timeMinutes = clock.hour*60 + clock.minute;
  
  if (timeMinutes <= 449) { //start
      Serial.print("blank");
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
      
  } else if ((450 <= timeMinutes) && (timeMinutes <= 469)) { //start-amber
      Serial.print("start-amber");
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
    for (int i = 0; i < 255; i += 1)
    {
      delay(4471);
      redValue += 1;
      analogWrite(RED, redValue);
      if (redValue > 64) {
        greenValue += 1;
        analogWrite(GREEN, greenValue);
      }
    }
      
  } else if ((470 <= timeMinutes) && (timeMinutes <= 479)) { //amber
      Serial.print("amber");
      analogWrite(RED, 255);
      analogWrite(GREEN, 191);
      analogWrite(BLUE, 0);

  } else if ((480 <= timeMinutes) && (timeMinutes <= 484)) { //amber-lgreen
      Serial.print("amber-lgreen");
      analogWrite(RED, 255);
      analogWrite(GREEN, 191);
      analogWrite(BLUE, 0);
    for (int i = 0; i < 144; i += 1)
    {
      delay(1667);
      blueValue += 1;
      analogWrite(BLUE, blueValue);
      if (blueValue > 33) {
        redValue -= 1;
        analogWrite(RED, redValue);
      }
      if (blueValue > 97) {
        greenValue += 1;
        analogWrite(GREEN, greenValue);
      }
    }
      
  } else if ((485 <= timeMinutes) && (timeMinutes <= 509)) { //light green
      Serial.print("lightgreen");
      analogWrite(RED, 144);
      analogWrite(GREEN, 238);
      analogWrite(BLUE, 144);

  } else if ((510 <= timeMinutes) && (timeMinutes <= 519)) { //lgreen-orange
      Serial.print("lgreen-orange");
      analogWrite(RED, 144);
      analogWrite(GREEN, 238);
      analogWrite(BLUE, 144);
    for (int i = 0; i < 144; i += 1)
    {
      delay(3751);
      blueValue -= 1;
      analogWrite(BLUE, blueValue);
      if (blueValue < 111) {
        redValue += 1;
        analogWrite(RED, redValue);
        greenValue -= 1;
        analogWrite(GREEN, greenValue);
      }
    }
      
  } else if ((520 <= timeMinutes) && (timeMinutes <= 569)) { //orange
      Serial.print("orange");
      analogWrite(RED, 255);
      analogWrite(GREEN, 127);
      analogWrite(BLUE, 0);

  } else if ((570 <= timeMinutes) && (timeMinutes <= 599)) { //orange-lapiz
      Serial.print("orange-lapiz");
      analogWrite(RED, 255);
      analogWrite(GREEN, 127);
      analogWrite(BLUE, 0);
    for (int i = 0; i < 217; i += 1)
    {
      delay(8019);
      redValue -= 1;
      analogWrite(RED, redValue);
      if (redValue < 194) {
        blueValue += 1;
        analogWrite(BLUE, blueValue);
      }
      if (redValue < 68) {
        greenValue -= 1;
        analogWrite(GREEN, greenValue);
      }
    }
      
  } else if ((600 <= timeMinutes) && (timeMinutes <= 779)) { //lapiz
      Serial.print("lapiz");
      analogWrite(RED, 38);
      analogWrite(GREEN, 97);
      analogWrite(BLUE, 156);

  } else if ((780 <= timeMinutes) && (timeMinutes <= 789)) { //lapiz-off
      Serial.print("lapiz-off");
      analogWrite(RED, 38);
      analogWrite(GREEN, 97);
      analogWrite(BLUE, 156);
    for (int i = 0; i < 156; i += 1)
    {
      delay(3462);
      blueValue -= 1;
      analogWrite(BLUE, blueValue);
      if (blueValue < 97) {
        greenValue -= 1;
        analogWrite(GREEN, greenValue);
      }
      if (blueValue < 38) {
        redValue -= 1;
        analogWrite(RED, redValue);
      }
    }

  } else if ((790 <= timeMinutes) && (timeMinutes <= 829)) { //off
      Serial.print("blank");
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);

  } else if ((830 <= timeMinutes) && (timeMinutes <= 839)) { //off-yellow
      Serial.print("off-yellow");
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
    for (int i = 0; i < 255; i += 1)
    {
      delay(2118);
      redValue += 1;
      analogWrite(RED, redValue);
      if (redValue > 32) {
        greenValue += 1;
        analogWrite(GREEN, greenValue);
      }
    }
 
  } else if ((840 <= timeMinutes) && (timeMinutes <= 864)) { //yellow
      Serial.print("yellow");
      analogWrite(RED, 255);
      analogWrite(GREEN, 223);
      analogWrite(BLUE, 0);

  } else if ((865 <= timeMinutes) && (timeMinutes <= 869)) { //yellow-navy
      Serial.print("yellow-navy");
      analogWrite(RED, 255);
      analogWrite(GREEN, 223);
      analogWrite(BLUE, 0);
    for (int i = 0; i < 255; i += 1)
    {
      delay(942);
      redValue -= 1;
      analogWrite(RED, redValue);
      if (redValue < 223) {
        greenValue -= 1;
        analogWrite(GREEN, greenValue);
      }
      if (redValue < 128) {
        blueValue += 1;
        analogWrite(BLUE, blueValue);
      }
    }

  } else if ((870 <= timeMinutes) && (timeMinutes <= 959)) { //navy
      Serial.print("navy");
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 128);

  } else if ((960 <= timeMinutes) && (timeMinutes <= 964)) { //navy-lred
      Serial.print("navy-lred");
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 128);
    for (int i = 0; i < 255; i += 1)
    {
      delay(942);
      redValue += 1;
      analogWrite(RED, redValue);
      if (redValue > 150) {
        greenValue += 1;
        analogWrite(GREEN, greenValue);
      }
      if (redValue > 224) {
        blueValue -= 1;
        analogWrite(BLUE, blueValue);
      }
    }

  } else if ((965 <= timeMinutes) && (timeMinutes <= 1014)) { //light red
      Serial.print("light red");
      analogWrite(RED, 255);
      analogWrite(GREEN, 105);
      analogWrite(BLUE, 97);

  } else if ((1015 <= timeMinutes) && (timeMinutes <= 1019)) { //lred - rred
      Serial.print("lightred-rrred");
      analogWrite(RED, 255);
      analogWrite(GREEN, 105);
      analogWrite(BLUE, 97);
    for (int i = 0; i < 100; i += 1)
    {
      delay(2401);
      redValue -= 1;
      analogWrite(RED, redValue);
      if (redValue < 243) {
        greenValue -= 1;
        analogWrite(GREEN, greenValue);
      }
      if (redValue < 222) {
        blueValue -= 1;
        analogWrite(BLUE, blueValue);
      }
    }

  } else if ((1020 <= timeMinutes) && (timeMinutes <= 1109)) { //ruby red
      Serial.print("ruby red");
      analogWrite(RED, 155);
      analogWrite(GREEN, 17);
      analogWrite(BLUE, 30);

  } else if ((1110 <= timeMinutes) && (timeMinutes <= 1119)) { //rred-off
      Serial.print("rred-off");
      analogWrite(RED, 155);
      analogWrite(GREEN, 17);
      analogWrite(BLUE, 30);
    for (int i = 0; i < 155; i += 1)
    {
      delay(3484);
      redValue -= 1;
      analogWrite(RED, redValue);
      if (redValue < 30) {
        blueValue -= 1;
        analogWrite(BLUE, blueValue);
      }
      if (redValue < 17) {
        greenValue -= 1;
        analogWrite(GREEN, greenValue);
      }
    }

  } else if ((1120 <= timeMinutes) && (timeMinutes <= 1159)) { //fadeout
      Serial.print("blank");
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);

  } else if ((1160 <= timeMinutes) && (timeMinutes <= 1169)) { //off-turquoise
      Serial.print("off-tuqruotise");
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
    for (int i = 0; i < 224; i += 1)
    {
      delay(2411);
      greenValue += 1;
      analogWrite(GREEN, greenValue);
      if (greenValue > 16) {
        blueValue += 1;
        analogWrite(BLUE, blueValue);
      }
      if (greenValue > 160) {
        redValue += 1;
        analogWrite(RED, redValue);
      }
    }
      
  } else if ((1170 <= timeMinutes) && (timeMinutes <= 1259)) { //turquoise
      Serial.print("turquoise");
      analogWrite(RED, 64);
      analogWrite(GREEN, 224);
      analogWrite(BLUE, 208);

  } else if ((1260 <= timeMinutes) && (timeMinutes <= 1269)) { //turquoise-brown
      Serial.print("turqoruise-brown");
      analogWrite(RED, 64);
      analogWrite(GREEN, 224);
      analogWrite(BLUE, 208);
    for (int i = 0; i < 208; i += 1)
    {
      delay(2597);
      blueValue -= 1;
      analogWrite(BLUE, blueValue);
      if (blueValue < 149) {
        greenValue -= 1;
        analogWrite(GREEN, greenValue);
      }
      if (blueValue < 86) {
        redValue += 1;
        analogWrite(RED, redValue);
      }
    }

  } else if ((1270 <= timeMinutes) && (timeMinutes <= 1309)) { //brown
      Serial.print("brown");
      analogWrite(RED, 150);
      analogWrite(GREEN, 75);
      analogWrite(BLUE, 0);

  } else if ((1310 <= timeMinutes) && (timeMinutes <= 1319)) { //brown - magenta
      Serial.print("brown-magenta");
      analogWrite(RED, 150);
      analogWrite(GREEN, 75);
      analogWrite(BLUE, 0);
    for (int i = 0; i < 123; i += 1)
    {
      delay(4391);
      blueValue += 1;
      analogWrite(BLUE, blueValue);
      if (blueValue > 71) {
        redValue -= 1;
        analogWrite(RED, redValue);
      }
      if (blueValue > 79) {
        greenValue -= 1;
        analogWrite(GREEN, greenValue);
      }
    }

  } else if ((1320 <= timeMinutes) && (timeMinutes <= 1389)) { //magenta
      Serial.print("magenta");
      analogWrite(RED, 202);
      analogWrite(GREEN, 31);
      analogWrite(BLUE, 123);

  } else if ((1390 <= timeMinutes) && (timeMinutes <= 1399)) { //magenta-fgreen
      Serial.print("magetna-fgreen");
      analogWrite(RED, 202);
      analogWrite(GREEN, 31);
      analogWrite(BLUE, 123);
    for (int i = 0; i < 168; i += 1)
    {
      delay(3215);
      redValue -= 1;
      analogWrite(RED, redValue);
      if (redValue < 142) {
        greenValue += 1;
        analogWrite(GREEN, greenValue);
      }
      if (redValue < 123) {
        blueValue -= 1;
        analogWrite(BLUE, blueValue);
      }
    }

  } else if ((1400 <= timeMinutes) && (timeMinutes <= 1429)) { //forest green
      Serial.print("fgreen");
      analogWrite(RED, 34);
      analogWrite(GREEN, 139);
      analogWrite(BLUE, 34);

  } else if ((1430 <= timeMinutes) && (timeMinutes <= 1439)) { //fgreen-off
      Serial.print("fgreen-off");
      analogWrite(RED, 34);
      analogWrite(GREEN, 139);
      analogWrite(BLUE, 34);
    for (int i = 0; i < 139; i += 1)
    {
      delay(3885);
      greenValue -= 1;
      analogWrite(GREEN, greenValue);
      if (greenValue < 34) {
        greenValue -= 1;
        analogWrite(GREEN, greenValue);
        blueValue -= 1;
        analogWrite(BLUE, blueValue);
      }
    }
 
  } else { 
      Serial.print("no time zone");
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
      
      
  } //close if

} //close colorChangeIf method
