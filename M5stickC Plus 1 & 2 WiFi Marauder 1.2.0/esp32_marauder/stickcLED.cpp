#include "stickcLED.h"
// NB M5Stick C Plus LED is active low, so digitalWrite() calls are inverted

#ifdef MARAUDER_M5STICKCP2
    #define M5LED_ON HIGH
    #define M5LED_OFF LOW
#else
    #define M5LED_ON LOW
    #define M5LED_OFF HIGH
#endif

void stickcLED::RunSetup() {
    pinMode(STICKC_LED_PIN, OUTPUT);

if (!settings_obj.loadSetting<bool>("EnableLED")) {
    digitalWrite(STICKC_LED_PIN, HIGH);
    return;
}

delay(50);

  digitalWrite(STICKC_LED_PIN, M5LED_ON);
  delay(500);
  digitalWrite(STICKC_LED_PIN, M5LED_OFF);
  delay(250);
  digitalWrite(STICKC_LED_PIN, M5LED_ON);
  delay(500);
  digitalWrite(STICKC_LED_PIN, M5LED_OFF);
  delay(250);
  digitalWrite(STICKC_LED_PIN, M5LED_ON);
  delay(500);
  digitalWrite(STICKC_LED_PIN, M5LED_OFF);
}

void stickcLED::attackLED() {
  if (!settings_obj.loadSetting<bool>("EnableLED"))
    return;
    
  digitalWrite(STICKC_LED_PIN, M5LED_ON);
  delay(300);
  digitalWrite(STICKC_LED_PIN, M5LED_OFF);
}

void stickcLED::sniffLED() {
  if (!settings_obj.loadSetting<bool>("EnableLED"))
    return;
    
  digitalWrite(STICKC_LED_PIN, M5LED_ON);
  delay(300);
  digitalWrite(STICKC_LED_PIN, M5LED_OFF);
}

void stickcLED::offLED() {
  if (!settings_obj.loadSetting<bool>("EnableLED"))
    return;
  
  digitalWrite(STICKC_LED_PIN, M5LED_OFF);
}

void stickcLED::main() {
  // do nothing
}
