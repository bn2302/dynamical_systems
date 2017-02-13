#ifndef LIB_DYNAMICAL_SYSTEM_H_
#define LIB_DYNAMICAL_SYSTEM_H_
#include <vector>

class DynamicalSystem
{
  public:
    DynamicalSystem(double time, std::vector<double> state);

    virtual ~DynamicalSystem() = 0;

    virtual std::vector<double> right_hand_side(
        const double time, const std::vector<double>& state) const = 0;

    const std::vector<double>& getState() const;
    void setState(const std::vector<double> state);

    double getTime() const;

    void setTime(double time);

  private:
    double time;
    std::vector<double> state;
};

#endif /* ifndef LIB_DYNAMICAL_SYSTEM_H_ */
