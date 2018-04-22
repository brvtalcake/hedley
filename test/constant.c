#include <assert.h>
#include <stddef.h>

#include "../hedley.h"

int main(int argc, char* argv[HEDLEY_ARRAY_PARAM(argc)]) {
  char foo[HEDLEY_REQUIRE_CONSTEXPR(42)] = { 0, };

  assert(argv[argc - 1] != NULL);
  assert(foo[0] == 0);

#if defined(HEDLEY__IS_CONSTEXPR)
  assert(HEDLEY_IS_CONSTANT(1729) == 1);
#else
  assert(HEDLEY_IS_CONSTANT(1729) == 0);
#endif

  assert(HEDLEY_IS_CONSTANT(argc) == 0);

  return 0;
}
