# Hey Guys, I'm Ratnesh 
# This code will help you to generate qr code using python

import pyqrcode # Install pyqrcode by using "pip install pyqrcode command"
import png # Use command pip install pyqrcode
from pyqrcode import QRCode

s=str(input("Enter url here: "))
url=pyqrcode.create(s)
url.svg("myqrcode.svg",scale=8)
url.png("myqrcode.png",scale=6)