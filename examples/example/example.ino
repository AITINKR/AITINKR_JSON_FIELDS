#include <Arduino.h>
#include "AITINKR_JSON_FIELDS.h"

// Create an instance of the AITINKR_JSON_FIELDS class with static memory
AITINKR_JSON_FIELDS jsonFields(4096);  // Increased buffer capacity for larger JSON

void setup() {
  // Initialize the serial port for debugging
  Serial.begin(115200);
  delay(1000);

  // Add fields with different types of parameters
  jsonFields.addField(1, "Temperature", 25.6789, "C", "sensor");           // Default precision (2 decimal places)
  jsonFields.addField(2, "Status", "OK", "", "system");                    // String
  jsonFields.addField(3, "Pressure", 101, "Pa", "sensor");                 // Integer
  jsonFields.addField(4, "Altitude", 1500.7568, "m", "sensor");            // Default precision (2 decimal places)
  jsonFields.addField(5, "Humidity", 60.12345, "%", "sensor", 3);          // Custom precision (3 decimal places)
  jsonFields.addField(2, "Status", 1 , "", "system");                    // bool

  // Serialize and print the JSON document
  String jsonOutput = jsonFields.getJsonString();
  Serial.println("Initial JSON:");
  Serial.println(jsonOutput);

  // Delete the "Status" field (index 2)
  jsonFields.deleteField(2);

  // Print the JSON after deleting the "Status" field
  jsonOutput = jsonFields.getJsonString();
  Serial.println("\nJSON after deleting Status:");
  Serial.println(jsonOutput);

  // Clear the entire document
  jsonFields.clearJson();

  // Print the JSON after clearing all fields
  jsonOutput = jsonFields.getJsonString();
  Serial.println("\nJSON after clearing all fields:");
  Serial.println(jsonOutput);
}

void loop() {
  // No loop code needed for this example
}
