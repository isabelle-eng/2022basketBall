//농구대 만들기
 
#define TRIG 9 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO 8 //ECHO 핀 설정 (초음파 받는 핀)
 
int led = 13;
int led2 = 11;
int speakerpin = 5;
 
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(led, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(speakerpin, OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
    long duration, distance;  //시간, 거리
 
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
 
    duration = pulseIn (ECHO, HIGH);
    distance = duration * 17 / 1000;  //cm변환
    Serial.println(duration ); 
    Serial.print("\nDIstance : ");
    Serial.print(distance);
    Serial.println(" Cm");
    delay(10); 
 
    if (distance<10) {  //공과 센서 사이 거리가 10cm
        digitalWrite(led, HIGH);
        digitalWrite(led2, HIGH);
        tone(speakerpin, 73, 1000);
    }
    else {
        digitalWrite(led, LOW);
        digitalWrite(led2, LOW);
        noTone(speakerpin);
    }
}
