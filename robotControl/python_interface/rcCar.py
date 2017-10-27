import serial, time
from random import randint
import win32api
import win32con
# tries a connection to the ardunio through windows communication port 3.
try:
    conn = serial.Serial('COM3', 9600, timeout=.1)
    time.sleep(2)
except Exception as e:
    print(e)
# sends a custom bit code to the ardunio.    
def sendCode(code, delay=0):
    byteChr = chr(int(code, 2))
    conn.write(byteChr.encode())
    time.sleep(delay)
# checks for a set of keys being pressed or not using windows api and returns the keys pressed in lowercase form.
def keyState(keys):
    stack = []
    for key in keys:
        state = win32api.GetAsyncKeyState(ord(key))
        if(state < 0 or state == 1):
            stack.append(key.lower())
    return stack
# creates and send a bit code only if a change happens.
def main():
    names = ('forward', 'backward', 'right', 'left')
    motors = ('w', 's', 'd', 'a')
    state = False
    while True:
        code = ''
        keyStack = keyState('WASD')
        if(keyStack):
            motor_on = []
            state = True
            for index, key in enumerate(motors):
                if key in keyStack:
                    code += '1'
                    motor_on.append(names[index])
                else:
                    code += '0'
            sendCode(code)
            print('motors: {} on'.format(motor_on))          
        elif(state):
            sendCode('0000')
            state = False                    
main()
