# AITINKR_JSON_FIELDS Library

The **AITINKR_JSON_FIELDS** library is designed to handle dynamic JSON field management for Arduino-based projects. It offers simple methods to add, modify, delete, and clear fields while maintaining a lightweight structure using the ArduinoJson library.

## Features

- **Add fields with various data types**: Supports int, float, double, and String types.
- **Precision control**: Custom precision support for float and double values.
- **String fields**: Easily handle String values for both labels and values.
- **Clear or delete fields**: Remove specific fields by index or clear the entire JSON document.
- **Lightweight**: Utilizes a fixed-size buffer to minimize memory usage on embedded devices.


## Requirements

- ArduinoJson library
- Compatible with Arduino