# Number Guessing Game

A small command-line game written in standard C. The computer chooses a number from 1 to 100, and you try to guess it. It gives higher/lower hints and counts your guesses.

## Build

You need a C compiler such as GCC or Clang.

```sh
gcc -std=c11 -Wall -Wextra -pedantic main.c -o guessing-game
```

On Windows with MinGW, run the resulting program with:

```powershell
./guessing-game.exe
```

On macOS or Linux:

```sh
./guessing-game
```

## Play

Enter a number between 1 and 100. Type `q` to give up on the current round. Choose `y` when asked to start another round.

## License

This project is released into the public domain under [The Unlicense](https://unlicense.org/).
