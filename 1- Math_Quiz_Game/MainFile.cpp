#include <iostream>
#include <cstdlib>
using namespace std;

// Vars
enum enQuestionLevel {
  Easy = 1,
  Med = 2,
  Hard = 3,
  Mix = 4,
};
enum enOperationType {
  Add = 1,
  Sub = 2,
  Mul = 3,
  Div = 4,
  MixOp = 5,
};
struct stQuestion {
  int Num1 = 0;
  int Num2 = 0;
  enQuestionLevel QuestionLevel;
  enOperationType OperationType;
  int PlayerAnswer;
  int CorrectAnswer;
  bool AnswerResult = false;
};
struct stQuez {
  stQuestion Questions[100];
  short NumOfQuestions = 0;
  enQuestionLevel QuestionsLevel;
  enOperationType OperationsType;
  short RightAnswers = 0;
  short WrongAnswers = 0;
  bool isPass = false;
};
/* FUNCTIONS */
// FROM LIBRARY
int ReadNumber(string Message) {
  int Number = 0;
  cout << Message << endl;
  cin >> Number;
  return Number;
}
short RandomNumber(int From, int To) { return rand() % (To - From + 1) + From; }
void ResetScreen() { system("cls"); }
// APP FUNCS
enQuestionLevel ReadQuestionsLevel() {
  short Level;
  do {
    cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
    cin >> Level;
  } while (Level < 1 || Level > 4);
  return (enQuestionLevel)Level;
}
enOperationType ReadOperationsType() {
  short OpType;
  cout
      << "Operation Type? ([Add: 1], [Sub: 2], [Mult: 3], [div: 4], [Mix: 5]) ";
  cin >> OpType;
  return (enOperationType)OpType;
}
enOperationType HandleRandomOperationType() {
  short Op = RandomNumber(1, 4);
  return (enOperationType)Op;
}
enQuestionLevel HandleRandomQuestionLevel() {
  short Lev = RandomNumber(1, 3);
  return (enQuestionLevel)Lev;
}

int SimpleCalculator(int Num1, int Num2, enOperationType OpType) {
  switch (OpType) {
    case enOperationType::Add:
      return Num1 + Num2;
    case enOperationType::Sub:
      return Num1 - Num2;
    case enOperationType::Mul:
      return Num1 * Num2;
    case enOperationType::Div:
      return Num1 / Num2;
    default:
      return Num1 + Num2;
  }
}
stQuestion CreateQuestion(stQuez Quez) {
  stQuestion Question;

  if (Quez.OperationsType == enOperationType::MixOp)
    Question.OperationType = HandleRandomOperationType();
  else
    Question.OperationType = Quez.OperationsType;

  if (Quez.QuestionsLevel == enQuestionLevel::Mix)
    Question.QuestionLevel = HandleRandomQuestionLevel();
  else
    Question.QuestionLevel = Quez.QuestionsLevel;

  switch (Question.QuestionLevel) {
    case enQuestionLevel::Easy:
      Question.Num1 = RandomNumber(1, 10);
      Question.Num2 = RandomNumber(1, 10);
      Question.CorrectAnswer = SimpleCalculator(Question.Num1, Question.Num2,
                                                Question.OperationType);
      return Question;
    case enQuestionLevel::Med:
      Question.Num1 = RandomNumber(10, 50);
      Question.Num2 = RandomNumber(10, 50);
      Question.CorrectAnswer = SimpleCalculator(Question.Num1, Question.Num2,
                                                Question.OperationType);
      return Question;
    case enQuestionLevel::Hard:
      Question.Num1 = RandomNumber(50, 100);
      Question.Num2 = RandomNumber(50, 100);
      Question.CorrectAnswer = SimpleCalculator(Question.Num1, Question.Num2,
                                                Question.OperationType);
      return Question;

    default:
      break;
  }
}
void CreateQuestionList(stQuez &Quez) {
  for (short Question = 0; Question < Quez.NumOfQuestions + 1; Question++) {
    Quez.Questions[Question] = CreateQuestion(Quez);
  }
}
string GetOpTypeSymbol(enOperationType OpType) {
  switch (OpType) {
    case enOperationType::Add:
      return "+";
    case enOperationType::Sub:
      return "-";
    case enOperationType::Mul:
      return "x";
    case enOperationType::Div:
      return "/";
    default:
      return "+";
  }
}
string GetLevelName(enQuestionLevel QLevel) {
  switch (QLevel) {
    case enQuestionLevel::Easy:
      return "Easy";
    case enQuestionLevel::Med:
      return "Midium";
    case enQuestionLevel::Hard:
      return "Hard";
    default:
      return "Easy";
  }
}
void CurrectTheQuestionAnswer(stQuez &Quez, int Question) {
  if (Quez.Questions[Question].CorrectAnswer ==
      Quez.Questions[Question].PlayerAnswer) {
    cout << "Answer is True :)\n";
    Quez.Questions[Question].AnswerResult = true;
    Quez.RightAnswers++;
  } else {
    cout << "Answer is Wrong :(\n"
         << "Right Answer is: " << Quez.Questions[Question].CorrectAnswer
         << "\n\n";
    Quez.Questions[Question].AnswerResult = false;
    Quez.WrongAnswers++;
  }
}
void AskAndCorrectQuestionListAnswers(stQuez &Quez) {
  for (int Question = 1; Question <= Quez.NumOfQuestions; Question++) {
    // print question
    cout << "\n";
    cout << "Question [" << Question << "/" << Quez.NumOfQuestions << "] \n\n";
    cout << Quez.Questions[Question].Num1 << endl;
    cout << Quez.Questions[Question].Num2 << " ";
    cout << GetOpTypeSymbol(Quez.Questions[Question].OperationType);
    cout << "\n_________" << endl;
    // get player answer
    Quez.Questions[Question].PlayerAnswer = ReadNumber("");
    CurrectTheQuestionAnswer(Quez, Question);
  }
}
string IsPassed(stQuez Quez) {
  if (Quez.RightAnswers >= Quez.WrongAnswers)
    return "Pass :)";
  else
    return "Fail :(";
}
void PrintQuezResults(stQuez Quez) {
  cout << "__________________________\n\n";
  cout << "   Final Results is " << IsPassed(Quez) << "\n";
  cout << "__________________________\n\n";
  cout << "Number of questions: " << Quez.NumOfQuestions << endl;
  cout << "Questions Level: " << GetLevelName(Quez.QuestionsLevel) << endl;
  cout << "Operations type: " << GetOpTypeSymbol(Quez.OperationsType) << endl;
  cout << "Number of right answer: " << Quez.RightAnswers << endl;
  cout << "Number of wrong answer: " << Quez.WrongAnswers << endl;
  cout << "__________________________\n";
}
void PlayGame(stQuez Quez) {
  Quez.NumOfQuestions = ReadNumber("Enter The Number Of Questions!");
  Quez.QuestionsLevel = ReadQuestionsLevel();
  Quez.OperationsType = ReadOperationsType();

  CreateQuestionList(Quez);
  AskAndCorrectQuestionListAnswers(Quez);
  PrintQuezResults(Quez);
}
void StartGame() {
  stQuez Quez;
  bool again = true;
  do {
    ResetScreen();
    PlayGame(Quez);
    cout << "Do you want to play again? ([1] Yes, [0] No)\n";
    cin >> again;
  } while (again == 1);
}
int main() {
  srand((unsigned)time(NULL));
  StartGame();
  cout << "\n***************\n";
  return 0;
}