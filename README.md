# serial-control
Code to allow ESPEasy running on ESP8266 to send serial data to ATTiny44 to control 6 output pins.
You must wait about 1/2 second after sending a serial string before sending another.  This is probably 
related to the baud rate (300), which is pretty slow.
The rules file is for test purposes but demonstrates how ESPEasy can talk to the ATTiny44.
A schematic to follow.
The serial string has first character is the output pin 0 - pin 5 which is ATTiny44 package pins 13 - 8.
Second character is the desired pin state, either 0 or 1.
Connect serial from ESPEasy TX to ATTiny pin 10 (package pin 2). You can/should use a 1K resistor between the two.
Create a "Serial Server" device in ESPEasy. Set a TCP port which isn't used (but could be), 300 baud. 

For example, in the rules, a "serialsend,51" will send data characters "51" to the ATTiny. This will set pin 5 to HIGH.
See also: https://www.letscontrolit.com/wiki/index.php/Ser2Net for more information.
