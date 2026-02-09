#include <iostream>
#include <windows.h>
#include <string>

void lockFileOnWindows(const std::string& filePath) {
    std::string infinite;
    // 使用 CreateFile 以独占模式打开文件
    HANDLE hFile = CreateFileA(
        filePath.c_str(),           // 文件名
        GENERIC_READ | GENERIC_WRITE, // 读写权限
        0,                          // 不共享（独占模式）
        NULL,                       // 默认安全属性
        OPEN_EXISTING,              // 打开现有文件
        FILE_ATTRIBUTE_NORMAL,      // 普通文件属性
        NULL                        // 无模板文件
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        std::cerr << "Error code: " << GetLastError() << std::endl;
        return;
    }

    system("cls");
    std::cout << "Successfully opened and locked Module File: " << filePath << std::endl;
    std::cout << "The Module File is now in use and cannot be accessed by other programs." << std::endl;
    std::cout << "Module isolation successful. Press Enter to close and release..." << std::endl;

    // 程序暂停，保持文件打开状态，从而锁定文件
    std::cin.get();
    while (true) {
        std::cin >> infinite;
        system("cls");
        std::cout << "Successfully opened and locked Module File: " << filePath << std::endl;
        std::cout << "The Module File is now in use and cannot be accessed by other programs." << std::endl;
        std::cout << "Module isolation successful. Press Enter to close and release..." << std::endl;
    }

    // 关闭文件句柄（释放锁）
    CloseHandle(hFile);
}

int main() {
    std::string filePath;
    std::cin >> filePath;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清空缓冲区
    lockFileOnWindows(filePath);
    return 0;
}
