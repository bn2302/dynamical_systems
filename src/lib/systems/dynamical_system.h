#ifndef LIB_DYNAMICAL_SYSTEM_H_
#define LIB_DYNAMICAL_SYSTEM_H_
#include <vector>

//
// © Bastian Niebel
//
// Abstract class describing differential algebraic equations.
//
// The () operator implements the right hand side of the ordinary differential
// systems of equations.
//
class DynamicalSystem
{
  public:
    DynamicalSystem(double initial_time, std::vector<double> initial_state);

    virtual ~DynamicalSystem() = 0;

    virtual std::vector<double> operator()
        (const double time, const std::vector<double>& state) const = 0;

    const std::vector<double>& getInitialState() const;
    void setInitialState(const std::vector<double> initial_state);

    double getInitialTime() const;
    void setInitialTime(double initial_time);

  private:

    std::vector<double> initial_state;

    double initial_time;

};

#endif /* ifndef LIB_DYNAMICAL_SYSTEM_H_ */
