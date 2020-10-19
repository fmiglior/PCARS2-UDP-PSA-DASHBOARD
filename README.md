# PCARS2-UDP-PSA-DASHBOARD-


## About
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/M1NcEVVuiBA/0.jpg)](https://www.youtube.com/watch?v=M1NcEVVuiBA)

On this project i read valeus from the game project cars 2, from the UPD packs and send to a Peugeot 3008 dashboard using CAN signal.

I use a arduino and a ESP32 on this project, because the MCP2515 needs 5V to work, and the ESP32 operating voltage is 3V.(Today i have another solution to this a Sn65hvd230 can bus module, but i didn't update the code to use only the esp32.)

All credits to *cyclicscooby* and his post on project cars forum, I use his work to undestand the Pcars UDP and how to use the esp32 to read. 
http://forum.projectcarsgame.com/showthread.php?43111-How-to-import-data-from-wifi-into-arduino/page4

This code works for Project Cars 2 (Ps4, Xbox one and PC) and Automobilista 2 (PC). you need to set the games to Project cars 2 protocol and adjust the speed, normally 6 is good.


# Pcars2 UPD Format.

on the [Project Cars API Website](https://www.projectcarsgame.com/two/project-cars-2-api/) you can download the UDP definitions, on the file you will find watch packets the game sends.
Basically, the Project Cars 2 Protocol sends some packages depending on what is happens in the game. The telemetry packet, for example, will be send all the time if the car is in the track. the telemetry packet have a size of 559, on the adress 40 and 41 you will find the HEX values referring to RPM, on 45 gear.


# What you need:
- ESP32;
- Arduino Uno or NANO;
- MCP2515;
- PSA can 2010 Dashboard (i use a 3008 TFT screen)


``
You can read more about the PSA CAN, and download the MCP2515 library to use in this project: https://github.com/autowp/arduino-mcp2515 [https://github.com/autowp/arduino-mcp2515]
``

# ESP32
On this project the ESP32 was used to receive the UDP data from the game, by wifi, and convert the values to understendable values. Like Km/h, RPM and Gear Number, and then convert again to a HEX.
after all conversions the ESP32 makes a PACK and send it by serial port to the arduino.


***You will connect ONLY the TX port of the ESP32 to the RX port of the ARDUINO, DON'T connect the TX of arduino on the RX ESP32!!!! remember to connect one ESP32 GROUND to Arduino GROUND too***

# ARDUINO
Arduino receive the packet on serial port from the ESP32, and use the MCP2515 to send can mensages to the 3008 Dashboard.
On the arduino code, there 2 importants CAN comannds to keep the display ON. (the display needs receive the signal to tell him the ignition and the can network is ON).


# Problems 
the esp32 send a pack to arduino every time he receive a UPD pack, and arduino send a can command every time he receive a pack from esp32. but the dashboard doesn't handle well if to much code came on the same time.




