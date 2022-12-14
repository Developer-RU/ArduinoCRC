#pragma once


#include <Arduino.h>


/**
 * @brief 
 * 
 */
class Crc 
{
    public:
    
        /**
         * @brief 
         * 
         */
        void start();

        /**
         * @brief 
         * 
         * @param byte 
         */
        void add(uint8_t byte);

        /**
         * @brief 
         * 
         * @param data 
         * @param dataLen 
         */
        void add(uint8_t data[], uint16_t dataLen);

        /**
         * @brief Get the Crc object
         * 
         * @return uint8_t 
         */
        uint8_t get();

    private:

        /**
         * @brief 
         * 
         */
        uint8_t crc;
};
