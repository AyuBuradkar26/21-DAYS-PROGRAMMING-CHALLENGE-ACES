from pygame import mixer
from tkinter import *
from tkinter import ttk

Win=Tk()
Win.geometry("600x300")
Win.title("Music")
Win.configure(background="black")
a=Label(Win,text="Music Player",bg="green",fg="white").grid(row=0,column=1)
b=Label(Win,text="Sathiyaa.mp3",width=15).grid(row=1,column=1)
frame=Frame(Win)

mixer.init()
def Play():
    mixer.music.load("song.mp3")
    mixer.music.play()
def Pause():
    mixer.music.pause()
def Resume():
    mixer.music.unpause()
def Exit():
    mixer.music.stop()
def Time():
    t=mixer.music.get_pos()
    print(t/1000)
def Set():
    st=v.get()
    mixer.music.set_pos(st)
def Vol():
    Vol=vol.get()
    mixer.music.set_volume(Vol)


v=DoubleVar()
scale=Scale(Win, variable=v,from_=1,to=200,orient=HORIZONTAL,bg='grey').grid(row=4,column=1)

vol=Label(Win,text='Volume: ',bg='lightblue',width=15).grid(row=5,column=0)
mixer.music.set_volume(0.5)
def VI():
    V=mixer.music.get_volume()
    if(V<=1):
        V=V+0.1
        mixer.music.set_volume(V)
        print(V)

def VD():
    V=mixer.music.get_volume()
    if(V>=0):
        V=V-0.1
        mixer.music.set_volume(V)
        print(V)


B1 = Button(Win, text='Pause', bg='Lightgreen', width=18, command=Pause).grid(row=2, column=1)
B2 = Button(Win, text='Resume', bg='Lightgreen', width=18, command=Resume).grid(row=2, column=2)
B3 = Button(Win, text='Stop', bg='Lightgreen', width=18, command=Exit).grid(row=2, column=3)
B4 = Button(Win, text='Play', bg='Lightgreen', width=18, command=Play).grid(row=2, column=0)
B5 = Button(Win, text='submit', width=18, command=Time).grid(row=3, column=1)
B6 = Button(Win, text='Set time', command=Set,width=15).grid(row=4, column=2)
B7 = Button(Win, text='Vol+', command=VI, bg='lightblue',width=10).grid(row=5, column=1)
B8 = Button(Win, text='Vol-', command=VD, bg='lightblue',width=10).grid(row=5, column=2)



Win.mainloop()   





