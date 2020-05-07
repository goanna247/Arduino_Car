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