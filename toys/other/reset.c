/* reset.c - reset the terminal.
 *
 * Copyright 2015 Rob Landley <rob@landley.net>
 *
 * No standard.

USE_RESET(NEWTOY(reset, 0, TOYFLAG_USR|TOYFLAG_BIN))

config RESET
  bool "reset"
  default y
  help
    usage: reset

    Reset the terminal.
*/
#include "toys.h"

void reset_main(void)
{
  int fd = tty_fd_tb();

  // man 4 console_codes: reset terminal is ESC (no left bracket) c
  // DEC private mode set enable wraparound sequence.
  xwrite(fd<0 ? 1 : fd, "\033c\033[?7h", 2);
}
