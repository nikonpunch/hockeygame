#include <Arduino.h>

int led1 = 8;     //led1
int led2 = 9;     //led2
int led3 = 10;    //led3
int led4 = 11;    //led4
int sensor1 = 2;  //sensor1
int sensor2 = 3;  //sensor2 
int sensor3 = 4;  //sensor 3
int reset = 5;    //reset button
int speakerpin = 13; //speaker pin assignment
bool allhit = false;    // All targets hit
bool target1 = false;   // Target 1 bool
bool target2 = false;   // Target 2 bool
bool target3 = false;   // Target 3 bool
bool target4 = false;   // Target 4 bool
int haswon = 0; // var for running win command once

void setup() {
//setup code 
Serial.begin(9600);
pinMode (led1,OUTPUT);
pinMode (led2,OUTPUT);
pinMode (led3,OUTPUT);
pinMode (led4,OUTPUT);
pinMode (sensor1,INPUT);
pinMode (sensor2,INPUT);
pinMode (sensor3,INPUT);
pinMode (reset, INPUT);
}
void loop()
{ 
int vibsen1 = digitalRead(sensor1);
int vibsen2 = digitalRead(sensor2);
int vibsen3 = digitalRead(sensor3);

// Reset Game
int resetgame = digitalRead(reset);
if (resetgame == HIGH)
  {
    allhit = false;
    target1 = false;
    target2 = false;
    target3 = false;
    haswon = 0;
    Serial.println("RESET");
    delay(500);
  }
  
//win sequence 
if (target1&&target2&&target3==true and haswon==0) 
  {
    allhit = true;
    Serial.println("All Targets Hit");
    digitalWrite(led4, HIGH); 
    tone(speakerpin, 1000, 100);
    delay(500);
    tone(speakerpin, 2000, 100);
    delay(500);
    tone(speakerpin, 1500, 100);
    delay(500);
    noTone(speakerpin);
    haswon++;
  }
  
//keep WIN LED off until player wins
if (allhit == false) 
  {
    digitalWrite(led4, LOW);
  }
  
//Sensor 1 
if (vibsen1 == LOW&&target1 == false) //look for hit if no previous hit
  {
    target1 = true; // target has been hit
    Serial.println("Target 1 hit");
    tone(speakerpin, 1000, 100);
    delay(100);
  }
else 
  {
    digitalWrite(led1, LOW);
    //Serial.println("Not touched");
  }
if (target1 == true) // Turn on LED on hit
  {
    digitalWrite(led1, HIGH);
  }
else
  {
    digitalWrite(led1, LOW);
  }
  
//Sensor 2 
if (vibsen2 == LOW&&target2==false)
  {
    target2 = true;
    Serial.println("Target 2 hit");
    tone(speakerpin, 1500, 100);
    delay(100);
  }
else 
  {
    digitalWrite(led2, LOW);
    //Serial.println("Not touched");
  }
if (target2 == true) // Turn on LED on hit
  {
    digitalWrite(led2, HIGH);
  }
else
  {
    digitalWrite(led2, LOW);
  }
  
//Sensor 3
if (vibsen3 == LOW&&target3 == false)
  {
    target3 = true;
    tone(speakerpin, 2000, 100);
    Serial.println("Target 3 hit");
    delay(100);
  }
else 
  {
    digitalWrite(led3, LOW);
    //Serial.println("Not touched");
  }
if (target3 == true) // Turn on LED on hit
  {
    digitalWrite(led3, HIGH);
  }
else
  {
    digitalWrite(led3, LOW);
  }
  
}
