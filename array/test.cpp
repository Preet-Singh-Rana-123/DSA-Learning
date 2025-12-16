#include <filesystem>
#include <iostream>

int main() {
    std::filesystem::path p = ".";
    std::cout << "Current path is: " << std::filesystem::absolute(p) << "\n";
}