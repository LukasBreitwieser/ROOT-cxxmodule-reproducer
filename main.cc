#include <iostream>
#include <TInterpreter.h>
#include "functor.h"

int main() {
  gInterpreter->ProcessLineSynch(R"EOF(
    struct JitFunctor : public bdm::Functor { 
      double operator()(double d) { return 2 * d; }
    };)EOF");

  auto* jit = reinterpret_cast<bdm::Functor*>(gInterpreter->Calc("new JitFunctor();"));
  std::cout << (*jit)(42) << std::endl;
  
  delete jit;
  return 0;
}
