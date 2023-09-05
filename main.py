# import pywhatkit as kit
# import pyautogui as pg

# kit.sendwhatmsg('+91 99989 28777','Systummm'*2000,16,27,15)

import pywhatkit as kit
import datetime
import pyautogui as pg
import time
number = '+91 90810 75280'
msg = 'hello'
hour = 9
min = 29
kit.sendwhatmsg(number, msg, hour, min, 15)
# time.sleep(2)
message = "Systummm"
for i in range(1000):
    pg.typewrite(message)
    time.sleep(0.0000001)
    pg.press('enter')
    