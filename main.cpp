#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

int main() {
  using std::filesystem::is_regular_file;
  using std::filesystem::path;
  using std::filesystem::recursive_directory_iterator;

  auto recursiveGetFileNamesByExtension = [](path path,
                                             const std::string extension) {
    if (!is_regular_file(path)) {
      std::vector<std::filesystem::path> paths;
      for (auto& i : recursive_directory_iterator(path)) {
        if (!i.path().extension().compare(extension)) {
          paths.push_back(i.path());
        }
      }

      return paths;
    }
  };

  std::vector<path> paths =
      recursiveGetFileNamesByExtension("C:\\Users\\logbaby\\Downloads", ".jpg");

  for (auto& i : paths) std::cout << i << std::endl;
}