# Implementation Notes

This file holds some notes about the test implementation that I am using to show off a final implementation for this
section of the project.

## Encoder

The encoder that I am using for testing is a [Bourns Audio
3315](https://www.digikey.com/product-detail/en/bourns-inc/3315C-001-016L/3315C-001-016L-ND/2537720). This encoder has a
counting range from 0-16. An encoder counting range is the number of mechanical ticks that an encoder has. Usually an
range of 0-16 is pretty good for user input. For motor applications this number is very low. A low resolution means that
the mapping from ticks to degrees is of low resolution. With the current test configuration I was able to get a mapping
of around **5 degrees per tick on the encoder**. In a production motion control system this would be abysmal. For the
testing application it should be good enough to show that something is working.

## PWM System

PWM for an actual motor control situation would be designed more strictly. In this demonstrations example I set the PWM
period to a reasonable default that will clearly show the system working. In an actual motor control situation the
period and duty cycle would have to match the motor under control. Since I do not have an actual motor for testing I had
to make some liberal default value choices. To make the math easy, I chose a PWM period of 1ms with 360 duty cycle
deviations. That means that the duty cycle can be set in increments of 360. As an example, a 50% duty cycle would have a
value of 180 in the counter compare register. This simplification makes the conversion from encoder ticks to PWM output
straightforward. A 1ms period makes visualization on an oscilloscope easy.
