#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using std::ofstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int reduceChoices(int** arr,int num, int n,int currentArray){
    int newN = 0;
    for (int g=0;g<n;g++){
        if (arr[g]!=NULL){
            int count =0;
            for (int h=0;h<5;h++){
                if (arr[g][h]==arr[currentArray][h]){
                    count++;
                }
            }
            if (count!=num && count!=5 && g!=currentArray){
                delete[]arr[g];
                arr[g] = NULL;
                newN++;
            }
        }
    }
    delete[]arr[currentArray];
    arr[currentArray] = NULL;
    newN++;
    return newN;
}

void numGuess(){
    int ** choices = new int*[100000];
    int n = 100000;
    int left = n;
    for (int a=0;a<10;a++){
        for (int b=0;b<10;b++){
            for (int c=0;c<10;c++){
                for (int d=0;d<10;d++){
                    for (int e=0;e<10;e++){
                        int arrayInt = a*10000 + b*1000 + c*100 + d*10 + e;
                        int* array = new int[5];
                        array[0] = a;
                        array[1] = b;
                        array[2] = c;
                        array[3] = d;
                        array[4] = e;
                        choices[arrayInt] = array;
                    }
                }
            }
        }
    }
    cout << "Please write down 5 seperate digits between 0 and 9." << endl << "I will show a list of numbers" << endl << "and you tell me how many numbers I got in the right position." << endl;
    int numRight=0;
    int guesses = 0;
    while(numRight<5){
        guesses++;
        int ran = rand() % n;
        int loops = 0;
        while (choices[ran]==NULL){
            ran = rand() % n;
            loops++;
            if (loops>100000){
                int z = 0;
                while (choices[ran]==NULL){
                        ran = z;
                        z++;
                    }
                break;
                }
            }
        //cout << "ran = " << ran << endl;
        cout << "Number of possibilites left: " << left << endl;
        cout << "Guess #" << guesses << " : ";
        for (int aa=0;aa<5;aa++){
            cout << choices[ran][aa];
        }
        cout << endl;
        cout << "How many numbers did I guess in the correct position?" << endl;
        cin >> numRight;
        if (numRight<5){
            left -= reduceChoices(choices,numRight,n,ran);
            if (left<=0){
                cout << "Are you sure? Maybe try it again." << endl;
                return;
            }
        } else {

        }
    }
    cout << "I was able to guess your list of numbers in " << guesses << " guesses." << endl;
}

int main(){
    numGuess();
    char aorx;
    while (aorx!='x'){
        aorx = ' ';
        cout << "Type 'a' to go again, type 'x' to exit" << endl;
        cin >> aorx;
        if (aorx=='x'){
            return 0;
        } else if (aorx=='a') {
            numGuess();
        } else {
            cout << "Please enter only 'a' or 'x'" << endl;
        }
    }
}
