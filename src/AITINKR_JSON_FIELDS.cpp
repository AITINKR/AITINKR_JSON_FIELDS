#include "AITINKR_JSON_FIELDS.h"

// Constructor to initialize the JSON document with static capacity
AITINKR_JSON_FIELDS::AITINKR_JSON_FIELDS(size_t capacity)
{
    // The capacity is defined by StaticJsonDocument, so we initialize it
}

// Destructor (nothing to free in StaticJsonDocument)
AITINKR_JSON_FIELDS::~AITINKR_JSON_FIELDS() {}

// Overloaded function to add a field with integer value
void AITINKR_JSON_FIELDS::addField(int index, const char *label, int value, const char *units, const char *key)
{
    String fieldLabel = "field" + String(index) + "_label";
    String fieldValue = "field" + String(index) + "_value";
    String fieldUnits = "field" + String(index) + "_units";
    String fieldkey = "field" + String(index) + "_key";

    doc[fieldLabel] = label ? label : "NA";
    doc[fieldValue] = value;
    doc[fieldUnits] = units ? units : "NA";
    doc[fieldkey] = key ? key : "NA";
}

// Overloaded function to add a field with float value and default to 2 decimal places
void AITINKR_JSON_FIELDS::addField(int index, const char *label, float value, const char *units, const char *key)
{
    addField(index, label, value, units, key, 2);
}

// Overloaded function to add a field with double value and default to 2 decimal places
void AITINKR_JSON_FIELDS::addField(int index, const char *label, double value, const char *units, const char *key)
{
    addField(index, label, value, units, key, 2);
}

// Overloaded function to add a field with float value and custom precision
void AITINKR_JSON_FIELDS::addField(int index, const char *label, float value, const char *units, const char *key, int precision)
{
    String fieldLabel = "field" + String(index) + "_label";
    String fieldValue = "field" + String(index) + "_value";
    String fieldUnits = "field" + String(index) + "_units";
    String fieldkey = "field" + String(index) + "_key";

    doc[fieldLabel] = label ? label : "NA";
    doc[fieldValue] = String(value, precision);
    doc[fieldUnits] = units ? units : "NA";
    doc[fieldkey] = key ? key : "NA";
}

// Overloaded function to add a field with double value and custom precision
void AITINKR_JSON_FIELDS::addField(int index, const char *label, double value, const char *units, const char *key, int precision)
{
    String fieldLabel = "field" + String(index) + "_label";
    String fieldValue = "field" + String(index) + "_value";
    String fieldUnits = "field" + String(index) + "_units";
    String fieldkey = "field" + String(index) + "_key";

    doc[fieldLabel] = label ? label : "NA";
    doc[fieldValue] = String(value, precision);
    doc[fieldUnits] = units ? units : "NA";
    doc[fieldkey] = key ? key : "NA";
}

// Overloaded function to add a field with String value for both label and value
void AITINKR_JSON_FIELDS::addField(int index, const String &label, const String &value, const String &units, const String &key)
{
    String fieldLabel = "field" + String(index) + "_label";
    String fieldValue = "field" + String(index) + "_value";
    String fieldUnits = "field" + String(index) + "_units";
    String fieldkey = "field" + String(index) + "_key";

    doc[fieldLabel] = label;
    doc[fieldValue] = value;
    doc[fieldUnits] = units;
    doc[fieldkey] = key;
}

// Overloaded function to add a field with String value for both label and value
void AITINKR_JSON_FIELDS::addField(int index, const String &label, bool value, const String &units, const String &key)
{
    String fieldLabel = "field" + String(index) + "_label";
    String fieldValue = "field" + String(index) + "_value";
    String fieldUnits = "field" + String(index) + "_units";
    String fieldkey = "field" + String(index) + "_key";

    doc[fieldLabel] = label;
    doc[fieldValue] = (value) ? "True" : "False";
    doc[fieldUnits] = units;
    doc[fieldkey] = key;
}

// Overloaded function to add a field with const char* label and String value
void AITINKR_JSON_FIELDS::addField(int index, const char *label, const String &value, const char *units, const char *key)
{
    String fieldLabel = "field" + String(index) + "_label";
    String fieldValue = "field" + String(index) + "_value";
    String fieldUnits = "field" + String(index) + "_units";
    String fieldkey = "field" + String(index) + "_key";

    doc[fieldLabel] = label ? label : "NA";
    doc[fieldValue] = value;
    doc[fieldUnits] = units ? units : "NA";
    doc[fieldkey] = key ? key : "NA";
}

// Overloaded function to add a field with String label and const char* value
void AITINKR_JSON_FIELDS::addField(int index, const String &label, const char *value, const String &units, const String &key)
{
    addField(index, label.c_str(), value, units.c_str(), key.c_str());
}

// Overloaded function to add a field with const char* for both label and value
void AITINKR_JSON_FIELDS::addField(int index, const char *label, const char *value, const char *units, const char *key)
{
    String fieldLabel = "field" + String(index) + "_label";
    String fieldValue = "field" + String(index) + "_value";
    String fieldUnits = "field" + String(index) + "_units";
    String fieldkey = "field" + String(index) + "_key";

    doc[fieldLabel] = label ? label : "NA";
    doc[fieldValue] = value ? value : "NA";
    doc[fieldUnits] = units ? units : "NA";
    doc[fieldkey] = key ? key : "NA";
}

// Function to get the JSON string
String AITINKR_JSON_FIELDS::getJsonString()
{
    String jsonString;
    serializeJson(doc, jsonString);
    return jsonString;
}

// Function to clear the entire JSON document
void AITINKR_JSON_FIELDS::clearJson()
{
    doc.clear();
}

// Function to delete a specific field by index
void AITINKR_JSON_FIELDS::deleteField(int index)
{
    String fieldLabel = "field" + String(index) + "_label";
    String fieldValue = "field" + String(index) + "_value";
    String fieldUnits = "field" + String(index) + "_units";
    String fieldkey = "field" + String(index) + "_key";

    doc.remove(fieldLabel);
    doc.remove(fieldValue);
    doc.remove(fieldUnits);
    doc.remove(fieldkey);
}
