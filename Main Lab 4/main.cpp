/* So...
 * I'm pretty sure there are a bajillion ways to make this code simpler and easier to read.
 * But it works. And if it ain't broke don't fix it.
 */

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stoi;

//declaring functions
string PromptStringUserInput(string prompt, string choice1, string choice2, string choice3 = "");
void Ending(string prompt);
int PromptScaledUserInput(string prompt, int rangeLow, int rangeHigh);
void PrintStars();
void RandomChoice(string &userInput, string choice1, string choice2, string choice3 = "");

int main() {
    //declaring variables
    string stringUserChoice1;
    string stringUserChoice2;
    string stringUserChoice3;
    int moneyScale;
    int cuteScale;
    int crazyScale;
    int hotScale;
    bool changeYourManOrWoman = true; //using true so the loop will automatically restart unless changed

    //setting random based on time so it will be random for every run of the program
    srand(time(0));

    //initial output
    PrintStars();
    cout << "WELCOME TO THE CRAZY/HOT CUTE/MONEY MATRIX" << endl;
    cout << "Your #1 consultant on all things dating" << endl;
    PrintStars();

    stringUserChoice1 = PromptStringUserInput("Are you dating men or women?", "men", "women", "not in the market");
    if (stringUserChoice1 == "women") { //the WOMEN dating tree
        do {
            hotScale = PromptScaledUserInput("Please indicate how hot your lady is", 1, 10);
            if (hotScale >= 1 && hotScale <= 4) {
                stringUserChoice3 = PromptStringUserInput(
                        "NO GO ZONE. Your lady has not met the minimum hotness threshold.\n"
                        "We recommend reevaluating your priorities.\n\n"
                        "Would you like to change your answer?", "yes", "no");
                if (stringUserChoice3 == "yes") {
                    cout << "Whew! That was a close call. Remember, she might have friends..." << endl << endl;
                    //the do-while loop will restart back to the hotScale prompt
                }
                else if (stringUserChoice3 == "no") {
                    changeYourManOrWoman = false; //I know this is unnecessary because the Ending function will exit the program
                                                //anyway, but the endless loop error was driving me nuts. I did this for all of the "endings"
                    Ending("Oh. So you are a nice guy. That's nice. Good for you. I hope you two have a lovely life.");
                }
            }
            else if (hotScale >= 5 && hotScale <= 7) {
                do {
                    crazyScale = PromptScaledUserInput(
                            "Alright. We can work with this. How crazy is this lady of yours?", 4, 10);
                    if (crazyScale >= 1 && crazyScale <= 3) {
                        cout << "My good sir, you must be mistaken. There is no such thing as a lady below a 4 crazy." << endl;
                    }
                }
                while (crazyScale >= 1 && crazyScale <= 3);

                if (crazyScale >= 4 && crazyScale <= 10) {
                    if ((hotScale == 7 && crazyScale <= 8) || (hotScale == 6 && crazyScale <= 7) || (hotScale == 5 && crazyScale <= 8)) { //Complicated, but meant to represent the crazy-hot diagonal line. If above, in danger zone, if below, see options.
                        changeYourManOrWoman = false;
                        Ending("Fun zone! Remember that there is plenty of fish in the sea, but she'll be good enough for now.");
                    }
                    else {
                        changeYourManOrWoman = false;
                        Ending("DANGER ZONE!!!!!! RUN!!!!!!!");
                    }
                }
            }
            else if (hotScale >= 8 && hotScale <= 10) {
                do {
                    crazyScale = PromptScaledUserInput("WOWZERS you scored! Save some for the rest of us, eh?\n"
                                                       "We need to double check though, how crazy is this lady?", 4, 10);
                    if (crazyScale >= 1 && crazyScale <= 3) {
                        cout << "My good sir, you must be mistaken. There is no such thing as a lady below a 4 crazy." << endl;
                    }
                }
                while (crazyScale >= 1 && crazyScale <= 3);

                if (crazyScale >= 4 && crazyScale <= 10) {
                    if ((hotScale == 8 && crazyScale <= 9) || (hotScale == 9 && crazyScale <= 10) || (hotScale == 10)) { //Same as before, attempt to represent the crazy-hot line
                        if (hotScale == 10 && crazyScale == 10) {
                            changeYourManOrWoman = false;
                            Ending("https://www.youtube.com/watch?v=WXBHCQYxwr0"); //;)
                        }
                        else if (crazyScale >= 6) {
                            changeYourManOrWoman = false;
                            Ending("DATE ZONE! Well done! You can date her indefinitely.\n\n"
                                   "Though do keep in mind:\n"
                                   "\"The first commandment that God gave to Adam and Eve"
                                   "\npertained to their potential for parenthood as husband and wife."
                                   "\nWe declare that God’s commandment for His children to multiply"
                                   "\nand replenish the earth remains in force.\"\n\n"
                                   ";)");
                        }
                        else if (crazyScale == 5) {
                            changeYourManOrWoman = false;
                            Ending("WIFE ZONE! She's a keeper, you lucky son-of-a-gun.\n"
                                   "[Please share your tips, I need help]");
                        }
                        else if (crazyScale == 4) {
                            changeYourManOrWoman = false;
                            Ending("UNICORN ZONE!?!?\n"
                                   "These creatures do not exist. If you find one, please capture it.\n"
                                   "We'd like to study it and possibly replicate it.");
                        }
                    }
                    else {
                        changeYourManOrWoman = false;
                        Ending("DANGER ZONE!!!!!! RUN!!!!!!!");
                    }
                }
            }
        }
        while (changeYourManOrWoman);
    }
    else if (stringUserChoice1 == "men") { //the MEN dating tree
        do {
            moneyScale = PromptScaledUserInput("Please indicate how much money your man has", 1, 10);
            if (moneyScale >= 1 && moneyScale <= 6) {
                cuteScale = PromptScaledUserInput("Oh. That's unfortunate. Well, umm, is he cute?", 1, 5);
                if (cuteScale >= 1 && cuteScale <= 3) {
                    stringUserChoice2 = PromptStringUserInput("NO GO ZONE. Back up slowly.\n"
                                                              "This is not your man. I repeat, this is not your man.\n\n"
                                                              "Would you like to change your answer?", "yes", "no");
                    if (stringUserChoice2 == "yes") {
                        cout << "Wow, that was fast. Hope you didn't break his heart into too many pieces" << endl;
                    }
                    else if (stringUserChoice2 == "no") {
                        changeYourManOrWoman = false;
                        Ending("Oh well, don't say I didn't warn you. Try not to have too many kids.");
                    }
                }
                else if (cuteScale >= 4 && cuteScale <= 5) {
                    changeYourManOrWoman = false;
                    Ending("Well, at least he has one thing going for him.\n"
                           "It will be fun to date him, but remember that the\n"
                           "real value of a man lies in the size of his wallet.");
                }
                else if (cuteScale >= 6 && cuteScale <= 10) {
                    cout << "Not trying to break your heart here, but no man is that cute. Speaking from experience." << endl;
                    //will restart the do-while loop
                }

            }
            else if (moneyScale >= 7 && moneyScale <= 10) {
                changeYourManOrWoman = false;
                Ending("$$$ GOLDEN $$$. It doesn't matter HOW hot he is,\nyou better scoop him up before he gets nabbed by some other gold digger.");
            }
        }
        while (changeYourManOrWoman);

    }
    else if (stringUserChoice1 == "not in the market") {
        Ending("Not my problem. Move over for the rest of us single people please.");
    }
    return 0;
}

//function definitions
string PromptStringUserInput(string prompt, string choice1, string choice2, string choice3) {
    //prints the prompt and the choices, then checks if the input is one of the choices
    //if a choice, returns the choice
    //if not, prompts the user again
    string userInput;
    bool unacceptableInput;
    do {
        cout << endl;
        PrintStars();
        cout << prompt << endl;
        /*there is one decision with three choices, and a couple other ones with two. So the
         * first if statement will execute if there is three, the second if there is only two options
         */
        if (choice3 != "") {
            cout << "(" << choice1 << ", " << choice2 << ", " << choice3 << ")" << endl;
            PrintStars();
            getline(cin, userInput); //used getline for the not[space]in[space]the[space]market option
        }
        else {
            cout << "(" << choice1 << ", " << choice2 << ")" << endl;
            PrintStars();
            cin >> userInput; //I don't know why, but my code only worked if I used cin instead of getline. ????
        }

        if (userInput == choice1 || userInput == choice2 || userInput == choice3 || userInput == "random") {
            unacceptableInput = false; //if the input is a choice, then escape the do-while loop
        }
        else {
            unacceptableInput = true;
            cout << endl;
            PrintStars();
            cout << "I'm not sure what you mean. Can you try again?" << endl;
            PrintStars();
        }
    }
    while (unacceptableInput);

    //if "random" is inputted, run the RandomChoice function to choose a random choice
    if (userInput == "random") {
        RandomChoice(userInput, choice1, choice2, choice3);
    }

    return (userInput);
}

void PrintStars() {
    //simple function to print a line of stars
    for (int i = 0; i < 40; ++i) {
        cout << "*";
    }
    cout << endl;
}

void RandomChoice(string &userInput, string choice1, string choice2, string choice3) {
    //function will randomly select a choice and update userInput with that choice
    int randomNumber;

    if (choice3 != "") { //if three decisions are available
        randomNumber = rand() % 3 + 1; //random number generated between 1 - 3
        if (randomNumber == 1) {
            userInput = choice1;
        }
        if (randomNumber == 2) {
            userInput = choice2;
        }
        if (randomNumber == 3) {
            userInput = choice3;
        }
    }
    else { //otherwise only two choices are available
        randomNumber = rand() % 2 + 1; //random number generated between 1 - 2
        if (randomNumber == 1) {
            userInput = choice1;
        }
        if (randomNumber == 2) {
            userInput = choice2;
        }
    }

    cout << endl;
    PrintStars();
    cout << "Random choice: " << userInput << endl;
    PrintStars();
}

int RandomNumber() {
    //Function to randomly select a number for a scaled choice, between 1 - 10
    //Returns the random number
    int randomNumber;
    randomNumber = rand() % 10 + 1; //Random number generated between 1 - 10

    cout << endl;
    PrintStars();
    cout << "Random number chosen: " << randomNumber << endl;
    PrintStars();

    return (randomNumber);
}

int PromptScaledUserInput(string prompt, int rangeLow, int rangeHigh) {
    string userInput;
    int userInputNumberForm;
    bool unacceptableInput;
    do {
        cout << endl;
        PrintStars();
        cout << prompt << endl;
        cout << "(scale " << rangeLow << "-" << rangeHigh << ")" << endl;
        PrintStars();
        cin >> userInput;

        //This is my annoying way to distinguish a input of string "random" from a input of int 1 - 10
        if (isdigit(userInput.at(0))) { //if input is a digit

            userInputNumberForm = stoi (userInput); //convert string # to int # and assign it to userInputNumberForm

            if (userInputNumberForm >= 1 && userInputNumberForm <= 10) { //checking to make sure its a valid number
                unacceptableInput = false;
            }
            else {
                unacceptableInput = true;
                cout << endl;
                PrintStars();
                cout << "I'm not sure what you mean. Can you try again?" << endl;
                PrintStars();
            }
        }
        else if (userInput != "random") { //if NOT a number and it ISN'T "random"
            unacceptableInput = true;
            cout << endl;
            PrintStars();
            cout << "I'm not sure what you mean. Can you try again?" << endl;
            PrintStars();
        }
        else { //otherwise it IS "random" and run the RandomNumber function, assigned to userInputNumberForm
            unacceptableInput = false;
            userInputNumberForm = RandomNumber();
        }
    }
    while (unacceptableInput);

    return userInputNumberForm; //return the number
}

void Ending (string prompt) {
    //ends the program
    cout << endl;
    PrintStars();
    cout << prompt;
    cout << endl << endl << "END";
    cout << endl << endl << "(for more information, please see https://www.youtube.com/watch?v=R_USJCTIgs4)";
    cout << endl << "(HINT: try typing \"random\" if you are too lazy to put in your own guy/gal)";
    cout << endl;
    PrintStars();
    exit(0);
}