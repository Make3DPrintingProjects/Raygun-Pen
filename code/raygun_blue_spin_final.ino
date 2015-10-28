// Raygun Pen program
// Modified the original version from Adafruit Goggles project

#include <Adafruit_NeoPixel.h>
#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
 #include <avr/power.h>
#endif

#define PIN 0

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(32, PIN);

uint8_t  mode   = 0, // Current animation effect
         offset = 0; // Position of spinning LED
uint32_t color  = 0x0000FF; // Start blue
uint32_t prevTime;

void setup() {
#ifdef __AVR_ATtiny85__ // Trinket
  if(F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
  pixels.setBrightness(85); // 1/3 brightness
  prevTime = millis();
}

void loop() {
  uint8_t  i;
  uint32_t t;

{
  
       for(i=0; i<16; i++) {
      uint32_t c = 0;
      if(((offset + i) & 7) < 2) c = color; // 4 pixels on...
      pixels.setPixelColor(   i, c); // NeoPixel in Shell

    }
    pixels.show();
    offset++;
    delay(50);
   }

 }
