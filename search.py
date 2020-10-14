from tkinter import *
from tkinter import ttk
import webbrowser
Pwindow=Tk()
Pwindow.geometry("500x400")
Pwindow.title("browser")
Pwindow.configure(background="skyblue");
a=Label(Pwindow,text="WELCOME GOOGLE").grid(row=1,column=3)


url='https://www.youtube.com/'

url1='https://mail.google.com/mail/u/0/#inbox'

url2='https://translate.google.com/'

url3='https://classroom.google.com/h'

url4='https://www.google.com/maps'

url5='https://drive.google.com/drive/my-drive'

chrome_path='C:\Program Files (x86)\Google\Chrome\Application'
def open(): 
    webbrowser.open(url)
def open1():
    webbrowser.open(url1)   
def open2():
    webbrowser.open(url2)    
def open3():
    webbrowser.open(url3)
def open4():
    webbrowser.open(url4) 
def open5():
    webbrowser.open(url5)                

btn=ttk.Button(Pwindow,text="youtube",command=open).grid(row=3,column=1)
btn=ttk.Button(Pwindow,text="gmail",command=open1).grid(row=3,column=2)
btn=ttk.Button(Pwindow,text="translation",command=open2).grid(row=3,column=3)
btn=ttk.Button(Pwindow,text="G.classroom",command=open3).grid(row=3,column=4)
btn=ttk.Button(Pwindow,text="G.Maps",command=open4).grid(row=3,column=5)
btn=ttk.Button(Pwindow,text="G.Drive",command=open5).grid(row=3,column=6)
Pwindow.mainloop()
