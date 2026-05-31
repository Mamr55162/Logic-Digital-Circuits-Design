# Indicators class
## Overview
This class focuses on implementing different types of indicators to use on the outputs of the circuits.
## Code Walkthrough & Multisim guide
* **LED**: the most important and most used indicator, implemented as a function that accepts a value and outputs a scentence whether the LED is on or off, see the following code snippet:
```cpp
 static void LED(bool val)
   {
      if (val == true)
         cout << "LED is ON\n";
      else
         cout << "LED is OFF\n";
   }
```
It is easy, readable and manageable. For Multisim design, a LED can be found in Diodes section in a subsection named LED, you can use LED_blue, LED_red, etc., each color has its own forward voltage and current, make sure to connect the anode of the LED with the output of the circuit or gate you are using, and connect the cathode directly to a ground.

<img width="257" height="167" alt="image" src="https://github.com/user-attachments/assets/c88be3ce-b746-42aa-b952-40865b10cb3e" />

***A LED_red connected to the output of an AND gate and a ground***

