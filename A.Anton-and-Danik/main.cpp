#include <iostream>

int main() {
  int num_of_games, anton = 0, danik = 0;
  std::string results;

  std::cin >> num_of_games;
  std::cin >> results;

  for (int i = 0; i < num_of_games; i++)
    switch (results[i]) {
    case 'A':
      anton++;
      break;
    case 'D':
      danik++;
      break;
    }

  if (anton > danik)
    std::cout << "Anton" << std::endl;
  else if (anton < danik)
    std::cout << "Danik" << std::endl;
  else
    std::cout << "Friendship" << std::endl;

  return 0;
}
