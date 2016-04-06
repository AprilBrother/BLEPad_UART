#include "BLEPad_UART.h"

BLEPad_UART::BLEPad_UART(Stream *s) : stream(s) {};

int BLEPad_UART::available() {
    return stream->available();
}

size_t BLEPad_UART::write(uint8_t c) {
    return stream->write(c);
}

void BLEPad_UART::println(const char data[]) {
    stream->println(data);
}

size_t BLEPad_UART::println(int n, int base) {
    return stream->println(n, base);
}

int BLEPad_UART::read() {
    return stream->read();
}

