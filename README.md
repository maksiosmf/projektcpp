# Advanced Phone Directory

A C++ application that provides a simple and intuitive phone directory management system. This application fulfills various C++ programming requirements including input/output operations, control structures, custom type definitions, namespaces, command-line arguments, custom functions, and data structure implementations.

## Features

- Add phone directory entries
- Remove entries
- Display all entries
- Find specific entries by name
- Sort entries alphabetically
- Persistent storage (entries are saved to a file)

## Requirements

- C++ compiler with C++14 support
- CMake (3.30 or later)

## Building the Application

1. Clone the repository
2. Navigate to the project directory
3. Build the application using CMake:
```
cmake --build cmake-build-debug --target projektcpp
```

## Usage

The application uses command-line arguments to perform various operations. Here are the available commands:

### Adding an Entry

```
./cmake-build-debug/projektcpp add [name] [phone]
```

Example:
```
./cmake-build-debug/projektcpp add John 123456789
```

### Removing an Entry

```
./cmake-build-debug/projektcpp remove [name]
```

Example:
```
./cmake-build-debug/projektcpp remove John
```

### Displaying All Entries

```
./cmake-build-debug/projektcpp display
```

### Finding an Entry

```
./cmake-build-debug/projektcpp find [name]
```

Example:
```
./cmake-build-debug/projektcpp find John
```

### Sorting Entries

```
./cmake-build-debug/projektcpp sort
```

## Project Structure

- `main.cpp`: Main application entry point
- `include/PhoneDirectory.h`: Header file defining the Directory class
- `src/PhoneDirectory.cpp`: Implementation of the Directory class

## Implementation Details

The application uses a custom namespace `PhoneBook` and implements the following C++ features:

- Custom type definitions using `typedef`
- Namespaces for code organization
- Command-line argument processing
- Custom functions with various parameter passing methods
- File I/O operations for data persistence
- STL containers and algorithms 