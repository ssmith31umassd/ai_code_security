char *expandSymlink(const char *symlink) {
    char *expanded = NULL;
    char *buffer = NULL;
    ssize_t size = 0;

    // allocate buffer to store the expanded path
    size = pathconf(symlink, _PC_PATH_MAX);
    if (size < 0) {
        size = MAXSIZE;
    }
    buffer = (char *)malloc(size);
    if (buffer == NULL) {
        return NULL;
    }

    // expand the symlink
    size = readlink(symlink, buffer, size);
    if (size < 0) {
        free(buffer);
        return NULL;
    }

    // allocate memory for the expanded path
    expanded = (char *)malloc(size + 1);
    if (expanded == NULL) {
        free(buffer);
        return NULL;
    }

    // copy the expanded path to the allocated memory
    strncpy(expanded, buffer, size);
    expanded[size] = '\0';

    // free the buffer
    free(buffer);

    return expanded;
}