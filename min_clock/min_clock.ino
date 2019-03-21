#include <Wire.h>
#include <DS3231.h>
#include <Stepper.h>

DS3231  rtc(SDA, SCL);

long sec;
long m=0;
#define FFPIN 2
int rep=0;

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
//Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
Stepper myStepper(stepsPerRevolution, 11, 9, 10, 8);


void setup() { 
  // set the speed at 60 rpm:
  myStepper.setSpeed(1);
  // initialize the serial port:
  Serial.begin(9600);

  rtc.begin();
  sec = rtc.getUnixTime(rtc.getTime());

  pinMode(FFPIN, INPUT);
}

void loop() {
  int  buttonState = digitalRead(FFPIN);
  if ( buttonState == HIGH ){
    rep += 1; //key repeat
    if ( rep > 180 ){
      myStepper.setSpeed(8);
    }
    else if ( rep > 120 ){
      myStepper.setSpeed(4);
    }
    else if ( rep > 60 ){
      myStepper.setSpeed(2);
    }
    else{
      myStepper.setSpeed(1);
    }
    myStepper.step(1);
  }
  else{
    rep = 0;
    //clock mode
    //60 sec == 2048 steps
    //so the motor progresses 2048/60 steps per second
    //m is the numerator of the fraction.
    //1 sec ~ 34 steps
    long delta = rtc.getUnixTime(rtc.getTime()) - sec;
    if ( m + delta*2048L >= 60L * 34L ){
      long n = (m + delta*2048L) / 60L;
      myStepper.setSpeed(2);
      myStepper.step(n);
      sec += delta;
      m = m + delta*2048L - 60L*n;
    }
    Serial.println(sec);
    delay(100);
  }
}
