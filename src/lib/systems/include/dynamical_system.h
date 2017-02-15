#ifndef LIB_DYNAMICAL_SYSTEM_H_
#define LIB_DYNAMICAL_SYSTEM_H_
#include <vector>

template <typename T>
class DynamicalSystem
{
  public:
    DynamicalSystem(T time, std::vector<T> state);

    virtual ~DynamicalSystem() = 0;

    virtual std::vector<T> operator()
        (const T time, const std::vector<T>& state) const = 0;

    const std::vector<T>& getState() const;
    void setState(const std::vector<T>& state);

    T getTime() const;

    void setTime(T time);

  private:
    T time;
    std::vector<T> state;
};

template class DynamicalSystem<float>;

template class DynamicalSystem<double>;



#endif /* ifndef LIB_DYNAMICAL_SYSTEM_H_ */
