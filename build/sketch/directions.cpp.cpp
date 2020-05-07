#include <Arduino.h>
#line 1 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\directions.cpp"
#include "header.h"

DriveBase _driveBase;


#line 6 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\directions.cpp"
void forwards(int speed, int waitTime);
#line 24 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\directions.cpp"
void backwards(int speed, int waitTime);
#line 42 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\directions.cpp"
void oneWheelRight(int speed, int waitTime);
#line 59 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\directions.cpp"
void twoWheelRight(int speed, int waitTime);
#line 76 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\directions.cpp"
void oneWheelLeft(int speed, int waitTime);
#line 93 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\directions.cpp"
void twoWheelLeft(int speed, int waitTime);
#line 110 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\directions.cpp"
void breaking();
#line 115 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\directions.cpp"
void LEDROn();
#line 120 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\directions.cpp"
void LEDOff();
#line 124 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\directions.cpp"
void RGB_colour(int LEDR_value, int LEDG_value, int LEDB_value);
#line 23 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\main.ino"
void setup();
#line 30 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\main.ino"
void loop();
#line 6 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\directions.cpp"
void forwards (int speed, int waitTime) {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  digitalWrite(_driveBase.IN1, HIGH);
  digitalWrite(_driveBase.IN2, LOW);
  digitalWrite(_driveBase.IN3, HIGH);
  digitalWrite(_driveBase.IN4, LOW);
  analogWrite(_driveBase.ENA, speed);
  analogWrite(_driveBase.ENB, speed);

  delay(waitTime);

  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);

  Serial.write("forwards");
}

void backwards (int speed, int waitTime) {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  digitalWrite(_driveBase.IN1, LOW);
  digitalWrite(_driveBase.IN2, HIGH);
  digitalWrite(_driveBase.IN3, LOW);
  digitalWrite(_driveBase.IN4, HIGH);
  analogWrite(_driveBase.ENA, speed);
  analogWrite(_driveBase.ENB, speed);

  delay(100);

  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);

  Serial.write("backwards");
}

void oneWheelRight (int speed, int waitTime) {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  digitalWrite(_driveBase.IN1, HIGH);
  digitalWrite(_driveBase.IN2, LOW);
  digitalWrite(_driveBase.IN3, LOW);
  digitalWrite(_driveBase.IN4, LOW);
  analogWrite(_driveBase.ENA, speed);
  analogWrite(_driveBase.ENB, speed);

  delay(100);

  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  Serial.write("oneWheelRight");
}

void twoWheelRight (int speed, int waitTime) {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  digitalWrite(_driveBase.IN1, HIGH);
  digitalWrite(_driveBase.IN2, LOW);
  digitalWrite(_driveBase.IN3, LOW);
  digitalWrite(_driveBase.IN4, HIGH);
  analogWrite(_driveBase.ENA, speed);
  analogWrite(_driveBase.ENB, speed);

  delay(100);

  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  Serial.write("twoWheelRight");
}

void oneWheelLeft (int speed, int waitTime) {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  digitalWrite(_driveBase.IN1, LOW);
  digitalWrite(_driveBase.IN2, LOW);
  digitalWrite(_driveBase.IN3, HIGH);
  digitalWrite(_driveBase.IN4, LOW);
  analogWrite(_driveBase.ENA, speed);
  analogWrite(_driveBase.ENB, speed);

  delay(100);

  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
Serial.write("oneWheelLeft");
}

void twoWheelLeft (int speed, int waitTime) {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  digitalWrite(_driveBase.IN1, LOW);
  digitalWrite(_driveBase.IN2, HIGH);
  digitalWrite(_driveBase.IN3, HIGH);
  digitalWrite(_driveBase.IN4, LOW);
  analogWrite(_driveBase.ENA, speed);
  analogWrite(_driveBase.ENB, speed);

  delay(100);

  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
Serial.write("twoWheelLeft");
}

void breaking() {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
}

void LEDROn() {
  //Red for speeeeeeeeeeed
  RGB_colour(255, 0, 0);
}

void LEDOff() {
  RGB_colour(0, 0, 0);
}

void RGB_colour(int LEDR_value, int LEDG_value, int LEDB_value) {
  analogWrite(_driveBase.LEDR, LEDR_value);
  analogWrite(_driveBase.LEDG, LEDG_value);
  analogWrite(_driveBase.LEDB, LEDB_value);
}
#line 1 "c:\\Users\\61412\\Documents\\code\\Arduino stuff\\Car\\main.ino"
#include <boarddefs.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremote.h>
#include <IRremoteInt.h>

// to any one who is looking at my code, this is object oriented c++
// we define the object in the class (header.h) then call an instance of it
// because we have only one drivebase we can define the ports in the header as well
// i might make this into a library later so that its easier for people who are just starting to code

#include <IRremote.h>
#include "header.h"

int RECV_PIN = 11;
int x = 150;
int y = 300;
bool stop;
bool going;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  _driveBase.Init();
  Serial.println("Enabeling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled the IRin");
}

void loop() {

  // remoteDrive();
  if(irrecv.decode(&results)) {
    Serial.println(results.value,HEX);
    irrecv.resume();
  }

  if(results.value == 0xFF629D) {
    going = true;
    if (!stop) {
      while (going) {
        forwards(150, 100);
        if (results.value == 0xFF6897){
          going = false;
        }
      }
    }else {
    forwards(150, y);
    }
  } else if(results.value == 0xFFA857) {
    going = true;
    if (!stop) {
      while(going) {
        backwards(150, 100);
        if (results.value == 0xFF6897){
          going = false;
        }
      }
    } else {
      backwards(150, x);
    }
  } else if(results.value == 0xFFC23D) {
    going = true;
    if (!stop) {
      while(going) {
        twoWheelRight(150, 100);
        if (results.value == 0xFF6897) {
          going = false;
        }
      }
    } else {
    twoWheelRight(150, x);
    }
  } else if(results.value == 0xFF22DD){
    going = true;
    if (!stop) {
      while(going) {
        twoWheelLeft(150, 100);
        if (results.value == 0xFF6897) {
          going = false;
        }
      }
    } else {
    twoWheelLeft(150, x);
    }
  } else if(results.value == 0xFF7A85){
    x = 500;
  } else if(results.value == 0xFF18E7){
    x = 250;
  } else if(results.value == 0xFF30CF){
    x = 100;
  } else if(results.value == 0xFFB04F){
    y = 500;
  } else if(results.value == 0xFF9867){
    y = 350;
  } else if(results.value == 0xFF6897){
    y = 200;
  } else if (results.value == 0xFF6897){
    //dosn't stop
    stop = false;
    LEDROn();
  } else if (results.value == 0xFF6897){
    //does stop
    stop = true;
    LEDOff();
  }
} 
