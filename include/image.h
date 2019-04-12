#ifndef IMAGE_H
#define IMAGE_H

#include <stdlib.h>
#include <stdio.h>

#define DRK_CH_WND_WT 5 //should be an odd number
#define DRK_CH_WND_HT 5 //should be an odd number

#define MAX(x,y) ((x)<=(y)? (y):(x))
#define MIN(x,y) ((x)<=(y)? (x):(y))

#ifdef _MSC_VER
#ifdef SDK_EXPORTS
#define CV_SDK_API_ __declspec(dllexport)
#else
#define CV_SDK_API_
#endif
#else /* _MSC_VER */
#ifdef SDK_EXPORTS
#define CV_SDK_API_ __attribute__((visibility("default")))
#else
#define CV_SDK_API_
#endif
#endif

#ifdef __cplusplus
#define CV_SDK_API extern "C" CV_SDK_API_
#else
#define CV_SDK_API CV_SDK_API_
#endif

struct pix_t
{
    int w;
    int h;
};

struct arry_pix_t
{
    unsigned long int num_of_pixs;
    struct pix_t *elm;
};

struct img_t
{
    int wt;
    int ht;
    unsigned char **data;
};

struct img_rgb_t
{
    int wt;
    int ht;

    unsigned char **r;
    unsigned char **g;
    unsigned char **b;
};

struct img_yuv_t
{
    int wt;
    int ht;

    unsigned char **y;
    unsigned char **u;
    unsigned char **v;
};

struct map_t
{
    int wt;
    int ht;
    double **data;
};

struct map_rgb_t
{
    int wt;
    int ht;
    double **r;
    double **g;
    double **b;
};

struct map_yuv_t
{
    int wt;
    int ht;
    double **y;
    double **u;
    double **v;
};

struct clr_t
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

// function prototype
#ifdef __cplusplus
extern "C" {
#endif

CV_SDK_API_
struct arry_pix_t *
arry_pix_create
(
    unsigned long num_of_pixs
);
CV_SDK_API_
void
arry_pix_destruct
(
    struct arry_pix_t *arry_pix
);
CV_SDK_API_
unsigned char **
Malloc2D_uchr
(
    int wt,
    int ht,
    unsigned char init
);
CV_SDK_API_
double **
Malloc2D_dbl
(
    int wt,
    int ht,
    double init
);
CV_SDK_API_
struct img_t *
img_create
(
    int wt,
    int ht,
    unsigned char init
);
CV_SDK_API_
void
img_destruct
(
    struct img_t *img
);

CV_SDK_API_
struct img_rgb_t *
img_rgb_create
(
    int wt,
    int ht,
    unsigned char init
);

CV_SDK_API_
void
img_rgb_destruct
(
    struct img_rgb_t *img
);
CV_SDK_API_
struct img_yuv_t *
img_yuv_create
(
    int wt,
    int ht,
    unsigned char init
);
CV_SDK_API_
void
img_yuv_destruct
(
    struct img_yuv_t *img
);
CV_SDK_API_
struct map_t *
map_create
(
    int wt,
    int ht,
    double init
);
CV_SDK_API_
void
map_destruct
(
    struct map_t *map
);
CV_SDK_API_
struct map_rgb_t *
map_rgb_create
(
    int wt,
    int ht,
    double init
);
CV_SDK_API_
void
map_rgb_destruct
(
    struct map_rgb_t *map
);
CV_SDK_API_
struct map_rgb_t *
img_to_map_rgb
(
    struct img_rgb_t *in
);
CV_SDK_API_
struct img_rgb_t *
map_to_img_rgb
(
    struct map_rgb_t *map
);
CV_SDK_API_
struct img_yuv_t *
img_rgb_to_yuv
(
    struct img_rgb_t *img_rgb
);

// dehaze
CV_SDK_API_
struct img_rgb_t *
Dehaze
(
    struct img_rgb_t *in,
    double omega,
    double t0,
    double p
);

#ifdef __cplusplus
}
#endif

#endif // IMAGE_H
