import serial, time
from random import randint
import win32api
import win32con

try:
    conn = serial.Serial('COM3', 9600, timeout=.1)
    time.sleep(2)
except Exception as e:
    print(e)
    
def sendCode(code, delay=0):
    byteChr = chr(int(code, 2))
    conn.write(byteChr.encode())
    time.sleep(delay)

def keyState(keys):
    stack = []
    for key in keys:
        state = win32api.GetAsyncKeyState(ord(key))
        if(state < 0 or state == 1):
            stack.append(key.lower())
    return stack

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
