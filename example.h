#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <stdio.h>

/*
 * Include file for users of JPEG library.
 * You will need to have included system headers that define at least
 * the typedefs FILE and size_t before you can include jpeglib.h.
 * (stdio.h is sufficient on ANSI-conforming systems.)
 * You may also wish to include "jerror.h".
 */

#include "jpeg-9c/jpeglib.h"

/*
 * <setjmp.h> is used for the optional error recovery mechanism shown in
 * the second part of the example.
 */

#include <setjmp.h>

#include<stdlib.h>

GLOBAL(void)
write_JPEG_file (char * filename, int quality, int image_width, int image_height, JSAMPLE * image_buffer);

GLOBAL(int)
read_JPEG_file (char * filename, int * image_width, int * image_height, int* num_components, JSAMPLE ** output);

#endif
