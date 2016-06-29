#include <iostream>
#include <stdlib.h>
#include <cmath>
double myrand();
using namespace std;



class Particle{

    public:

        //constructor definition
        Particle(double x = 0,double y = 0,double vx = 0,double vy = 0)
        {
            cout << "constructor called" << endl;
            //this->m = 1.0;
            this->x = x;
            this->y = y;
            this->vx = vx;
            this->vy = vy;    
            double particleX(double);
            double particleVX(double);
            
        }
        
            double particleX(double x = 0)
            {
            //this->x = x;
            x = this->x;
            return x;
            }
            double particleVX(double vx = 0)
            {
            //this->vx = vx;
            vx = this->vx;
            return vx;
            }
    private:
        
        double x;
        double y;
        double vx;
        double vy;
        double m;
        
    
};




class simBox{
    
    public:
        
        //setting up constructor 
        simBox(double X0 = 0,double XR = 0,double Y0 = 0,double YT = 0)
        {
        
            this->X0=X0;
            this->XR=XR;
            this->Y0=Y0;
            this->YT=YT;
            //track the pressure at left and right wall for the current time...
            this->p0 = 0;
            this->pR = 0;
            
        }
        
        /*double bCondition(double p)
        {
            
            //cout >> "Testing , uh bC?" >> endl;
            double Particle::particleX();
            double Particle::particleVX();
            double x0 = this->X0;
            double xR = this->XR;
            double y0 = this->Y0;
            double yT = this->YT;
            double x = Particle::particleX();
            double vx = Particle::particleVX();
            
            // add accumulators to calculate pressure at boundaries
            if(p.x < x0)
            {
                double this->p0 += 2 * (abs (p.vx)) * p.m;
                double p.vx = -p.vx;
                
                
            }*/
            
            
        /*def make_particle(self):
        #print("make p")
        x = self.X0 + (self.XR-self.X0)*random()
        y = self.Y0 + (self.YT-self.Y0)*random()
        vx = 2*( 0.5 - random() )
        vy = 2*( 0.5 - random() )
        return Particle(x,y,vx,vy)*/
        
            Particle make_particle()
            {
                double x = this->X0 + (this->XR - this->X0)*myrand();
                double y = this->Y0 + (this->YT - this->Y0)*myrand();
                double vx = 2*(0.5 - myrand() );
                double vy = 2*(0.5 - myrand() );
                Particle(x,y,vx,vy);
                //#include <iostream>
                //#include <stdlib.h>article ;simBox::make_particle;
                

                char printthis();
                printthis();
                //cout >> "testing" ;
                return Particle(x,y,vx,vy);
                
                //return x,y,vx,vy;
            }
        
            void printthis()
            {
                //char a = "printthis" ;
            
                cout << "a" << endl;
            }
            
            
        
        
    private:
        double X0;
        double XR;
        double Y0;
        double YT;
        double p0;
        double pR;
    
    
    
    
    
};
//static simBox(0,0,0,0);
//Particle simBox::make_particle(0,0,0,0);
simBox simBox();


int main(){
	cout << myrand() << endl; 
	cout << myrand() << endl;
        Particle Particle();
        void printthis();
        Particle; simBox; 
        
        
	return 0;
        
	
	
}

double myrand(){
	
	return rand()/double(RAND_MAX);
	//return float(5)/float(3);
	
	
	
	
	
}
