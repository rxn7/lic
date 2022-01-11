#include <stdio.h>
#include <stdlib.h>

static unsigned long count_lines(const char *file_path) {
	FILE *f = fopen(file_path, "r");
	if(!f) {
		fprintf(stderr, "Failed to open file `%s`.\n", file_path);
		exit(-1);
	}

	unsigned long count = 0;
	char c;
	while((c = fgetc(f)) != EOF) {
		if(c == '\n') {
			++count;
		}
	}

	fclose(f);

	return count;
}

int main(int argc, const char **argv) {
	for(unsigned int i=1; i<argc; ++i) {
		printf("%s: %lu\n", argv[i], count_lines(argv[1]));
	}
}
