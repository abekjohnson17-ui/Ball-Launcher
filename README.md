Ping Pong Ball Launcher

What does it do?

This project is a ball launcher that has a closed-loop feedback system. There are three main things that the project does:
1. Calculate the velocity after each shot to dial in the accuracy on the next shot.
2. Often times ping pong can have a wide variety of spin on the ball, this machine can change the spin of the ball at launch.
3. Randomly decide where the next shot will be from left to right.

Motivation:

I am an avid tennis player and a student at the University at Buffalo studying Mechanical Engineering. I wanted to make a tennis ball launcher but the motors and components would be out of my budget, so I decided to scale it down to a ping pong ball launcher. 
I have used tennis ball launchers before and one thing that they can do is they can put variable spin on the ball to simulate a real game. This is a major feature I want to encorporate into my project. Essentially, the two robots are the same just scaled differently.

BOM:

<img width="520" height="306" alt="image" src="https://github.com/user-attachments/assets/81c263d6-ea6e-49f2-8fed-538e559e370f" />

Link to BOM: 

https://docs.google.com/spreadsheets/d/1TKzZSILnyTzFo4eQHcQ44TPMbz68pp8OG-lISy_ujTU/edit?gid=0#gid=0


STL Files are located under the src folder -> STL Files

Wiring:

<img width="764" height="499" alt="image" src="https://github.com/user-attachments/assets/0ad6333a-b479-4e06-9f63-7a8a01f4fd2d" />


What is Each Part Responsible for?
- 12V MAX 300 RPM DC Motors >> Spin the wheels to launch the balls.
- 6V MAX 5 RPM DC Motors >> Spin auger feeding mechanism.
- 20KG Servo Motor >> Turn machine left to right.
- Hall Effect Sensors >> Used to determine spin and RPM of motors.
- Laser Reciever Sensors >> Used to calculate exit velocity of the ball and make the next shot more accurate.
- L293D Motor Driver >> Allows for variable speed control of the motors.

Limitations:

1. The motors do not spin fast enough to launch the ball at a decent distance, I should have used motors that spin at much higher RPM. To get around this with what I had I used a gear ratio to increase speed.
2. The auger feeding mechanism will drop 2-3 balls at a time. To fix this I can add dividers along the length of the auger to drop one ball at a time.
3. The servo that turns the machine from left to right will jam sometimes. I should have made the attachment system more aligned with the axis.

Pictures:

![IMG_7604](https://github.com/user-attachments/assets/cd588d3d-096e-4a29-9018-58366ef20755)

![IMG_7606](https://github.com/user-attachments/assets/5221963b-b5d1-48bf-ae88-c3cd4df74e90)

![IMG_7608](https://github.com/user-attachments/assets/8b1680ac-cd74-48f7-92b6-3d4eaf3051e0)

Link to YouTube Video of Velocity Calculation Demo:

https://studio.youtube.com/video/sxxTJT0Kazk/edit
