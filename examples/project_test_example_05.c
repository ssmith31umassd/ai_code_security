#include <stdio.h>
#include <png.h>

// Reference:
// OWASP Foundation. "Buffer Overflow." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Buffer_Overflow (retrieved Feb. 21, 2024).
void pngVulnerabilityTest(png_structp png_ptr, png_bytep readbuf, png_size_t length) {
    if (!(png_ptr->mode & PNG_HAVE_PLTE)) {
    /* Should be an error, but we can cope with it */
    png_warning(png_ptr, "Missing PLTE before tRNS");
    }
    else if (length > (png_uint_32)png_ptr->num_palette) {
    png_warning(png_ptr, "Incorrect tRNS chunk length");
    png_crc_finish(png_ptr, length);
    return;
    }
    png_crc_read(png_ptr, readbuf, (png_size_t)length);
}
// end

int main(int argc, char *argv[]) {
    return 0;
}
