#pragma once

#include <Arduino.h>

namespace NanoMQTT {

class PrintMux: public ::Print {
    public:
        PrintMux() {}

        PrintMux(Print & print) : prints({&print}) {}

        void add(Print & print) {
            prints.push_back(&print);
        }

        virtual size_t write(uint8_t) override;
        virtual size_t write(const uint8_t * buffer, size_t size) override;
        virtual void flush();

        size_t size() const { return prints.size(); }

    protected:
        std::vector<Print *> prints;
};

}
