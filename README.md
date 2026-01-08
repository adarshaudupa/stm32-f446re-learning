# STM32 F446RE Learning Journey

## Week 1: GPIO Fundamentals

### Day 1-2: Pull-up Resistors and Input Configuration

**Goal**: Understand how pull-up resistors prevent floating GPIO inputs.

#### Hardware Setup
- **Pin used**: PC13 (Blue Button on Nucleo board)
- **Hardware pull-up**: 4.7kΩ external resistor on board
- **Software pull-up**: Disabled (set to GPIO_NOPULL in code)

#### What I Observed
- **Button not pressed**: PC13 reads HIGH (1) — pulled to VDD by external 4.7kΩ resistor
- **Button pressed**: PC13 reads LOW (0) — button connects pin directly to GND


#### Code Explanation
The main loop reads PC13 every 500ms and prints the state over UART.

#### Why Pull-ups Matter
Without a pull-up, the pin floats and reads random values. The external 4.7kΩ resistor keeps the pin stable at HIGH when the button isn't pressed.

#### Key Takeaway
Pull-up resistors prevent floating inputs by connecting the pin to VDD through a resistor. This ensures stable logic levels.
