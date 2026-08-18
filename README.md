# Arduino-Password-Lock

## Overview
This project is an embedded password-authentication system built using an
Arduino UNO, IR receiver, and LCD1602 display.

Users enter a password using an IR remote. The Arduino reads and processes
the input, compares it against the stored password, and provides feedback
through the LCD.

## Hardware

- Arduino UNO
- IR receiver
- LCD1602
- IR remote
- Breadboard
- Jumper wires

## How It Works

1. The IR receiver detects button presses from the remote.
2. The Arduino converts those signals into usable input values.
3. Entered digits are stored until the password is complete.
4. The entered password is compared against the stored password.
5. The LCD displays whether access is accepted or denied.

## Hardware Setup



## Key Concepts

- Embedded programming
- Hardware/software integration
- IR communication
- LCD interfacing
- Input validation
- Breadboard prototyping
- Hardware debugging

## Source Code

The Arduino program is available in:
