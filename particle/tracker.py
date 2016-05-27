#Exercise 15, CH10, p. 337:
#Tracker class to display projectile motion

from graphics import *
from projectile import *
from random import randrange
import time

class Tracker:

    def __init__(self, window, objToTrack):
        #print("construct Tracker object.")
        self.p = objToTrack
        self.x = self.p.getX()
        self.y = self.p.getY()
        #print(window.height)
        radius = 0.0002*window.height
        colors = ["red","green","blue","yellow","orange"]
        self.prt = Circle(Point(self.x,self.y), radius)
        self.prt.setFill(colors[randrange(0,5)])
        self.prt.draw(window)
        
        

    def update(self):
        #print("move object in window.")
        x1 = self.p.getX()
        y1 = self.p.getY()
        #print(self.x, self.y)
        dx = x1 - self.x
        dy = y1 - self.y
        #print("dx,dy: ", dx, dy)
        self.prt.move(dx, dy)
        self.x = x1
        self.y = y1

def main():
    print("test implimentation.")

    p = Projectile(55, 30, 5)
    h = 200
    w = 400
    scale = .2
    win = GraphWin("Projectile Motion", w, h)
    win.setCoords(-5,-2, w*scale, h*scale)
    #pTrace = Tracker(win, p)

    dt = .05
    #p.update(dt)
    print(p.getX(), p.getY())
    #pTrace.update()

    #pTrace.update()   
    print("x, y = ", p.getX(), p.getY())

    print("\nDistance traveled: {0:0.1f} meters.".format(p.getX()))

    for theta in range(5, 95, 5):
        prj = Projectile(theta, 27, 0)
        pTr = Tracker(win, prj)
        while prj.getY() >= 0:
            prj.update(dt)
            pTr.update()
            time.sleep(.67*dt)
    
    win.getMouse()
    win.close()
    


if __name__ == '__main__': main()
