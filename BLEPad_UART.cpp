#include "BLEPad_UART.h"

BLEPad_UART::BLEPad_UART(HardwareSerial *s) {
    hs = s;
};

void BLEPad_UART::begin(unsigned long baud) {
    hs->begin(baud);
}

size_t BLEPad_UART::write(uint8_t c) {
    return hs->write(c);
}

void BLEPad_UART::println(const char data[]) {
    hs->println(data);
}

size_t BLEPad_UART::println(int n, int base) {
    return hs->println(n, base);
}

int BLEPad_UART::read() {
    return hs->read();
}

int BLEPad_UART::available() {
    return hs->available();
}

