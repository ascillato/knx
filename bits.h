#pragma  once

#include <stdint.h>

#ifdef __linux__
#include <arpa/inet.h>
#define lowByte(val) ((val) & 255)
#define highByte(val) (((val) >> ((sizeof(val) - 1) << 3)) & 255)
#define bitRead(val, bitno) (((val) >> (bitno)) & 1)
#else
#include <Arduino.h>
#include <user_interface.h>
#define printf Serial.printf
#endif



uint8_t* popByte(uint8_t& b, uint8_t* data);
uint8_t* popWord(uint16_t& w, uint8_t* data);
uint8_t* popInt(uint32_t& i, uint8_t* data);
uint8_t* popByteArray(uint8_t* dst, uint32_t size, uint8_t* data);
uint8_t* pushByte(uint8_t b, uint8_t* data);
uint8_t* pushWord(uint16_t w, uint8_t* data);
uint8_t* pushInt(uint32_t i, uint8_t* data);
uint8_t* pushByteArray(const uint8_t* src, uint32_t size, uint8_t* data);
uint16_t getWord(uint8_t* data);
uint32_t getInt(uint8_t* data);