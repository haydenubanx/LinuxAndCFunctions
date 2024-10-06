# Bitwise Operations and Endian Checker

## Overview

This project includes a series of C programs that demonstrate various low-level operations using bitwise manipulation and system-level data organization (endianess). These programs are primarily focused on understanding how bits work in memory and how to manipulate them efficiently for tasks such as endian checking, bit manipulation, and byte replacements.

## Features

- **Endian Checker**: Determines if the system is running in little-endian or big-endian mode.
- **XYZ Variables**: Demonstrates bit manipulation on three variables (x, y, z) with masking techniques.
- **Byte Replacement**: Replaces a specific byte in a word with another byte.
- **Bit Checker**: Checks for specific bit patterns in data.
- **Odd Bit Checker**: Determines if any odd bit in a word is set to 1.

## Program Descriptions

### 1. Endian Checker (`2.58_endianizer.c`)
- **Description**: Checks if the system is little-endian or big-endian.
- **How It Works**: The program checks the first byte of an integer to determine the endian type of the system. If the first byte is the least significant, it’s little-endian, otherwise it’s big-endian.

### 2. XYZ Variables (`2.59_xyz_variables.c`)
- **Description**: Demonstrates masking and bitwise operations on three variables.
- **How It Works**: The program uses bit masking to manipulate the bits of variables `x`, `y`, and `z`, and demonstrates various bitwise operations such as AND, OR, and XOR.

### 3. Byte Replacement (`2.60_byte_replacement.c`)
- **Description**: Replaces a specific byte in a word with another byte.
- **How It Works**: The program takes an input word and replaces a designated byte at a specific position with a new byte value using bitwise shifting and masking.

### 4. Bit Checker (`2.61_bit_checker.c`)
- **Description**: Checks for specific bit patterns in data.
- **How It Works**: The program applies masks and other bitwise techniques to check for certain bit patterns within a word.

### 5. Odd Bit Checker (`2.64_any_odd_one.c`)
- **Description**: Checks if any odd bit of a 32-bit word is set to 1.
- **How It Works**: The program isolates the odd bits of a word and checks if any of them are set to 1 using masking and logical operations.

## Compilation and Usage

### Prerequisites

To compile and run the programs, you will need:
- A C compiler (e.g., GCC, Clang).
- A terminal or command line environment.

### Compilation

Each C file can be compiled individually using the following command:

```bash
gcc -o endianizer 2.58_endianizer.c
gcc -o xyz_variables 2.59_xyz_variables.c
gcc -o byte_replacement 2.60_byte_replacement.c
gcc -o bit_checker 2.61_bit_checker.c
gcc -o any_odd_one 2.64_any_odd_one.c
```

### Running the Programs
```bash
./endianizer           # For checking endian type
./xyz_variables        # For demonstrating XYZ variable bit manipulation
./byte_replacement     # For replacing bytes in a word
./bit_checker          # For checking specific bit patterns
./any_odd_one          # For checking odd bit values
```

## Example Output

### Endian Checker:
```bash
Initial hexadecimal value is 0x00000001
Discovering Endian Type
Little Endian Type Detected
```

### Odd Bit Checker:
```bash
Is there an odd bit of 1 in F0F0F0F0?: 1
Is there an odd bit of 1 in 0F0F0F0F?: 0
```

## Future Improvements

- **Extended Bitwise Operations**: Add more bitwise challenges such as rotating bits, counting set bits, etc.
- **Optimizations**: Improve the efficiency of certain bitwise operations for larger data types.
- **Multi-byte Support**: Extend the byte replacement program to work with different data types beyond integers.

## License

This project is open source under the MIT License. See the [LICENSE](LICENSE) for more details.