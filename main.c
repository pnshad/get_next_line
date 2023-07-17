#include "get_next_line.h"
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_DIR "tests/"

int check_file(char* filename) {
  int fd = open(filename, O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  char* line;
  while ((line = get_next_line(fd)) != NULL) {
    // can do more checks on each line here
    free(line);
  }

  close(fd);

  // Check for leaks
  system("leaks a.out");

  return 0;
}

int main() {

  DIR* dir = opendir(TEST_DIR);
  if (!dir) {
    perror("opendir");
    return 1;
  }

  struct dirent* ent;
  while ((ent = readdir(dir)) != NULL) {
    if (ent->d_type == DT_REG) { // regular file
      char path[1024];
      sprintf(path, "%s%s", TEST_DIR, ent->d_name);

      int result = check_file(path);
      if (result != 0) {
        printf("Failed on %s\n", path);
        closedir(dir);
        return result;
      }
    }
  }

  closedir(dir);

  return 0;
}
