#include "PID.h"
#include <iostream>
#include <cmath>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    Kp_ = Kp;
    Ki_ = Ki;
    Kd_ = Kd;
    prev_cte = 0.0;
    total_cte = 0.0;
    num_iterations = 0;
}

void PID::UpdateError(double cte, double speed, double angle) {
    num_iterations += 1;

    // p_error = cte+angle/40;
    p_error = cte;

    d_error = (cte-prev_cte)*speed;
    prev_cte = cte;

    total_cte += cte;
    i_error = total_cte; 
}

double PID::TotalError() {
    return -Kp_*p_error-Kd_*d_error-Ki_*i_error/num_iterations*50;
}

