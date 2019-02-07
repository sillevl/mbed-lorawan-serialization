#pragma once

#include "stdint.h"

class LoRaEncoder
{
  public:
    LoRaEncoder(uint8_t *buffer);
    void writeUint8(uint8_t value);
    void writeUint16(uint16_t value);
  private:
    uint8_t* buffer;
    void intToBytes(uint8_t *buf, int32_t i, uint8_t byteSize);
};