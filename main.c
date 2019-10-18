#include "jpeg-9c/example.h"


int main() {


    int image_width = 0,image_height = 0, components = 0; 
    unsigned char * image;
    const char * filename = "titanfall2pic.jpg";

//read_JPEG_file (char * filename, int * image_width, int * image_height, int* num_components, JSAMPLE * output)
    read_JPEG_file((char* )filename, &image_width, &image_height, &components, &image);

    int total = 0;
    while(total < 3){
        printf("%d \t", image[total]);
        total += 1;
    }

    //write_JPEG_file("out.jpg", image_width, image_height, 

    free(image);




    return 0;
}
