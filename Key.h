/*****************************************************************************
 * Key.h *
 *****************************************************************************
 * allows easy handling of keys with debounce protection and edge detection  *
 *                                                                           *
 * v1.0 - Domingo Alcala  domingo.alcala@gmail.com                           *
 *****************************************************************************
 */

#ifndef Key_h
#define Key_h

class Key {

  private:
    int pinNumber;
    bool keyState;
    bool keySwitch;
    bool keyOldState;
    bool keyPE;
    bool keyNE;
    long timeStamp;

  public:

    /* class constructor */
    /*   pin : the pin number where the key is connected  */
    /*   setPullUp : true to set internal pullup resistors */

    Key(int pin, bool setPullUp);

    /* update must be called every loop */
    void update();

    /* return key state: true = key pressed */
    bool getState();

    /* return true if positive edge detected. Will remain true until next update */
    bool getPE() ;

    /* return true if negative edge detected. Will remain true until next update */
    bool getNE();
};

#endif

