#include <cstdio>
#include <cstdlib>
#include <cstring>

// Renders a stored report.
//
// Added on a branch so the pull request has findings of its own.

void renderReport(const char *customer) {
  char path[64];

  // No bound: a long customer name runs off the end of path.
  strcpy(path, "/var/reports/");
  strcat(path, customer);

  char command[256];
  sprintf(command, "cat %s", path);

  // The caller's text reaches a shell.
  system(command);
}

int reportMain(int argc, char **argv) {
  if (argc > 1) {
    renderReport(argv[1]);
  }
  return 0;
}
