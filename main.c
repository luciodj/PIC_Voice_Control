/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    Modified configuration to control the 4x4 RGB Click
    SPI2 - (PIC mode 0) has been configured for 8MHz
    the SDO2 pin is re-directed to the CS pin of the mikrobus to drive DATA-In

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.125
        Device            :  PIC24FJ128GA705
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36B
        MPLAB 	          :  MPLAB X v5.20
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "mcc_generated_files/led.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/debug_print.h"
#include "mcc_generated_files/sensors_handling.h"
#include "mcc_generated_files/cloud/cloud_service.h"
#include "mcc_generated_files/application_manager.h"
#include "json.h"

bool red = false;
bool yel = false;


//This handles messages published from the MQTT server when subscribed
void receivedFromCloud(uint8_t *topic, uint8_t *payload)
{
    bool value;

	LED_GREEN_set_level(LED_OFF);
//	debug_printer(SEVERITY_NONE, LEVEL_NORMAL, "topic: %s", topic);
	debug_printer(SEVERITY_NONE, LEVEL_NORMAL, "payload: %s", payload);
    if (JSON_getBool(payload, "red", &value)) {
        red = value;
    }

    if (JSON_getBool(payload, "yellow", &value)) {
        yel = value;
    }

    // execute the command
   LED_YELLOW_set_level((yel) ? 0:1);
   LED_RED_set_level(   (red) ? 0:1);

    // report back state
    static char json[70];
    char*boolean[2] = {"false", "true"};
    int len = sprintf(json, "{\"red\":%s,\"yellow\":%s}",
                                boolean[red],   boolean[yel]);
    if (len > 0) {
      CLOUD_publishData((uint8_t*)json, len);
   }
}

// This will get called every CFG_SEND_INTERVAL seconds only while we have a valid Cloud connection
void sendToCloud(void)
{
//   static char json[70];
//   int rawTemperature = SENSORS_getTempValue();
//   int light = SENSORS_getLightValue();
//   int len = sprintf(json, "{\"Light\":%d,\"Temp\":%d}", light,rawTemperature/100);
//   if (len >0) {
//      CLOUD_publishData((uint8_t*)json, len);
//   }

  }


int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    application_init();

    while (1)
    {
        runScheduler();
    }

    return 0;
}
