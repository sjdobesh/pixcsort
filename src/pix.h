#ifndef _PIX_H_
#define _PIX_H_
#include "spng.h"

/* declare sort parameters */
typedef struct sort_info {
  spng* img_ref; /* image to sort */
  unsigned vertical_sort:1; /* boolean for vert or horiz sort */
  float angle; /* angle to sort along (0-2 Pi) */
  float start_threshold, stop_threshold; /* controls what gets sorted */
  int random_start, random_stop; /* random amount to dither threshold by */
  int min_length, max_length; /* minimum and maximum sorted length */
  int (*comparison_function)(const void*, const void*); /* sort function */
  int (*threshold_function)(const void*, float); /* determines what to sort */
} sort_info;

/* pixel comparison function */ 
int compare_brightness_greater(const void*, const void*, int);

/* vert horiz sort */
void orthogonal_sort(sort_info);

#endif /* _PIX_H_ */
