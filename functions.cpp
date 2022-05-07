#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

#include "lorenzstate.H"

/*
This file containes the following functions:

integrate_rk2(const double sigma, const double beta, const double rho, const double tmax, const double dt)
rhs(const LorenzState& state, const double sigma, const double beta, const double rho)
write_history(const std::vector<LorenzState>& history)



*/

// Added these as an extra precaution
//LorenzState rhs(const LorenzState& state, const double sigma, const double beta, const double rho);
//void write_history(const std::vector<LorenzState>& history);
//std::vector<LorenzState> integrate_rk2(const double sigma, const double beta, const double rho, const double tmax, const double dt);


// Function used to integrate through the Runge-Kutta method
std::vector<LorenzState> integrate_rk2(const double sigma, const double beta, const double rho, const double tmax, const double dt) {

    // how the history of the orbit
    std::vector<LorenzState> lorenz_history_rk2{};

    // Set initial conditions
    LorenzState state{};
    LorenzState state_mid{};

    // Assuming inital coordinates (x,y,z) = (10,10,10) at t = 0 
    state.t = 0.0;
    state.x = 10;
    state.y = 10;
    state.z = 10;

    // Push inital conditions
    lorenz_history_rk2.push_back(state);

    // integration loop
    while (state.t < tmax) {

        // Get the derivatives
        auto d1 = rhs(state, sigma, beta, rho);

        // Calculation at midpoint state
        state_mid.t = state.t + 0.5 * dt;
        state_mid.x = state.x + 0.5 * dt * d1.x;
        state_mid.y = state.y + 0.5 * dt * d1.y;
        state_mid.z = state.z + 0.5 * dt * d1.z;

        // Get the derivatives of midpoint state
        auto d2 = rhs(state_mid, sigma, beta, rho);
        
        // Update state with midpoint state
        state.t += dt;
        state.x += d2.x * dt;
        state.y += d2.y * dt;
        state.z += d2.z * dt;

        // Push new calculated state
        lorenz_history_rk2.push_back(state);
    }

    return lorenz_history_rk2;

}


// Function for finding the deriviatives
LorenzState rhs(const LorenzState& state, const double sigma, const double beta, const double rho) {

    LorenzState dodt{};

    // dx/dt = vx; dy/dt = vy
    dodt.x = sigma * (state.y - state.x); //state.vx;
    dodt.y = (state.x * (rho - state.z) - state.y); //state.vy;
    dodt.z = state.x * state.y - beta * state.z; //state.vz;

    return dodt;

}

void write_history(const std::vector<LorenzState>& history) {

    for (auto o : history) {
        std::cout << std::setw(12) << o.t
                  << std::setw(12) << o.x
                  << std::setw(12) << o.y
                  << std::setw(12) << o.z << std::endl;

    }

}