#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#include <stdio.h>
#include <DS1302.h>
#define DHT11PIN 2
dht11 DHT11;
 
LiquidCrystal_I2C lcd(0x27, 16, 2);

namespace {

// Set the appropriate digital I/O pin connections. These are the pin
// assignments for the Arduino as well for as the DS1302 chip. See the DS1302
// datasheet:
//
//   http://datasheets.maximintegrated.com/en/ds/DS1302.pdf
const int kCePin   = 4;  // Chip Enable
const int kIoPin   = 5;  // Input/Output
const int kSclkPin = 6;  // Serial Clock

// Create a DS1302 object.
DS1302 rtc(kCePin, kIoPin, kSclkPin);

String dayAsString(const Time::Day day) {
  switch (day) {
    case Time::kSunday: return "Pazar";
    case Time::kMonday: return "Pazartesi";
    case Time::kTuesday: return "Sali";
    case Time::kWednesday: return "Carsamba";
    case Time::kThursday: return "Persembe";
    case Time::kFriday: return "Cuma";
    case Time::kSaturday: return "Cumartesi";
  }
  return "(Bilinmeyen gun)";
}

int printTime() {
  // Get the current time and date from the chip.
  Time t = rtc.time();
  // Name the day of the week.
  const String day = dayAsString(t.day);
  String ay;

  switch (t.mon)
  {
    case 1: ay="Ocak"; break;
    case 2: ay="Subat"; break;
    case 3: ay="Mart"; break;
    case 4: ay="Nisan"; break;
    case 5: ay="Mayis"; break;
    case 6: ay="Haziran"; break;
    case 7: ay="Temmuz"; break;
    case 8: ay="Agustos"; break;
    case 9: ay="Eylul"; break;
    case 10: ay="Ekim"; break;
    case 11: ay="Kasim"; break;
    case 12: ay="Aralik"; break;
    }

  lcd.setCursor(0,0);
  lcd.print("  SAAT:");
  lcd.print(t.hr);
  lcd.print(":");
  lcd.print(t.min);
  lcd.print(":");
  lcd.print(t.sec);
  lcd.setCursor(0,1); 
  lcd.print("  "); 
  lcd.print(t.date);  
  lcd.print(" ");
  lcd.print(ay);
  lcd.print(" ");  
  lcd.print(day.c_str());
  lcd.setCursor(0,0);
  return t.sec;
  }

}

void setup()
{
// LCD yi çalıştır
lcd.begin();
lcd.backlight();
}

void printTemp()
{
  int chk = DHT11.read(DHT11PIN);
    lcd.print("Nem (%): ");
    lcd.print((float)DHT11.humidity, 2);
    lcd.setCursor(0,1); 
    lcd.print("Sicaklik: ");
    lcd.print((float)DHT11.temperature, 2);
    lcd.setCursor(0,0);
    /*
    // Çiğ Oluşma Noktası, Dew Point
    Serial.print("Cig Olusma Noktasi: ");
    Serial.println(DHT11.dewPoint(), 2); */
    /*delay(3000); 
    lcd.noBacklight();  //ekran isigi kapatma */
}
 
void loop()
{
    int sayi1=printTime(); 
     switch (sayi1){     
    case 30:         
    case 60:
    case 0:
    lcd.setCursor(0,1);
    lcd.print("                "); 
    lcd.setCursor(0,0);   
    lcd.print("                "); 
    lcd.setCursor(0,0);    
    printTemp();
    delay(5000);  break;   
    }
}
