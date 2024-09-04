#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/*
 * Please fill in the following team struct
 */

team_t team = {

    "CST-LastHero", /* Team name */

    "½¯ÔÆÏè", /* First member full name */

    "2864080068@qq.com", /* First member email address */

    "", /* Second or third member full name (leave blank if none) */

    "" /* Second or third member email addr (leave blank if none) */

};

/***************
 * ROTATE KERNEL

 ***************/

 /******************************************************
  * Your different versions of the rotate kernel go here
  ******************************************************/

  /*
   * naive_rotate - The naive baseline version of rotate
   */

char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel* src, pixel* dst) {
    int i, j;

    for (i = 0; i < dim; i++)

        for (j = 0; j < dim; j++)

            dst[RIDX(dim - 1 - j, i, dim)] = src[RIDX(i, j, dim)];

    return;
}

/*



 * rotate - Your current working version of rotate



 * IMPORTANT: This is the version you will be graded on



 */

char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel* src, pixel* dst)

{
    naive_rotate(dim, src, dst);
}

char rotate_descr_c[] = "rotate_c: Current working version";
void rotate_c(int dim, pixel* src, pixel* dst) {
    int i, j;

    for (j = 0; j < dim; j++)

        for (i = 0; i < dim; i++)

            dst[RIDX(dim - 1 - j, i, dim)] = src[RIDX(i, j, dim)];

    return;
}

char rotate_descr_b8[] = "rotate_b8: Current working version";
void rotate_b8(int dim, pixel* src, pixel* dst)

{
    int i, j, i_1, j_1;

    for (i = 0; i < dim; i += 8) {
        for (j = 0; j < dim; j += 8) {
            for (i_1 = i; i_1 < i + 8; i_1++) {
                for (j_1 = j; j_1 < j + 8; j_1++)

                    dst[RIDX(dim - 1 - j_1, i_1, dim)] = src[RIDX(i_1, j_1, dim)];
            }
        }
    }
}

char rotate_descr_b4[] = "rotate_b4: Current working version";
void rotate_b4(int dim, pixel* src, pixel* dst)

{
    int i, j, i_1, j_1;

    for (i = 0; i < dim; i += 4) {
        for (j = 0; j < dim; j += 4) {
            for (i_1 = i; i_1 < i + 4; i_1++) {
                for (j_1 = j; j_1 < j + 4; j_1++)

                    dst[RIDX(dim - 1 - j_1, i_1, dim)] = src[RIDX(i_1, j_1, dim)];
            }
        }
    }
}

char rotate_descr_b16_u2[] = "rotate_b16_u2: Current working version";
void rotate_b16_u2(int n, pixel* src, pixel* dst) {
    for (int i = 0; i < n; i += 16) {
        for (int j = 0; j < n; j += 16) {
            for (int k = 0; k < 16; ++k) {
                for (int l = 0; l < 16; l += 2) {
                    dst[(n - 1 - (j + l)) * n + (i + k)] = src[(i + k) * n + (j + l)];

                    dst[(n - 1 - (j + l + 1)) * n + (i + k)] = src[(i + k) * n + (j + l + 1)];
                }
            }
        }
    }
}

char rotate_descr_b32_u2[] = "rotate_b32_u2: Current working version";

void rotate_b32_u2(int n, pixel* src, pixel* dst) {
    for (int i = 0; i < n; i += 32) {
        for (int j = 0; j < n; j += 32) {
            for (int k = 0; k < 32; ++k) {
                for (int l = 0; l < 32; ++l) {
                    dst[(n - j - 1 - l) * n + i + k] = src[(i + k) * n + j + l];
                }
            }
        }
    }
}

char rotate_descr_b8_u4_c[] = "rotate_b8_u4_c: Current working version";
void rotate_b8_u4_c(int dim, pixel* src, pixel* dst) {
    int i, j, ii, jj;

    for (ii = 0; ii < dim; ii += 8) {
        for (jj = 0; jj < dim; jj += 8) {
            for (j = jj; j < jj + 8; j += 4) {
                for (i = ii; i < ii + 8; i++) {
                    pixel tmp1 = src[RIDX(i, j, dim)];

                    pixel tmp2 = src[RIDX(i, j + 1, dim)];

                    pixel tmp3 = src[RIDX(i, j + 2, dim)];

                    pixel tmp4 = src[RIDX(i, j + 3, dim)];

                    dst[RIDX(dim - 1 - j, i, dim)] = tmp1;

                    dst[RIDX(dim - 1 - j - 1, i, dim)] = tmp2;

                    dst[RIDX(dim - 1 - j - 2, i, dim)] = tmp3;

                    dst[RIDX(dim - 1 - j - 3, i, dim)] = tmp4;
                }
            }
        }
    }
}

char rotate_descr_b8_u4[] = "rotate_b8_u4: Current working version";
void rotate_b8_u4(int dim, pixel* src, pixel* dst) {
    int i, j, ii, jj;

    for (ii = 0; ii < dim; ii += 8) {
        for (jj = 0; jj < dim; jj += 8) {
            for (i = ii; i < ii + 8; i++) {
                for (j = jj; j < jj + 8; j += 4) {
                    pixel tmp1 = src[RIDX(i, j, dim)];

                    pixel tmp2 = src[RIDX(i, j + 1, dim)];

                    pixel tmp3 = src[RIDX(i, j + 2, dim)];

                    pixel tmp4 = src[RIDX(i, j + 3, dim)];

                    dst[RIDX(dim - 1 - j, i, dim)] = tmp1;

                    dst[RIDX(dim - 1 - j - 1, i, dim)] = tmp2;

                    dst[RIDX(dim - 1 - j - 2, i, dim)] = tmp3;

                    dst[RIDX(dim - 1 - j - 3, i, dim)] = tmp4;
                }
            }
        }
    }
}

char rotate_descr_b16_u4[] = "rotate_b16_u4: Current working version";
void rotate_b16_u4(int dim, pixel* src, pixel* dst) {
    int i, j, ii, jj;

    for (ii = 0; ii < dim; ii += 16) {
        for (jj = 0; jj < dim; jj += 16) {
            for (i = ii; i < ii + 16; i++) {
                for (j = jj; j < jj + 16; j += 4) {
                    pixel tmp1 = src[RIDX(i, j, dim)];

                    pixel tmp2 = src[RIDX(i, j + 1, dim)];

                    pixel tmp3 = src[RIDX(i, j + 2, dim)];

                    pixel tmp4 = src[RIDX(i, j + 3, dim)];

                    dst[RIDX(dim - 1 - j, i, dim)] = tmp1;

                    dst[RIDX(dim - 1 - j - 1, i, dim)] = tmp2;

                    dst[RIDX(dim - 1 - j - 2, i, dim)] = tmp3;

                    dst[RIDX(dim - 1 - j - 3, i, dim)] = tmp4;
                }
            }
        }
    }
}

char rotate_descr_b16_u4_c[] = "rotate_b16_u4_c: Current working version";
void rotate_b16_u4_c(int dim, pixel* src, pixel* dst) {
    int i, j, ii, jj;

    for (jj = 0; jj < dim; jj += 16) {
        for (ii = 0; ii < dim; ii += 16) {
            for (j = jj; j < jj + 16; j += 4) {
                for (i = ii; i < ii + 16; i++) {
                    pixel tmp1 = src[RIDX(i, j, dim)];

                    pixel tmp2 = src[RIDX(i, j + 1, dim)];

                    pixel tmp3 = src[RIDX(i, j + 2, dim)];

                    pixel tmp4 = src[RIDX(i, j + 3, dim)];

                    dst[RIDX(dim - 1 - j, i, dim)] = tmp1;

                    dst[RIDX(dim - 1 - j - 1, i, dim)] = tmp2;

                    dst[RIDX(dim - 1 - j - 2, i, dim)] = tmp3;

                    dst[RIDX(dim - 1 - j - 3, i, dim)] = tmp4;
                }
            }
        }
    }
}

char rotate_descr_b32_u4[] = "rotate_b32_u4: Current working version";
void rotate_b32_u4(int dim, pixel* src, pixel* dst) {
    int i, j, ii, jj;

    for (ii = 0; ii < dim; ii += 32) {
        for (jj = 0; jj < dim; jj += 32) {
            for (i = ii; i < ii + 32; i++) {
                for (j = jj; j < jj + 32; j += 4) {
                    pixel tmp1 = src[RIDX(i, j, dim)];

                    pixel tmp2 = src[RIDX(i, j + 1, dim)];

                    pixel tmp3 = src[RIDX(i, j + 2, dim)];

                    pixel tmp4 = src[RIDX(i, j + 3, dim)];

                    dst[RIDX(dim - 1 - j, i, dim)] = tmp1;

                    dst[RIDX(dim - 1 - j - 1, i, dim)] = tmp2;

                    dst[RIDX(dim - 1 - j - 2, i, dim)] = tmp3;

                    dst[RIDX(dim - 1 - j - 3, i, dim)] = tmp4;
                }
            }
        }
    }
}

char rotate_descr_b32_u4_c[] = "rotate_b32_u4_c: Current working version";
void rotate_b32_u4_c(int dim, pixel* src, pixel* dst) {
    int i, j, ii, jj;

    for (jj = 0; jj < dim; jj += 32) {
        for (ii = 0; ii < dim; ii += 32) {
            for (j = jj; j < jj + 32; j += 4) {
                for (i = ii; i < ii + 32; i++) {
                    pixel tmp1 = src[RIDX(i, j, dim)];

                    pixel tmp2 = src[RIDX(i, j + 1, dim)];

                    pixel tmp3 = src[RIDX(i, j + 2, dim)];

                    pixel tmp4 = src[RIDX(i, j + 3, dim)];

                    dst[RIDX(dim - 1 - j, i, dim)] = tmp1;

                    dst[RIDX(dim - 1 - j - 1, i, dim)] = tmp2;

                    dst[RIDX(dim - 1 - j - 2, i, dim)] = tmp3;

                    dst[RIDX(dim - 1 - j - 3, i, dim)] = tmp4;
                }
            }
        }
    }
}

/*********************************************************************



 *     register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_rotate_functions()

{
    add_rotate_function(&naive_rotate, naive_rotate_descr);
   
    add_rotate_function(&rotate, rotate_descr);
   
    add_rotate_function(&rotate_c, rotate_descr_c);
   
    add_rotate_function(&rotate_b8, rotate_descr_b8);

    add_rotate_function(&rotate_b4, rotate_descr_b4);

    add_rotate_function(&rotate_b16_u2, rotate_descr_b16_u2);

    add_rotate_function(&rotate_b32_u2, rotate_descr_b32_u2);

    add_rotate_function(&rotate_b8_u4_c, rotate_descr_b8_u4_c);

    add_rotate_function(&rotate_b8_u4, rotate_descr_b8_u4);

    add_rotate_function(&rotate_b16_u4, rotate_descr_b16_u4);

    add_rotate_function(&rotate_b16_u4_c, rotate_descr_b16_u4_c);

    add_rotate_function(&rotate_b32_u4, rotate_descr_b32_u4);

    add_rotate_function(&rotate_b32_u4_c, rotate_descr_b32_u4_c);

    /* ... Register additional test functions here */
}

/***************
 * SMOOTH KERNEL
 **************/

 /***************************************************************
  * Various typedefs and helper functions for the smooth function
  * You may modify these any way you like.
  **************************************************************/

  /* A struct used to compute averaged pixel value */

typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */

static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/*
 * initialize_pixel_sum - Initializes all fields of sum to 0
 */

static void initialize_pixel_sum(pixel_sum* sum)

{
    sum->red = sum->green = sum->blue = 0;

    sum->num = 0;

    return;
}

/*
 * accumulate_sum - Accumulates field values of p in corresponding
 * fields of sum
 */

static void accumulate_sum(pixel_sum* sum, pixel p)

{
    sum->red += (int)p.red;

    sum->green += (int)p.green;

    sum->blue += (int)p.blue;

    sum->num++;

    return;
}

/*
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel
 */

static void assign_sum_to_pixel(pixel* current_pixel, pixel_sum sum)

{
    current_pixel->red = (unsigned short)(sum.red / sum.num);

    current_pixel->green = (unsigned short)(sum.green / sum.num);

    current_pixel->blue = (unsigned short)(sum.blue / sum.num);

    return;
}

/*
 * avg - Returns averaged pixel value at (i,j)
 */

static pixel avg(int dim, int i, int j, pixel* src)

{
    int ii, jj;

    pixel_sum sum;

    pixel current_pixel;

    initialize_pixel_sum(&sum);

    for (ii = max(i - 1, 0); ii <= min(i + 1, dim - 1); ii++)

        for (jj = max(j - 1, 0); jj <= min(j + 1, dim - 1); jj++)

            accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);

    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

 /*
  * naive_smooth - The naive baseline version of smooth
  */

char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";

void naive_smooth(int dim, pixel* src, pixel* dst)

{
    int i, j;

    for (i = 0; i < dim; i++)

        for (j = 0; j < dim; j++) dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * smooth - Your current working version of smooth.
 * IMPORTANT: This is the version you will be graded on
 */

char smooth_descr[] = "smooth: Current working version";

void smooth(int dim, pixel* src, pixel* dst)

{
    naive_smooth(dim, src, dst);
}

char smooth_final_descr[] = "smooth_final: Optimized column-major version";

void smooth_final(int dim, pixel* src, pixel* dst)

{
    int i, j;

    pixel current_pixel;

    pixel* pcurrent_pixel = &current_pixel;

    i = 0;

    j = 0;

    pcurrent_pixel->red =

        (unsigned short)(((int)(src[RIDX(0, 0, dim)].red +
            src[RIDX(0, 1, dim)].red +

            src[RIDX(1, 0, dim)].red +
            src[RIDX(1, 1, dim)].red)) /

            4);

    pcurrent_pixel->green =

        (unsigned short)(((int)(src[RIDX(0, 0, dim)].green +
            src[RIDX(0, 1, dim)].green +

            src[RIDX(1, 0, dim)].green +
            src[RIDX(1, 1, dim)].green)) /

            4);

    pcurrent_pixel->blue =

        (unsigned short)(((int)(src[RIDX(0, 0, dim)].blue +
            src[RIDX(0, 1, dim)].blue +

            src[RIDX(1, 0, dim)].blue +
            src[RIDX(1, 1, dim)].blue)) /

            4);

    dst[RIDX(0, 0, dim)] = current_pixel;

    i = 0;

    j = dim - 1;

    pcurrent_pixel->red =

        (unsigned short)(((int)(src[RIDX(i, j, dim)].red +
            src[RIDX(i + 1, j, dim)].red +

            src[RIDX(i, j - 1, dim)].red +
            src[RIDX(i + 1, j - 1, dim)].red)) /

            4);

    pcurrent_pixel->green =

        (unsigned short)(((int)(src[RIDX(i, j, dim)].green +
            src[RIDX(i + 1, j, dim)].green +

            src[RIDX(i, j - 1, dim)].green +
            src[RIDX(i + 1, j - 1, dim)].green)) /

            4);

    pcurrent_pixel->blue =

        (unsigned short)(((int)(src[RIDX(i, j, dim)].blue +
            src[RIDX(i + 1, j, dim)].blue +

            src[RIDX(i, j - 1, dim)].blue +
            src[RIDX(i + 1, j - 1, dim)].blue)) /

            4);

    dst[RIDX(i, j, dim)] = current_pixel;

    i = dim - 1;

    j = 0;

    pcurrent_pixel->red =

        (unsigned short)(((int)(src[RIDX(i, j, dim)].red +
            src[RIDX(i - 1, j, dim)].red +

            src[RIDX(i, j + 1, dim)].red +
            src[RIDX(i - 1, j + 1, dim)].red)) /

            4);

    pcurrent_pixel->green =

        (unsigned short)(((int)(src[RIDX(i, j, dim)].green +
            src[RIDX(i - 1, j, dim)].green +

            src[RIDX(i, j + 1, dim)].green +
            src[RIDX(i - 1, j + 1, dim)].green)) /

            4);

    pcurrent_pixel->blue =

        (unsigned short)(((int)(src[RIDX(i, j, dim)].blue +
            src[RIDX(i - 1, j, dim)].blue +

            src[RIDX(i, j + 1, dim)].blue +
            src[RIDX(i - 1, j + 1, dim)].blue)) /

            4);

    dst[RIDX(i, j, dim)] = current_pixel;

    i = dim - 1;

    j = dim - 1;

    pcurrent_pixel->red =

        (unsigned short)(((int)(src[RIDX(i, j, dim)].red +
            src[RIDX(i - 1, j, dim)].red +

            src[RIDX(i, j - 1, dim)].red +
            src[RIDX(i - 1, j - 1, dim)].red)) /

            4);

    pcurrent_pixel->green =

        (unsigned short)(((int)(src[RIDX(i, j, dim)].green +
            src[RIDX(i - 1, j, dim)].green +

            src[RIDX(i, j - 1, dim)].green +
            src[RIDX(i - 1, j - 1, dim)].green)) /

            4);

    pcurrent_pixel->blue =

        (unsigned short)(((int)(src[RIDX(i, j, dim)].blue +
            src[RIDX(i - 1, j, dim)].blue +

            src[RIDX(i, j - 1, dim)].blue +
            src[RIDX(i - 1, j - 1, dim)].blue)) /

            4);

    dst[RIDX(i, j, dim)] = current_pixel;

    j = 0;

    for (i = 1; i < dim - 1; i++)

    {
        pcurrent_pixel->red =

            (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].red +
                src[RIDX(i - 1, j + 1, dim)].red +

                src[RIDX(i, j, dim)].red +
                src[RIDX(i, j + 1, dim)].red +

                src[RIDX(i + 1, j, dim)].red +
                src[RIDX(i + 1, j + 1, dim)].red)) /

                6);

        pcurrent_pixel->green =

            (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].green +
                src[RIDX(i - 1, j + 1, dim)].green +

                src[RIDX(i, j, dim)].green +
                src[RIDX(i, j + 1, dim)].green +

                src[RIDX(i + 1, j, dim)].green +
                src[RIDX(i + 1, j + 1, dim)].green)) /

                6);

        pcurrent_pixel->blue =

            (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].blue +
                src[RIDX(i - 1, j + 1, dim)].blue +

                src[RIDX(i, j, dim)].blue +
                src[RIDX(i, j + 1, dim)].blue +

                src[RIDX(i + 1, j, dim)].blue +
                src[RIDX(i + 1, j + 1, dim)].blue)) /

                6);

        dst[RIDX(i, j, dim)] = current_pixel;
    }

    i = dim - 1;

    for (j = 1; j < dim - 1; j++)

    {
        pcurrent_pixel->red =

            (unsigned short)(((int)(src[RIDX(i, j, dim)].red +
                src[RIDX(i - 1, j, dim)].red +

                src[RIDX(i, j - 1, dim)].red +
                src[RIDX(i - 1, j - 1, dim)].red +

                src[RIDX(i, j + 1, dim)].red +
                src[RIDX(i - 1, j + 1, dim)].red)) /

                6);

        pcurrent_pixel->green =

            (unsigned short)(((int)(src[RIDX(i, j, dim)].green +
                src[RIDX(i - 1, j, dim)].green +

                src[RIDX(i, j - 1, dim)].green +
                src[RIDX(i - 1, j - 1, dim)].green +

                src[RIDX(i, j + 1, dim)].green +
                src[RIDX(i - 1, j + 1, dim)].green)) /

                6);

        pcurrent_pixel->blue =

            (unsigned short)(((int)(src[RIDX(i, j, dim)].blue +
                src[RIDX(i - 1, j, dim)].blue +

                src[RIDX(i, j - 1, dim)].blue +
                src[RIDX(i - 1, j - 1, dim)].blue +

                src[RIDX(i, j + 1, dim)].blue +
                src[RIDX(i - 1, j + 1, dim)].blue)) /

                6);

        dst[RIDX(i, j, dim)] = current_pixel;
    }

    j = dim - 1;

    for (i = 1; i < dim - 1; i++)

    {
        pcurrent_pixel->red =

            (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].red +
                src[RIDX(i - 1, j - 1, dim)].red +

                src[RIDX(i, j, dim)].red +
                src[RIDX(i, j - 1, dim)].red +

                src[RIDX(i + 1, j, dim)].red +
                src[RIDX(i + 1, j - 1, dim)].red)) /

                6);

        pcurrent_pixel->green =

            (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].green +
                src[RIDX(i - 1, j - 1, dim)].green +

                src[RIDX(i, j, dim)].green +
                src[RIDX(i, j - 1, dim)].green +

                src[RIDX(i + 1, j, dim)].green +
                src[RIDX(i + 1, j - 1, dim)].green)) /

                6);

        pcurrent_pixel->blue =

            (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].blue +
                src[RIDX(i - 1, j - 1, dim)].blue +

                src[RIDX(i, j, dim)].blue +
                src[RIDX(i, j - 1, dim)].blue +

                src[RIDX(i + 1, j, dim)].blue +
                src[RIDX(i + 1, j - 1, dim)].blue)) /

                6);

        dst[RIDX(i, j, dim)] = current_pixel;
    }

    i = 0;

    for (j = 1; j < dim - 1; j++)

    {
        pcurrent_pixel->red =

            (unsigned short)(((int)(src[RIDX(i, j, dim)].red +
                src[RIDX(i + 1, j, dim)].red +

                src[RIDX(i, j - 1, dim)].red +
                src[RIDX(i + 1, j - 1, dim)].red +

                src[RIDX(i, j + 1, dim)].red +
                src[RIDX(i + 1, j + 1, dim)].red)) /

                6);

        pcurrent_pixel->green =

            (unsigned short)(((int)(src[RIDX(i, j, dim)].green +
                src[RIDX(i + 1, j, dim)].green +

                src[RIDX(i, j - 1, dim)].green +
                src[RIDX(i + 1, j - 1, dim)].green +

                src[RIDX(i, j + 1, dim)].green +
                src[RIDX(i + 1, j + 1, dim)].green)) /

                6);

        pcurrent_pixel->blue =

            (unsigned short)(((int)(src[RIDX(i, j, dim)].blue +
                src[RIDX(i + 1, j, dim)].blue +

                src[RIDX(i, j - 1, dim)].blue +
                src[RIDX(i + 1, j - 1, dim)].blue +

                src[RIDX(i, j + 1, dim)].blue +
                src[RIDX(i + 1, j + 1, dim)].blue)) /

                6);

        dst[RIDX(i, j, dim)] = current_pixel;
    }

    for (i = 1; i < dim - 1; i++)

    {
        for (j = 1; j < dim - 1; j++)

        {
            pcurrent_pixel->red =

                (unsigned short)(((int)(src[RIDX(i + 1, j, dim)].red +
                    src[RIDX(i + 1, j - 1, dim)].red +

                    src[RIDX(i, j, dim)].red +
                    src[RIDX(i - 1, j, dim)].red +

                    src[RIDX(i, j - 1, dim)].red +
                    src[RIDX(i - 1, j - 1, dim)].red +

                    src[RIDX(i, j + 1, dim)].red +
                    src[RIDX(i - 1, j + 1, dim)].red +

                    src[RIDX(i + 1, j + 1, dim)].red)) /

                    9);

            pcurrent_pixel->green =

                (unsigned short)(((int)(src[RIDX(i + 1, j, dim)].green +
                    src[RIDX(i + 1, j - 1, dim)].green +

                    src[RIDX(i, j, dim)].green +
                    src[RIDX(i - 1, j, dim)].green +

                    src[RIDX(i, j - 1, dim)].green +
                    src[RIDX(i - 1, j - 1, dim)].green +

                    src[RIDX(i, j + 1, dim)].green +
                    src[RIDX(i - 1, j + 1, dim)].green +

                    src[RIDX(i + 1, j + 1, dim)].green)) /

                    9);

            pcurrent_pixel->blue =

                (unsigned short)(((int)(src[RIDX(i + 1, j, dim)].blue +
                    src[RIDX(i + 1, j - 1, dim)].blue +

                    src[RIDX(i, j, dim)].blue +
                    src[RIDX(i - 1, j, dim)].blue +

                    src[RIDX(i, j - 1, dim)].blue +
                    src[RIDX(i - 1, j - 1, dim)].blue +

                    src[RIDX(i, j + 1, dim)].blue +
                    src[RIDX(i - 1, j + 1, dim)].blue +

                    src[RIDX(i + 1, j + 1, dim)].blue)) /

                    9);

            dst[RIDX(i, j, dim)] = current_pixel;
        }
    }
}

/*********************************************************************
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);

    add_smooth_function(&naive_smooth, naive_smooth_descr);

    add_smooth_function(&smooth_final, smooth_final_descr);

    /* ... Register additional test functions here */
}
