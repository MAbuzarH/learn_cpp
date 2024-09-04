#include <iostream>

using namespace std;

class Islamic_info {
public:
  void Quran_info();
  void display_namaz_list();
  int sum_five_prayer_faraz_rakat();
  void showChoices();
};

void Islamic_info::Quran_info() {
  cout << "Quran Details" << endl;
  cout << "Total Parrah:30 "<<endl;  
 cout << "Surrah:114" << endl;
 cout << "Madni Sura:28" << std::endl;
  cout << "Makhi Surrah:86" << endl;
  cout << "Total Ayat:6666" << std::endl;
}

void Islamic_info::display_namaz_list() {
//  cout << "**Number of Faraz Rakats for Five Prayers**" << endl;
  cout << "Paraz rakat in each  Paryers: 2 4 4 3 4" << endl;

}

int Islamic_info::sum_five_prayer_faraz_rakat() {
  int faraz_rakats[5] = {2, 4, 4, 3, 4};
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += faraz_rakats[i];
  }
  return sum;
}

void Islamic_info::showChoices() {
//  cout << "**Enter your choice (1, 2, 3, or 4):**" << endl;
    cout << "Manue" << endl;
 cout << "1: Quran Info:" << endl;
  cout << "2: Display list of five prayers Faraz rakat:" << endl;
  cout << "3: Sum all five prayers Farz rakat:" << endl;
cout << "4. Exit" << endl;
}

int main() {
  Islamic_info islamicInfo;
  int choice;

 do {
    islamicInfo.showChoices();
      cout<<"Enter your choice :";
    cin >> choice;

    switch (choice) {
      case 1:
        islamicInfo.Quran_info();
        break;
      case 2:
        islamicInfo.display_namaz_list();
        break;
      case 3:
       cout << "Sum of Faraz Rakats: " << islamicInfo.sum_five_prayer_faraz_rakat() << endl;
        break;
      case 4:
       cout << "Exit" << endl;
        break;
      default:
        cout << "Invalid choice. Please enter a valid choice (1, 2, 3, or 4)." << endl;
    }
  } while (choice != 4);

  return 0;
}
