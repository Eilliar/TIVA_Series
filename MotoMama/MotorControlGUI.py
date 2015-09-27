# -*- coding: utf-8 -*-
"""
Graphical User Interface (GUI) to Control a DC Motor using MotoMama V2.0 (L298N Driver)
Created on Sat Sep 26 13:12:48 2015

@author: Bruno Godoi Eilliar
Notes:
    - Using Python serial module
    - Using Tkinter module to create GUI
"""

from Tkinter import *
from PIL import ImageTk, Image
import serial

global velocity
global direction
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
    win.title("Motor Control Interface")
    win.geometry("400x180")
    win.protocol("WM_DELETE_WINDOW", on_closing)

    # Create image compatible with Tkinter
    path = "logo.jpg"
    logo = ImageTk.PhotoImage(Image.open(path))
    #The Label widget is a standard Tkinter widget used to display a text or image on the screen.
    panel = Label(win, image = logo)
    panel.image = logo
    

    # Create buttons
    Forward = Button(win, text = "Move Forward", command = forward)
    Backward = Button(win, text = "Move Backward", command = backward)
    Off = Button(win, text="Turn Off the motor", command = turnOFF)
    bar_v = Scale(win, from_=10, to=75, resolution = 1, orient = HORIZONTAL, label = "Velocity", command = update_v)
    
    # Attach buttons on the window
    Forward.grid(row = 0, column = 0)
    Backward.grid(row = 1, column = 0)
    Off.grid(row = 2, column = 0)
    bar_v.grid(row = 3 , column = 0)
    
    #The Pack geometry manager packs widgets in rows or columns.
    panel.place(x = 150, y = 10)

    # Start GUI
    win.mainloop()

except serial.serialutil.SerialException:
    print "MSP430 not connected!"
