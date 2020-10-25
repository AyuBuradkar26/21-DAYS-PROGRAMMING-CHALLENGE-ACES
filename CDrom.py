import pygame.cdrom as cdrom
cdrom.init()
cd=cdrom.CD(0)
cd.init()
while True:
    cd.eject()