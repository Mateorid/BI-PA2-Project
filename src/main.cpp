#include "Application.hpp"

int main(int argc, char *argv[]) {
    auto *app = new Application();
    return app->Start();
}