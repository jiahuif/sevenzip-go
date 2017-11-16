
#ifndef LIBC7ZIP_H
#define LIBC7ZIP_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct lib;
typedef struct lib lib;
lib *lib_new();
void lib_free(lib *l);

typedef int (*read_cb_t)(int64_t id, void *data, int64_t size, int64_t *processed_size);
typedef int (*seek_cb_t)(int64_t id, int64_t offset, int32_t whence, int64_t *new_position);
typedef int (*write_cb_t)(int64_t id, const void *data, int64_t size, int64_t *processed_size);

typedef struct in_stream_def {
  int64_t id;
	seek_cb_t seek_cb;
	read_cb_t read_cb;
  char *ext;
  int64_t size;
} in_stream_def;

typedef struct out_stream_def {
  int64_t id;
	seek_cb_t seek_cb;
  write_cb_t write_cb;
} out_stream_def;

struct in_stream;
typedef struct in_stream in_stream;
in_stream *in_stream_new();
in_stream_def *in_stream_get_def(in_stream *is);
void in_stream_free(in_stream *is);

struct out_stream;
typedef struct out_stream out_stream;
out_stream *out_stream_new();
out_stream_def *out_stream_get_def(out_stream *s);
void out_stream_free(out_stream *s);

struct archive;
typedef struct archive archive;
archive *archive_open(lib *l, in_stream *is);
int64_t archive_get_item_count(archive *a);

struct item;
typedef struct item item;
item *archive_get_item(archive *a, int64_t index);
void archive_item_free(item *i);
int archive_extract(archive *a, item *i, out_stream *os);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIBC7ZIP_H