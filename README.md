# Arduino-SoftwareSerial-converter
How I connected Arduino as TTL when everything else failed

# Why?
There are ways to use Arduino as TTL converter. For instance, you can remove Atmel chip from your board (if it's not soldered) or connect RST to GND. However none of that has worked for me to connect my Arduino Nano compatible board (with CH340 chip) to other Arduino, so I decided to write this simple code.

# How it works? - 5 steps
1. You have to connect Arduino to your PC and upload attached sketch.
2. Then do some wiring: converter's digital pin 10 to external device's Tx pin, converter's digital pin 11 to external device's Rx pin, converter's ground to device's ground.
3. Open serial monitor in Arduino IDE (or oher app).
4. You will see information that converter is connected.
5. Now all data that you send will be received by converter (hardware serial port) and passed to connected device (software serial port). That works in both ways - you will also receive data sent by your device.
