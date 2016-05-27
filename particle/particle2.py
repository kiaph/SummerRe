# Ideal gas particles in a box code.
# Reflecting boundaries (left and right) x-direction.
# Periodic (aka cyclic) boundaries (top and bottom) y-direction.
from random import random
from math import sqrt
from tracker import Tracker
from graphics import *
import time

class Particle:
    
    def __init__(self, x, y, vx, vy): #particle object constructor
        self.m = 1 #particle mass
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy

    def getX(self):
        return self.x
    def getY(self):
        return self.y


class Boundary:
    
    def __init__(self, AxisCut, NormalVector):
        self.intercept = AxisCut #where the boundary plane cuts a cartesian axis
        self.Nhat = NormalVector #outward normal to the boundary plane
        self.bnd = (self.intercept, (self.Nhat[0], self.Nhat[1]))


class Wall(Boundary):
    boundaryType = 'reflecting'

    def set_momentum(self, mnt):
        self.momentum = mnt #accumulate momentum on wall due to reflections
    
    
    def reflection(self, particle):
        vx0 = particle.vx
        vy0 = particle.vy
        m = particle.m
        nx = self.bnd[1][0]
        ny = self.bnd[1][1]
        vx1 = -nx*abs(vx0)
        vy1 = -ny*abs(vy0)
        if ny == 0:
            dvx = vx1 - vx0
            dvy = 0
            particle.vx = vx1
        elif nx == 0:
            dvy = vy1 - vy0
            dvx = 0
            particle.vy = vy1
        else:
            print('bad n assignment in Wall.reflection')            
        self.momentum = self.momentum + m*sqrt(dvx**2 + dvy**2)
        #print("mom = ", self.momentum)
        
class Periodic(Boundary):

    boundaryType = 'cyclic'

    def set_wavelength(self, L):
        self.wavelength = L

    def cycle(self, particle):
        L = self.wavelength
        nx = self.bnd[1][0]
        ny = self.bnd[1][1]
        if nx != 0:
            particle.x = particle.x - nx*L
        elif ny != 0:
            particle.y = particle.y - ny*L
        else:
            print('bad n vect in Periodic.cycle')

class simBox:   
    def __init__(self, X0, XR, Y0, YT, timeStep): #simulation box constructor
        self.X0=X0
        self.XR=XR
        self.Y0=Y0
        self.YT=YT
        self.timeStep = timeStep
        self.leftWall = Wall(X0, (-1, 0))
        self.rightWall = Wall(XR, (1, 0))
        L = YT-Y0
        self.top = Periodic(YT, (0, 1))
        self.top.set_wavelength(L)
        self.bottom = Periodic(Y0, (0, -1))
        self.bottom.set_wavelength(L)
        self.pList = [] #list of particles
        self.pLave = 0#running average of leftWall pressure
        self.pRave = 0
        self.timeStepCounter = 0

    def make_N_particles(self, N):
        for i in range(N):
            x = self.X0 + (self.XR-self.X0)*random()
            y = self.Y0 + (self.YT-self.Y0)*random()
            vx = 2*( 0.5 - random() )
            vy = 2*( 0.5 - random() )
            p = Particle(x,y,vx,vy)
            self.pList.append( p )
            

    def move_particles(self):
        x0 = self.X0
        xR = self.XR
        y0 = self.Y0
        yT = self.YT
        dt = self.timeStep
        self.leftWall.set_momentum(0)
        self.rightWall.set_momentum(0)
        for p in self.pList:
            p.x = p.x + p.vx*dt
            p.y = p.y + p.vy*dt
            if p.x < x0:
                #print("lw")
                self.leftWall.reflection(p)
            elif p.x > xR:
                #print("rw")
                self.rightWall.reflection(p)       
            if p.y > yT:
                #print("top")
                self.top.cycle(p)
            elif p.y < y0:
                #print("bot")
                self.bottom.cycle(p)
        i = self.timeStepCounter
        A = (yT-y0)**2
        pLave = self.pLave
        pRave = self.pRave
        mL = self.leftWall.momentum
        mR = self.rightWall.momentum
        pL = mL/(A*dt)
        pR = mR/(A*dt)
        pLave = (i*pLave + pL)/(i+1)
        pRave = (i*pRave + pR)/(i+1)
        i = i + 1
        self.timeStepCounter = i
        self.pLave = pLave
        self.pRave = pRave
        #print(pLave, pRave)

    def kinetic_pressure(self):
        #print('get kinetic pressure')
        sqrsum = 0
        for p in self.pList:
            sqrsum = sqrsum + p.m*p.vx**2
        L = self.YT - self.Y0
        kp = sqrsum/L**3
        return kp

        
def main():
    print("1.5D Ideal Gas in a Box Simmulation...")
    dt = 0.1  
    box = simBox(0,10,0,10,dt)
    N = 200
    box.make_N_particles(N)
    print("kp: ", round( box.kinetic_pressure(), 2) )

    h = 400
    w = 400
    win = GraphWin("1.5D Box of Gas Sim.", w, h)
    win.setCoords(-0.1,-0.1,10.1,10.1)
    pTrList = []
    for p in box.pList:
        tp = Tracker(win, p)
        pTrList.append(tp)
    
    timeSteps = 10000    
    for n in range(timeSteps):
        box.move_particles()
        for p in pTrList:
            p.update()
            #time.sleep(.0001*dt)
        
    print("pave: ", round((box.pLave + box.pRave)/2, 2) )
    print("kp: ", round( box.kinetic_pressure(), 2) )
    
main()
