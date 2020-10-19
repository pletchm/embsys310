# Embedded Device Example

An example of an embedded device is a touchscreen for a smart phone. I'm ot talking about
the whole phone, which of course has a general purpose operating system, but rather the technology
that takes the analog data from a capacitive touchscreen and converts it into digital information
that indicates a user's activity.

## How it Works
The embedded devices that control/manage touchscreens take analog capacitance data from the touchscreen
which are actually a grid of tiny transparent sensors (i.e., capacitors). A change in capacitance
(electric field) relative to the baseline capacitance can mean that a finger is touching the part of the
screen where that sensor is located. The device must convert analog capacitance data needs to be converted
into a digital format so that it can be processed further. The device will need to apply digital signal
processing (DSP) techniques to the data in order to intepret the data and discern if there was user
activity and determine the location and magnitude of that user data. Then this interpreted data is
reported to the host system so that it can act on it. 

## Design Challenges
Here are a list of the design challenges for making this embedded system device:

1. Given how there is already limited space in a phone, and much of that space needs to be used for
   larger components like the general purpose computer running the OS of the device, the battery that
   powers the device, etc., the embedded device that controls/manages the touchscreen must be small.

2. Processor Hog: complex and robust digital signal processing (DSP) is required. The device must be
   able to quickly and efficiently detect multiple fingers touching a screen, even if they are wet
   or cold. This requires complex mathematical calculations that can be compuationally intensive.

3. The company making the embedded touchscreen device may not actually be making the entire phone.
   That is they may be contracted to make only the touchscreen device by the company actually making
   the phone. This likely imposes restrictions and reduces flexibility of the design:

   a. Cost: They will need to make the device as cheap as possible to remain competitive.
   
   b. Hardware interface: There may be inflexible requirements for how the device interfaces with the
      phone's hardware.

   c. Software interface: There may be inflexible requirements for how the device interfaces with the
      phone's software/OS.

