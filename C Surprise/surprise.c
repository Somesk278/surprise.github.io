#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void loadBar() {

  const int LOADING_ARRAY = 61; // Size of the array that represents the loading bar. The extra 1 is for the null terminating character
  const int LOADING_BAR_SIZE = LOADING_ARRAY - 1; // The size of the actual loading bar

  char loadingBar[LOADING_ARRAY];  // Create the character array
  memset(loadingBar, ' ', LOADING_BAR_SIZE*sizeof(char)); // Fill the loading bar with spaces
  loadingBar[LOADING_BAR_SIZE] = '\0'; // Null terminating character

  srand(time(0)); // Set up to be able to generate random numbers

  int numA =  rand() % (40 - 19) + 20; // Random number between 20 and 40 representing number of a's in loading bar

  // Iterate through loading bar
  for(int i = 0; i < LOADING_BAR_SIZE; i++) {
    // Fill numA amount of loading bar with a's, then fill rest with h's
    if(i < numA) {
      loadingBar[i] = 'a';
    } else {
      loadingBar[i] = 'h';
    }

    /*
      Print out entire loadingBar, then on another iteration, carriage return (\r), and reprint/overwrite previous bar with updated loadingBar array
      In other words, in first iteration, the bar is:
      Loading: [a           ] |    1%[cursor]

      Then, on the next iteration, the cursor is moved back to the front of the  line:
      [cursor]Loading: [a           ] |    1%

      The whole line is then overwritten with the new loadingBar array data so it looks like this:
      Loading: [aa          ] |    3%[cursor]

      This repeats till it's all the whole thing is iterated through
    */
    printf("\rLoading: [%s] | %3d%%\0",loadingBar, ((i+1)*100) / LOADING_BAR_SIZE);
    fflush(stdout); // Need to do this so that it actually prints out during the iterations, instead of just waiting until everything ends to print out the finished product

    int sleepTime = rand() % 500001; // Choose a random number between 0 and 0.25 seconds. Apparently doing it this way with just the modulo creates some skew towards certain numbers, but I really don't care
    usleep(sleepTime); // Sleep for sleepTime seconds
  }
  usleep(1000000);

  putchar('\n'); // Newline to not mess up how everything looks
}

void openPage() {
  // Countdown to surprise
  for(int i = 5; i >= 0; i--) {
    printf("\rOpening surprise in %d", i);
    fflush(stdout);
    usleep(1000000);
  }

  putchar('\n'); // We love newlines

  system("explorer https://htmlpreview.github.io/?https://github.com/Somesk278/Dakota-Birthday/blob/master/HTML%20Surprise/index.html"); // Open surprise
}

int main() {
  loadBar(); // Display download bar
  printf("Loading complete.\n");
  usleep(1000000);
  openPage(); // Countdown to surprise
  return 0;
}
