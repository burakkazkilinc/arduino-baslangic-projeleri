#define echoPin 7
#define trigPin 6
#define LEDPin 12
#define LEDBir 9
#define LEDIki 4
#define LEDUc 2
#define SES 10

int maxRange = 200;
int minRange= 0;
long duration,distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(LEDPin,OUTPUT);
  pinMode(LEDBir,OUTPUT);
  pinMode(LEDIki,OUTPUT);
  pinMode(LEDUc,OUTPUT);
  pinMode(SES,OUTPUT);
}

void LEDMesafe(int distance)
{
  if(distance<=15)  //15 cm kala
  {
    digitalWrite(LEDBir,HIGH);
    digitalWrite(LEDIki,HIGH);
    digitalWrite(LEDUc,HIGH);
    digitalWrite(SES,HIGH);
    
  }
  else if(distance<=30) //30 cm kala
  {
    digitalWrite(LEDBir,HIGH);
    digitalWrite(LEDIki,HIGH);
    digitalWrite(LEDUc,LOW);
    digitalWrite(SES,LOW);
  }
  else if(distance<=45) //45 cm kala
  {
    digitalWrite(LEDBir,HIGH);
    digitalWrite(LEDIki,LOW);
    digitalWrite(LEDUc,LOW);
    digitalWrite(SES,LOW);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration/58.2;
  if(distance>=maxRange || distance <= minRange)
  {
    Serial.println("-1");
    digitalWrite(LEDBir,LOW);
    digitalWrite(LEDIki,LOW);
    digitalWrite(LEDUc,LOW);
    digitalWrite(LEDPin,HIGH);
  }
  else
  {
     Serial.println(distance);
     LEDMesafe(distance);
     digitalWrite(LEDPin,LOW);   
  }  
  delay(50);  
}