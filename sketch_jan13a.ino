#include "Keyboard.h"

int outputsL[] = {19,20,21,22,26,27};
int inputsL[] = {12,13,14,16,17,18};

int outputsR[] = {1,2,3,4,5,6};
int inputsR[]= {7,8,9,10,23,29};

int LLT[6][6] = {
    {2,1,1,1,1,1},
    {3,1,1,1,1,1},
    {4,1,1,1,1,1},
    {5,1,1,1,1,1},
    {6,7,8,9,10,11},
    {12,13,14,15,16,17}
};

char LLM[6][6] = {
    {' ','1','2','3','4','5'},
    {' ','\'',',','.','p','y'},
    {' ','a','o','e','u','i'},
    {' ',';','q','j','k','x'},
    {' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' '}
};

int RLT[6][6] = {
    {1,1,1,1,1,2},
    {1,1,1,1,1,3},
    {1,1,1,1,1,4},
    {1,1,1,1,1,5},
    {6,7,8,9,10,11},
    {12,13,14,15,16,17}
};

char RLM[6][6] = {
    {'6','7','8','9','0',' '},
    {'f','g','c','r','l',' '},
    {'d','h','t','n','s',' '},
    {'b','m','w','v','z',' '},
    {' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' '}
};

bool keyDownL[6][6];
bool keyDownR[6][6];

void setup()  {
  for(int i; i < 6; i++)  {
    pinMode(inputsL[i], INPUT_PULLUP);
  }
  for(int j; j < 6; j++)  {
    pinMode(outputsL[j], OUTPUT);
    digitalWrite(outputsL[j], HIGH);
  }
  Keyboard.begin();
}

void loop() {
  for(int i; i < 6; i++)  {
    digitalWrite(outputsL[i], LOW);
    delayMicroseconds(5);

    for(int j; j < 6; j++)  {
      if(digitalRead(inputsL[j]) == LOW) {
        keyPressedL(i,j);
      }
      else if(keyDownL[i][j] != 0)  {
        resetKeyL(i,j);
      }
    }
    digitalWrite(outputsL[i], HIGH);
    digitalWrite(outputsR[i], LOW);
    delayMicroseconds(5);

    for(int k; k < 6; k++)  {
      if(digitalRead(inputsR[k]) == LOW) {
        keyPressedR(i,k);
      }
      else if(keyDownR[i][k] != 0)  {
        resetKeyR(i,k);
      }
    }
    delayMicroseconds(400);
  }
}

void keyPressedL(int row, int col)  {
  if(keyDownL[row][col] == false) {
    switch(LLT[row][col]) {
      case 1:
        Keyboard.write(LLM[row][col]);
        break;
      case 2:
        Keyboard.press(KEY_ESC);
        break;
      case 3:
        Keyboard.press(KEY_TAB);
        break;
      case 4:
        Keyboard.press(KEY_LEFT_SHIFT);
        break;
      case 5:
        Keyboard.press(KEY_LEFT_CTRL);
        break;
      case 6:
        Keyboard.press(KEY_LEFT_GUI);
        break;
      case 7:
        Keyboard.press(KEY_LEFT_ALT);
        break;
    }
    keyDownL[row][col] = true;
  }
}

void resetKeyL(int row, int col)  {
    switch(LLT[row][col]) {
      case 1:
        Keyboard.write(LLM[row][col]);
        break;
      case 2:
        Keyboard.press(KEY_ESC);
        break;
      case 3:
        Keyboard.press(KEY_TAB);
        break;
      case 4:
        Keyboard.press(KEY_LEFT_SHIFT);
        break;
      case 5:
        Keyboard.press(KEY_LEFT_CTRL);
        break;
      case 6:
        Keyboard.press(KEY_LEFT_GUI);
        break;
      case 7:
        Keyboard.press(KEY_LEFT_ALT);
        break;
    }
    keyDownL[row][col] = false;
}


void keyPressedR(int row, int col)  {
  if(keyDownR[row][col] == false) {
    switch(RLT[row][col]) {
      case 1:
        Keyboard.write(RLM[row][col]);
        break;
      case 2:
        Keyboard.press(KEY_BACKSPACE);
        break;
      case 3:
        Keyboard.press(KEY_RETURN);
        break;
      case 4:
        Keyboard.press(KEY_RIGHT_SHIFT);
        break;
      case 5:
        Keyboard.press(KEY_RIGHT_CTRL);
        break;
      case 6:
        Keyboard.press(KEY_RIGHT_GUI);
        break;
      case 7:
        Keyboard.press(KEY_RIGHT_ALT);
        break;
      default:
        break;
    }
    keyDownR[row][col] = true;
  }
}

void resetKeyR(int row, int col)  {
    switch(RLT[row][col]) {
      case 1:
        Keyboard.write(RLM[row][col]);
        break;
      case 2:
        Keyboard.press(KEY_BACKSPACE);
        break;
      case 3:
        Keyboard.press(KEY_RETURN);
        break;
      case 4:
        Keyboard.press(KEY_RIGHT_SHIFT);
        break;
      case 5:
        Keyboard.press(KEY_RIGHT_CTRL);
        break;
      case 6:
        Keyboard.press(KEY_RIGHT_GUI);
        break;
      case 7:
        Keyboard.press(KEY_RIGHT_ALT);
        break;
      default:
        break;
    }
    keyDownR[row][col] = false;
  }
