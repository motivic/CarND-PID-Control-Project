#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp_;
  double Ki_;
  double Kd_;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte, double speed, double angle);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

private:
  double prev_cte;  // Previous cross track error
  double total_cte; // Total cross track error
  int num_iterations; // Total number of iterations
};

#endif /* PID_H */
