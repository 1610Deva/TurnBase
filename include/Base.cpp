#include <cmath>
#include <ctime>

int randomInRange(int min, int max) { return min + rand() % (max - min + 1); }

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
