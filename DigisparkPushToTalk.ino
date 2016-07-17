/*
 * Digispark based Keyboard to trigger "Push-to-talk" in Mumble
 * Mumble push-to-talk key must be set to <Control>+<Alt> 
 */
#include "DigiKeyboard.h"

char pinButton = 0;
char pinLED = 1;
char lastButtonState = 0;

void setup() {
    pinMode(pinButton, INPUT);
    digitalWrite(pinButton, HIGH);
} 

void loop() {
    int buttonState = digitalRead(pinButton);
    
    if (buttonState != lastButtonState) {
        lastButtonState = buttonState;
        if (buttonState == LOW) {
            DigiKeyboard.sendKeyPress(0, MOD_CONTROL_LEFT | MOD_ALT_LEFT);
        } else {
            DigiKeyboard.sendKeyPress(0, 0);
        }
    }
    // kind of debouncing...
    DigiKeyboard.delay(50);
}
