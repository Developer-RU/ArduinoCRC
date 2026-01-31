/**
 * @file Checksum.cpp
 * @author Masyukov Pavel
 * @brief Implementation of the Checksum class for 8-bit checksum calculation.
 * @version 1.0.0
 * @see https://github.com/Developer-RU/ArduinoCRC
 */

#include "Checksum.h"

namespace utils {

void Checksum::start() {
    m_checksum = INITIAL_VALUE;
}

void Checksum::add(uint8_t byte) {
    m_checksum += byte;
}

/**
 * @note If data is nullptr, the function does nothing.
 */
void Checksum::add(const uint8_t* data, uint16_t dataLen) {
    if (data == nullptr) {
        return;
    }
    
    // Directly add bytes to the member variable to avoid function call overhead in the loop.
    for (uint16_t i = 0; i < dataLen; ++i) {
        m_checksum += data[i];
    }
}

uint8_t Checksum::get() const {
    return m_checksum;
}

/**
 * @note A convenient static method for a one-time calculation.
 */
uint8_t Checksum::calculate(const uint8_t* data, uint16_t dataLen) {
    Checksum checksum;
    checksum.start();
    checksum.add(data, dataLen);
    return checksum.get();
}

bool Checksum::verify(const uint8_t* data, uint16_t dataLen, uint8_t expected) {
    return calculate(data, dataLen) == expected;
}

} // namespace utils
