# Checksum Library for Arduino

<p>
  <img src="/images/version.svg" alt="Version 1.0.0">
  <img src="/images/license.svg" alt="License MIT">
</p>

A lightweight 8-bit checksum library for Arduino, ESP8266, ESP32 and other AVR/ARM platforms.
Provides efficient data integrity verification through simple byte summation.

## Features

* 8-bit checksum calculation with overflow
* Incremental calculation mode
* Batch calculation mode
* Initial value: 0xFF (configurable in code)
* Support for both single bytes and byte arrays
* Static methods for one-time calculations
* Memory efficient (minimal footprint)
* No external dependencies

## Installation

### Using Arduino IDE

1. Download the library as ZIP
2. In Arduino IDE: Sketch → Include Library → Add .ZIP Library...
3. Select the downloaded ZIP file

### Using PlatformIO

Add to your `platformio.ini`:

[env:your_board]
platform = espressif32  ; or your platform
framework = arduino
lib_deps = 
    https://github.com/Developer-RU/ArduinoCRC.git

## Usage

```cpp
#include <Checksum.h>

void setup() {
    Serial.begin(115200);
    
    // Example 1: Incremental calculation
    utils::Checksum checksum;
    checksum.start();
    checksum.add(0x01);
    checksum.add(0x02);
    checksum.add(0x03);
    uint8_t result = checksum.get(); // 0xFF + 0x01 + 0x02 + 0x03 = 0x05
    
    Serial.print("Incremental checksum: 0x");
    Serial.println(result, HEX);
    
    // Example 2: Batch calculation
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    uint8_t batchResult = utils::Checksum::calculate(data, sizeof(data));
    
    Serial.print("Batch checksum: 0x");
    Serial.println(batchResult, HEX);
    
    // Example 3: Verification
    uint8_t expected = 0x09;
    bool isValid = utils::Checksum::verify(data, sizeof(data), expected);
    
    Serial.print("Verification: ");
    Serial.println(isValid ? "PASS" : "FAIL");
}

void loop() {
    // Empty
}
```

## API Reference 

### Class: `utils::Checksum`

| Method | Description |
|---|---|
| `void start()` | Resets the checksum to its initial value (0xFF). |
| `void add(uint8_t byte)` | Adds a single byte to the checksum. |
| `void add(const uint8_t* data, uint16_t dataLen)` | Adds a byte array to the checksum. |
| `uint8_t get() const` | Returns the current checksum value. |

### Static Methods

| Method | Description |
|---|---|
| `static uint8_t calculate(const uint8_t* data, uint16_t dataLen)` | Calculates the checksum for a byte array in one call. |
| `static bool verify(const uint8_t* data, uint16_t dataLen, uint8_t expected)` | Verifies if the calculated checksum for a byte array matches an expected value. |

## Limitations

8-bit checksum provides basic error detection only

Not cryptographically secure

Susceptible to certain error patterns

Maximum overflow: 255 bytes without loss of precision

## Examples

The library includes the following examples (File → Examples → ArduinoCRC):

BasicUsage - Simple checksum calculation and verification

Incremental - Demonstrates incremental checksum building

DataVerification - Complete data integrity check example

SerialMonitor - Interactive checksum calculator via Serial

## Platform Compatibility

✅ Arduino Uno/Nano/Mega (AVR)
✅ ESP8266
✅ ESP32
✅ Arduino Due (SAM)
✅ Teensy 3.x/4.x
✅ Raspberry Pi Pico (RP2040)

## Library Structure

ArduinoCRC/
├── examples/           # Example sketches
├── src/
│   ├── Checksum.cpp   # Implementation
│   └── Checksum.h     # Header file
├── library.properties # Library metadata
├── keywords.txt       # Arduino IDE syntax highlighting 
├── LICENSE           # MIT License
└── README.md          # This file

## Contributing

Contributions are welcome! Please: 

Fork the repository

Create a feature branch

Make your changes

Submit a pull request

Report issues at: https://github.com/Developer-RU/ArduinoCRC/issues

## Changelog

### v1.0.0

Initial release

## Links

Repository: https://github.com/Developer-RU/ArduinoCRC

Issues: https://github.com/Developer-RU/ArduinoCRC/issues

Releases: https://github.com/Developer-RU/ArduinoCRC/releases
