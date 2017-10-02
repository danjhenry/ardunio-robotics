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
    conn.write(code.encode())
    time.sleep(delay)
    return conn.readline().decode()

def keyState(keys):
    stack = []
    for key in keys:
        stack.append([win32api.GetAsyncKeyState(ord(key)), key])
    return stack
    
def main():
    motors_on = False
    while True:
        for state, key in keyState('WASD'): 
            if(state < 0 or state == 1):
                result = sendCode(key.lower())
                motors_on = True
                print('key: {}, value: {}, Pin: {}'.format(key, state, result))
                break
        else:
            if(motors_on):
                results = sendCode('q')
                motors_on = False
                print(results)      
main()
