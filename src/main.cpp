#include "Application.hpp"

int main(int argc, char *argv[]) {
    try {
        auto *app = new Application();
        int tmp = app->Start();
        delete app;
        return tmp;
    }
    catch (std::runtime_error &err) {
        std::cout << err.what() << std::endl;
        return 69;
    }
}