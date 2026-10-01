//Input and Output Stream (cout, cin and endl)
#include <iostream>

#include <cstdlib>

// Everything to do with Vectors
#include <vector>

//Basic Math Operations
#include <cmath>

//String Manipulation (string data type, concatonation and length)
#include <string>

using namespace std;

int Basics(){
    // cin >> only reads until the first space. 
    // Use getline() for full sentences.

    /* STRING INPUT AND OUTPUT */
    string fullName_getline;

    cout << "Enter your full name: ";
    getline(cin >> ws, fullName_getline); //the ws removes the white space from the beginning

    cout << "Full Name using getline(): " + fullName_getline << endl << endl;

    /* STRING MANIPULATION AND METHODS */
    
    //Getting the length of a string
    string s = "Hello";
    cout << "Length: " << s.length() << endl << endl; 

    //Getting a substring
    string part = s.substr(0, 4); // Remeber the 4 is exclusive. 
    cout << "From index 0 to 3, the output is: " + part << endl << endl;

    // Finding characters: returns the index
    auto found = s.find("lo");  
    // NOTE: The auto keyword automatically detects the type of a variable based on the value you assign to it.

    // Concatonation
    s += "World";

    cout << endl << endl;

    //This is also the same thing for integers
    cout << 3 << endl;
    cout << 3 + 3 << endl;
    cout << 3 * 3 << endl << endl;

    int x = 5, y = 6, z = 7;
    cout << x + y + z << endl << endl;

    x = y = z = 50;
    cout << x + y + z << endl << endl;

    return 0;
}

int Conditionality(){
    //variable = (condition) ? outputIfTrue: outputIfFalse
    int age = 20;
    
    string value = (true) ? "True": "False";

    string status = (age >= 18) ? "Adult" : "Minor";

    if (age >= 18){
        cout << "You are an adult";
    } else {
        cout << "You are a minor";
    }

    switch (age) {
        case 0: 
            cout << "Newborn";
            break;
        case 1 ... 12:
            cout << "Child";
            break;
        case 13 ... 19:
            cout << "Teenager";
            break;
        case 20 ... 64:
            cout << "Adult";
            break;
        case 65 ... 120:
            cout << "Senior Citizen";
            break;
        default:
            cout << "Invalid age";
            break;
    }

    return 0;
}

int Loops(){
    //While Loop
    int i = 0;

    while (i < 5) { 
        cout << i << "\n";
        i++;
    }

    //Do-While Loop
    i = 0;
    do {
        cout << i << "\n";
        i++;
    } while (i < 5);

    //For Loop
    for (int k = 0; k < 5; k++){
        cout << k << "\n";
    }

    //For Each Loop
    int myNumbers[5] = {10, 20, 30, 40, 50};
    for (int num : myNumbers) {
        cout << num << "\n";
    }

    return 0;
}

int Arrays(){
    // Arrays: Fixed size, fast, but "dumb" (don't know their own size easily)
    
    //Instantiating Arrays
    string arr[4] = {"A", "B", "C", "D"};

    //Indexing
    cout << arr[1];
    arr[1] = "E";


    //This returns the size of the array in bytes
    cout << sizeof(arr);

    //This returns the size of the type of array in bytes (int, char, double, etc.)
    cout << sizeof(arr[0]);

    //Get the "length" of the Arrays
    int size = sizeof(arr) / sizeof(arr[0]);

    //Looping through with a for each loop
    for (string letter: arr){
        cout << letter << "\n";
    }

    return 0;
}

int Vectors(){
    // Vectors: Dynamic size, smart, preferred in modern C++
    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda", "Chevy"};

    //Indexing
    //Note: you can do somethinglike cars[0], but its better to do cars.at(0)
    cout << cars.at(1);
    cars.at(2) = "Honda";

    //Adds the element at the end of the vector
    cars.push_back("Mitsubishi");

    // Get the first element
    cout << cars.front();

    // Get the last element
    cout << cars.back();

    //Remove the last element of the vector
    cars.pop_back();

    //Check the size
    cout << cars.size();

    //Check if empty
    cout << cars.empty();

    return 0;
}

int MultidimentionalArrays(){
    string letters[2][4] = {
        { "A", "B", "C", "D" },
        { "E", "F", "G", "H" }
    };

    //Accessing Multidimensional arrays
    cout << letters[0][2]; 

    //changing an elelment in Multidimensional arrays
    letters[0][0] = "Z";
    cout << letters[0][0];

    //Looping through Multidimensional Arrays
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cout << letters[i][j] << "\n";
        }
    }

    return 0;
} 

int Math(){
    //atan2()
    cout << atan2(0.5, 0.5);

    //cosine
    cout << cos(-3);

    //sine
    cout << sin(3);

    //tanget
    cout << tan(3);

    //square root
    cout << sqrt(1);

    cout << pow(2, 2);

    return 0;
}

int Structures(){
    struct Person{
        string name;
        int age;
    };

    Person p = {"Alice", 25};
    cout << p.name << endl;
    cout << p.age << endl;

    return 0;
}

int main(){
    Basics();

    Conditionality();

    Loops();

    Arrays();

    Vectors();

    MultidimentionalArrays();

    Math();

    Structures();

    return 0;
}