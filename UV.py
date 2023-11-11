#pip install schedule
#pip install pyserial

import serial
import time
import schedule

def pull():
    esp = serial.Serial('com7', 115200, timeout=3) #set comx according to the port of your ESP32
    print('Established serial connection to ESP32')
    esp_data = esp.readlines()

    decoded_values = str(esp_data[0:len(esp_data)])
    print(f'Collected readings from ESP: {decoded_values}')
    
    uv_value = int(decoded_values[-7])
    
    if uv_value in [1, 2]:
        f = open('UVread.txt', 'a+')
        f.write(decoded_values + '\n')
        f.write("Generously apply broad spectrum SPF 15+ sunscreen every 2 hours" + '\n\n')
        f.close()
        print("Safe")
    elif uv_value in [3, 4]:
        f = open('UVread.txt', 'a+')
        f.write(decoded_values + '\n')
        f.write("Generously apply broad spectrum SPF 30+ sunscreen every 2 hours" + '\n\n')
        f.close()
        print("Safe")
    elif uv_value in [5, 6]:
        f = open('UVread.txt', 'a+')
        f.write(decoded_values + '\n')
        f.write("Generously apply broad spectrum SPF 40+ sunscreen every 2 hours" + '\n\n')
        f.close()
        print("Unsafe")
    elif uv_value in [7, 8]:
        f = open('UVread.txt', 'a+')
        f.write(decoded_values + '\n')
        f.write("Generously apply broad spectrum SPF 50+ sunscreen every 2 hours" + '\n\n')
        f.close()
        print("Unsafe")
    else:
        f = open('UVread.txt', 'a+')
        f.write(decoded_values + '\n')
        f.write("Generously apply broad spectrum SPF 60+ sunscreen every 2 hours" + '\n\n')
        f.close()
        print("Unsafe")

    esp_data = 0
    esp.close()
    print('Connection closed')
    print('<----------------------------->')

print('Program started')

# Setting up the ESP
schedule.every(10).seconds.do(pull)

while True:
    schedule.run_pending()
    time.sleep(1)
