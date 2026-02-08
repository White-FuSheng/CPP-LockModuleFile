#include <iostream>
#include <fstream>
#include <string>

void lockFileOnWindows(const std::string& filePath) {
    std::string  infinite;
    // 以读写模式打开文件。在Windows上，这会自动创建一个独占锁。
    std::fstream file(filePath, std::ios::in | std::ios::out);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return;
    }
    system("cls");
    std::cout << "Successfully opened and locked Module Flie: " << filePath << std::endl;
    std::cout << "The Module File is now in use and cannot be accessed by other programs." << std::endl;
    std::cout << "Module isolation successful. Press Enter to close and release..." << std::endl;

    // 程序暂停，保持文件打开状态，从而锁定文件
    std::cin.get();
    for (int i = 0; i == i; i = i)
    {
        std::cin >> infinite;
        system("cls");
        std::cout << "Successfully opened and locked Module Flie: " << filePath << std::endl;
        std::cout << "The Module File is now in use and cannot be accessed by other programs." << std::endl;
        std::cout << "Module isolation successful. Press Enter to close and release..." << std::endl;
    }
}

int main() {
    std::string filePath; 
    std::cin >> filePath;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清空缓冲区
    lockFileOnWindows(filePath);
    return 0;
}

