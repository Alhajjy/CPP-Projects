#include <iostream>  // For standard input/output (cin, cout)
#include <string>    // For string class and string operations
#include <fstream>  // For file stream operations (ifstream, ofstream)
#include <iomanip>  // For output formatting (setw, setprecision, etc.)
#include <vector>    // For dynamic array implementation (vector container)

using namespace std;
/* GLOBAL VARIBALES */
const string FileName = "Playlists.txt";
const string Seperator = "_~_";
void PauseProgram() {
  cout << "\nPress Enter to exit...";
  cin.ignore();
  cin.get();
}
/* MOST USED */
struct stPlaylist {
  string PlaylistNumber;
  string Title;
  string Topic;
  string Description;
  int VideoCount;
  string Url;
  string ChannelName;
  int Year;
};
bool VerifyDecision(string Message) {
  bool bl = false;
  cout << "Are You Sure To " << Message << " (0, 1):" << endl;
  cin >> bl;
  return bl;
}
vector<string> SplitString(string Text) {
  vector<string> vWords;
  int pos = 0;
  string sWord;
  while ((pos = Text.find(Seperator)) != std::string::npos) {
    sWord = Text.substr(0, pos);
    if (sWord != "") vWords.push_back(sWord);
    Text.erase(0, pos + Seperator.length());
  }
  if (Text != "") vWords.push_back(Text);
  return vWords;
}
stPlaylist ConverLineToRecord(string Line) {
  stPlaylist item;
  vector<string> vitem = SplitString(Line);

  while (vitem.size() < 8) vitem.push_back("");  // ÊÃßÏ Ãä Ýíå 8 ÚäÇÕÑ

  item.PlaylistNumber = vitem[0];
  item.Title = vitem[1];
  item.Topic = vitem[2];
  item.Description = vitem[3];
  item.VideoCount = vitem[4] != "" ? stoi(vitem[4]) : -1;
  item.Url = vitem[5];
  item.ChannelName = vitem[6];
  item.Year = vitem[7] != "" ? stoi(vitem[7]) : -1;
  return item;
}

vector<stPlaylist> LoaditemsDataFromFile(string FileName) {
  vector<stPlaylist> vcPlaylist;
  fstream MyFile;
  MyFile.open(FileName, ios::in);
  if (MyFile.is_open()) {
    string line;
    stPlaylist item;
    while (getline(MyFile, line)) {
      item = ConverLineToRecord(line);
      vcPlaylist.push_back(item);
    }
    MyFile.close();
  }
  return vcPlaylist;
}
string PrintRecordInLine(stPlaylist item) {
  string itemRecord;
  itemRecord += item.PlaylistNumber + Seperator;
  itemRecord += item.Title + Seperator;
  itemRecord += item.Topic + Seperator;
  itemRecord += item.Description + Seperator;
  itemRecord += to_string(item.VideoCount) + Seperator;
  itemRecord += item.Url + Seperator;
  itemRecord += item.ChannelName + Seperator;
  itemRecord += to_string(item.Year);
  return itemRecord;
}
void PrintRecord(stPlaylist item) {
  cout << "\n\nPlaylist:\n";
  cout << "\nPlaylist Number:  " << item.PlaylistNumber;
  cout << "\nTitle:  " << item.Title;
  cout << "\nTopic:  " << item.Topic;
  cout << "\nDescription:  " << item.Description;
  cout << "\nVideo Count:  " << item.VideoCount;
  cout << "\nUrl:  " << item.Url;
  cout << "\nChannel:  " << item.ChannelName;
  cout << "\nYear:  " << item.Year << endl << endl;
}
void SaveVectorDataToFile(vector<stPlaylist> vcPlaylist) {
  fstream MyFile;
  MyFile.open(FileName, ios::out);
  if (MyFile.is_open()) {
    string DataLine;
    for (short i = 0; i < vcPlaylist.size(); i++) {
      DataLine = PrintRecordInLine(vcPlaylist[i]);
      MyFile << DataLine;
      if (i != vcPlaylist.size() - 1) MyFile << endl;
    }
  }
  MyFile.close();
  cout << "___________________________________________________________\n";
}
stPlaylist ReadPlaylistData(string PlaylistNumber = "",
                            bool SkipPlaylistNumber = 0) {
  stPlaylist Playlist;
  if (SkipPlaylistNumber == 0) {
    cout << "Playlist UNIQE Number?  ";
    getline(cin >> ws, Playlist.PlaylistNumber);
  } else {
    Playlist.PlaylistNumber = PlaylistNumber;
  }
  cout << "Playlist Title?  ";
  getline(cin >> ws, Playlist.Title);
  cout << "Topic?  ";
  getline(cin, Playlist.Topic);
  cout << "Description?  ";
  getline(cin, Playlist.Description);
  cout << "How Many Videos in Playlist?  ";
  cin >> Playlist.VideoCount;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Url?  ";
  getline(cin, Playlist.Url);
  cout << "Channel Name?  ";
  getline(cin, Playlist.ChannelName);
  cout << "Year Created?  ";
  cin >> Playlist.Year;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "---------\n";
  return Playlist;
};
string AskPlaylistNumber(string Message) {
  string EnteredNumber;
  cout << Message;
  cin >> EnteredNumber;
  return EnteredNumber;
}
bool FindPlaylistByNumber(vector<stPlaylist> vcPlaylist, string EnteredNumber) {
  for (stPlaylist playlist : vcPlaylist) {
    if (EnteredNumber == playlist.PlaylistNumber) {
      return 1;
    }
  }
  return 0;
}
/* OPERATOINS */
// show all 1
void HandleTableHeader() {
  cout << "\n===================== PLAYLISTS =====================\n\n";
  cout << left << setw(6) << "Num" << setw(18) << "Title" << setw(15) << "Topic"
       << setw(30) << "Description" << setw(8) << "Videos" << setw(25) << "URL"
       << setw(18) << "Channel" << setw(6) << "Year" << endl << endl;
}
void PrintPlaylistInTable(stPlaylist List) {
  auto truncate = [](string s, size_t len) {
    return (s.size() > len) ? s.substr(0, len - 3) + "..." : s;
  };

  cout << left << setw(6) << List.PlaylistNumber << setw(18)
       << truncate(List.Title, 17) << setw(15) << truncate(List.Topic, 14)
       << setw(30) << truncate(List.Description, 29) << setw(8)
       << List.VideoCount << setw(25) << truncate(List.Url, 24) << setw(18)
       << truncate(List.ChannelName, 17) << setw(6) << List.Year << endl;
}
void HandleTableContent(vector<stPlaylist> vcPlaylist) {
  for (stPlaylist List : vcPlaylist) {
    PrintPlaylistInTable(List);
  }
    cout << "\n\n\n";
}
void ShowAllPlaylists(vector<stPlaylist> vcPlaylist) {
  HandleTableHeader();
  HandleTableContent(vcPlaylist);
}
// create 2
void AddPlaylist(string Payload) {
  fstream MyFile;
  MyFile.open(FileName, ios::out | ios::app);

  if (MyFile.is_open()) {
    MyFile << "\n" << Payload;
  }
  MyFile.close();
}
void AddPlaylists() {
  bool again = 1;
  while (again) {
    system("cls");
    AddPlaylist(PrintRecordInLine(ReadPlaylistData()));
    cout << "Playlist Record Saved Successfully\n";
    cout << "Do you want to add another Playlist? (1, 0): ";
    cin >> again;
  }
  cout << "___________________________________________________________\n";
}
/*
    update 3
*/
void UpdatePlaylist(vector<stPlaylist> &vcPlaylist) {
  vector<stPlaylist> CopyVcPlaylist;
  string EnteredNumber =
      AskPlaylistNumber("Enter a playlist number to update..  ");
  // search
  if (FindPlaylistByNumber(vcPlaylist, EnteredNumber)) {
    // update
    for (stPlaylist List : vcPlaylist) {
      if (EnteredNumber == List.PlaylistNumber) {
        PrintRecord(List);
        if (VerifyDecision("Update This Playlist?")) {
          CopyVcPlaylist.push_back(ReadPlaylistData(EnteredNumber, 1));
          cout << "Updated Successfully!" << endl;
        } else {
          CopyVcPlaylist.push_back(List);
          cout << "Ok man:)" << endl;
        }
      } else {
        CopyVcPlaylist.push_back(List);
      }
    }
    SaveVectorDataToFile(CopyVcPlaylist);
  } else {
    cout << "This Playlist Not Found, Try to write Number it again!" << endl;
  }
}
/*
    delete 4
*/
void DeletePlaylist(vector<stPlaylist> &vcPlaylist) {
  vector<stPlaylist> CopyVcPlaylist;
  string EnteredNumber =
      AskPlaylistNumber("Enter a playlist number to update..  ");
  // search
  if (FindPlaylistByNumber(vcPlaylist, EnteredNumber)) {
    // delete
    for (stPlaylist Playlist : vcPlaylist) {
      if (Playlist.PlaylistNumber != EnteredNumber) {
        CopyVcPlaylist.push_back(Playlist);
      }
    }
    // save to file
    SaveVectorDataToFile(CopyVcPlaylist);
    cout << "Deleted Successfully!\n";
  } else {
    cout << "Playlist Not Found!";
  }
}
/*
    search 5
*/
bool SearchPlaylist(vector<stPlaylist> vcPlaylist) {
  bool again = true;
  while (again) {
    string EnteredNumber =
        AskPlaylistNumber("Enter a playlist number to search..  ");
    for (stPlaylist List : vcPlaylist) {
      if (EnteredNumber == List.PlaylistNumber) {
        cout << "Playlist is Exist:" << endl;
        PrintRecord(List);
        return 0;
      }
    }
    cout << "Playlist with " << EnteredNumber
         << " doesn`t exist! Want to Try again? (0, 1)" << endl;
    cin >> again;
  }
  return 1;
}
/* MAIN */
void MainScreen(vector<stPlaylist> vcPlaylist) {
  // cout << "\n\nWelcome to Playlist Manager\n";
  cout << "\033[90m";  // background
  cout << "\033[1m";   // bold
  cout << "\033[47m";  // color
  cout << "*********************************************\n";
  cout << "*     Welcome to Playlist Manager           *\n";
  cout << "*********************************************\n";
  cout << "\033[40m";
  cout << "\033[0m";  // reser all
  cout << "\nThere is " << vcPlaylist.size() << " Playlist:" << endl;
  cout << "Choose the Operation You Need to Do..:" << endl;
  cout << "\033[35m";
  cout << "1) Show All Playlists\n";
  cout << "\033[32m";
  cout << "2) Create New Playlist\n";
  cout << "\033[34m";
  cout << "3) Update Playlist\n";
  cout << "\033[31m";
  cout << "4) Delete Playlist\n";
  cout << "\033[36m";
  cout << "5) Search Playlist\n";
  cout << "\033[31m";
  cout << "6) Quit Program\n";
  cout << "\033[0m";  // reset all
}
short ChooseOperation() {
  short num = 0;
  do {
    cout << "\nEnter (1, 2, 3 ,4, 5, 6)" << endl;
    cin >> num;
  } while (num < 1 || num > 6);
  return num;
}
void HandleOperation(vector<stPlaylist> &vcPlaylist, short variable,
                     bool &quitFlag) {
  system("cls");
  switch (variable) {
    case 1:
      // show all
      ShowAllPlaylists(vcPlaylist);
      break;
    case 2:
      // create
      AddPlaylists();
      break;
    case 3:
      // update
      UpdatePlaylist(vcPlaylist);
      break;
    case 4:
      // delete
      DeletePlaylist(vcPlaylist);
      break;
    case 5:
      // search
      SearchPlaylist(vcPlaylist);
      break;
    case 6:
      // quit
      quitFlag = true;
      return;
    default:
      cout << "Invalid option!" << endl;
      PauseProgram();
  }
}
// APP
void App() {
  vector<stPlaylist> vcPlaylist = LoaditemsDataFromFile(FileName);
  bool QuitProgram = false;
  do {
    MainScreen(vcPlaylist);
    HandleOperation(vcPlaylist, ChooseOperation(), QuitProgram);
  } while (!QuitProgram);
}
int main() {
  App();
  return 0;
}