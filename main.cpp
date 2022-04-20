// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: Gray Scale Image Processor.cpp
// Last Modification Date: 4/5/2022
// Author1 and ID and Group: Sara Tamer Mohamed Bihery - 20210155 - S25
// Author2 and ID and Group: Farah Mohamed Mohamed El-Sayed - 20210288 - S25
// Author3 and ID and Group: Laila Abdelaaty Mohammed Abdelaal - 20211072 - S25
// Teaching Assistant: Eng\ Mohamoud Fateaha
// Purpose: Making different filters on an image


#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"


using namespace std;
const int RBG = 3;
unsigned char image[SIZE][SIZE][RBG];
unsigned char image2[SIZE][SIZE][RBG];
unsigned char image3[SIZE][SIZE][RGB];

void loadImage ();
void saveImage();
void loadImage0();      
void saveImage0(); 
void merge0();
void darken1();
void lighten1();    
void invert1();
void shrinkHalf();
void shrinkToaThird();
void shrinkQuarter();
void blur();
void ImageBW();
void ImageReverseVertical();
void ImageReverseHorizontal();
void EdgeDetection();
void RightMirror();
void LeftMirror();
void UpperMirror();
void LowerMirror();
void Rotate90();
void Rotate180();
void Rotate270();
void ImageTranspose();
void saveImage0();
void Quarter1();
void Quarter2();
void Quarter3();
void Quarter4();
void Shuffle();




int main() {
//    The menu display
    char choice , choice2;
    string choice3;

    cout << "Please select a filter to apply or 0 to exit:\n"
            "1- Black & White Filter\n"
            "2- Invert Filter\n"
            "3- Merge Filter \n"
            "4- Flip Image\n"
            "5- Rotate Image clockwise\n"
            "6- Darken or Lighten Image \n"
            "7- Detect Image Edges \n"
            "8- Enlarge Image\n"
            "9- Shrink Image\n"
            "a- Mirror 1/2 Image\n"
            "b- Shuffle Image\n"
            "c- Blur Image\n"
            "s- Save the image to a file\n"
            "0- Exit\n";
    cin >> choice;
    loadImage();

    if (choice == '1'){
        ImageBW ();
        saveImage ();

    }
    else if ( choice == '2'){
        invert1();
        saveImage();
    }
    else if ( choice == '3'){
        loadImage0();
        merge0();
        saveImage0();
    }
    else if (choice == '4'){
        cout << "choose 'v' for vertical flip \nor 'h' for horizontal flip\n";
        cin >> choice2;

        if(choice2 == 'v'){
            ImageReverseVertical();
        }
        else if (choice2 == 'h'){
            ImageReverseHorizontal();
        }
        saveImage();
    }
    else if (choice == '5'){
        cout << "choose '1' for rotating 90 degrees, \n'2' for rotating 180 degrees or"
                "\n'3' for rotating 270 degrees\n";
        cin >> choice2;
        if (choice2 == '1'){
            Rotate90();
        }
        else if (choice2 == '2'){
            Rotate180();
        }
        else if ( choice2 == '3'){
            Rotate270();
        }
        saveImage ();
    }
    else if ( choice == '6'){
        cout <<  "choose 'd' for Darken or 'l' for lighten\n";
        cin >> choice2;
        if ( choice2 == 'd'){
            darken1();
        }
        else if ( choice2 == 'l'){
            lighten1();
        }
        saveImage(); 
    }
    else if (choice == '7'){
        EdgeDetection();
        saveImage ();
    }
    else if (choice == '8'){
        cout << "Choose 'q1' for the upper right quarter or\n"
                "q2 for the upper left quarter or\n"
                "q3 for the lower right quarter or \n"
                "q4 for the lower left quarter \n";
        cin >> choice3;
        if(choice3 == "q1"){
            Quarter1();
        }else if (choice3 == "q2")
            Quarter2();
        else if ( choice3 == "q3")
            Quarter3();
        else if (choice3 == "q4")
            Quarter4();
        saveImage0 ();
    }
    else if ( choice == '9'){
        cout << "choose 't' for shrink to 1/2 or 'y' for shrink to 1/3 0r 'o' for shrink to 1/4\n";
        cin >> choice2;
        if ( choice2 == 't'){
            shrinkHalf();
        }
        else if( choice2 == 'y'){
            shrinkToaThird();
        }
        else if ( choice2 == 'o'){
            shrinkQuarter();
        }
        saveImage0();
    }
    else if (choice == 'a'){
        cout << "choose 'r' for right mirror ,\n 'f' for left mirror ,\n "
                "'u' for upper mirror or 'l' for lower mirror\n";
        cin >> choice2;
        if(choice2 == 'r'){
            RightMirror();
        }
        else if (choice2 == 'f'){
            LeftMirror();
        }
        else if ( choice2 == 'u'){
            UpperMirror();
        }
        else if ( choice2 == 'l'){
            LowerMirror();
        }
        saveImage ();
    }
    else if (choice == 'b'){
        cout << "Enter the pattern you need.\n";
        Shuffle();
        saveImage0 ();
    }
    else if ( choice == 'c'){
        
    }
}
void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: \n";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}
void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}
void loadImage0(){
  //    char image1FileName[100];
    char image2FileName[100];

    // Get gray scale image file name
    cout << "Enter the source image2 file name: ";
    cin >> image2FileName;

    // Add to it .bmp extension and load image
    strcat (image2FileName, ".bmp");
    readRGBBMP(image2FileName, image2);
}
void saveImage0(){
  char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image3);
}

// Black and white function
void ImageBW (){
    long sum = 0 ,average = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for(int k = 0; k < 3; k++) {
                sum += image[i][j][k];
            }
        }
        average = sum/(SIZE*SIZE*SIZE);
    }
    for (int i = 0; i <SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                if (image[i][j][k] > average)
                    image[i][j][k] = 255;
                else
                    image[i][j][k] = 0;
            }
        }
    }
}
void ImageReverseVertical(){
    int n = 256;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n / 2; j++) {
            for (int k = 0; k < 3; k++) {
                int temp = image[i][j][k];
                swap(image[i][j][k], image[i][n - j - 1][k]);
                image[i][n - j - 1][k] = temp;
            }
        }
    }
}
void ImageReverseHorizontal() {
    int n = 256;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 3; k++) {
                int temp = image[i][j][k];
                swap(image[i][j][k], image[n - i - 1][j][k]);
                image[n - i - 1][j][k] = temp;
            }
        }
    }
}
void EdgeDetection() {
//    call the black and white function to deal with
    ImageBW();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                //if the pixel and the next pixel (in row or column) are equal make them white else make them black
                if (image[i][j][k] != image[i + 1][j][k] || image[i][j][k] != image[i][j + 1][k]) {
                    image[i][j][k] = 0;
                } else {
                    image[i][j][k] = 255;
                }
            }
        }
    }
}
void RightMirror() {
    int n = 256;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            for (int k = 0; k < 3; k++) {

                image[i][j][k] = image[i][n - j - 1][k];
            }
        }
    }
}
//function to mirror the left half
void LeftMirror() {
    int n = 256;
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE / 2; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {

                image[i][j][k] = image[i][n - j - 1][k];
            }
        }
    }
}
//function to mirror the upper half
void UpperMirror() {
    int n = 256;
    for (int i = SIZE / 2; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j][k] = image[n - i - 1][j][k];
            }
        }
    }
}
//function to mirror the lower half
void LowerMirror() {
    int n = 256;
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j][k] = image[n - i - 1][j][k];
            }
        }
    }
}
void ImageTranspose(){
    int n = 256;
    for (int i = 0; i < n ; i++) {
        for (int j = i; j < n; j++) {
            for (int k = 0; k < 3; k++) {

                int temp = image[i][j][k];
                swap(image[i][j][k], image[j][i][k]);
                image[j][i][k] = temp;
            }
        }
    }
}
void Rotate90(){
    ImageTranspose();
    ImageReverseVertical();
}
void Rotate180(){
    ImageReverseVertical();
    ImageReverseHorizontal();
}
void Rotate270(){
    ImageTranspose();
    ImageReverseHorizontal();
}
void Quarter1() {
    for (int f = 0, i = 0; i < SIZE; f++, i += 2) {
        for (int z = 0, j = 0; j < SIZE; z++, j += 2) {
            for (int k = 0; k < 3; k++) {

                image3[i][j][k] = image[f][z][k];
                image3[i + 1][j][k] = image[f][z][k];
                image3[i + 1][j + 1][k] = image[f][z][k];
                image3[i][j + 1][k] = image[f][z][k];

            }
        }
    }
}
void Quarter2() {
    for (int f = 0, i = 0; i < SIZE; f++, i += 2) {
        for (int z = 128, j = 0; j < SIZE; z++, j += 2) {
            for (int k = 0; k < 3; k++) {

                image3[i][j][k] = image[f][z][k];
                image3[i + 1][j][k] = image[f][z][k];
                image3[i + 1][j + 1][k] = image[f][z][k];
                image3[i][j + 1][k] = image[f][z][k];

            }
        }
    }
}
void Quarter3() {
    for (int f = 128, i = 0; i < SIZE; f++, i += 2) {
        for (int z = 0, j = 0; j < SIZE; z++, j += 2) {
            for (int k = 0; k < 3; k++) {

                image3[i][j][k] = image[f][z][k];
                image3[i + 1][j][k] = image[f][z][k];
                image3[i + 1][j + 1][k] = image[f][z][k];
                image3[i][j + 1][k] = image[f][z][k];
            }
        }
    }
}
void Quarter4() {
    for (int f = 128, i = 0; i < SIZE; f++, i += 2) {
        for (int z = 128, j = 0; j < SIZE; z++, j += 2) {
            for (int k = 0; k < 3; k++) {
                image3[i][j][k] = image[f][z][k];
                image3[i + 1][j][k] = image[f][z][k];
                image3[i + 1][j + 1][k] = image[f][z][k];
                image3[i][j + 1][k] = image[f][z][k];
            }
        }
    }
}

void Shuffle() {
    int q1, q2, q3, q4, x = 0, y = 0;
    cin >> q1 >> q2 >> q3 >> q4;
    if (q1 == 1 && q2 == 2 && q3 == 3 && q4 == 4) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image3[i][j][k] = image[i][j][k];
                }
            }
        }
    }
    if (q1 == 1 && q2 == 2 && q3 == 4 && q4 == 3) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image3[i][j][k] = image[i][j][k];
                }
            }
        }
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j + 128][k], image3[i][j][k]);
                }
            }
        }
    }
    if (q1 == 1 && q2 == 3 && q3 == 2 && q4 == 4) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image3[i][j][k] = image[i][j][k];
                }
            }
        }
        for (int f = 128, i = 0; i < SIZE / 2; f++, i++) {
            for (int z = 0, j = 128; j < SIZE; z++, j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i + 1][j][k], image3[f][z][k]);
                }
            }
        }
    }
    if (q1 == 1 && q2 == 3 && q3 == 4 && q4 == 2) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image3[i][j][k] = image[i][j][k];
                }
            }
        }
        for (int f = 128, i = 0; i < SIZE / 2; f++, i++) {
            for (int z = 0, j = 128; j < SIZE; z++, j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i + 1][j][k], image3[f][z][k]);
                }
            }
        }
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j + 128][k], image3[i][j][k]);
                }
            }
        }
    }
    if (q1 == 1 && q2 == 4 && q3 == 3 && q4 == 2) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image3[i][j][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 128; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j][k], image3[i + 128][j][k]);
                }
            }
        }
    }
    if (q1 == 1 && q2 == 4 && q3 == 2 && q4 == 3) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image3[i][j][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 128; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j][k], image3[i + 128][j][k]);
                }
            }
        }
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j + 128][k], image3[i][j][k]);
                }
            }
        }

    }
    if (q1 == 2 && q2 == 1 && q3 == 3 && q4 == 4) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image3[i][j][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j][k], image3[i][j + 128][k]);
                }
            }
        }
    }
    if (q1 == 2 && q2 == 3 && q3 == 4 && q4 == 1) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image3[i][j][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j][k], image3[i][j + 128][k]);
                }
            }
        }
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j + 128][k], image3[i][j][k]);
                }
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 128; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j][k], image3[i + 128][j][k]);
                }
            }
        }
    }
    if (q1 == 2 && q2 == 3 && q3 == 1 && q4 == 4) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image3[i][j][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j][k], image3[i][j + 128][k]);
                }
            }
        }
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j + 128][k], image3[i][j][k]);
                }
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 128; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j][k], image3[i + 128][j][k]);
                }
            }
        }
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j + 128][k], image3[i][j][k]);
                }
            }
        }
    }
    if (q1 == 2 && q2 == 1 && q3 == 4 && q4 == 3) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image3[i][j][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j][k], image3[i][j + 128][k]);
                }
            }
        }
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j + 128][k], image3[i][j][k]);
                }
            }
        }
    }
    if (q1 == 2 && q2 == 4 && q3 == 3 && q4 == 1) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image3[i][j][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j][k], image3[i][j + 128][k]);
                }
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 128; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j][k], image3[i + 128][j][k]);
                }
            }
        }
    }
    if (q1 == 2 && q2 == 4 && q3 == 1 && q4 == 3) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image3[i][j][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j][k], image3[i][j + 128][k]);
                }
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 128; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j][k], image3[i + 128][j][k]);
                }
            }
        }
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j + 128][k], image3[i][j][k]);
                }
            }
        }
    }
    if (q1 == 3 && q2 == 1 && q3 == 2 && q4 == 4) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image3[i][j][k] = image[i][j][k];
                }
            }
        }
        for (int f = 128, i = 0; i < SIZE / 2; f++, i++) {
            for (int z = 0, j = 128; j < SIZE; z++, j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i + 1][j][k], image3[f][z][k]);
                }
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image3[i][j][k], image3[i][j + 128][k]);
                }
            }
        }
        if (q1 == 3 && q2 == 1 && q3 == 4 && q4 == 2) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        image3[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int f = 128, i = 0; i < SIZE / 2; f++, i++) {
                for (int z = 0, j = 128; j < SIZE; z++, j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i + 1][j][k], image3[f][z][k]);
                    }
                }
            }
            for (int i = 128; i < SIZE; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j + 128][k], image3[i][j][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i][j + 128][k]);
                    }
                }
            }
        }
        if (q1 == 3 && q2 == 2 && q3 == 1 && q4 == 4) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        image3[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }

        }
        if (q1 == 3 && q2 == 2 && q3 == 4 && q4 == 1) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        image3[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i][j + 128][k]);
                    }
                }
            }
            for (int i = 128; i < SIZE; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j + 128][k], image3[i][j][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 128; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i][j + 128][k]);
                    }
                }
            }
        }
        if (q1 == 3 && q2 == 4 && q3 == 1 && q4 == 2) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        image3[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 128; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }
        }

        if (q1 == 3 && q2 == 4 && q3 == 2 && q4 == 1) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        image3[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 128; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }
            for (int i = 128; i < SIZE; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j + 128][k], image3[i][j][k]);
                    }
                }
            }
        }

        if (q1 == 4 && q2 == 1 && q3 == 2 && q4 == 3) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        image3[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 128; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i][j + 128][k]);
                    }
                }
            }
            for (int i = 128; i < SIZE; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j + 128][k], image3[i][j][k]);
                    }
                }
            }
        }
        if (q1 == 4 && q2 == 1 && q3 == 3 && q4 == 2) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        image3[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 128; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i][j + 128][k]);
                    }
                }
            }
        }
        if (q1 == 4 && q2 == 2 && q3 == 3 && q4 == 1) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        image3[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i][j + 128][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 128; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i][j + 128][k]);
                    }
                }
            }
        }
        if (q1 == 4 && q2 == 2 && q3 == 1 && q4 == 3) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        image3[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i][j + 128][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 128; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }
            for (int i = 128; i < SIZE; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j + 128][k], image3[i][j][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i][j + 128][k]);
                    }
                }
            }
        }
        if (q1 == 4 && q2 == 3 && q3 == 1 && q4 == 2) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        image3[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 128; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i][j + 128][k]);
                    }
                }
            }
        }
        if (q1 == 4 && q2 == 3 && q3 == 2 && q4 == 1) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        image3[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 128; j < SIZE; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i + 128][j][k]);
                    }
                }
            }
            for (int i = 128; i < SIZE; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j + 128][k], image3[i][j][k]);
                    }
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        swap(image3[i][j][k], image3[i][j + 128][k]);
                    }
                }
            }
        }
    }
}

void merge0(){
     
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++){
        for(int k = 0; k < RGB; k++){

          image3[i][j][k] = (image[i][j][k]+image2[i][j][k])/2;

      }  
    }
  }
}

void darken1() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
          for( int k = 0; k < RGB ; k++){
            
            image[i][j][k] = (image[i][j][k])/4;
      }
    }
  }
}

void lighten1() {

  for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
          for( int k = 0; k < RGB; k++){

            image[i][j][k] =  (image[i][j][k]);
            
          }  
       }
    }
}

void invert1() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
          for (int k = 0; k < RGB; k++){

            image[i][j][k] = (image[i][j][k])*(-1);
      }
    }
  }
}

void shrinkHalf(){
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          for (int k = 0; k < RGB; k++){

            image3[i][j][k] = (image[i*2][j*2][k]);
      }
    }
  }
} 

void shrinkToaThird(){
    for (int i = 0; i < SIZE/3; i++) {
        for (int j = 0; j< SIZE/3; j++) {
          for (int k = 0; k < RGB; k++){

            image3[i][j][k] = (image[i*3][j*3][k]);
      }
    }
  }
}

void shrinkQuarter(){
    for (int i = 0; i < SIZE/4; i++) {
        for (int j = 0; j< SIZE/4; j++) {
          for (int k = 0; k < RGB; k++){

            image3[i][j][k] = (image[i*4][j*4][k]);
      }
    }
  }
}
