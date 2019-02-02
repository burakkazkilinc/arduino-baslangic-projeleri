#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#define DHT11PIN 2
dht11 DHT11;
 
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup()
{
// LCD yi çalıştır
lcd.begin();
lcd.backlight();
 
// Ekrana yazdırılacak metin
/*lcd.print("     Burak     ");
lcd.setCursor(0,1);
lcd.print("   KAZKILINC   ");*/
}
 
void loop()
{
    int chk = DHT11.read(DHT11PIN);
    lcd.print("Nem (%): ");
    lcd.print((float)DHT11.humidity, 2);
    lcd.setCursor(0,1); 
    lcd.print("Sicaklik: ");
    lcd.print((float)DHT11.temperature, 2);
    lcd.setCursor(0,0); //imlec basa aliniyor
    /*
    // Çiğ Oluşma Noktası, Dew Point
    Serial.print("Cig Olusma Noktasi: ");
    Serial.println(DHT11.dewPoint(), 2); */
    /*delay(3000); 
    lcd.noBacklight();*/
    delay(10000);  // 10 saniyede bir veri yenilemesi yapiliyor  
    //lcd.backlight();
}
