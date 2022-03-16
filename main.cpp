/*
 * Copyright (c) 2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

// Specify different pins to test printing on UART other than the console UART.
#define TARGET_TX_PIN                                                     USBTX
#define TARGET_RX_PIN                                                     USBRX

// Create a BufferedSerial object to be used by the system I/O retarget code.
static BufferedSerial serial_port(TARGET_TX_PIN, TARGET_RX_PIN, 9600);

FileHandle *mbed::mbed_override_console(int fd)
{
    return &serial_port;
}

int main(void)
{
    // print to the console using the `serial_port` object.
    printf(
        "Mbed OS version %d.%d.%d\n",
        MBED_MAJOR_VERSION,
        MBED_MINOR_VERSION,
        MBED_PATCH_VERSION
    );
}

//int main()
//{
    // Initialise the digital pin LED1 as an output
//#ifdef LED1
//    DigitalOut led3(LED3);
//    DigitalOut led2(LED2);
//    DigitalOut led1(LED1);
//#else
//    bool led;
//#endif
//
//    while (true) {
//        led1 = !led1;
//        ThisThread::sleep_for(BLINKING_RATE);
//        led2 = !led2;
//        ThisThread::sleep_for(BLINKING_RATE);
//        led3 = !led3;
//        ThisThread::sleep_for(BLINKING_RATE);
//    }
//}
