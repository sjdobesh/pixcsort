#include <stdio.h>
#include <spng.h>
#include "../src/pix.h"

int main() {
  printf("loading spng\n");
  spng s;
  spng_load(&s, "./input/spookies-small.png");
  printf("loaded image. applying filter\n");

  orthogonal_sort((sort_info){
    .img_ref = &s,
    .vertical_sort = 0,
    .start_threshold = 0.018,
    .stop_threshold = 0.02,
    .random_start = 10,
    .random_stop = 10,
    .min_length = 40,
    .max_length = 300,
    .comparison_function = compare_brightness_less
   });

  printf("saving\n");
  spng_save(s, "./output/spooked.png");
  printf("freeing\n");
  spng_free(&s);
  printf("done\n");
  return 0;
}
