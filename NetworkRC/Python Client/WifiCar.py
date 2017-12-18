import requests
import win32api
import time

url = 'http://192.168.8.108/controls'

def keyState(keys):
    stack = []
    for key in keys:
        state = win32api.GetAsyncKeyState(ord(key))
        if(state < 0 or state == 1):
            stack.append(key)
    return stack

def main():
    speed = 0
    direction = 1
    steerAngle = 80
    payload = {}
    payload['aSpeed'] = str(speed)
    payload['aDir'] = str(direction)
    payload['steerAngle'] = str(steerAngle)
    on = False
    while True:
        keysOn = keyState('WASD')
        if(keysOn):
            on = True
            for key in keysOn:
                if(key == 'W'):
                    if speed < 1023:
                        speed += 256
                    if speed > 1023:
                        speed = 1023
                if(key == 'S'):
                    if speed > -1023:
                        speed -= 256
                    if speed < -1023:
                        speed = -1023
                if(key == 'A'):
                    if steerAngle > 60:
                        steerAngle -= 20
                if(key == 'D'):
                    if steerAngle < 100:
                        steerAngle += 20
            if speed > 0:
                direction = 0
            else:
                direction = 1
        else:
            speed = 0
            direction = 1
            steerAngle = 80
        if speed < -1:
            payload['aSpeed'] = str(speed*-1)
        else:
            payload['aSpeed'] = str(speed)
        payload['aDir'] = str(direction)
        payload['steerAngle'] = str(steerAngle)
        if on:
            r = requests.get(url, params=payload)
            print(r.text, '\n')
            if speed == 0 and steerAngle == 80:
                on = False
                
main()
























    
