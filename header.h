#ifndef _HEADER_H_
#define _HEADER_H_

class DriveBase {
  public:
    const int ENA = 4;
    const int IN1 = 3;
    const int IN2 = 2;
    const int IN3 = 10;
    const int IN4 = 9;
    const int ENB = 8;  
    int LEDR = 11;
    int LEDG = 12;
    int LEDB = 0;

    void Init() {
      pinMode(IN1, OUTPUT);
      pinMode(IN2, OUTPUT);
      pinMode(IN3, OUTPUT);
      pinMode(IN4, OUTPUT);
      pinMode(ENA, OUTPUT);
      pinMode(ENB, OUTPUT);
      pinMode(LEDR, OUTPUT);
      pinMode(LEDG, OUTPUT);
      pinMode(LEDB, OUTPUT);
      Serial.begin(9600);
    }
  private:
    // int x = 1;
};

#endif // _HEADER_H_