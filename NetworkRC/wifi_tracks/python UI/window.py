from tkinter import *
from PIL import ImageTk
from control import nodeMCU as nm

class Window(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.tank = nm('http://192.168.8.109/', response = False)
        self.master = master
        self.init_window()
        self.change = None
        
    def init_window(self):
        self.imgs = {}
        button_imgs = ('up', 'down', 'right', 'left')
        self.master.geometry('{}x{}'.format(800, 600))
        self.master.title('Robot Command')
        self.pack(fill=BOTH, expand=1)

        for image in button_imgs:
            self.imgs[image] = ImageTk.PhotoImage(file='images/{}.png'.format(image))

        self.up = Button(self, image=self.imgs['up'], compound=CENTER, height = 75, width = 75)
        self.up.bind("<ButtonPress>", self.upEvent)
        self.up.bind("<ButtonRelease>", self.release)
        
        self.down = Button(self, image=self.imgs['down'], compound=CENTER, height = 75, width = 75)
        self.down.bind("<ButtonPress>", self.downEvent)
        self.down.bind("<ButtonRelease>", self.release)
        
        self.right = Button(self, image=self.imgs['right'], compound=CENTER, height = 75, width = 75)
        self.right.bind("<ButtonPress>", self.rightEvent)
        self.right.bind("<ButtonRelease>", self.release)
        
        self.left = Button(self, image=self.imgs['left'], compound=CENTER, height = 75, width = 75)
        self.left.bind("<ButtonPress>", self.leftEvent)
        self.left.bind("<ButtonRelease>", self.release)
            
        self.motorPWM = Scale(self, from_=100, to=0, length = 550, width= 50, command=self.scaleUpdate)
        motorPWM_label = Label(self, text= 'MotorPower')
        
        self.motorPWM.place(x=700, y=20)
        motorPWM_label.place(x=715, y=0)
        self.up.place(x=350,y=425)
        self.down.place(x=350,y=510)
        self.right.place(x=435,y=470)
        self.left.place(x=265,y=470)

    def upEvent(self, event):
        self.tank.send(rightDir=0, leftDir=0, rightSpeed=self.speed, leftSpeed=self.speed)
        print('FORWARD')
    def downEvent(self, event):
        self.tank.send(rightDir=1, leftDir=1, rightSpeed=self.speed, leftSpeed=self.speed * 0.93)
        print('BACKWARD')
    def rightEvent(self, event):
        self.tank.send(rightDir=0, leftDir=1, rightSpeed=self.speed, leftSpeed=self.speed)
        print('RIGHT')
    def leftEvent(self, event):
        self.tank.send(rightDir=1, leftDir=0, rightSpeed=self.speed, leftSpeed=self.speed)
        print('LEFT')
    def release(self, event):
        self.tank.send(rightDir=0, leftDir=0, rightSpeed=0, leftSpeed=0)
        print('STOP')
    
    def scaleUpdate(self, event):
        if self.change:
            self.after_cancel(self.change)
        self.change = self.after(500, self.scalePos)

    def scalePos(self):
        self.change = None
        self.speed = (self.motorPWM.get()/100) * 1023
        print ("speed: ", self.motorPWM.get())
     
root = Tk()
app = Window(root) 
root.mainloop()

