#ifndef  _BLEPAD_UART_H
#define _BLEPAD_UART_H

#include <Arduino.h>

class BLEPad_UART : public Print {

    public:
        BLEPad_UART(Stream *s = &Serial1);
        void println(const char data[]);

        int available();
        int read();

        virtual size_t write(uint8_t c);
        virtual size_t println(int, int = DEC);

        // pull in write(str) and write(buf, size) from Print
        using Print::write;

    private:
        Stream    *stream;     // -> BLE module, e.g. SoftwareSerial or Serial1

};

#endif
