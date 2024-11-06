#include <iostream>

int main(int argc, char** argv) {
    if(argc <= 1) {
        printf("No arguments supplied!\n");
        return 0;
    }
    printf("Args: \n");

    for(size_t i = 1; i < static_cast<size_t>(argc); i++)
        printf("%zu.) %s\n", i, argv[i]);

    return 0;
}
