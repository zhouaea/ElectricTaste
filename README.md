# Tongue Buds: A DIY Electricity-Based Taste Interface Device 

The primary way that most people receive output from their devices are through sight and sound. However, there are no fundamental limitations that prevent computers from being able to transmit data through other senses. After all, any kind of data can be represented with binary digits. In their [seminal paper in 2011] (https://dl.acm.org/doi/abs/10.1145/2030112.2030213), Ranasinghe and colleagues found that they could simulate sour, salty, and bitter sensations via electrodes by transmitting different amounts of electric current on the tongue.  

![image](https://user-images.githubusercontent.com/75145715/217974514-855754fd-5c83-465c-86cd-e68d7eb6cd61.png)

Over the course of a week, I tried to create an equivalent device using an arduino kit to test the paper for myself.

## The Device
![taste-machine](https://user-images.githubusercontent.com/75145715/217975376-5f3efdf2-4b81-441b-a378-69bc5c205603.JPG)
The device consists of only five components: an arduino, an ammeter, a joystick, a breadboard, and a few copper wires. The arduino outputs a voltage from 0-5V that is manually operated by the joystick. There are two copper wires that the user puts on their tongue. Below is a close up of the breadboard and arduino that will match with the ports the code in this repo is looking for.

![taste-machine-closeup](https://user-images.githubusercontent.com/75145715/217977514-e5039ec3-74ff-4130-a151-9cb9f1d1020b.JPG)

## How To Use (two people recommended)
![taste-machine-test](https://user-images.githubusercontent.com/75145715/217976367-1fca4032-1524-4a3e-813d-2c0e32eefc3d.jpg)
1. Upload the code from the repository into the arudino. Keep your laptop connected to the arduino and open the serial monitor.
2. Once the arduino is running the code, open the serial monitor, which will show the voltage of the electrical output of the arduino.
3. The person who is not using the device should complete the circuit on the breadboard with the ammeter (which should be set to monitor microamps). The ammeter should show a number greater than 0. 
4. Whoever is using the device should gently hold the flat part of the two wires onto their tongue (carefully, as the wire tip can be sharp). 
5. Now that everything is setup, the person who is not using the device can increase the voltage of the arduino by holding the joystick up. 
6. To obtain specific taste sensations, adjust the joystick to get specific microamp readings on the ammeter that match with the figure above.

## Design Methodology
Coming Soon!





