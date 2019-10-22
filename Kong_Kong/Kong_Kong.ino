#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

const int analogInPin = A0;  // Water Sensor Input
const int LED_R = 8;
const int LED_G = 9;
const int LED_B = 10;
const int trig = 2;
const int echo = 3;
const int buzz = 6;
const int human = 4;
int sensorValue = 0;        // value read from the water sensor
Servo watering;
int ser_pos = 0;
LiquidCrystal_I2C lcd(0x3f,16,2);
int tick = 0;
int lcd_stat = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(human, INPUT);
  watering.attach(5);
  lcd.begin();
  lcd.noBacklight();
}

float get_height(){
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  unsigned long duration = pulseIn(echo, HIGH); 
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  float distance = 15.0 - ((float)(340 * duration) / 10000) / 2;  
  if (distance < 0) distance = 0.0;
  return distance;
}
int get_water(){
  sensorValue = analogRead(analogInPin);
  if(sensorValue > 550) {
    digitalWrite(LED_R,LOW);
    digitalWrite(LED_B,HIGH);
    watering.write(0);
  }
  else if (sensorValue <500) {
    watering.write(90);
    digitalWrite(LED_R,HIGH);
    digitalWrite(LED_B,LOW);
  }
  else {
    digitalWrite(LED_R,HIGH);
    digitalWrite(LED_B,HIGH);
  }
  return sensorValue;
}
void song(){
  int note_4 = 500;
  int note_8 = note_4/2;
  int note_16 = note_4/2;
}

int get_human(){
 if (digitalRead(human) == HIGH) return 1;
 else return 0;
}

void loop() {
  tick++;
  int water_sensor = get_water();
  Serial.print("sensor = ");
  Serial.println(water_sensor);
  
  float h = get_height();
  Serial.print("Height: ");
  Serial.println(h);
  if(h > 10.0) song();
  lcd.setCursor(0,0);
  lcd.print("Water:");;
  lcd.setCursor(6,0);
  lcd.print("   ");
  lcd.setCursor(6,0);
  lcd.print(water_sensor);

  lcd.setCursor(0,1);
  lcd.print("Height:");;
  lcd.setCursor(7,1);
  lcd.print("      ");
  lcd.setCursor(7,1);
  lcd.print(h);
  lcd.setCursor(15,0);
  if(get_human() == 1) {
    lcd_stat = tick;
    lcd.backlight();
  }
  else if(tick - lcd_stat > 6) {
    lcd.noBacklight();
  }
  lcd.print(get_human());
  delay(500);
}
