#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    // Set the path for the chroot jail
    const char *jail_path = "/var/ftproot";

    // Filename to read inside the chroot jail
    const char *filename = "example.txt";

    // Change root directory to the jail path
    if (chroot(jail_path) != 0) {
        perror("chroot");
        return EXIT_FAILURE;
    }

    // Open the file inside the chroot jail
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Read and display the contents of the file
    char buffer[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        return EXIT_FAILURE;
    }

    // Close the file
    close(fd);

    return EXIT_SUCCESS;
}
