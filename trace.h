#ifndef hcx_trace_h
#define hcx_trace_h

#define hcx_trace(function) fprintf(stderr, "(hcx) " function "() in %s:%d\n", \
      __FILE__, __LINE__)

#define hcx_trace_exit(function) fprintf(stderr, "(hcx) "function "() in %s:%d\n", \
      __FILE__, __LINE__) exit(17);

#endif
