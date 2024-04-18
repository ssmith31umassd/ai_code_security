#include <stdio.h>
#include <stdlib.h>
#include <png.h>

#define PNG_BYTES_TO_CHECK 8

void warning_function(png_structp png_ptr, png_const_charp warning_msg) {
    // Custom warning handling
    fprintf(stderr, "libPNG Warning: %s\n", warning_msg);
}

void error_function(png_structp png_ptr, png_const_charp error_msg) {
    // Custom error handling
    fprintf(stderr, "libPNG Error: %s\n", error_msg);
    longjmp(png_jmpbuf(png_ptr), 1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file.png>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Check if the file is a PNG by reading the header
    png_byte header[PNG_BYTES_TO_CHECK];
    fread(header, 1, PNG_BYTES_TO_CHECK, file);
    if (png_sig_cmp(header, 0, PNG_BYTES_TO_CHECK) != 0) {
        fprintf(stderr, "Error: %s is not a PNG file\n", argv[1]);
        fclose(file);
        return EXIT_FAILURE;
    }

    // Initialize libPNG structures
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, error_function, warning_function);
    if (!png_ptr) {
        fprintf(stderr, "Error: png_create_read_struct failed\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        fprintf(stderr, "Error: png_create_info_struct failed\n");
        png_destroy_read_struct(&png_ptr, NULL, NULL);
        fclose(file);
        return EXIT_FAILURE;
    }

    // Set up error handling
    if (setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "Error: Error during PNG file read\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        fclose(file);
        return EXIT_FAILURE;
    }

    // Initialize PNG IO
    png_init_io(png_ptr, file);
    png_set_sig_bytes(png_ptr, PNG_BYTES_TO_CHECK);

    // Read PNG info
    png_read_info(png_ptr, info_ptr);

    // Check if the PNG file is in the correct mode
    int color_type = png_get_color_type(png_ptr, info_ptr);
    if ((color_type & PNG_COLOR_MASK_PALETTE) != PNG_COLOR_MASK_PALETTE) {
        fprintf(stderr, "Warning: PNG image does not have a palette\n");
    }

    // Check tRNS chunk length
    png_uint_32 trns_len;
    if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)) {
        png_get_tRNS(png_ptr, info_ptr, NULL, &trns_len, NULL);
        if (trns_len > 0) {
            fprintf(stderr, "tRNS chunk length: %u\n", trns_len);
        }
    }

    // Allocate memory for image buffer
    png_uint_32 width = png_get_image_width(png_ptr, info_ptr);
    png_uint_32 height = png_get_image_height(png_ptr, info_ptr);
    png_byte bit_depth = png_get_bit_depth(png_ptr, info_ptr);
    png_bytep row_pointers[height];
    for (int i = 0; i < height; i++) {
        row_pointers[i] = (png_bytep)malloc(png_get_rowbytes(png_ptr, info_ptr));
    }

    // Read image data
    png_read_image(png_ptr, row_pointers);

    // Example: Copy data using png_crc_read
    // This is just a demonstration, you can use it for your specific requirements
    unsigned char *buffer = (unsigned char *)malloc(width * height * 4 * sizeof(unsigned char));
    unsigned char *ptr = buffer;
    for (int y = 0; y < height; y++) {
        png_crc_read(png_ptr, row_pointers[y], width * 4 * sizeof(png_byte));
        memcpy(ptr, row_pointers[y], width * 4 * sizeof(unsigned char));
        ptr += width * 4 * sizeof(unsigned char);
    }

    // Cleanup
    for (int i = 0; i < height; i++) {
        free(row_pointers[i]);
    }
    free(buffer);
    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
    fclose(file);

    return EXIT_SUCCESS;
}
