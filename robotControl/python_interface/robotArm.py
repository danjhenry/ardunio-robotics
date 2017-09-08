import serial, time
from random import randint

try:
    ser = serial.Serial('COM3', 9600, timeout=.8)
except Exception as e:
    print(e)
    
time.sleep(2)
##while True:
##    movements = {'fwrd' : str(randint(65, 180)), 'base' : str(randint(0, 180)), 'claw' : str(randint(135, 180))}
##    for key, value in movements.items():
##        if key == 'base':
##            if(int(movements['fwrd']) > 130):
##                break
##        key += '\r\n'
##        value += '\r\n'
##        ser.write(key.encode())
##        print('Ardunio output: ', ser.readline().decode())
##        time.sleep(.5)
##        ser.write(value.encode())
##        print('Ardunio output: ', ser.readline().decode())
##        time.sleep(.5)

while True:
    inputs = (input('Enter servo: '), input('Enter angle: '))
    for item in inputs:
        item += '\r\n'
        ser.write(item.encode())
        time.sleep(0)
        print('Ardunio output: ', ser.readline().decode())
        time.sleep(0)

