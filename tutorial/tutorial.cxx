#include <iostream>
#include <cmath>
#include <cstdlib>

#include "tutorial_config.h"

#ifdef USE_MYMATH
#include "mysqrt.h"
#endif

int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cout << " Usage: " << argv[0] << " Version ";
    std::cout << MAJOR_VERSION << "." << MINOR_VERSION << "\n";
    return 1;
  }

  const double input = std::atof(argv[1]);


  #ifdef USE_MYMATH
    const double output = mysqrt( input );
  #else
    const double output = std::sqrt( input );
  #endif

  std::cout << " The quare root of " << input << " is " << output << "\n";
  return 0;
}
