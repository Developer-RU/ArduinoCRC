/**
 * @file BasicExample.ino
 * @brief Basic usage example for the Checksum library.
 * @author Masyukov Pavel
 * @see https://github.com/Developer-RU/ArduinoCRC
 * 
 * Demonstrates three ways to work with the checksum:
 * 1. Incremental calculation (byte by byte)
 * 2. Batch calculation (for a data array)
 * 3. Data verification
 */

#include <Checksum.h>

void setup()
{
    Serial.begin(115200); // Initialize serial port for output
    delay(1000);
    
    Serial.println("=======================================");
    Serial.println("Checksum Library Basic Example");
    Serial.println("=======================================\n");
    Serial.println("Example 1: Incremental Calculation");
    Serial.println("-----------------------------------");
    
    utils::Checksum checksum; // Create a Checksum object
    checksum.start(); // Reset to the initial value 0xFF
    
    // Add bytes sequentially
    checksum.add(0x01);
    checksum.add(0x02);
    checksum.add(0x03);
    
    // Get the result: 0xFF + 0x01 + 0x02 + 0x03 = 0x05
    uint8_t incrementalResult = checksum.get();
    
    Serial.print("Bytes: 0x01, 0x02, 0x03\n");
    Serial.print("Initial value: 0xFF\n");
    Serial.print("Incremental checksum: 0x");
    Serial.println(incrementalResult, HEX);
    
    // Show the math for clarity
    Serial.print("Calculation: 0xFF + 0x01 + 0x02 + 0x03 = 0x");
    Serial.println(incrementalResult, HEX);
    Serial.println();
    Serial.println("Example 2: Batch Calculation");
    Serial.println("----------------------------");
    
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    uint16_t dataLength = sizeof(data);
    
    uint8_t batchResult = utils::Checksum::calculate(data, dataLength);
    
    Serial.print("Data array: ");
    for (uint16_t i = 0; i < dataLength; i++) {
        Serial.print("0x");
        Serial.print(data[i], HEX);
        if (i < dataLength - 1) Serial.print(", ");
    }
    Serial.println();
    
    Serial.print("Data length: ");
    Serial.print(dataLength);
    Serial.println(" bytes");
    
    Serial.print("Batch checksum: 0x");
    Serial.println(batchResult, HEX);
    
    // Manual check of the calculation
    Serial.print("Manual check: 0xFF + 0x01 + 0x02 + 0x03 + 0x04 + 0x05 = 0x");
    Serial.println(batchResult, HEX);
    Serial.println();

    Serial.println("Example 3: Data Verification");
    Serial.println("----------------------------");
    
    // The correct expected checksum for the `data` array
    // 0xFF + 0x01 + 0x02 + 0x03 + 0x04 + 0x05 = 0x0E
    uint8_t expectedChecksum = 0x0E;
    
    Serial.print("Expected checksum: 0x");
    Serial.println(expectedChecksum, HEX);
    
    // Verify the checksum
    bool isValid = utils::Checksum::verify(data, dataLength, expectedChecksum);
    
    if (isValid) {
        Serial.println("✓ Verification: PASS - Data integrity confirmed");
    } else {
        Serial.println("✗ Verification: FAIL - Data corruption detected");
    }
    
    // Demonstrate error detection
    Serial.println("\nDemonstrating error detection:");
    
    // Simulate data corruption by changing one byte
    uint8_t corruptedData[] = {0x01, 0x02, 0x03, 0x44, 0x05}; // 0x04 is changed to 0x44
    
    Serial.print("Corrupted data: ");
    for (uint16_t i = 0; i < dataLength; i++) {
        Serial.print("0x");
        Serial.print(corruptedData[i], HEX);
        if (i < dataLength - 1) Serial.print(", ");
    }
    Serial.println();
    
    bool isCorruptedValid = utils::Checksum::verify(corruptedData, dataLength, expectedChecksum);
    
    if (isCorruptedValid) {
        Serial.println("✓ Corrupted data verification: PASS (unexpected!)");
    } else {
        Serial.println("✗ Corrupted data verification: FAIL (as expected)");
    }
    
    Serial.println("\n=======================================");
    Serial.println("Example completed successfully!");
    Serial.println("=======================================");
}

void loop()
{
    // This example runs once in setup()
    // For interactive examples, you could add code to the loop()
    delay(1000);
}