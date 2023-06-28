#ifndef FUNCTOR_H_
#define FUNCTOR_H_

namespace bdm {

struct Functor {
  virtual double operator()(double d) = 0;
};

}  // namespace bdm

#endif  // FUNCTOR_H_
