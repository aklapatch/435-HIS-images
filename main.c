#include "jpeg-9c/example.h"
#include <math.h>

int main() {


    int image_width = 0,image_height = 0, components = 0; 
    unsigned char * image;
    const char * filename = "titanfall2pic.jpg";

//read_JPEG_file (char * filename, int * image_width, int * image_height, int* num_components, JSAMPLE * output)
    read_JPEG_file((char* )filename, &image_width, &image_height, &components, &image);

    // format is in RGB side by side


    int total = image_height * image_width * components;
    int i = 0;
    int R = 0;
    int G = 0;
    int B =0;
    double saturation =0;
    double hue =0;
    int intensity = 0;
    unsigned char *h_image= malloc(sizeof(char) * total);

    unsigned char *i_image= malloc(sizeof(char) * total);

    unsigned char *s_image= malloc(sizeof(char) * total);

    if (!s_image|| !i_image || !h_image ){
        printf("Failed memory allocation");
        exit(-1);
    }

    for (i = 0; i < total; i +=3){

        R = image[i];
        G = image[i+1];
        B = image[i+2];

         int lightness = R + G + B;
         intensity = (R + G + B)/3;
        // get saturation if R,G,B = 0,0,0
        if ( R == 0 && G == 0 && B == 0){
            saturation = 0;
            hue = 0;
        }
        else {
            // get min value of the triple
            int min = (R < B) ? R : B ;
            if (min > G) min = G;
            
            saturation = ((double)min/intensity); 

             
            int tmp = (R-G) + (R-B);
            hue= (double)tmp/ (2* sqrt((double) (pow((double)R-G, 2.0) + (R-B)* (G-B)) ) );

        }

        if (G >=B){
            hue = acos(hue)*180.0/(3.14159);
        }
        else{
            hue = 360 - acos(hue)*180.0/(3.14159);
        }
        h_image[i] = h_image[i+1] = h_image[i+2] = (unsigned char)255*((double)hue/360);

        i_image[i] = i_image[i+1] = i_image[i+2] = (unsigned char)intensity;

        s_image[i] = s_image[i+1] = s_image[i+2] = (unsigned char)round(saturation*255);

    }



    write_JPEG_file("h_out.jpg", 100, image_width, image_height, h_image);

    write_JPEG_file("i_out.jpg", 100, image_width, image_height, i_image);

    write_JPEG_file("s_out.jpg", 100, image_width, image_height, s_image);
    free(image);
    free(h_image);
    free(i_image);
    free(s_image);




    return 0;
}
