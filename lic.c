#include <stdio.h>
#include <sys/stat.h>

static long count_lines(const char *file_path) {
	FILE *f = fopen(file_path, "r");
	if(!f) {
		fprintf(stderr, "Failed to open file `%s`.\n", file_path);
		return -1;
	}

	struct stat path_stat;
	stat(file_path, &path_stat);
	if(S_ISDIR(path_stat.st_mode)) {
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
	/* If the user didn't specify any file */
	if(argc < 2) {
		printf("Usage: `lic <file(s)>`\n");
		return -1;
	}

	long count;
        unsigned int total = 0;
	
        for(unsigned int i = 1; i<argc; ++i) {
		count = count_lines(argv[i]);

		/* Continue if file failed to load */
		if(count == -1) continue;

		total += count;
		printf("%s: %lu lines\n", argv[i], count);
	}

	/* Print total lines only if at least 2 files were specified */
	if(argc > 2) {
		printf("\nTotal lines: %u\n", total);
	}
}
