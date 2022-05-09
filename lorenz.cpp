#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

#include "lorenzstate.H"

int main() {

    double tmax = 40;
    double dt = 0.01;
    double sigma = 10;    
    double beta = 8.0 / 3.0;
    double rho = 28;

    double init_x = 10;
    double init_y = 10;
    double init_z = 10;

    auto lorenz_history = integrate_rk2(sigma, beta, rho, tmax, dt, init_x, init_y, init_z);
    write_history(lorenz_history);

}