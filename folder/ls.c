#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>   // Required for struct stat and S_ISDIR/S_ISREG
#include <string.h>     // Required for string operations if needed
#include <unistd.h>     // Required for isatty()

int main(int argc, char *argv[]) {
  const char *path = (argc > 1) ? argv[1] : ".";

  DIR *dir = opendir(path);

  printf("%s \n", path);
  if (!dir) {
    perror("opendir");
    return 1;
  }
  const char *BLUE = "\033[1;34m";
  const char *GREEN = "\033[1;32m";
  const char *WHITE = "\033[1;37m";
  const char *RESET = "\033[0m";

  int use_color = isatty(STDOUT_FILENO);

  struct dirent *entry;
  struct stat path_stat;
  char full_path[1024];

  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_name[0] == '.')
      continue;
    snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

    if (stat(full_path, &path_stat) == 0) {
      
      if (S_ISDIR(path_stat.st_mode)) {
       
        if (use_color) printf("%s%s%s/%s\n", BLUE, entry->d_name, WHITE, RESET);
        else printf("%s/\n", entry->d_name);
      } 
      else if (S_ISREG(path_stat.st_mode)) {
        
        if (use_color) printf("%s%s%s*%s\n", GREEN, entry->d_name, WHITE, RESET);
        else printf("%s*\n", entry->d_name);
      } 
      else {
        printf("%s\n", entry->d_name);
      }
      
    } else {
    
      printf("%s\n", entry->d_name);
    }
  }

  closedir(dir);
  return 0;
}
