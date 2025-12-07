What does it do?
This project is a ball launcher that has a closed-loop feedback system. There are three main things that the project does:
1. Calculate the velocity after each shot to dial in the accuracy on the next shot.
2. Often times ping pong can have a wide variety of spin on the ball, this machine can change the spin of the ball at launch.
3. Randomly decide where the next shot will be from left to right.

Motivation:
I am an avid tennis player and a student at the University at Buffalo studying Mechanical Engineering. I wanted to make a tennis ball launcher but the motors and components would be out of my budget, so I decided to scale it down to a ping pong ball launcher. 
I have used tennis ball launchers before and one thing that they can do is they can put variable spin on the ball to simulate a real game. This is a major feature I want to encorporate into my project. Essentially, the two robots are the same just scaled differently.

Parts:
- (12V MAX 300 RPM DC Motors)[https://www.amazon.com/dp/B072N84V8S?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1] [2 QTY] Link: https://www.amazon.com/dp/B072N84V8S?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1
- 6V MAX 5 RPM DC Motors    [1 QTY] Link: https://www.amazon.com/dp/B0DP439JSX?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1
- 20KG Servo Motor          [1 QTY] Link: https://www.amazon.com/Miuzei-Torque-Digital-Waterproof-Control/dp/B07HNTKSZT/ref=sr_1_7?crid=CWLL0Z4T3YVP&dib=eyJ2IjoiMSJ9.cU8tLWXpdTzPYBltBAIFiy9cAixaNMLwpIij9XVgfnhEN1XV1s7OP64ENuOFrw9q0WzQyRamgMz8oVlQ63T46UIDUMUm8E-B8w1VZe102q36vgtpOOWl3oAPMdtXRmJcywIImvGlTUPvC0KJ_C5KaHid76_wqYPB9ct1-fyxDanhzNzHGMnFlSaQzyIgiV8jsUisj-z-Ve21F26Q0Ut_k_bKmj3uhqxbbWllPn-ont8j8ZYCORZSO7gJb_5HiIysSAAEf4SHi4QQS86qNWmpW7KVLd8cosWYgi4FyujYN8A.aMgmCREqT7Q8lBQ9tHOvImQbNwIlwzKTWiGdI9vjb4k&dib_tag=se&keywords=servo&qid=1765056216&sprefix=servo%2Caps%2C136&sr=8-7
- Hall Effect Sensors       [2 QTY] Link: https://www.amazon.com/dp/B01NBE2XIR?ref=ppx_yo2ov_dt_b_fed_asin_title
- Lazer Reciever Sensors    [2 QTY] Link: https://www.amazon.com/dp/B01NBE2XIR?ref=ppx_yo2ov_dt_b_fed_asin_title
- Bearings 8 x 22 x 7MM     [3 QTY] Link: https://www.amazon.com/YAMASO-Pcs-608-Ball-Bearings/dp/B0CYYYZRV9/ref=sr_1_6?crid=345CK3ADJQPPQ&dib=eyJ2IjoiMSJ9.qSDWLuUG4RM0AgA10amN7FIdGGP1z8uSXYf9a6c8pXzB8P80rEzY1IP-RrjCXYk9gOJM15TMt73J2q4Pyxonet2TRniTL_gCEWexJ2VJt0ashtdQee0gOMVyaEAP0o12YK5hYZFxeouQkZsx1WJHH1dvxeyK8Is70R1RQGnf02VHXf8BtfhM404ZXQE-1Ao54txxRCgyrEVOn9t2woC5x0h_s83i_N3sgt54xoFTah0.A0vgxy0vnDexkokLErtcjbk2NK_3-Ab30_CXxsXjmEs&dib_tag=se&keywords=ball+bearings&qid=1765056630&sprefix=ball+bearing%2Caps%2C207&sr=8-6
- L293D Motor Driver        [2 QTY] Link: https://www.amazon.com/BOJACK-16-pin-Stepper-Drivers-Controllers/dp/B09NBQVYLL/ref=sr_1_1_sspa?crid=2DPPVN8TKODHA&dib=eyJ2IjoiMSJ9.ypgiMPr-VKlehiP5grMA9ykHk1f1rlY8HZNqsh-Rs339pmOrxXBpQpOD6x9XXCt0pMsOdvxhKYKhs5DVRXori_vWePv4tPr7xYU8d8UGIgvvTd-1kDuKpKhoyhKz7X4mfnatc4NWe49Z07_EMyEpEx-8Tn-xdIwlIcgimc6z2LazyinaHRcMVQpGZdtfqOZUTTnPWwTJZLO8usQWkyS-R4da0HYWz-lD7ORfchcw3T0.5AqcHRyihYBcP_3WwXrTENQWssteNHstqgE7rfmK8qA&dib_tag=se&keywords=l293D&qid=1765057013&sprefix=l293%2Caps%2C173&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1
- Assorted M2, M3, and M4 Heat Set Inserts Link: https://www.amazon.com/Kadrick-Threaded-Assortment-Printing-Components/dp/B0CPVCTXJ7/ref=sr_1_2_sspa?crid=234UR6JHXYEAT&dib=eyJ2IjoiMSJ9.DQJ37CXmBvW7v_BbLiFA8zUTI7xU089Gk1hdb1-UtXWx4OPa62PdpFxFqOkPXwnxc-kzLgTebQB9G_QDNFi17-3V1HuEsZ15ET2vpQ8S8GYq0VtCLBv5b5LWu3Qc--21VW0BpCPuROgLeWDAPPD9xRxs02UvD8j7o3oiTFFsbCwC3bKTZ4uVSvBBeCxnlUvwQIFLAaDfsys3sh4b_q_zIf9a2pFkBMWZIE0COJZfxzs.0s34Yc0q8o_Dm260whIFXXMjUMaCdTdghNKesvmjDbM&dib_tag=se&keywords=assorted%2Bheat%2Bset%2Binserts&qid=1765056868&sprefix=assorted%2Bheat%2Bins%2Caps%2C145&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1
- Assorted M2, M3, and M4 Bolts Link: https://www.amazon.com/Hapric-Metric-Assortment-Plated-Washers/dp/B0FK9THQ3D/ref=sr_1_13?crid=2Q0XA3S13F342&dib=eyJ2IjoiMSJ9.j0ipUOvIRt8aDayBQ3hXb-9425LdeSs_AFzWXZnEincldA-bP6DUjDEIdY_GQwXYHsuTpWLDl21Lk7cJY1qrk8d3SplNnPEocfWJKZO0Ci6Uqx3C_i2aKjbL_6S-bJROmmOmMGMBxcvhVckc1hq3M3nPhlhuP6HKdKKoeTRoHp3xsciDaMF5InoibiKJRiawNzjTS8VkUgDHPw_n9IapjeE6txWrVZVYZvq7lRfW8fc.mPKXB02Q6HFqasliRAOdRg6-AHNd96zlX1T1Zw3ulPI&dib_tag=se&keywords=assort%2Bm2%2Bto%2Bm5%2Bbolts&qid=1765057044&sprefix=assort%2Bm2%2Bto%2Bm5%2Bbolts%2Caps%2C117&sr=8-13&th=1
- 3D Printed Custom Components (See in "STL Files" folder)

What is Each Part Responsible for?
- 12V MAX 300 RPM DC Motors >> Spin the wheels to launch the balls.
- 6V MAX 5 RPM DC Motors >> Spin auger feeding mechanism.
- 20KG Servo Motor >> Turn machine left to right.
- Hall Effect Sensors >> Used to determine spin and RPM of motors.
- Lazer Reciever Sensors >> Used to calculate exit velocity of the ball and make the next shot more accurate.
- L293D Motor Driver >> Allows for variable speed control of the motors.

Limitations:
There are three main limitations:
1. The motors do not spin fast enough to launch the ball at a decent distance, I should have used motors that spin at much higher RPM. To get around this with what I had I used a gear ratio to increase speed.
2. The auger feeding mechanism will drop 2-3 balls at a time. To fix this I can add dividers along the length of the auger to drop one ball at a time.
3. The servo that turns the machine from left to right will jam sometimes. I should have made the attachment system more aligned with the axis.
