# Tongue Buds: A DIY Electricity-Based Taste Interface Device 

The primary way that most people receive output from their devices are through sight and sound. However, there are no fundamental limitations that prevent computers from being able to transmit data through other senses. After all, any kind of data can be represented with binary digits. 

In their [seminal paper in 2011](https://dl.acm.org/doi/abs/10.1145/2030112.2030213), Ranasinghe and colleagues found that they could simulate sour, salty, and bitter sensations via electrodes by transmitting different amounts of electric current on the tongue.

![image](https://user-images.githubusercontent.com/75145715/217974514-855754fd-5c83-465c-86cd-e68d7eb6cd61.png)

Since the publicatiion of this paper, research on taste-based computer interfaces has gotten impressively sophisticated (See further reading section below). The implications for this technology are incredible: it would essentially allow people to enjoy flavor without eating food, birthing everything from dieting products, specialized silverware that enhances the flavor of food, to even taste as a language.

This stuff is really exciting to think about. Discussing it with friends, even more incredible is how taste-based interfaces could integrate with digital media. We could have a Spotify for flavors, where musicians become chefs, or integration with social media, where anyone can share the flavors of their food pictures. We could taste the food in video games and VR/AR applications, or even somehow integrate taste into movies. 

Given the ramifications of this technology, I wanted to make a prototype for myself. Over the course of a week, I tried to create an equivalent device to the 2011 paper using a basic arduino kit. Arduinos are programmable circuit boards that usually come with some cheap wires, sensors, and motors that can be connected to eachother using a block with a bunch of holes in it called a breadboard.

## Table of Contents
- Background Knowledge
- Design Process
- Testing The Device
- The Device
- How To Use
- Future Projects
- Further Reading

## Background Knowledge
To understand how the device works, one needs to have a basic understanding of electricity: specifically voltage, resistance, and current. 

![image](https://user-images.githubusercontent.com/75145715/218164189-b81cdb46-67fc-4eeb-9853-b8f3aed5673c.png)
Comparing electricity to water, voltage is like the water pressure, current is the rate at which the water is flowing, and resistance is how small the water pipe is. Voltage is measured in volts, current is measured in amps, and resistance is measured in ohms. You can express the relationship between these three measurements with the formula voltage = current * resistance.

## Design Process
The key to this device is to essentially add the tongue to an electric circuit. The arudino supplies the voltage, and the tongue acts as the resistance the electricity needs to pass through to complete the circuit. 

One issue at the beginning I was especially worried about was safety. I didn't want to accidentally fry someone's tongue. For reference, people tend to feel a tingling sensation when the current is [around 1-5 milliamps](https://www.sparkfun.com/news/1385). For reference, the maximum current applied in the 2011 paper was 250 microamps, or about 4-20 times less than that. 

With safety out of the way, all that was left was the mechanism for simulating different flavors. As shown in the table from the paper above, to simulate specific flavor sensations you have to applying a specific amount of electric current to the tongue. Unfortunately, arduinos can only directly vary voltage. I remember spending a decent amount of time researching how I could get an arduino to apply a constant current source, but basically every option required some electrical engineering knowledge that I didn't have. So eventually, I ended up opting for the simplest possible method, which was to connect a device that could measure current (an ammeter) to the circuit, and manually adjust the voltage (indirectly changing the current, since the resistance of the circuit would be the same) via a videogame joystick. 

With some back of the envelope

## Testing the Device
TODO

## How to Use
![taste-machine](https://user-images.githubusercontent.com/75145715/217975376-5f3efdf2-4b81-441b-a378-69bc5c205603.JPG)
The device consists of only five components: an arduino, an ammeter, a joystick, a breadboard, and a few copper wires. The arduino outputs a voltage from 0-5V that is manually operated by the joystick. There are two copper wires that the user puts on their tongue. Below is a close up of the breadboard and arduino that will match with the ports the code in this repo is looking for.

![taste-machine-closeup](https://user-images.githubusercontent.com/75145715/217977514-e5039ec3-74ff-4130-a151-9cb9f1d1020b.JPG)

These were the steps we followed to run the device:
1. Upload the code from the repository into the arudino. Keep your laptop connected to the arduino and open the serial monitor.
2. Once the arduino is running the code, open the serial monitor, which will show the voltage of the electrical output of the arduino.
3. The person who is not using the device should complete the circuit on the breadboard with the ammeter (which should be set to monitor microamps). The ammeter should show a number greater than 0. 
4. Whoever is using the device should gently hold the flat part of the two wires onto their tongue (carefully, as the wire tip can be sharp). 
5. Now that everything is setup, the person who is not using the device can increase the voltage of the arduino by holding the joystick up. 
6. To obtain specific taste sensations, adjust the joystick to get specific microamp readings on the ammeter that match with the figure above.

![taste-machine-test](https://user-images.githubusercontent.com/75145715/217976367-1fca4032-1524-4a3e-813d-2c0e32eefc3d.jpg)

## Future Projects
Testing how taste interacts with sight and sound by synchronizing the machine to a youtube video. What if we added the sour taste while watching someone eat a lemon? Or adding a sour taste to a video of someone eating a non-sour food?

## Further Reading
TODO



