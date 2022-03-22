#include <iostream>

int main() {
  int num_of_friends, height_of_fence, height_of_person;
  std::cin >> num_of_friends;
  std::cin >> height_of_fence;

  int road_min_width = 0;

  for (int i; i < num_of_friends; i++) {
    std::cin >> height_of_person;
    road_min_width += height_of_person > height_of_fence ? 2 : 1;
  }

  std::cout << road_min_width << std::endl;

  return 0;
}
