#include <png.h>

int checkCrc(png_structp *png_ptr) {
    if (!(png_ptr->mode & PNG_HAVE_PLTE)) {
        return 0;
    }
    return 1;
}