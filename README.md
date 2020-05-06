# Fastest_Finger_First
Quiz-type game shows are increasing and becoming popular on television these days. In such games, the fastest finger first indicators (FFFIs) are used to test the player’s reaction time. The player’s designated number is displayed with an audio alarm when the player presses his entry button.

The circuit presented here determines as to which of the four contestants first pressed the button and locks out the remaining three entries. Simultaneously, an audio alarm and the correct decimal number display of the corresponding contestant are activated.

The components used in this specific project are listed below. We will be discussing these components in detail in the next section of our report.

1. PUSH SWITCHES(5)
2. IC 7805
3. IC 7475
4. IC 74LS20
5. IC 74LS147
6. IC 74LS04
7. IC 74LS47
8. 7 SEGMENT DISPLAY
9. NE 555 TIMER
10. BUZZER
11. RESISTORS(470K-5,100k,330,10)
12. CAPACITORS(0.047,0.033,0.01)
13. POLARISED CAPACITOR(47)
14. ARDUINO UNO BOARD
15. JUMPER WIRES
16. VOLTAGE/POWER SUPPLY
17. BREADBOARDS

The Fastest Finger First Indicator circuit determines as to which of the four contestants pressed the button first and locks out the entries from the remaining three contestants. Simultaneously, an audio alarm and the correct decimal number display of the corresponding contestant are activated.

WORKING:

When a contestant presses his switch, the corresponding output of latch IC2 (7475) changes its logic state from 1 to 0. The combinational circuitry comprising dual 4input NAND gates of IC3 (7420) locks out subsequent entries by producing the appropriate latch-disable signal.

Priority encoder IC4 (74147) encodes the active-low input condition into the corresponding binary coded decimal (BCD) number output. The outputs of IC4 after inversion by inverter gates inside hex inverter 74LS04 (IC5) are coupled to BCD to- 7-segment decoder/display driver IC6 (7447). The output of IC6 drives a common anode 7-segment LED display (DIS.1, FND507, or LT542).
The audio alarm generator comprises clock oscillator IC7 (555), whose output drives a loudspeaker. The oscillator frequency can be varied with the help of preset VR1. Logic 0 state at one of the outputs of IC2 produces logic 1 input condition at pin 4 of IC7, thereby enabling the audio oscillator.

IC7 needs a +12V DC supply for a sufficient alarm level. The remaining circuit operates on regulated +5V DC supply, which is obtained using IC1 (7805).

Once the organizer identifies the contestant who pressed the switch first, he disables the audio alarm and at the same time forces the digital display to ‘0’ by pressing reset push button S5.
