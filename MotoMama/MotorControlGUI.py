# -*- coding: utf-8 -*-
"""
Created on Sat Sep 26 13:12:48 2015

@author: Bruno
"""

from Tkinter import *
import serial

velocity
direction = 0

try: 
    # Create a Serial connection with MSP430.
    msp430 = serial.Serial('COM5', 9600, timeout = 10)

    def on_closing():
        """
        When the window is closed, make sure to release kill serial communication
        """
        print "Closing Connection..."
        msp430.close()
        print "Done!"
        win.destroy()
        
    def forward():
        global direction, velocity
        direction = 1
        msp430.write( str(direction) + "," + str(velocity) + "\n")
        
        
    def backward():
        global direction, velocity
        direction = 2
        msp430.write( str(direction) + "," + str(velocity) + "\n")
    
        
    def turnOFF():
        global direction, velocity
        direction = 0
        msp430.write( str(direction) + "," + str(velocity) + "\n")
    
    
    def update_v(value):
        global velocity, direction
        velocity = value
        msp430.write( str(direction) + "," + str(velocity) + "\n")
    
    # Create a window
    win = Tk()
    win.protocol("WM_DELETE_WINDOW", on_closing)
    
    # Create buttons
    Forward = Button(win, text = "Move Forward", command = forward)
    Backward = Button(win, text = "Move Backward", command = backward)
    Off = Button(win, text="Turn Off the motor", command = turnOFF)
    bar_v = Scale(win, from_=10, to=75, resolution = 1, orient = HORIZONTAL, label = "Velocity", command = update_v)
    
    # Attach buttons on the window
    Forward.pack()
    Backward.pack()
    Off.pack()
    bar_v.pack()
    # Start GUI
    win.mainloop()

except serial.serialutil.SerialException:
    print "MSP430 not connected!"