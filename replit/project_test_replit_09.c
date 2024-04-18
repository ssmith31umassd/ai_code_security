#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *filename = "file.txt";
    char *chroot_path = "/var/ftproot";

    if (chroot(chroot_path) != 0) {
        perror("chroot");
        return 1;
    }

    char actual_path[256];
    snprintf(actual_path, sizeof(actual_path), "%s/%s", chroot_path, filename);

    int fd = open(actual_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[1024];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    close(fd);
    return 0;
}