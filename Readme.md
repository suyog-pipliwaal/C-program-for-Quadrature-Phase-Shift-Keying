# Understanding Quadrature Phase Shift Keying (QPSK) Modulation
Quadrature phase shift keying (QPSK) is another modulation technique, and it’s a particularly interesting one because it actually transmits two bits per symbol. In other words, a QPSK symbol doesn’t represent 0 or 1—it represents 00, 01, 10, or 11.

This two-bits-per-symbol performance is possible because the carrier variations are not limited to two states. In ASK, for example, the carrier amplitude is either amplitude option A (representing a 1) or amplitude option B (representing a 0). In QPSK, the carrier varies in terms of phase, not frequency, and there are four possible phase shifts.

We can intuitively determine what these four possible phase shifts should be: First we recall that modulation is only the beginning of the communication process; the receiver needs to be able to extract the original information from the modulated signal. Next, it makes sense to seek maximum separation between the four phase options, so that the receiver has less difficulty distinguishing one state from another. We have 360° of phase to work with and four phase states, and thus the separation should be 360°/4 = 90°. So our four QPSK phase shifts are 45°, 135°, 225°, and 315°.

## Input of program:-
1.length of signal

2.Digital signal

3.Data Rate(in bps)

other factor like carrier frequency and amplitude are hard coded in file

## Output of program
output is written in output.txt file in form of x (space )y corrdinates where x in term of time and y is instantaneous value of amplitude at that time

## Ploting
use gnuplot for ploting with command 
plot "output.txt" with linespoints  


## Output for 10001111 when data rate is 1bps
![Output for 10001111 when data rate = 1](/test1.png?raw=true)
