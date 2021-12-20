#include "mbed.h"
#include "LoRaMessage.h"

LoRaMessage::LoRaMessage()
{
  size = 0;
  buffer = (uint8_t*) malloc(size);
}

LoRaMessage::~LoRaMessage()
{
  free(buffer);
}

LoRaMessage& LoRaMessage::addUint8(uint8_t value)
{
  reallocBuffer(1).writeUint8(value);
  return *this;
}

LoRaMessage& LoRaMessage::addUint16(uint16_t value)
{
  reallocBuffer(2).writeUint16(value);
  return *this;
}


LoRaEncoder LoRaMessage::reallocBuffer(int delta) 
{
    void* temp = realloc(buffer, (size + delta) * sizeof(uint8_t));
    if (temp == NULL) {
        free(buffer);
        printf("bad memory allocation!");
        while(true);
    } else {
        buffer = (uint8_t*) temp;
    }
    LoRaEncoder encoder(buffer + size);
    size += delta;
    return encoder;
}

uint8_t* LoRaMessage::getMessage()
{
  return buffer;
}

uint8_t LoRaMessage::getLength()
{
  return size;
}
