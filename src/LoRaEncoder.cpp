#include "mbed.h"
#include "LoRaEncoder.h"

LoRaEncoder::LoRaEncoder(uint8_t *buffer)
{
  this->buffer = buffer;
}

void LoRaEncoder::writeUint8(uint8_t value)
{
    intToBytes(buffer, value, 1);
    buffer += 1;
}

void LoRaEncoder::writeUint16(uint16_t value)
{
    intToBytes(buffer, value, 2);
    buffer += 2;
}

void LoRaEncoder::intToBytes(uint8_t *buf, int32_t i, uint8_t byteSize)
{
  for(uint8_t x = 0; x < byteSize; x++) {
      buf[x] = (uint8_t) (i >> (x*8));
  }
}
