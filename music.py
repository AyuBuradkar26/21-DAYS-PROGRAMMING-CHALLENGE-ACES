from pygame import mixer
from tkinter import *
from tkinter import ttk
import tkinter.font as F

Win=Tk()
Win.geometry("600x300")
Win.title("Music")
Win.configure(background="black")

frame=Frame(Win)

mixer.init()
def Select():
    mixer.music.load(S.get())
def Play():
    mixer.music.play()
def Pause():
    mixer.music.pause()
def Resume():
    mixer.music.unpause()
def Exit():
    mixer.music.stop()
'''def Time():
    t=mixer.music.get_pos()
    print(t/1000)'''
def Set():
    st=v.get()
    mixer.music.set_pos(st)
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

Mfont=F.Font(weight="bold",size=10)
Mfont1=F.Font(weight="bold")

a=Label(Win,text="Music Player",bg="green",fg="yellow",font=Mfont1).grid(row=0,column=1)
b=Label(Win,text="Select song :",width=15,font=Mfont).grid(row=1,column=0)
v=DoubleVar()
scale=Scale(Win, variable=v,from_=1,to=200,orient=HORIZONTAL,bg='grey',width=18,font=Mfont).grid(row=4,column=0,padx=4,pady=5)

vol=Label(Win,text='Volume: ',bg='lightblue',width=15,font=Mfont).grid(row=5,column=0)

S=StringVar()
R1=Radiobutton(Win,text="Sathiyaa",variable=S,value="song.mp3",command=Select,selectcolor='yellow',cursor='hand2',font=Mfont).grid(row=1,column=1,padx=4,pady=5)
R2=Radiobutton(Win,text="Bhijuna gela vara",variable=S,value="song1.mp3",command=Select,selectcolor='yellow',cursor='hand2',font=Mfont).grid(row=1,column=2,padx=4,pady=5)


B1 = Button(Win, text='Pause ||', bg='Lightgreen', width=16, command=Pause,font=Mfont).grid(row=2, column=1,padx=4,pady=5)
B2 = Button(Win, text='Resume', bg='Lightgreen', width=16, command=Resume,font=Mfont).grid(row=2, column=2,padx=4,pady=5)
B3 = Button(Win, text='Stop []', bg='Lightgreen', width=16, command=Exit,font=Mfont).grid(row=2, column=3,padx=4,pady=5)
B4 = Button(Win, text='Play |>', bg='Lightgreen', width=16, command=Play,font=Mfont).grid(row=2, column=0,padx=4,pady=5)
#B5 = Button(Win, text='submit', width=18, command=Time).grid(row=3, column=1,padx=4,pady=5)
B6 = Button(Win, text='Set time', command=Set,font=Mfont).grid(row=4, column=1,padx=4,pady=5)
B7 = Button(Win, text='Vol+', command=VI, bg='lightblue',width=10,cursor='sb_up_arrow',font=Mfont).grid(row=5, column=1,padx=4,pady=5)
B8 = Button(Win, text='Vol-', command=VD, bg='lightblue',width=10,cursor='sb_down_arrow',font=Mfont).grid(row=5, column=2,padx=4,pady=5)

Win.mainloop()   





