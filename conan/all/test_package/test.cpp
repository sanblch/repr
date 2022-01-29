#include <repr/repr.h>

#include <iostream>
#include <map>
#include <vector>

int main() {
  std::vector<std::vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::cout << repr(mat) << "\n";
  // {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}

  std::map<std::string, std::vector<int>> map{{"a", {1, 2, 3}}, {"b", {4, 5, 6}}, {"c", {7, 8, 9}}};
  std::cout << repr(map) << "\n";
  // {{"a", {1, 2, 3}}, {"b", {4, 5, 6}}, {"c", {7, 8, 9}}}

  std::optional<int> opt;
  std::cout << repr(opt) << "\n";
  // nullopt

  enum class Color { RED = 2, BLUE = 4, GREEN = 8 };
  Color color = Color::BLUE;
  std::cout << repr(color) << "\n";
  // BLUE
}
