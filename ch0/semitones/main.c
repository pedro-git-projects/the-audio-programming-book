/*
 * This little music theory program calculates the interval between
 * two notes and prints its semitone lenght and name
 * We ask the user to input two notes, which we take in as characters
 * and then translate into numerical pitch classes (0–11).
 * The user is expected to separate the two note names by a ‘‘carriage return’’
 * character, or even a blank space.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum NumericalPitchClasses {
  C,
  Cb,
  D,
  Eb,
  E,
  F,
  Gg,
  G,
  A,
  Bb,
  B
} NumericalPitchClasses;

int main(void) {
  /*
   * characters will be stored sequentially in the buffer so:
   * buffer[0] = 'A'  // The first character of input
   * buffer[1] = '\n' // The newline from pressing Enter
   * buffer[2] = '\0' // Null terminator added by fgets
   */
  char buffer[3];
  char note1[3], note2[3];

  puts("Please enter two notes (e.g., A, Bb, G#):");

  printf("note 1: -> ");
  if (fgets(buffer, sizeof(buffer), stdin)) {
    strncpy(note1, buffer, 2);
    note1[2] = '\0';
    if (note1[1] == '\n')
      note1[1] = '\0';
  }

  printf("note 2: -> ");
  if (fgets(buffer, sizeof(buffer), stdin)) {
    strncpy(note2, buffer, 2);
    note2[2] = '\0';
    if (note2[1] == '\n')
      note2[1] = '\0';
  }

  printf("note 1: %s and note 2: %s\n", note1, note2);

  return EXIT_SUCCESS;
}
