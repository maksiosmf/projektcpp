# Phone Directory

A simple C++ app for managing phone contacts with persistent storage.

## Features

- Add, remove, and find contacts
- Display all entries
- Sort entries alphabetically
- Save data to file automatically

## Requirements

- C++ compiler (C++14 support)
- CMake (3.30+)

## Building

```
cmake --build cmake-build-debug --target projektcpp
```

## Usage

The application uses command-line arguments to perform various operations.

### Adding an Entry

```
./cmake-build-debug/projektcpp add [name] [phone]
```

E.g.:
```
./cmake-build-debug/projektcpp add John 123456789
```

### Removing an Entry

```
./cmake-build-debug/projektcpp remove [name]
```

E.g.:
```
./cmake-build-debug/projektcpp remove JohnPork
```

### Displaying All Entries

```
./cmake-build-debug/projektcpp display
```

### Finding an Entry

```
./cmake-build-debug/projektcpp find [name]
```

E.g.:
```
./cmake-build-debug/projektcpp find JohnPork
```

### Sorting Entries

```
./cmake-build-debug/projektcpp sort
```

## Project Structure

- `main.cpp`: Main app
- `include/PhoneDirectory.h`: Defining directory class
- `src/PhoneDirectory.cpp`: Implementation of the Directory class

## Implementation Details

This app uses a custom made namespace `PhoneBook` that implements following C++ features:

- Custom type definitions using `typedef`
- Custom Namespaces for organisation
- CMD arg. processing
- Custom functions
- Containers and algorithms