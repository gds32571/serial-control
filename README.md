# serial-control
Code to allow ESPEasy running on ESP8266 to send serial data to ATTiny44 to control 6 output pins.
You must wait about 1/2 second after sending a serial string before sending another.  This is probably 
related to the baud rate (300), which is pretty slow.
The rules file is for test purposes but demonstrates how ESPEasy can talk to the ATTin44.
A schematic to follow.
