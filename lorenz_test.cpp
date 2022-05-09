#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>

#include "lorenzstate.H"

int main() {

    // Inital parameters
    double tmax = 35;
    double dt = 0.01;
    double sigma = 10;    
    double beta = 8.0 / 3.0;
    double rho = 28;

    // The test relies on setting (x,y) = (0,0). With z = 10, we can now use the differential equation solution
    double init_x = 0;
    double init_y = 0;
    double init_z = 10;

    auto lorenz_history = integrate_rk2(sigma, beta, rho, tmax, dt, init_x, init_y, init_z);

    // Variables to check size of data and amount of tests passed
    int tests = lorenz_history.size();
    double pass_count = 0;

    // Top of table for pass/fail check
    std::cout << std::setw(12) << "Pass/Fail"
              << std::setw(12) << "Actual"
              << std::setw(12) << "Integrated" << std::endl;
        
    // Purposely placed time delay to show steps better
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    for (auto o : lorenz_history) {
        if( abs(o.z - (init_z * exp(-1 * beta * o.t))) < 0.005 ) {
            std::cout << "Test Passed";
            pass_count += 1;
        }
        else {
            std::cout << "Test Failed";
        }
        std::cout << std::setw(12) << o.z
                  << std::setw(12) << init_z * exp(-1 * beta * o.t) << std::endl;
    }

    // Purposely placed time delay to show steps better
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << std::endl;

    // Check to see if all values fall within a fixed range. If so, all tests have passed
    if (tests == pass_count) {
        std::cout << "All tests have been passed! Values are within a 0.005 range when comparing the integrator method to the solution of the differential equation. " << std::endl;
    }
    else {
        std::cout << "Not all tests have passed. Possible issue may be due to fixed +/- value" << std::endl;
    }
}