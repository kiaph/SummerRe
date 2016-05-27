# Ideal gas particles in a box code.
# Reflecting boundaries (left and right) x-direction.
# Periodic (aka cyclic) boundaries (top and bottom) y-direction.
from random import random

class Particle:
    def __init__(self, x, y, vx, vy): #particle object constructor
        self.m = 1 #particle mass
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy


class simBox:
    def __init__(self, X0, XR, Y0, YT): #simulation box constructor
        self.X0=X0
        self.XR=XR
        self.Y0=Y0
        self.YT=YT
        #track the pressure at left and right wall for the current time step
        self.p0 = 0
        self.pR = 0

    def bCondition(self, p):
        #print("bC")
        x0 = self.X0
        xR = self.XR
        y0 = self.Y0
        yT = self.YT
        #if p.x < x0 or p.x > xR:
        #    p.vx = -p.vx
        #add accumulators to calculate pressure at boundaries
        if p.x < x0:
            self.p0 = self.p0 + 2*abs(p.vx)*p.m
            p.vx = -p.vx
        elif p.x > xR:
            self.pR = self.pR + 2*abs(p.vx)*p.m
            p.vx = -p.vx           
        if p.y > yT:
            p.y = p.y - yT
        elif p.y < y0:
            p.y = p.y + yT

        return p
        

    def make_particle(self):
        #print("make p")
        x = self.X0 + (self.XR-self.X0)*random()
        y = self.Y0 + (self.YT-self.Y0)*random()
        vx = 2*( 0.5 - random() )
        vy = 2*( 0.5 - random() )
        return Particle(x,y,vx,vy)

    def move_particle(self, p, dt):      
        p.x = p.x + p.vx*dt
        p.y = p.y + p.vy*dt
        p = self.bCondition(p)
        return p

    def wall_pressure(self, dt):
        #print("wall pressure")
        L = self.XR - self.X0
        p0 = self.p0/(dt*L*L)
        pR = self.pR/(dt*L*L)
        self.p0 = 0
        self.pR = 0
        return p0, pR

    def kinetic_pressure(self, pList):
        #print('get kinetic pressure')
        sqrsum = 0
        for p in pList:
            sqrsum = sqrsum + p.m*p.vx**2
        L = self.XR - self.X0
        kp = sqrsum/L**3
        return kp



def main():
    print("1.5D Ideal Gas in a Box Simmulation...")

    box = simBox(0,10,0,10)
    #p1 = box.make_particle()
    #print(p1.x)
    N = 100000 #number of particles.
    pList = [] #particles in box.
    for i in range(N):
        pList.append(box.make_particle())
        #print(pList[i].vx)

    #print(pList[0].x)
    #box.move_particle(pList[0], 0.5)
    #print(pList[0].x)

    dt = 0.1 
    timeSteps = 1000
    p0Rlist = []
    for n in range(timeSteps):
        for i in range(N):
            #print(pList[i].x)
            box.move_particle(pList[i], dt)
            #print(round(pList[i].x, 2), round(pList[i].y, 2))
        p0, pR = box.wall_pressure(dt)        
        kp = box.kinetic_pressure(pList)
        #print(round(p0,2), round(pR,2), round(kp,2))
        p0Rlist.append(p0)
        p0Rlist.append(pR)
    pAve = round(sum(p0Rlist)/len(p0Rlist),2)
    print('pAve = ', pAve)
    kp = round(kp,2)
    print('kp =', kp)
    print("Discrepency: (kp - pAve)*100/kp = ", round((kp - pAve)*100/kp, 2), "%")
        
    
main()
