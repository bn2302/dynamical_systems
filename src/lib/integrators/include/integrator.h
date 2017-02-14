#ifndef LIB_INTEGRATOR_H_
#define LIB_INTEGRATOR_H_


#include <vector>
#include "dynamical_system.h"


class IntegrationData
{

  public:

    IntegrationData();

    void push_back(double time_point, const std::vector<double>& state);

    void writeData();


  private:

    std::vector<double> timepoints;

    std::vector<std::vector<double>> states_over_time;

};



class Integrator
{

  public:

    Integrator(DynamicalSystem& dynamical_system);

    virtual ~Integrator() = 0;

    IntegrationData integrateNSteps(int n);

    void setDynamicalSystem(DynamicalSystem& dynamical_system);


  protected:

    DynamicalSystem& dynamical_system;

    virtual void integrateStep() = 0;

    static std::vector<double> multiply_by_scalar(
        const std::vector<double>& vec, double scalar);

    static std::vector<double> add_vectors(const std::vector<double>& vec1,
        const std::vector<double>& vec2);

};


#endif /* ifndef LIB_INTEGRATOR_H_ */
