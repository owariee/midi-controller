#ifdef AVR // or whatever -- check the compiler docs, I don't know the standard way to check this offhand
# define NO_CSTDINT 1  // AVR arduino has no <cstdint>; but we're coding to portable C++. So substitute.
#endif

// unless we know otherwise, use the compiler's <cstdint>
#ifndef NO_CSTDINT
# include <cstdint>
#else
// no <cstdint> -- make sure std:: contains the things we need.
# include <stdint.h>

namespace std {
  using ::int8_t;             
  using ::uint8_t;            
                     
  using ::int16_t;            
  using ::uint16_t;           
                     
  using ::int32_t;            
  using ::uint32_t;           
}

#endif
