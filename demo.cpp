#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include<ctime>

using namespace std;

void registration();
void login();
void traindetails();
void traincheck();
void bookTicket();
void generateReceipt(string name, int age,string from,string to, int tickets, string trainName, int distance, int pricePerTicket, int discount);

int main() {
    while (true) {
    int choice;
    cout <<"\n";
    cout << "~~~~~Welcome to Railway Ticket Booking System~~~~~\n";
    cout <<"\n";
    cout << "\t\t1.   Register\n";
    cout << "\t\t2.   Login\n";
    cout << "\t\t3.   Train details\n";
    cout << "\t\t4.   Exit\n";
    cout <<"\n";
    cout << "~~~~~Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registration();
            break;

        case 2:
            login();
            break;


        case 3:
            traindetails();
            break;

        case 4:
             traincheck();
             break;

        case 5:
            cout << "Exiting...\n";
            cout << "~~~~~ code by   23AIML031\n\t\t23AIML035\n\t\t23AIML045";

            return 0;
        default:
            cout << "Invalid choice ...!!!\nChoose a Valid Number   \n";
            break;
    }
    }
    return 0;
}

void registration()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream railusersFile("railusers.txt", ios::app);
    if (railusersFile.is_open()) {
        railusersFile << username << " " << password << endl;
        cout << "Registration successful!\n";
        railusersFile.close();
    } else {
        cout << "Error opening file for registration.\n";
    }

}

void login()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream railusersFile("railusers.txt");
    string line;
    bool found = false;
    while (getline(railusersFile, line)) {
        size_t pos = line.find(' ');
        string storedUsername = line.substr(0, pos);
        string storedPassword = line.substr(pos + 1);
        if (username == storedUsername && password == storedPassword) {
            found = true;
            break;
        }
    }
    railusersFile.close();

    if (found) {
        cout << "Login successful!\n";
        bookTicket();
    } else {
        cout << "Invalid username or password.\n";
    }

}

void traindetails() {

    string railname, railcode, railfare;
    cout << "Enter railname: ";
    cin >> railname;
    cout << "Enter railcode: ";
    cin >> railcode;
    cout << "Enter railfair: ";
    cin >> railfare;

    ofstream traindetailFile("traindetail.txt", ios::out);
    if (traindetailFile.is_open()) {
        traindetailFile << railname << " " << railcode << " " << railfare << endl;
        cout << "Registration successful!\n";
        traindetailFile.close();
    } else {
        cout << "Error opening file for registration.\n";
    }

}

void traincheck()
{
    string railname, railcode, railfare;
    cout << "Enter railname: ";
    cin >> railname;
    cout << "Enter railcode: ";
    cin >> railcode;
    cout << "Enter railfair: ";
    cin >> railfare;

    ifstream traindetailFile("traindetail.txt");
    string line;
    bool found = false;
    while (getline(traindetailFile, line)) {
        size_t pos = line.find(' ');
        string storedrailname = line.substr(0, pos);
        string storedrailcode = line.substr(pos + 1);
        string storedrailfare = line.substr(pos + 2);
        if (railname == storedrailname && railcode == storedrailcode && railfare == storedrailfare) {
            found = true;
            break;
        }
    }
    traindetailFile.close();
}
void bookTicket() {

    string name,from,to;
    int age, tickets;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter your age: ";
    cin>>age;
    cout << "Enter your from: ";
    cin.ignore();
    getline(cin, from);

    cout << "Enter your to: ";
    //cin.ignore();
    getline(cin, to);

    cout << "Enter number of tickets: ";
    cin >> tickets;

    // Selecting a train
    cout << "Available Trains:\n";
    cout << "1. Maharajas' Express\n";
    cout << "2. The Golden Chariot\n";
    cout << "3. Deccan Odyssey\n";
    cout << "4. Vande Bharat\n";
    cout << "5. Tejas Express\n";
    cout << "6. Gareeb Rath\n";
    int trainChoice;
    cout << "Select a train: ";
    cin >> trainChoice;
    string selectedTrain;
    int distance;
    int pricePerTicket;
    switch (trainChoice) {
        case 1:
            selectedTrain = "Maharajas' Express";
            //distance = 500;
           // pricePerTicket = 1000;
            break;

        case 2:
            selectedTrain = "The Golden Chariot";
           // distance = 700;
            //pricePerTicket = 1200;
            break;

        case 3:
            selectedTrain = "Deccan Odyssey";
           // distance = 250;
           // pricePerTicket = 1200;
            break;

        case 4:
            selectedTrain = "Vande Bharat";
            //distance = 150;
            //pricePerTicket = 900;
            break;

        case 5:
            selectedTrain = "Tejas Express";
            //distance = 100;
            //pricePerTicket = 120;
            break;

        case 6:
            selectedTrain = "Gareeb Rath";
            //distance = 100;
            //pricePerTicket = 60;
            break;
        default:
            cout << "Invalid train choice.\n";
            return;
    }

    // Selecting seat preference
    cout << "Seat Preferences:\n";
    cout << "1. Window\n";
    cout << "2. Aisle\n";
    int seatChoice;
    cout << "Select seat preference: ";
    cin >> seatChoice;
    string seatPreference;
    switch (seatChoice) {
        case 1:
            seatPreference = "Window";
            break;
        case 2:
            seatPreference = "Aisle";
            break;
        default:
            cout << "Invalid seat preference.\n";
            return;
    }


    // Further logic for selecting train, seat preference, calculating fare, etc.
    //string selectedTrain = "Sample Train";
    //int distance = 500; // Example distance
    //int pricePerTicket = 100; // Example price per ticket
    int discount = 0; // Example discount
    generateReceipt(name, age,from,to, tickets, selectedTrain, distance, pricePerTicket, discount);

}

void generateReceipt(string name, int age,string from,string to, int tickets, string trainName, int distance, int pricePerTicket, int discount) {
    //int totalPrice = tickets * pricePerTicket;
   // float discountedPrice = totalPrice - discount;
   // float totalPriceWithGST = discountedPrice * 1.05;

srand(time(NULL));

// Generates and prints a random number between 1 and 10
int  randomnum = (rand() % 10) + 1;
  pricePerTicket=randomnum*78;

int totalPrice= pricePerTicket*tickets;
    cout << "\n\t\tReceipt\n";
    cout << "\tName: " << name << endl;
    cout << "\tAge: " << age << endl;
    cout << "\tFrom: " << from << endl;
    cout << "\tTo: " << to << endl;
    cout << "\tTrain: " << trainName << endl;
    cout << "\tDistance: " << distance << " km" << endl;
    cout << "\tNumber of tickets: " << tickets << endl;
    cout << "\tprice per tickets: " << pricePerTicket<< endl;
    cout << "\tTotal Price: " << totalPrice << " Rs" << endl;
    cout << "\tDiscount: " << discount << " Rs" << endl;
    //cout << "\tPrice after discount: " << discountedPrice << " Rs" << endl;
    //cout << "\tTotal Price with GST: " << totalPriceWithGST << " Rs" << endl;
}
