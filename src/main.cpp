
#include "main.h"

int main(int argc, char *argv[]) {
    // it changes the seed of the rand method
    srand(time(NULL));
    MainWindow window;
    window.show(argc, argv);
    return Fl::run();
}