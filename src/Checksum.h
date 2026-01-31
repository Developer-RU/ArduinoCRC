/**
 * @file Checksum.h
 * @author Masyukov Pavel
 * @brief Header file for the Checksum class for 8-bit checksum calculation.
 * @version 1.0.0
 * @see https://github.com/Developer-RU/ArduinoCRC
 * 
 * The class provides functionality for incremental calculation of a checksum
 * as a simple sum of bytes (accumulated in a uint8_t).
 * 
 * @note Uses an initial value of 0xFF for the checksum.
 * @warning Due to the use of 8-bit overflow, the checksum is not
 *          cryptographically secure and is intended only for data
 *          integrity checks.
 */

#pragma once

#include <stdint.h>
#include <stddef.h>

namespace utils {

/**
 * @class Checksum
 * @brief Class for calculating and verifying an 8-bit checksum.
 * 
 * Supports two modes of operation:
 * 1. Incremental - sequential addition of data.
 * 2. Batch - calculation in a single call.
 */
class Checksum {
public:
    // ==================== Incremental Calculation Methods ====================
    
    /**
     * @brief Resets the checksum to its initial value.
     * @note The start() method is used instead of reset() for compatibility with older code.
     */
    void start();
    
    /**
     * @brief Adds a single byte to the current checksum.
     * @param byte The data byte to add.
     */
    void add(uint8_t byte);
    
    /**
     * @brief Adds a byte array to the current checksum.
     * @param data Pointer to the data array.
     * @param dataLen The number of bytes to add.
     */
    void add(const uint8_t* data, uint16_t dataLen);
    
    /**
     * @brief Returns the current value of the checksum.
     * @return The calculated checksum (0-255).
     */
    uint8_t get() const;
    
    // ==================== Static Batch Calculation Methods ====================
    
    /**
     * @brief Calculates the checksum for a given data array.
     * @param data Pointer to the data array.
     * @param dataLen The number of bytes to process.
     * @return The checksum for the provided data.
     * 
     * @note A convenient method for a one-time calculation without creating an object.
     */
    static uint8_t calculate(const uint8_t* data, uint16_t dataLen);
    
    /**
     * @brief Verifies the checksum for the given data.
     * @param data Pointer to the data array.
     * @param dataLen The number of bytes to process.
     * @param expected The expected checksum value.
     * @return true if the calculated checksum matches the expected value, false otherwise.
     */
    static bool verify(const uint8_t* data, uint16_t dataLen, uint8_t expected);

private:
    static const uint8_t INITIAL_VALUE = 0xFF;  ///< Initial value of the checksum.
    uint8_t m_checksum;                         ///< Current value of the checksum.
};

} // namespace utils
