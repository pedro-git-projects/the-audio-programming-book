/*
 * This little music theory program calculates the interval between
 * two notes and prints its semitone lenght and name
 * We ask the user to input two notes, which we take in as characters
 * and then translate into numerical pitch classes (0–11).
 * The user is expected to separate the two note names by a ‘‘carriage return’’
 * character, or even a blank space.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum NumericalPitchClasses {
  C,
  Db,
  D,
  Eb,
  E,
  F,
  Gb,
  G,
  Ab,
  A,
  Bb,
  B
} NumericalPitchClasses;

bool isNaturalNote(char note[4]) {
  return (note[1] == '\n' || note[1] == '\0');
}

void toUpperCase(char *noteName) { noteName[0] = toupper(noteName[0]); }

NumericalPitchClasses matchNote(char note[4]) {
  if (isNaturalNote(note)) {
    char noteName = note[0];
    switch (noteName) {
    case 'c':
    case 'C':
      return C;
    case 'd':
    case 'D':
      return D;
    case 'E':
    case 'e':
      return E;
    case 'F':
    case 'f':
      return F;
    case 'G':
    case 'g':
      return G;
    case 'A':
    case 'a':
      return A;
    case 'B':
    case 'b':
      return B;
    default:
      fprintf(stderr, "Invalid natural note: %c\n", noteName);
      exit(EXIT_FAILURE);
    }
  } else {
    char noteName[4] = "";
    strncpy(noteName, note, 2);
    noteName[2] = '\0';
    toUpperCase(noteName);

    if (strncmp(noteName, "Cb", 2) == 0)
      return Db;
    if (strncmp(noteName, "C#", 2) == 0)
      return Db;

    if (strncmp(noteName, "Eb", 2) == 0)
      return Eb;
    if (strncmp(noteName, "D#", 2) == 0)
      return Db;

    if (strncmp(noteName, "Gb", 2) == 0)
      return Gb;
    if (strncmp(noteName, "F#", 2) == 0)
      return Gb;

    if (strncmp(noteName, "Ab", 2) == 0)
      return Ab;
    if (strncmp(noteName, "G#", 2) == 0)
      return Ab;

    if (strncmp(noteName, "Bb", 2) == 0)
      return Bb;
    if (strncmp(noteName, "A#", 2) == 0)
      return Bb;

    fprintf(stderr, "Invalid accidental note: %s\n", noteName);
    exit(EXIT_FAILURE);
  }
}

void calculateIntervalModule12(NumericalPitchClasses pitch1,
                               NumericalPitchClasses pitch2) {
  int interval = pitch1 - pitch2;
  if (interval < 0)
    interval += 12;

  if (interval > 11)
    interval -= 12;

  printf("%d semitones up or %d semitones down\n", interval,
         interval ? 12 - interval : 0);
}

int main(void) {
  /*
   * characters will be stored sequentially in the buffer so:
   * buffer[0] = 'A'  // The first character of input
   * buffer[0] = '#'  // The second character of input
   * buffer[1] = '\n' // The newline from pressing Enter
   * buffer[2] = '\0' // Null terminator added by fgets
   */
  char buffer[4];
  char note1[4], note2[4];

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

  NumericalPitchClasses numNote1 = matchNote(note1);
  NumericalPitchClasses numNote2 = matchNote(note2);

  calculateIntervalModule12(numNote1, numNote2);

  return EXIT_SUCCESS;
}
