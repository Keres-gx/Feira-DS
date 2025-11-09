import serial
import keyboard
import time

arduino = serial.Serial('COM4', 9600)
time.sleep(2)
print("Conectado ao Arduino! Use as teclas para mover o braço:")

try:
    while True:
        if keyboard.is_pressed('up'):
            arduino.write(b'U')
            time.sleep(0.1)
        elif keyboard.is_pressed('down'):
            arduino.write(b'D')
            time.sleep(0.1)
        elif keyboard.is_pressed('left'):
            arduino.write(b'L')
            time.sleep(0.1)
        elif keyboard.is_pressed('right'):
            arduino.write(b'R')
            time.sleep(0.1)
        elif keyboard.is_pressed('q'):
            arduino.write(b'Q')
            time.sleep(0.1)
        elif keyboard.is_pressed('e'):
            arduino.write(b'E')
            time.sleep(0.1)
        elif keyboard.is_pressed('z'):
            arduino.write(b'Z')
            time.sleep(0.1)
        elif keyboard.is_pressed('x'):
            arduino.write(b'X')
            time.sleep(0.1)
except KeyboardInterrupt:
    print("Encerrando controle...")
    arduino.close()
