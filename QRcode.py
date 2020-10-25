import pyqrcode
import png
from pyqrcode import QRCode
QRstring="https://classroom.google.com/h"
url=pyqrcode.create(QRstring)
url.svg("Screenshots\205607.svg",scale=8)
url.png("Screenshots\205607.jpg", scale=6)