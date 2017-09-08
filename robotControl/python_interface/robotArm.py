import serial, time
from random import randint

try:
    ser = serial.Serial('COM3', 9600, timeout=1)
except Exception as e:
    print(e)
    
time.sleep(2)

while True:
    inputs = (input('Enter servo: '), input('Enter angle: '))
    for item in inputs:
        item += '\r\n'
        ser.write(item.encode())
        time.sleep(0)
        print('Ardunio output: ', ser.readline().decode())
        time.sleep(0)

