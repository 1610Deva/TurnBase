#include <cmath>
#include <ctime>

#include "./include/Base.h"
#include "./include/CLIDisplay.h"

int main() {
  srand(static_cast<unsigned int>(time(0)));
  clearScreen();
  Menu();
  return 0;
}
