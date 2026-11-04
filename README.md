# Embedded GPIO Register Simulator

A lightweight, interactive C console application that simulates low-level hardware register manipulation and bitwise operations for embedded microcontrollers (such as STM32 or AVR).

## Problem & Purpose
In embedded systems and microcontroller programming, the states of dozens of hardware pins and peripherals are rarely stored in separate variables. Instead, they are packed into individual bits within a single memory cell (a status or port register) to conserve memory and bandwidth. Manually calculating bitmasks and remembering bitwise operators can be challenging when developing low-level drivers.

This tool solves this challenge by providing an interactive command-line environment to:
- **Manipulating individual bits:** Safely turning hardware pins ON (`HIGH`) or OFF (`LOW`) using bitwise shifts and masks.
- **Toggling states:** Instantly flipping pin states using XOR operations.
- **Real-time diagnostics:** Checking individual pin statuses and printing the exact 8-bit binary representation alongside decimal values.

## File Overview
- `main.c` — The core simulation program containing the interactive loop, bitwise manipulation functions, and binary status printers.
