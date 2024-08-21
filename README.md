# STM32 Nucleo L476RG Multi-Sensor Project

## Overview

This project presents a multi-sensor application developed on STM32 Nucleo-L476RG microcontroller with KA-Nucleo-Multisensor shield. The project involves communicating with a temperature sensor via 1-Wire protocol and a pressure sensor via I2C protocol, and using an ADC to measure the voltage drop across a photoresistor. The measured values are displayed on 7-segment displays.

## Features
- Possibility to switch between modes with buttons equipped with software debouncing

- *Stopwatch*:
  - Push-button activated
  - Displays time on a 7-segment display

- *Temperature measurement via 1-Wire*: 
  - Uses a DS18B20 temperature sensor.
  - Communication is via 1-Wire protocol.
  - Displays temperature on a 7-segment display.

- *Pressure and temperature measurement via I2C*:
  - Uses LPS25HB pressure sensor.
  - I2C communication is established to read pressure and temperature.
  - Converts the pressure difference from the reference value to the altitude change
  - Displays altitude difference and temperature on a 7-segment display.

- *Light intensity measurement with ADC*:
  - Uses a photoresistor
  - ADC is used to read the voltage on the photoresistor
  - Displays temperature on a 7-segment display.

- *Libraries*:
  - The project uses libraries provided by Forbot.co.uk for 1-Wire and I2C communication.
  - The library for the 7-segment display is the author's.

## Hardware requirements

- *STM32 Nucleo-L476RG*.
- *KA-Nucleo-Multisensor Shield*.
- *DS18B20 temperature sensor*.
- *LPS25HB pressure sensor*.
- *Photoresistor*.
- *4x 7-segment display module*.

