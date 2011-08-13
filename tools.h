#ifndef hcx_tools_h
#define hcx_tools_h

#define hcx_tools_trace(function) fprintf(stderr, function "() in %s:%d\n", \
      __FILE__, __LINE__)

#define hcx_tools_trace_exit(function) fprintf(stderr,        \
      function "() in %s:%d\n", __FILE__, __LINE__) exit(17);

#endif
