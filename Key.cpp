#include <Arduino.h>
#include "Key.h"

// class constructor

Key::Key(int pin, bool setPullUp) {
      pinNumber = pin;
      if (setPullUp) {
        pinMode(pin, INPUT_PULLUP);
      }
      else {
        pinMode(pin, INPUT);
      }
      keyState = false;
      keyOldState = false;
      keySwitch = false;
      keyPE = false;
      keyNE = false;
}

void Key::update() {
      if ((!digitalRead(pinNumber) != keyState) && !keySwitch) {
        timeStamp = millis();
        keySwitch = true;
      }

      if (keySwitch && ((millis() - timeStamp) > 50)) {
        keyState = !digitalRead(pinNumber);
        keySwitch = false;
      }

      keyPE = (!keyOldState & keyState);
      keyNE = (keyOldState & !keyState);
      keyOldState = keyState;
} // end update

bool Key::getState() {
      return keyState;
}

bool Key::getPE() {
      return keyPE;
}

bool Key::getNE() {
      return keyNE;
}
