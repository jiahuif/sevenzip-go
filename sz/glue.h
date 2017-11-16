
#include "libc7zip.h"

#ifdef GLUE_IMPLEMENT
#define GLUE 
#else
#define GLUE extern
#endif

#define DECLARE(x) GLUE x##_t x##_;

int libc7zip_initialize();

// lib_new
typedef lib *(*lib_new_t)();
DECLARE(lib_new)
lib *libc7zip_lib_new();

// lib_free
typedef void (*lib_free_t)(lib *l);
DECLARE(lib_free)
void libc7zip_lib_free(lib *l);

// in_stream_new
typedef in_stream *(*in_stream_new_t)();
DECLARE(in_stream_new)
in_stream *libc7zip_in_stream_new();

// in_stream_get_def
typedef in_stream_def *(*in_stream_get_def_t)();
DECLARE(in_stream_get_def)
in_stream_def *libc7zip_in_stream_get_def(in_stream *s);

// in_stream_free
typedef void (*in_stream_free_t)(in_stream *is);
DECLARE(in_stream_free)
void libc7zip_in_stream_free(in_stream *is);

// archive_open
typedef archive *(*archive_open_t)(lib *l, in_stream *s);
DECLARE(archive_open)
archive *libc7zip_archive_open(lib *l, in_stream *s);

// archive_get_item_count
typedef int64_t (*archive_get_item_count_t)(archive *a);
DECLARE(archive_get_item_count)
int64_t libc7zip_archive_get_item_count(archive *a);
