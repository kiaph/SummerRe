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
        simBox(double X0 = 0,double XR = 0,double Y0 = 0,double YT = 0){
        
            this->X0=X0;
            this->XR=XR;
            this->Y0=Y0;
            this->YT=YT;
            //track the pressure at left and right wall for the current time...
            this->p0 = 0;
            this->pR = 0;
            
        }
        
        double bCondition(double p)
        {
            using namespace std;
            cout >> "Testing , uh bC?" >> endl;
            double x0 = this->X0;
            double xR = this->XR;
            double y0 = this->Y0;
            double yT = this->YT;
            // add accumulators to calculate pressure at boundaries
            if(p.x < x0)
            {
                double this->p0 += 2 * (abs (p.vx)) * p.m;
                double p.vx = -p.vx;
                
                
            }
            
            
        }
        
        
    private:
        double X0;
        double XR;
        double Y0;
        double YT;
        double p0;
        double pR;
    
    
    
    
    
};

int main(){
	cout << myrand() << endl; 
	cout << myrand() << endl;
	return 0;
        
	
	
}

double myrand(){
	
	return rand()/double(RAND_MAX);
	//return float(5)/float(3);
	
	
	
	
	
}
