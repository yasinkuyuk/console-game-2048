#include <iostream>
#include <time.h>

using namespace std;

class Game{
    int** matrix;
    public:
        Game();
        void move(char);
        void randomValue();
        void printScreen();
};

Game::Game(){
    this->matrix = new int *[4];
    for(int i=0; i<4; i++){
        this->matrix[i] = new int[4];
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            matrix[i][j] = 0;
        }
    }

    randomValue();
    randomValue();
    cout<<"Play with W,A,S,D";
    printScreen();
}

void Game::printScreen(){
    cout<<endl;
    cout<<endl<<"***************************"<<endl<<endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(matrix[i][j] != 0){
                cout<<matrix[i][j]<<"\t";
            }
            else{
                cout<<"-"<<"\t";
            }
        }
        cout<<endl;
    }
    cout<<endl<<"***************************"<<endl;
}

void Game::randomValue(){
    srand (time(NULL));
    int i,j;
    
    bool flag = true;
    
    while(flag){
        i = rand()%4;
        j = rand()%4;

        if(matrix[i][j] == 0){
            matrix[i][j] = ((rand() % 2) +1) * 2;
            flag = false;
        }
    }
}


int main(){
    Game game = Game();

    return EXIT_SUCCESS;
}