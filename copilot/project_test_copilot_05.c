#include <stdio.h>
#include <stdlib.h>
#include <png.h>

void read_png_file(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
        printf("Error creating PNG read struct\n");
        fclose(fp);
        return;
    }

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        printf("Error creating PNG info struct\n");
        png_destroy_read_struct(&png_ptr, NULL, NULL);
        fclose(fp);
        return;
    }

    if (setjmp(png_jmpbuf(png_ptr))) {
        printf("Error during PNG read\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        fclose(fp);
        return;
    }

    png_init_io(png_ptr, fp);
    png_read_info(png_ptr, info_ptr);

    int color_type = png_get_color_type(png_ptr, info_ptr);
    if (color_type != PNG_COLOR_TYPE_PALETTE) {
        printf("Warning: Color type is not PNG_COLOR_TYPE_PALETTE\n");
    }

    png_bytep trans_alpha = NULL;
    int num_trans = 0;
    png_get_tRNS(png_ptr, info_ptr, &trans_alpha, &num_trans, NULL);
    printf("tRNS chunk length: %d\n", num_trans);

    size_t row_bytes = png_get_rowbytes(png_ptr, info_ptr);
    png_bytep buffer = (png_bytep)malloc(row_bytes);
    if (!buffer) {
        printf("Error allocating memory for buffer\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        fclose(fp);
        return;
    }

    for (int y = 0; y < png_get_image_height(png_ptr, info_ptr); y++) {
        png_read_row(png_ptr, buffer, NULL);
        // Process the row data in the buffer
    }

    free(buffer);
    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
    fclose(fp);
}

int main() {
    const char* filename = "path/to/your/image.png";
    read_png_file(filename);
    return 0;
}