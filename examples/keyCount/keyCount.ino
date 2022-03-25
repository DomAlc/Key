/* example of use for library Key: 
 *   positive edge detection with debounce protection
 *   every 5 counts the led switches its state
 *   
 * PIN #8 ------  
 *             |
 *             |
 *                ] key
 *             |
 *             |
 *            GND 
 * 
 * Domingo Alcala - domingo.alcala@gmail.com
 */

#include <Key.h>

#define COUNTS 5

Key puls(8, true);

int counter = 0;
bool lampState = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  puls.update();
  if (puls.getPE()) {
    counter++;
    if (counter > COUNTS-1) {
      counter = 0;
      lampState = !lampState;
      digitalWrite(LED_BUILTIN,lampState);
    }
  }
}
