#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Planet {
    public:

    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
    const double G = 0.000000000006674;
    const double dt = 0.001;
    double m;

    Planet(double x, double y, double z, double mass) : x(x), y(y), z(z), m(m) {}

    void update(int index, vector<vector<double>> stateMatrix) {
        
        //Resetting acceleration state
        this->ax = 0;
        this->ay = 0;
        this->az = 0;

        for (int i = 0; i < stateMatrix.size(); i++) {

            if (i == index) {
                continue;
            }
            
            //Extracting values
            double x2 = stateMatrix[i][0];
            double y2 = stateMatrix[i][1];
            double z2 = stateMatrix[i][2];
            double m2 = stateMatrix[i][3];
            
            //Incrementing Accelerations
            this->ax += this->G*m2/abs(this->x - x2);
            this->ay += this->G*m2/abs(this->y - y2);
            this->az += this->G*m2/abs(this->z - z2);

        }
        
        //Updating velocities
        this->vx += this->ax*this->dt;
        this->vy += this->ay*this->dt;
        this->vz += this->az*this->dt;
        
        //Updating coordinates
        this->x += this->vx*this-<dt;
        this->y += this->vy*this-<dt;
        this->z += this->vz*this-<dt;
    }

};

class Space {
    public:

    vector<Planet> Planets;
    vector<vector<double>> stateMatrix;

    Space(const vector<Planet>& Planets) : Planets(Planets) {
        updateStateMatrix();
    }

    void updateState(){
        for (Planet& planet : this->Planets){
            planet.update(this->stateMatrix);
        }
        updateStateMatrix();
    }

    void updateStateMatrix(){
        for (int i = 0; i < this->Planets.size(); i++){
            this->stateMatrix[i][0] = Planets[i].x;
            this->stateMatrix[i][1] = Planets[i].y;
            this->stateMatrix[i][2] = Planets[i].z;
            this->stateMatrix[i][3] = Planets[i].m;
        }
    }

};

