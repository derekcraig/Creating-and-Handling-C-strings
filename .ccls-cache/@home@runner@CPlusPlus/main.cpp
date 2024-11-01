#include <iostream>
#include <cctype>
using namespace std;

int main() {
  std::cout << "Hello World!\n";
  char test[10] = "Super!";
  int result = 0;
  *char ptr = nullptr;
  char charSearch;
  
  result = isalpha(test[0]);
  ptr = strchr(test, charSearch);
}