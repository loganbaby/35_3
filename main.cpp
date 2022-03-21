#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
#include <iostream>
#include <string>
#include <vector>

int main() {
  using std::experimental::filesystem::is_regular_file;
  using std::experimental::filesystem::path;
  using std::experimental::filesystem::recursive_directory_iterator;

  auto recursiveGetFileNamesByExtension = [](path path,
                                             const std::string extension) {
    if (!is_regular_file(path)) {
      std::vector<std::experimental::filesystem::path> paths;
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