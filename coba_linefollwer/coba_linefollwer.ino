#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeShield.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeLineFollower linefollower_3(3);
MeDCMotor motor_2(2);
MeDCMotor motor_9(9);



void setup(){
    
}

void loop(){
    
    if(((linefollower_3.readSensors())==(3))){
        motor_2.run(0);
        motor_9.run(0);
        _delay(0.3);
    }else{
        if(((linefollower_3.readSensors())==(2))){
            motor_2.run(0);
            motor_9.run(0);
            _delay(0.3);
            motor_2.run(0);
            motor_9.run(-255);
            _delay(0.3);
        }else{
            if(((linefollower_3.readSensors())==(1))){
                motor_2.run(0);
                motor_9.run(0);
                motor_2.run(255);
                motor_9.run(0);
                _delay(0.3);
                _delay(0.3);
            }else{
                motor_2.run(0);
                motor_9.run(0);
                _delay(0.3);
                motor_2.run(255);
                motor_9.run(-255);
                _delay(1);
            }
        }
    }
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

