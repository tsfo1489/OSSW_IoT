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

const int water_pin = A0;  // Water Sensor Input
const int LED_R = 8;
const int LED_G = 9;
const int LED_B = 10;
const int ir_height = 3;
const int buzz = 6;
const int human = 4;
const int light_pin = A1;
Servo watering;
int ser_pos = 0;
LiquidCrystal_I2C lcd(0x3f,16,2);
int tick = 0;
int lcd_stat = 0;
float avg[10];
int song_played=0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(human, INPUT);
  pinMode(ir_height, INPUT);
  watering.attach(5);
  lcd.begin();
  lcd.noBacklight();
}
void song(){
  int note_4 = 260;
  int note_2 = note_4*2;
  int note_8 = note_4/2;
  int note_16 = note_8/2;
  /*
  tone(buzz,NOTE_F4);
  delay(note_4+note_8);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_F4);
  delay(note_8);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_C5);
  delay(note_4+note_4);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_C5);
  delay(note_4);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_G4);
  delay(note_8+note_16);
  tone(buzz,NOTE_A4);
  delay(note_16);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_C5);
  delay(note_2);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_G4);
  delay(note_4);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_F4);
  delay(note_8+note_16);
  tone(buzz,NOTE_A4);
  delay(note_16);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_G4);
  delay(note_4);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_F4);
  delay(note_8);
  tone(buzz,NOTE_G4);
  delay(note_8);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_C4);
  delay(note_4+note_2);
  noTone(buzz);
  delay(50+note_4);
  //백두산 정기뻗은 삼천리 강산
  
  tone(buzz,NOTE_D4);
  delay(note_4+note_8);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_D4);
  delay(note_8);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_G4);
  delay(note_4+note_4);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_AS4);
  delay(note_4);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_A4);
  delay(note_16+note_8);
  tone(buzz,NOTE_G4);
  delay(note_16);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_D5);
  delay(note_2);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_C5);
  delay(note_4+note_8);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_D5);
  delay(note_8);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_C5);
  delay(note_4);
  noTone(buzz);
  delay(50);
 
  tone(buzz,NOTE_G4);
  delay(note_8+note_16);
  tone(buzz,NOTE_A4);
  delay(note_16);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_C5);
  delay(note_4+note_2);
  noTone(buzz);
  delay(50+note_4);
  // 무궁화 대한으 온 누리의 빛
  tone(buzz,NOTE_F4);
  delay(note_4+note_8);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_F4);
  delay(note_8);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_F5);
  delay(note_4+note_4);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_F5);
  delay(note_4);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_C5);
  delay(note_16+note_8);
  tone(buzz,NOTE_D5);
  delay(note_16);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_F5);
  delay(note_2);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_D5);
  delay(note_4);
  tone(buzz,NOTE_A4);
  delay(note_4);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_D5);
  delay(note_2);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_D5);
  delay(note_4);  
  tone(buzz,NOTE_C5);
  delay(note_8);
  tone(buzz,NOTE_D5);
  delay(note_8);  
  noTone(buzz);
  delay(50);
 
  tone(buzz,NOTE_G4);
  delay(note_2);  
  noTone(buzz);
  delay(50);
 // 화랑의 핏줄타고 자라난 우리
  tone(buzz,NOTE_C5);
  delay(note_4+note_8);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_AS4);
  delay(note_8);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_A4);
  delay(note_2);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_G4);
  delay(note_4);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_A4);
  delay(note_8);
  tone(buzz,NOTE_F4);
  delay(note_8);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_D5);
  delay(note_2);
  noTone(buzz);
  delay(50);
 
  tone(buzz,NOTE_C5);
  delay(note_2);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_C5);
  delay(note_2);
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_G4);
  delay(note_4);  
  tone(buzz,NOTE_C5);
  delay(note_4);  
  noTone(buzz);
  delay(50);
 
  tone(buzz,NOTE_F4);
  delay(note_2);  
  noTone(buzz);
  delay(50);
  //그 이름 용감하다 대 한 육군
  */
  tone(buzz,NOTE_A4);
  delay(note_8+note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_A4);
  delay(note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_A4);
  delay(note_4);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_D5);
  delay(note_8+note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_A4);
  delay(note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_A4);
  delay(note_4);  
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_A4);
  delay(note_4/3);
  tone(buzz,NOTE_G4);
  delay(note_4/3);  
  tone(buzz,NOTE_A4);
  delay(note_4/3);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_D4);
  delay(note_4);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_D4);
  delay(note_2);  
  noTone(buzz);
  delay(50);
  //앞으로 앞으로 용진또용진
  tone(buzz,NOTE_G4);
  delay(note_8+note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_G4);
  delay(note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_G4);
  delay(note_4);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_C5);
  delay(note_8+note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_G4);
  delay(note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_G4);
  delay(note_4);  
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_G4);
  delay(note_4/3);
  tone(buzz,NOTE_F4);
  delay(note_4/3);  
  tone(buzz,NOTE_G4);
  delay(note_4/3);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_C4);
  delay(note_4);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_C4);
  delay(note_2);  
  noTone(buzz);
  delay(50);
  //우리는 영원한 조국의 방패
  tone(buzz,NOTE_C4);
  delay(note_8+note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_C4);
  delay(note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_D4);
  delay(note_4);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_D4);
  delay(note_8+note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_E4);
  delay(note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_F4);
  delay(note_4);  
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_F4);
  delay(note_4/3);
  tone(buzz,NOTE_E4);
  delay(note_4/3);  
  tone(buzz,NOTE_D4);
  delay(note_4/3);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_A4);
  delay(note_4);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_A4);
  delay(note_2);  
  noTone(buzz);
  delay(50);
  //앞으로 앞으로 용진또용진(2)
  tone(buzz,NOTE_D5);
  delay(note_8+note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_A4);
  delay(note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_A4);
  delay(note_4);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_G4);
  delay(note_8+note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_A4);
  delay(note_16);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_D5);
  delay(note_4);  
  noTone(buzz);
  delay(50);
  
  tone(buzz,NOTE_D5);
  delay(note_4/3);
  tone(buzz,NOTE_C5);
  delay(note_4/3);  
  tone(buzz,NOTE_D5);
  delay(note_4/3);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_F5);
  delay(note_4);  
  noTone(buzz);
  delay(50);

  tone(buzz,NOTE_F5);
  delay(note_2);  
  noTone(buzz);
  delay(50);
  //우리는 영원한 조국의 방패
}


float get_height(){
  if(digitalRead(ir_height) == HIGH) return 0;
  return 1;
}
int get_water(){  // 이상 상태면 1 정상이면 0
  int sensorValue;
  sensorValue = analogRead(water_pin);
  Serial.print("Water Sensor: ");
  Serial.println(sensorValue);
  if(sensorValue > 550) {
    watering.write(90);
    return 0;
  }
  else if (sensorValue <500) {
    watering.write(0);
    return 1;
  }
}
int get_light(){
  int sensorValue;
  sensorValue = analogRead(light_pin);
  Serial.print("Light Sensor: ");
  Serial.println(sensorValue);
  if(sensorValue > 740) return 1;
  else return 0;
}
int get_human(){
 if (digitalRead(human) == HIGH) return 1;
 else return 0;
}

void loop() {
  tick++;
  int water_sensor = get_water();
  int light_sensor = get_light();
  int h = get_height();
  
  lcd.setCursor(0,1);
  if(h == 1){
    lcd.print("Hello, world!");
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_R,LOW);
    digitalWrite(LED_B,LOW);
    if(song_played == 0) {
      song_played = 1;
      song();
    }
  }
  else{
    lcd.print("Growing......");
    digitalWrite(LED_G,LOW);
    song_played = 0;
    if(water_sensor == 1) {
      if(light_sensor == 0) noTone(buzz);
      else tone(buzz,131);
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_B, LOW);
    }
    else if(light_sensor == 1) {
      tone(buzz,131);
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_B, LOW);
    }
    else{
      noTone(buzz);
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_B, HIGH);
    }
  }
  lcd.setCursor(0,0);
  lcd.print("Water:");
  lcd.setCursor(6,0);
  if(water_sensor) lcd.print("F  ");
  else lcd.print("T  ");

  lcd.print("Light:");
  if(light_sensor) lcd.print("F");
  else lcd.print("T");
    
  if(get_human() == 1) {
    lcd_stat = tick;
    lcd.backlight();
  }
  else if(tick - lcd_stat > 12) {
    lcd.noBacklight();
  }
  delay(250);
}
