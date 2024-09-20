#ifndef AITINKR_JSON_FIELDS_H
#define AITINKR_JSON_FIELDS_H

#include <ArduinoJson.h>

class AITINKR_JSON_FIELDS
{
public:
    // Constructor to initialize the JSON document with static capacity
    AITINKR_JSON_FIELDS(size_t capacity);

    // Overloaded to support int, float, and double values
    void addField(int index, const char *label, int value, const char *units, const char *key);
    void addField(int index, const char *label, float value, const char *units, const char *key);                 // Default to 2 decimal places
    void addField(int index, const char *label, double value, const char *units, const char *key);                // For double
    void addField(int index, const char *label, float value, const char *units, const char *key, int precision);  // With custom precision
    void addField(int index, const char *label, double value, const char *units, const char *key, int precision); // For double with precision

    // Overloaded to support String and float/double values
    void addField(int index, const String &label, float value, const String &units, const String &key);                 // Default to 2 decimal places
    void addField(int index, const String &label, double value, const String &units, const String &key);                // For double with default precision
    void addField(int index, const String &label, float value, const String &units, const String &key, int precision);  // With custom precision
    void addField(int index, const String &label, double value, const String &units, const String &key, int precision); // For double with custom precision
    void addField(int index, const String &label, bool value, const String &units, const String &key);                  // For double with custom precision
    // Overloaded to support String values for both label and value
    void addField(int index, const String &label, const String &value, const String &units, const String &key);
    void addField(int index, const char *label, const String &value, const char *units, const char *key);
    void addField(int index, const String &label, const char *value, const String &units, const String &key);
    void addField(int index, const char *label, const char *value, const char *units, const char *key);

    // Function to get the JSON string
    String getJsonString();

    // Function to clear the entire JSON document
    void clearJson();

    // Function to delete a specific field by index
    void deleteField(int index);

    // Destructor to free memory
    ~AITINKR_JSON_FIELDS();

private:
    StaticJsonDocument<4096> doc; // Static JSON document for storing fields (fixed-size buffer)
};

#endif