#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
                size_t width;
                size_t height;
                unsigned char *data;
} Image;

static Image *
image_new (size_t width,
                                size_t height)
{
                Image *image;

                image = malloc (sizeof *image);
                image->width = width;
                image->height = height;
                image->data = malloc (width * height);

                return image;
}

static void
image_free (Image *image)
{
                free (image->data);
                free (image);
}

                static void
image_fill (Image *image,
                        unsigned char value)
{
                memset (image->data, value, image->width * image->height);
}

/**
 * image_set_pixel:
 *
 * Sets a pixel passed in signed (x, y) coordinates, where (0,0) is at
 * the center of the image.
 **/
static void
image_set_pixel (Image *image,
                                ssize_t x,
                                ssize_t y,
                                unsigned char value)
{
                size_t tx, ty;
                unsigned char *p;

                tx = (image->width / 2) + x;
                ty = (image->height / 2) + y;

                p = image->data + (ty * image->width) + tx;

                *p = value;
}

static void
image_save (const Image *image,
                        const char *filename)
{
                FILE *out;

                out = fopen (filename, "wb");
                if (!out)
                                return;

                fprintf (out, "P5\n");
                fprintf (out, "%zu %zu\n", image->width, image->height);
                fprintf (out, "255\n");

                fwrite (image->data, 1, image->width * image->height, out);

                fclose (out);
}

static void draw_Taijitu(Image *image,int radius,int value)
{
                int x,y;
                int rlimit ,llimit;

                int radius_2 = radius*radius;
                for(y = -radius;y<radius;y++)
                    for(x= -radius;x<radius;x++)
                       if(x*x+y*y <= radius_2)
                          image_set_pixel(image,x,y,0xff);

                for(y = -radius;y<0;y++)
                    for(x = 0;x<radius;x++)
                        if((x*x)+(y*y) <= radius_2)
                          image_set_pixel(image,x,y,value);

                for(y = -radius;y<0;y++)
                    for(x = -(int)sqrt((double)(-radius*y-y*y));x<0;x++)
                        image_set_pixel(image,x,y,value);


                for(y = 0;y<radius;y++)
                {
                                llimit = (int)sqrt((double)(radius*y - y*y));
                                rlimit = (int)sqrt((double)(radius_2 - y*y));
                                for(x = llimit;x<rlimit;x++)
                                                image_set_pixel(image,x,y,value);
                }

                for(y = 2*radius/6;y<4*radius/6;y++)
                {
                                rlimit =(int) sqrt((double)(radius*y-y*y-2*radius_2/9));
                                llimit = -rlimit;

                                for(x = llimit;x<rlimit;x++)
                                                image_set_pixel(image,x,y,value);
                }

                for(y = -4*radius/6;y<-2*radius/6;y++)
                {
                                rlimit = sqrt(-radius*y-y*y-2*radius_2/9);
                                llimit = -rlimit;
                                for(x = llimit;x<rlimit;x++)
                                                image_set_pixel(image,x,y,0xff);
                }

                return ;

}
                int
main (int argc, char *argv[])
{
                Image *image;

                image = image_new (800, 800);

                image_fill (image, 0xaa);
                draw_Taijitu (image, 300, 0);
                image_save (image, "taiji_6.pgm");

                image_free (image);

                return 0;
}
