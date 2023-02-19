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

## Testing the Device
I was a little worried if my device would work when I did some back of the envelope calculations. The average resistance of a human tongue is around 70,000 ohms. V = IR, so at the maximum voltage of the arduino, 5V, 5 / 70000 is approximately 70 microamps, which is actually not enough for the full range shown in the chart. When I actually tested the device with real people, I was able to consistently get up to around 200-300 microamps of current, so luckily the estimates online were on the high side. 

Getting up to around 200 microamps, the taste was really sour. The sour aftertaste in my tongue lasted for a while, at least a couple of hours actually, so 200 microamps might be too high for a commerical product :P. While it is sour, kind of like a lemon, it has a distinctly metallic and bitter flavor that comes with it as well. When we tried the lower currents to activate saltiness, it was salty, but there was also always a sour metallic taste included with it as well. 

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
Below are some resources, not only on taste technology, but multisensory technology in general.

### Electrical Taste Stimulation
- Nimesha Ranasinghe and Ellen Yi-Luen Do. 2016. Digital Lollipop: Studying electrical stimulation on the human tongue to simulate taste sensations. ACM Trans. Multimedia Comput. Commun. Appl. 13, 1, Article 5 (October 2016), 22 pages.
  - This one adds inverted current, which stimulates sweetness in addition to sour. First time sweetness has been induced with electricity. They also tried stimulating the left, right, and center of the tip of the tongue, with the left being less sensitive and being unable to perceive bitter. They also found a wide variation of perceived intensity of sourness with the same current levels. It shows that you have to calibrate the system to the user.
- Controlling saltiness without salt (2013): https://dl.acm.org/doi/10.1145/2506023.2506026
  - They run an electric current through a fork and a straw, to act as seasoning, kind of like Funrasa
- DIGITALLY STIMULATING THE SENSATION OF TASTE THROUGH ELECTRICAL AND THERMAL STIMULATION: https://core.ac.uk/download/pdf/48659289.pdf (2012)
  - Has detailed instructions on how to make a taste simulator that can do sour, salty, bitter, sweet, has arduino code + wiring diagram
### Thermal Taste Stimulation
- Nimesha Ranasinghe and Ellen Yi-Luen Do. 2016. Virtual Sweet: Simulating Sweet Sensation Using Thermal Stimulation on the Tip of the Tongue. In Proceedings of the 29th Annual Symposium on User Interface Software and Technology (UIST '16 Adjunct).
  - You can trigger mild sweetness and even spicy or minty by adjusting temperature of stimulus on the tongue.
- C. Suzuki, T. Narumi, T. Tanikawa, and M. Hirose. Affecting tumbler: affecting our flavor perception with thermal feedback. In Proceedings of the 11th Conference on Advances in Computer Entertainment Technology, p. 19. ACM, 2014. doi: 10.1145/2663806.2663825 
  - Heating or cooling the skin of the nose affects how we taste…
- Karunanayaka K, Johari N, Hariri S, Camelia H, Bielawski K and Cheok A. 2018. New Thermal Taste Actuation Technology for Future Multisensory Virtual Reality and Internet. IEEE Transactions on Visualization and Computer Graphics.
  - Implementation
    - Silver can be heated faster than copper
    - If you connect the peltier module with thermal epoxy, it reduces thermal resistance
    - Measures current flow to peltier module and its temperature with sensors
    - goes from 20C to 40C, for reference the max temperature the tongue can withstand is about 45C for 5-6 hours or 65C for 2 seconds
    - goes from 20C to 10C, couldn’t find anything on the min temperature the body can withstand
    - Certain people can’t taste sweetness via thermal stimulation, 50% or less according to previous studies, only 1/6 in this study
  - Results
    - Rapid rise of temperature associated with sweet, fatty, and electric
    - Rapid decrease of temperature associated with mint and metallic
    - Rapid rise of temperature makes sugar taste sweeter
### Chemical Taste Stimulation
- Norimaki Synthesizer Taste Stick: https://www.youtube.com/watch?v=7HIm4LoAZxU
  - This was released two years ago. Incredibly sophisticated, has all 5 basic tastes via electrolytes and works by subtracting them.
- D. Maynes-aminzade. Edible Bits: Seamless Interfaces between People, Data and Food. In Proceedings of the 2005 ACM Conference on Human Factors in Computing Systems (CHI’2005. Citeseer, 2005
  - TasteScreen: Sprays 20 flavored chemicals from computer screen that the user licks
- Derbyshire D. Revealed: The headset that will mimic all five senses and make the virtual world as convincing as real life, March 2009.
  - Sprays chemicals into face
- https://www.bbc.com/future/article/20141214-how-to-hack-your-taste-buds
  Certain foods have chemicals that latch onto taste buds, latent until they are washed away, changing the taste of the food you eat after
### Chemical Smell Stimulation 
- How to use smell to create an unforgettable experience: https://m.youtube.com/watch?v=NF198JITjF0
  - It is like being a chef, where senses are the ingredients used to cook up an intense moment
  - It will be the next form of “travel” 
  - It will reduce the fear of technology and increase trust (referring to using scents that instantly transport people to home or good memories)
- Eating better with digital scent: https://www.youtube.com/watch?v=JYpqL3bEPkE, 
  - There are more cells in the body than the ones in the nose that use smell (ex: immune system, organs, etc.)
  - Smell can signal the health of a person or even what disease they currently have
  - Smell determines how we interact with food
  - Has a device that emits smells to elicit emotions and even metabolic health
### Electrical Smell Stimulation
- Digital smell interface: https://www.youtube.com/watch?v=g37Qe8Kriuo, https://imagineeringinstitute.org/digital-smell-interface
You have to put it really deep up your nose…
### Combination Papers
#### Taste + Vision + Smell
- Vocktail (2017): https://dl.acm.org/doi/10.1145/3123266.3123440
  - Designed specifically for liquids, it’s a whole research paper and there’s a YouTube video with it. Modifies taste, smell, and even sight of a liquid via an LED in a special drinking cup.
  - The meat of their results came from seeing the effects of different smells on complexity, taste strength, and likability.
  - By this point, they’ve found electrical settings that correspond to tastes.
  - Sour: magnitude of current: 180uA, PWM duty cycle: 67%
  - Salty: magnitude of current: 40uA, PWM duty cycle: 20%
  - Bitter: magnitude of current: 80uA, PWM duty cycle: 43%
  - They also have smell technology, not much was detailed so I assume this has been covered somewhere else
#### Taste + Smell
- Simulating Tastes and Smells Using a Digital Lollipop - with Danielle George: https://www.youtube.com/watch?v=sSJ63KXyMqU&t=9s
  - 2014, such a surreal video. They show simulated tasting and smell, plus a hologram to a bunch of kids.
- Smell, Taste, Touch Via The Internet - Hi-Tech: https://www.youtube.com/watch?v=YxFXjKn1LxQ
  - Research lab has scentee, a product that you can connect to your smartphone that will puff up scents
- N. Ranasinghe, K. Karunanayaka, A. D. Cheok, O. N. N. Fernando, H. Nii, and P. Gopalakrishnakone. 2011c. Digital taste and smell communication. In Proceedings of the 6th International Conference on Body Area Networks. ICST (Institute for Computer Sciences, Social-Informatics and Telecommunications Engineering), 78–84. 
  - Not much on practical technology, but explores future deep brain stimulation techniques
#### Taste + Vision
- Teleporting Lemonade (2017): https://dl.acm.org/doi/10.1145/3024969.3024977
  - They only modify an LED at the bottom of a cup and strength of sourness with water, using sensors (RGB and PH) to try to mimic real lemonade
  - They found that real lemonade had a slightly higher sourness than the virtual lemonade, though it wasn’t statistically significant. They said it was because the water diluted the sourness or they should have done it to max setting. I think it might have been more sour because you could smell the real lemonade. But it was still impressive how similar the sourness intensity was for both.
- Hiromi Nakamura and Homei Miyashita. 2012. Development and evaluation of interactive system for synchronizing electric taste and visual content. In Proceedings of the SIGCHI Conference on Human Factors in Computing Systems. ACM, 517–520.
#### Vision + Smell
- Takuji Narumi, Takashi Kajinami, Tomohiro Tanikawa and Michitaka Hirose. Meta Cookie, SIGGRAPH 2010 Emerging Technologies, August 2010.
- Uses AR technology + scents to change the taste of a cookie
- H. Matsukura, T. Yoneda and H. Ishida, "Smelling screen: Technique to present a virtual odor source at an arbitrary position on a screen," 2012 IEEE Virtual Reality Workshops (VRW), 2012, pp. 127-128, doi: 10.1109/VR.2012.6180915.
#### Taste + Hearing
- https://www.international-sound-awards.com/hear-the-taste/
  - Food on airplanes tastes worse because the background noise increases bitter and umami sensations… Apparently high pitched noises support sweet tastes and low pitched sounds boost bitter tastes
  - Chef Steven Liu teamed up with a gastronomist to record soundscapes from Sweden for airline passengers to better enjoy food 
  - They had a fire crackling sound playing while guests were eating meatballs. Honestly it looked tastier…
  - Another restaraunt played sounds of the sea while serving seafood, which was reported to make the food taste better
- Junichi Yamaoka, Takaki Kimura, Toru Kawanabe, Taisuke Oshima, Ken Nakagaki and Yuri Hayamizu (Team Chimera). Tag Candy (in Japanese), International Collegiate Virtual Reality Contest (IVRC), The National Museum of Emerging Science and Innovation, August 2010.
https://www.frontiersin.org/articles/10.3389/fpsyg.2013.00838/full
  - Using certain words related to tasty foods can prime the brain to perceive it as more tasty
#### Eating, but not taste
- Yuki Hashimoto, et al. 2006. Straw-like user interface: virtual experience of the sensation of drinking using a straw. In Proceedings of the international conference on Advances in computer entertainment technology. ACM, 50.
  - Recreates feeling (pressure, vibrations) of drinking through a straw
- P. Kortum. HCI beyond the GUI: design for haptic, speech, olfactory and other nontraditional interfaces, pages 291–306. Elsevier/Morgan Kaufmann, 2008.
- Study on Control Method of Virtual Food Texture by Electrical Muscle Stimulation (2016)
  - Using electrodes on your face, you can change the perceived hardness and elasticity of the food you are eating
#### Taste besides food
- Hiromi Nakamura and Homei Miyashita. 2011. Augmented gustation using electricity. In Proceedings of the 2nd Augmented Human International Conference. ACM, 34.
  - Their vision is to be able to simulate the tongue to allow it to be able to recognize invisible stimuli like CO2 concentrations in the atmosphere 
  - The body of this work is a precursor to finding out how the tongue responds to electric currents
- Brainport (2008)  
  - a tool for the blind that creates a digital map of the world around them by converting camera footage to tongue stimulation
- José Vazquez-BuenosAires, Yohan Payan and Jacques Demongeot. Electro-stimulation of the tongue as a passive surgical guiding system, ICAR 03 Coimbra. IEEE Proceedings, pp. 638-643, 2003.
#### Smell for things besides food
- Inhaling history and smelling the future: https://www.youtube.com/watch?v=g37Qe8Kriuo
  - One artist put different smelling sculptures at different points in a retirement home for people with Alzheimer’s. They can’t forget the smells, allowing them to better navigate the home without getting lost, and even remember things from their childhood related to the smells.
- Why Smell is More Important Than You Think | Holladay Saltz | TEDxRVA
  - Rooms with a clean (citrus + fruity + flowery) smell make people more likely to do charitable things like donate money
#### Safety
- R.J. Dobrin. 1984. Liquid cleaner-disinfectant composition for use in wiping down dental operatories. (Aug. 7 1984). US Patent 4,464,293.
  - Rinse with tap water, swab with 70% isopropyl alcohol, then with deionized water for some reason, haven’t looked too far into this
  - You can reset taste by rinsing with deionized water
- C. F. Dalziel and W. R. Lee. 1968. Reevaluation of lethal electric currents. IEEE Transactions on Industry and General Applications, IGA-4, 5, 467–476.
  - Cited from some other papers, saying 200 micro amps is well below lethal range 

Also check out the only textbook on this subject to my knowledge as of the time of writing this: https://www.amazon.com/exec/obidos/ASIN/0198849621/books24x7com.
