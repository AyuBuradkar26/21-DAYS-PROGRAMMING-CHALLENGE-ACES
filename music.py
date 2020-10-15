from pygame import mixer
from tkinter import *
from tkinter import ttk

mixer.init()
mixer.music.load("song.mp3")
mixer.music.play()

Win=Tk()
Win.geometry("600x600")
Win.title("Music")
Win.configure(background="pink")
a=Label(Win,text="Music Player",bg="violet").grid(row=1,column=1)
frame=Frame(Win)

def Query():
    while(True):
        query=var.get()
        if query=="P":
            mixer.music.pause()
        elif query=="R":
            mixer.music.unpause()
        elif query=="E":
            mixer.music.stop()
        break

var=StringVar()
R1=Radiobutton(Win,text="Pause", value='P',variable=var).grid(row=2,column=0)
R2=Radiobutton(Win,text="Resume", value='R',variable=var).grid(row=2,column=1)
R3=Radiobutton(Win,text="Exit", value='E',variable=var).grid(row=2,column=3)

T = Button(Win, text='submit', bg='Purple', width=20, command=Query, fg='white').grid(row=3, column=1)
Win.mainloop()   





