#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

#include "lorenzstate.H"

int main() {

    double tmax = 35;
    double dt = 0.01;
    double sigma = 10;    
    double beta = 8.0 / 3.0;
    double rho = 28;

    auto lorenz_history = integrate_rk2(sigma, beta, rho, tmax, dt);
    write_history(lorenz_history);

}