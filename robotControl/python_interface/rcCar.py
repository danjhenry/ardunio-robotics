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
    return conn.readline().decode()

def keyState(keys):
    stack = []
    for key in keys:
        state = win32api.GetAsyncKeyState(ord(key))
        if(state < 0 or state == 1):
            stack.append(key.lower())
    return stack

def main():
    motorCode = {'w': '000', 'a': '110', 's': '100', 'd': '111'} 
    motors = {'w': False, 'a': False, 's': False, 'd': False}
    while True:
        keyStack = keyState('WASD')
        if(keyStack):
            for key, value in motors.items():
                if(value):
                    if key not in keyStack:
                        motors[key] = False
                        print('off: ', sendCode('0' + motorCode[key]))
                else:
                    if key in keyStack:
                        motors[key] = True
                        print('on: ', sendCode('1' + motorCode[key]))
        else:
            for key, value in motors.items():
                if(value):
                    motors[key] = False
                    print('off: ', sendCode('0' + motorCode[key]))
                                 
main()
