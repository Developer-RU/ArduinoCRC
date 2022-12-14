#include <ArduinoCRC.h>


uint8_t simple[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};


void setup() 
{ 
    Serial.begin(115200);
    Serial.println("Start simple CRC");
}

void loop()
{ 
    Crc crc;

    // Reset byte CRC, set 0xFF
    crc.start();

    // Add one byte to CRC
    crc.add(0x01);

    // Add array bytes to CRC
    crc.add(simple, sizeof(simple));


    // Print CRC
    Serial.println(crc.get()); 

    delay(1000);
}