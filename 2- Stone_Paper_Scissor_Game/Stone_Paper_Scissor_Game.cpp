#include <iostream>
using namespace std;

enum enStuff { Stone = 1, Paper = 2, Scissor = 3 };
enum enResult { Win = 1, Lose = -1, Draw = 0 };
int RandomNumber(int From, int To) { return rand() % (To - From + 1) + From; }
int ReadPozitifNumber(string Message) {
  int Number = 0;
  do {
    cout << Message << endl;
    cin >> Number;
  } while (Number <= 0);
  return Number;
}

int CheckResult(int PlayerStuff, int CoumputerStuff, int Info[4]) {
  switch (PlayerStuff) {
    case enStuff::Stone:
      if (CoumputerStuff == enStuff::Stone) {
        Info[3]++;
        return 0;
      }
      if (CoumputerStuff == enStuff::Paper) {
        Info[2]++;
        return -1;
      }
      if (CoumputerStuff == enStuff::Scissor) {
        Info[1]++;
        return 1;
      }
    case enStuff::Paper:
      if (CoumputerStuff == enStuff::Stone) {
        Info[1]++;
        return 1;
      }
      if (CoumputerStuff == enStuff::Paper) {
        Info[3]++;
        return 0;
      }
      if (CoumputerStuff == enStuff::Scissor) {
        Info[2]++;
        return -1;
      }
    case enStuff::Scissor:
      if (CoumputerStuff == enStuff::Stone) {
        Info[2]++;
        return -1;
      }
      if (CoumputerStuff == enStuff::Paper) {
        Info[1]++;
        return 1;
      }
      if (CoumputerStuff == enStuff::Scissor) {
        Info[3]++;
        return 0;
      }
    default:
      return 0;
  }
}
void ViewRoundResult(int Result, int PlayerStuff, int CoumputerStuff,
                     int Info[4]) {
  cout << "Your Choice     => " << PlayerStuff << endl;
  cout << "Computer Choice => " << CoumputerStuff << endl;
  if (Result == enResult::Win) {
    cout << "You Win!";
  } else if (Result == enResult::Lose) {
    cout << "You Lose!";
  } else if (Result == enResult::Draw) {
    cout << "You Draw!";
  }
}

void PlayRound(int Info[4]) {
  int PlayerStuff, CoumputerStuff;
  do {
    cout << "Enter stuff (Stone: 1, Paper: 2, Scissor: 3)\n";
    cin >> PlayerStuff;
  } while (PlayerStuff < 1 || PlayerStuff > 3);
  CoumputerStuff = RandomNumber(1, 3);
  ViewRoundResult(CheckResult(PlayerStuff, CoumputerStuff, Info), PlayerStuff,
                  CoumputerStuff, Info);
}
void PlayMultipleRounds(int Info[4]) {
  for (int i = 0; i < Info[0]; i++) {
    cout << "\n  _____________[ " << i + 1 << " ]____________\n";
    PlayRound(Info);
    cout << "\n  ______________________________\n";
  }
}
void ShowGameResults(int Info[4]) {
  string Winner;
  if (Info[1] > Info[2])
    Winner = "Player";
  else if (Info[1] < Info[2])
    Winner = "Computer";
  else
    Winner = "No Winner";
  cout << "==============================================================\n";
  cout << "                      +++ Game Over +++                       \n";
  cout << "==============================================================\n";
  cout << "======================[ Game Results ]========================\n";
  cout << "Game Rounds       : " << Info[0] << endl;
  cout << "Player1 won times : " << Info[1] << endl;
  cout << "Computer won times: " << Info[2] << endl;
  cout << "Draw times        : " << Info[3] << endl;
  cout << "Final Winner      : " << Winner << endl;
  cout << "==============================================================\n";
}
int main() {
  srand((unsigned)time(NULL));
  // Number of [Rounds , Player won, Computer won, Draw times]
  int Info[4] = {0, 0, 0, 0};
  bool again = true;
  do {
    Info[0] = ReadPozitifNumber("How many rounds do you want to play?");
    PlayMultipleRounds(Info);
    ShowGameResults(Info);
    cout << "Do you Want to Play again? (yes: 1, no: 0)\n";
    cin >> again;
  } while (again);
  return 0;
}