#ifndef  _BLEPAD_UART_H
#define _BLEPAD_UART_H

#include <Arduino.h>

class BLEPad_UART : public Stream{

    public:
        BLEPad_UART(Stream *s = &Serial1);
        void println(const char data[]);

        int available();
        int read();

        // Class Print virtual function Interface
        virtual size_t write(uint8_t c);
        virtual size_t println(int, int = DEC);

    private:
        Stream    *stream;     // -> BLE module, e.g. SoftwareSerial or Serial1

};

#endif
