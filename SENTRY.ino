#include <Servo.h>
Servo servo;
int servoPin= 10;
int angle= 0;
int motorPin = 3;
int trigPin = 6;
int echoPin = 7;
int irpin= 4;
long duration;
int distance;
int irmotion;
int detected=0;

void setup() {
Serial.begin(9600);
servo.attach(servoPin);
//Serial.println("Set Angle 0 to 180");
pinMode(motorPin, OUTPUT);
pinMode(trigPin, OUTPUT); 
pinMode(12, OUTPUT);
pinMode(echoPin, INPUT); 
pinMode(irpin,INPUT);
pinMode(13,OUTPUT);
delay(30000);//6000
}
void loop() {
while (angle < 180 )
{
  servo.write(angle);
  angle++;
  Serial.println(angle);
  sensores();
   if (detected==1)
  {
    delay(1000);
    Serial.print("Distance: ");   
    Serial.println(distance);
    //down();
  }
  else
  {
  delay (30);
  }
  detected=0;
}
while(angle >0 )
{
  servo.write(angle);
  angle--;
  Serial.println(angle);
  sensores();
  if (detected==1)
  {
    Serial.print("Distance: ");   
    Serial.println(distance);
    delay(1000);
    //down();
  }
  else
  {
  delay (30);
  }
  detected=0;
}

}
int sensores()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  irmotion = digitalRead(irpin); 
if(irmotion ==1)//detecta um humano, a variavel fica 1 alguns segundos enquanto que o HC varre a area pelo humano
{
digitalWrite( 13, HIGH);
if (distance < 100 && distance > 35)//20 cm de firing range
{
digitalWrite( 12, HIGH);//acende LED vermelha
digitalWrite(motorPin, HIGH);//ativa o motor de disparo
delay(300);
digitalWrite(motorPin, LOW);
delay(3000);//MOVEEEEEEEEEEEEEEEEEEEEEEEEEE
detected=1;
}
}
down();
}

int down()
{
/*
//testes de controlo
Serial.print("Distance: ");   
Serial.println(distance);
Serial.print("irmotion: ");  
Serial.println(irmotion);
*/
//desligar leds
delay(100);
digitalWrite( 12, LOW);
digitalWrite(13,LOW);
}
//NO ARDUINOS NOR SENSORS WERE HARMED DURING THIS PROJECT.
