/*
    \file   led.h

    \brief  led header file.

    (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip software and any
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party
    license terms applicable to your use of third party software (including open source software) that
    may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
    FOR A PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
    SOFTWARE.
*/


#ifndef LED_H_
#define LED_H_
#include <stdint.h>
#include <stdbool.h>
#include "pin_manager.h"

#define LED_ON				false
#define LED_OFF				true

#define LED_GREEN_set_level(x)      _LATC4 = x
#define LED_RED_set_level(x)        _LATB4 = x
#define LED_YELLOW_set_level(x)     _LATC3 = x
#define LED_BLUE_set_level(x)       _LATC5 = x


void LED_test(void);
void LED_flashYellow(void);
void LED_holdYellowOn(bool holdHigh);
void LED_flashRed(void);
void LED_blinkingBlue(bool amBlinking);
void LED_startBlinkingGreen(void);
void LED_stopBlinkingGreen(void);
bool LED_isBlinkingGreen (void);

#endif /* LED_H_ */
