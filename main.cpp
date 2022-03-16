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
  
  base.write(0);
  shoulder.write(0);    
  elbow.write(5);       // center
  wrist_rot.write(0);
  wrist_vert.write(-3);
  gripper.write(0);

  enable.write(1);
  
  while (1) {
    base.write(0);
    shoulder.write(0);
    elbow.write(5);
    wrist_rot.write(0);
    wrist_vert.write(-3);
    gripper.write(0);

    ThisThread::sleep_for(200ms);
  }
}
