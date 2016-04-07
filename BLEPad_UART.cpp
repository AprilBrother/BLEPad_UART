#include "BLEPad_UART.h"

#define PIN_WAKEUP          8
#define PIN_CONFIG          5
#define PIN_SWITCH_MODe     11

BLEPad_UART::BLEPad_UART(HardwareSerial *s) {
    hs = s;
};

void BLEPad_UART::begin(unsigned long baud) {
    pinMode(PIN_WAKEUP, OUTPUT);
    digitalWrite(PIN_WAKEUP, LOW);
    hs->begin(baud);
}

void BLEPad_UART::end(void) {
    digitalWrite(PIN_WAKEUP, HIGH);
    hs->end();
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

void BLEPad_UART::flush(void) {
    hs->flush();
}

int BLEPad_UART::peek(void) {
    return hs->peek();
}
