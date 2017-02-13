#ifndef LIB_RUNGEKUTTA4_H_
#define LIB_RUNGEKUTTA4_H_
#include <vector>
#include "integrator.h"
class RungeKutta4 : public Integrator
{
  public:
    RungeKutta4(DynamicalSystem& dynamical_system,double h);
    ~RungeKutta4();

  protected:
    void integrateStep();

  private:

    double h;

    std::vector<double> multiply_by_scalar(
        const std::vector<double>& vec, double scalar);

    std::vector<double> add_vectors(const std::vector<double>& vec1,
        const std::vector<double>& vec2);


};
#endif /* ifndef LIB_ODE45_H_ */
