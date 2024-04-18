#include <stdio.h>
#include <png.h>

void read_png_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file for reading\n");
        return;
    }

    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
        fprintf(stderr, "Error creating read struct\n");
        fclose(fp);
        return;
    }

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        fprintf(stderr, "Error creating info struct\n");
        png_destroy_read_struct(&png_ptr, NULL, NULL);
        fclose(fp);
        return;
    }

    if (setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "Error during init_io\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        fclose(fp);
        return;
    }

    png_init_io(png_ptr, fp);
    png_set_sig_bytes(png_ptr, 8);

    png_read_info(png_ptr, info_ptr);
    int color_type = png_get_color_type(png_ptr, info_ptr);

    if ((color_type != PNG_COLOR_TYPE_PALETTE) && (color_type != PNG_COLOR_TYPE_RGB)) {
        fprintf(stderr, "Warning: Mode is not PNG_HAVE_PLTE\n");
    }

    png_uint_32 trns_len;
    if (png_get_tRNS(png_ptr, info_ptr, NULL, &trns_len, NULL)) {
        printf("tRNS chunk length: %u\n", (unsigned int)trns_len);
    }

    png_bytep buffer;
    png_uint_32 data_size;
    png_get_iCCP(png_ptr, info_ptr, NULL, &buffer, &data_size);

    png_ptr->flags |= PNG_FLAG_CRC_ANCILLARY_NOWARN;

    png_crc_read(png_ptr);
    
    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
    fclose(fp);
}

int main() {
    const char* filename = "example.png";
    read_png_file(filename);

    return 0;
}