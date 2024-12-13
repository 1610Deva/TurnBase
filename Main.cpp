#include <cmath>
#include <ctime>

#include "include/CLIDisplay.cpp"

int main() {
  srand(static_cast<unsigned int>(time(0)));
  clearScreen();
  Menu();
  return 0;
}
