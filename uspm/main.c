#include <stdio.h>
#include "parser.h"
#include "parser.c"
#include "iu.c"

int main(int argc, char *argv[]) {
    printf("Welcome to USPM\n");
    chdir("/var/uspm/storage");

    int result = access("/var/uspm/storage/", W_OK);
    if (result != 0)
    {
        printf("Cannot write to the storage directory, exiting.\n");
        return 1;
    } else {

    }

    check_packages_file();
    check_config_file();

    if (argc >= 3) {
        if (strcmp(argv[1], "i") == 0) {
            printf("install %s\n", argv[2]);
            for (int i = 2; i < argc; i++) {
                install_package(argv[i]);
            }
        }

        else if (strcmp(argv[1], "u") == 0) {
            printf("uninstall %s\n", argv[2]);
            for (int i = 2; i < argc; i++) {
                uninstall_package(argv[i]);
            }
        }

        else if (strcmp(argv[1], "c") == 0) {
            for (int i = 2; i < argc; i++) {
                check_dependencies(argv[i]);
            }
        }

        else {
            printf("command not found");
        }
    } else {
        printf("No command found");
    }
    return 0;
}