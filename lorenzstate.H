#ifndef LORENZSTATE_H
#define LORENZSTATE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

struct LorenzState {
    double t;
    double x;
    double y;
    double z;
};

LorenzState rhs(const LorenzState& state, const double sigma, const double beta, const double rho);
void write_history(const std::vector<LorenzState>& history);
std::vector<LorenzState> integrate_rk2(const double sigma, const double beta, const double rho, const double tmax, const double dt);


std::ostream& operator<< (std::ostream& os, LorenzState& LorenzState);

#endif