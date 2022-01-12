#include <stdio.h>
#include <stdlib.h>

static long count_lines(const char *file_path) {
	FILE *f = fopen(file_path, "r");
	if(!f) {
		fprintf(stderr, "Failed to open file `%s`.\n", file_path);
		return -1;
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
        unsigned int total = 0; 
	long count;
	unsigned int i = 1;
	
        for(; i<argc; ++i) {
		count = count_lines(argv[i]);

		if(count == -1) {
			continue;
		}

		total += count;
		printf("%s: %lu\n", argv[i], count);
	}

	if(i > 2) {
		printf("\ntotal lines: %u\n", total);
	}
}
