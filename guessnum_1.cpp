#include <cstdlib>

#include <time.h>

#include <iostream>



using namespace std;



int main() {

      srand(time(0));

      int number;

      number = rand() % 1000 + 1; // it generates the random number between 1-1000

      int guess;

      do {

            cout << "Enter the number you guess: ";

            cin >> guess;

            if (guess < number)

                  cout << "Your guess is less than the secret number" << endl;

            else if (guess > number)

                  cout << "Your guess is more than the secret number" << endl;

            else

                  cout << "you guessed the right number!" << endl;

      }while (guess != number);

      system("PAUSE");

      return 0;

}
