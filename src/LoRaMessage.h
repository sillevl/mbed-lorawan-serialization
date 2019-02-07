#pragma once

#include "stdint.h"
#include "LoRaEncoder.h"

class LoRaMessage 
{
  public:
    LoRaMessage();
    ~LoRaMessage();

    LoRaMessage& addUint8(uint16_t value);
    LoRaMessage& addUint16(uint16_t value);

    LoRaEncoder reallocBuffer(int delta);
    uint8_t* getMessage();
    uint8_t getLength();

  private:
    uint8_t* buffer;
    uint8_t size;
};