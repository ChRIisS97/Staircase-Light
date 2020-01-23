                       
# Staircase-Light   
Staircase light with two PIR Sensor, one on top of the Staircase and other on the bottom. <br>
If you go from the bottom up, the light goes from the bottom up.
And from the top exactly the other way.

# Components 
- PIR sensors
- Arduino and the [IDE](https://www.arduino.cc/en/Main/Software) 
- Brightness sensor
- WS2812b LED strips
- LED Profil
- Power supply 5V 20A

# Functions at the time
- Running light from top to bottom and the other way
- If one sensor activ, the other is disabled at the moment 
- Switched off during the day, only active at a certain brightness value
- Only active when approaching

# How to
``` Ruby
Download the file
load file
Change pin assignment if it is differently
upload to your arduino

