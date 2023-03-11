#pragma once

#include <Arduino.h>
#include "Client.h"

#include "packet.h"

namespace NanoMQTT {

class IncomingPacket: public Packet, public Client {
    public:
        IncomingPacket(Client & client);

        IncomingPacket(const IncomingPacket &) = delete;
        const IncomingPacket & operator=(const IncomingPacket &) = delete;

        ~IncomingPacket();

        virtual int available() override;
        virtual int connect(IPAddress ip, uint16_t port) override;
        virtual int connect(const char * host, uint16_t port) override;
        virtual int peek() override;
        virtual int read() override;
        virtual int read(uint8_t * buf, size_t size) override;
        virtual operator bool() override;
        virtual size_t write(const uint8_t * buffer, size_t size) override;
        virtual size_t write(uint8_t value) override final;
        virtual uint8_t connected() override;
        virtual void flush() override;
        virtual void stop() override;

        uint8_t read_u8();
        uint16_t read_u16();

    protected:
        static Packet read_header(Client & client);

        Client & client;
};

}
