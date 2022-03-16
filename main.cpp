/*
 * Copyright (c) 2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Servo.h"

DigitalOut enable(PA_6);

Servo base(PA_7);
Servo shoulder(PD_14); // 0 is center
Servo elbow(PD_15);
Servo wrist_vert(PE_9);
Servo wrist_rot(PE_11);
Servo gripper(PE_13);

int main() {
  enable.write(0);
  
  base.attach(0);
  shoulder.attach(0);
  elbow.attach(1);
  wrist_rot.attach(0);
  wrist_vert.attach(0);
  gripper.attach(0);
  
  base.write(0);        // center  0  max 110   min -100
  shoulder.write(0);    // center  0  max 50    min -50
  elbow.write(5);       // center  5  max 100   min -100
  wrist_rot.write(-5);  // center -5  max 100   min -100
  wrist_vert.write(-3); // center -3  max 110   min -100
  gripper.write(-20);     // center -20 closed 10 open -50

  enable.write(1);
  ThisThread::sleep_for(1s);
  
  // base
  base.write(-30);
  ThisThread::sleep_for(500ms);
  base.write(30);
  ThisThread::sleep_for(500ms);
  base.write(0);

  ThisThread::sleep_for(1s);
   
  // 3 joints
  shoulder.write(-20);
  elbow.write(25);
  wrist_vert.write(-23);
  ThisThread::sleep_for(500ms);
  shoulder.write(20);
  elbow.write(-15);
  wrist_vert.write(17);
  ThisThread::sleep_for(500ms);
  shoulder.write(0);
  elbow.write(5);
  wrist_vert.write(-3);
  ThisThread::sleep_for(500ms);

  ThisThread::sleep_for(1s);
  
  // wrist
  wrist_rot.write(100);
  ThisThread::sleep_for(500ms);
  wrist_rot.write(-5);

  ThisThread::sleep_for(1s);
  
  // gripper
  gripper.write(-50);
  ThisThread::sleep_for(500ms);
  gripper.write(-20);
}
