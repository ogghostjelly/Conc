#include "file.h"

char *readFile(char *path, size_t *size)
{
	FILE *file = !!strcmp(path, "-") ? fopen(path, "r") : stdin;
	if(!file) return NULL;

	*size = 128;
	char *buf = malloc(*size);
	size_t off = 0;
	
	while (1) {
		if(!buf) return NULL;
		int bytes_read = fread(&buf[off], 1, *size-1, file);
		if(bytes_read == 0) break;
		off += bytes_read;
		buf = realloc(buf, *size *= 2);
	}

	fclose(file);
	return buf;
}
