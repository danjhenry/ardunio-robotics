import serial, time
from random import randint
import win32api
import win32con

try:
    conn = serial.Serial('COM3', 9600, timeout=1.2)
    time.sleep(2)
except Exception as e:
    print(e)
    
def sendCode(code, delay=0):
    code += '\r\n'
    conn.write(code.encode())
    time.sleep(delay)
    return conn.readline().decode()

def keyState(keys):
    stack = []
    for key in keys:
        stack.append([win32api.GetAsyncKeyState(ord(key)), key])
    return stack

def keepConnAlive(code='noInput'):
    code += '\r\n'
    conn.write(code.encode())
    return conn.readline().decode()
    
def main():
    inputs = {'W':'fwrd', 'S':'back', 'A':'left', 'D':'right'}
    while True:
        for state, key in keyState('WASD'): 
            if(state < 0 or state == 1):
                keepConnAlive('input')
                sendCode(inputs[key])
                print('key: {}, value: {}'.format(key, state))
                break
        else:
            keepConnAlive()       
main()
    
