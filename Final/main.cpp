#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//Document.h
class Document{
private:
    string name;
    string extension;
    string contents;
public:
    Document(string nameIn, string extensionIn, string contentsIn);
    string GetName();
    void Rename(string newDocumentName);
    string GetExtension();
    string GetContents();
    void Print();

};

//Document.cpp
Document::Document(string nameIn, string extensionIn, string contentsIn){
    name = nameIn;
    extension = extensionIn;
    contents = contentsIn;
}
string Document::GetName(){
    return name;
}
void Document::Rename(string newDocumentName){
    name = newDocumentName;
}
string Document::GetExtension(){
    return extension;
}
string Document::GetContents(){
    return contents;
}
void Document::Print(){
    cout << "Name: " << name << "." << extension << endl;
    cout << "Contents: " << contents << endl;
}

//main.cpp----------
void DisplayMenu(){
    cout << "Choose an option below: "<< endl;
    cout << "1. Add a document to your list"<< endl;
    cout << "2. Rename one of your documents"<< endl;
    cout << "3. Share one of your documents with your friend"<< endl;
    cout << "4. Display all of the documents"<< endl;
    cout << "5. Quit"<< endl << endl;
}

// Modify the main function to handle each menu option
// Consider creating a new function (above main) per menu option
int main(){
    const int ADD_DOCUMENT_OPTION = 1;
    const int RENAME_DOCUMENT_OPTION = 2;
    const int SHARE_YOUR_DOCUMENT_OPTION = 3;
    const int DISPLAY_ALL_DOCUMENTS_OPTION = 4;
    const int QUIT_OPTION = 5;

    vector<Document*> userDrive;
    vector<Document*> friendDrive;

    int option;
    DisplayMenu();
    cin >> option;

    while(option != QUIT_OPTION){
        if(option == ADD_DOCUMENT_OPTION){
            string docName;
            string docExtension;
            string docContent;

            cout << "Enter the document name:" << endl;
            cin >> docName;
            cout << "Enter the document extension:" << endl;
            cin >> docExtension;
            cout << "Enter the document content:" << endl;

            getline(cin, docContent);
            //Document* newDoc = new Document(docName, docExtension, docContent);
            //userDrive.push_back(newDoc);
        }
        else if(option == RENAME_DOCUMENT_OPTION){
            int indexToChange;
            string newName;
            cout << "Enter the index of the document you want to rename:" << endl;
            cin >> indexToChange;
            cout << "Enter the updated name of the document:" << endl;
            cin >> newName;

            userDrive.at(indexToChange)->Rename(newName);

        }
        else if(option == SHARE_YOUR_DOCUMENT_OPTION){
            int indexToShare;
            cout << "Enter the index of the document you want to share:" << endl;
            cin >> indexToShare;

            friendDrive.push_back(userDrive.at(indexToShare));
        }
        else if(option == DISPLAY_ALL_DOCUMENTS_OPTION){
            cout << setfill('-') << setw(19) << "" << "Your List" << setw(19) << "" << endl;
            for (int i = 0; i < userDrive.size(); ++i) {
                userDrive.at(i)->Print();
            }
            cout << setw(14) << "" << "Your Friend's List" << setw(14) << "" << endl;
            for (int i = 0; i < friendDrive.size(); ++i) {
                friendDrive.at(i)->Print();
            }
        }

        cout << endl << "Enter option: " << endl;
        cin >> option;
    }

    for (unsigned int i = 0; i < userDrive.size(); ++i) {
        delete userDrive.at(i);
    }
    return 0;
}
