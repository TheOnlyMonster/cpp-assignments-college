#include <bits/stdc++.h>
#include "bmplib.cpp"
using namespace std;

unsigned char image[SIZE][SIZE];
void BWImage();
void invertImage();
void mergeImage();
void flipImage();
void rotateImage();
void mirrorImage();
int main(){
    int num;
    char fileName[100];
    cout<<"Please Enter File Name of The Image to Process: "<<endl;
    cin>>fileName;
    strcat(fileName,".bmp");
    readGSBMP(fileName,image);

    char newFile[100];
    cout<<"Enter New File Name to Store Applied Filter: "<<endl;
    cin>>newFile;
    strcat(newFile,".bmp");

    bool b=true;
    while(b){
        cout<<"Please select a filter to apply or 0 to exit:\n"<<
        "1- Black & White Filter\n"<<
        "2- Invert Filter\n"<<
        "3- Merge Filter\n"<<
        "4- Flip Image\n"<<
        "5- Rotate Image\n"<<
        "================================\n" <<
        "6- Darken and Lighten Image\n" <<
        "7- Detect Image Edges\n"<<
        "8- Enlarge Image\n"<<
        "9- Shrink Image\n"<<
        "a- Mirror 1/2 Image\n"<<
        "b- Shuffle Image\n"<<
        "c- Blur Image\n"<<
        "s- Save the image to a file\n"<<
        "0- Exit\n";
        cin>>num;
        if(num==1){
            BWImage();
        }
        else if(num==2){
            invertImage();
        }
        else if(num==3){
            mergeImage();
        }
        else if(num==4){
            flipImage();
        }
        else if(num==5){
            rotateImage();
        }
        else{
            writeGSBMP(newFile,image);
            b=false;
        }
    }
}
void BWImage(){
    int sum=0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sum+=image[i][j];
        }
    }
    int avg = sum / (256 * 256);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if(image[i][j]>avg){
                image[i][j]=255;
            }
            else if(image[i][j]<avg){
                image[i][j]=0;
            }
        }
    }
    
}
void invertImage(){
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if(image[i][j]==255){
                image[i][j]==0;
            }
            else if(image[i][j]==0){
                image[i][j]==255;
            }
            else{
                image[i][j]=255-image[i][j];
            }
        }
        
    }
}
void mergeImage(){
    unsigned char secondFileName[SIZE][SIZE];
    char secondImage[100];
    cout<<"Enter the Name of Second Image to Merge with:"<<endl;
    cin>>secondImage;
    strcat(secondImage,".bmp");
    readGSBMP(secondImage,secondFileName);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j]=(image[i][j]/2) + (secondFileName[i][j]/2);
        }
    }
}
void flipImage(){
    char c;
    unsigned char tempImage[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            tempImage[i][j]=image[i][j];
        }
        
    }
    cout<<"Flip (h)orizontally or (v)ertically?"<<endl;
    cin>>c;
    if(c=='h'){
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j]=tempImage[256-i][j];
            }
        }
    }
    else if(c=='v'){
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j]=tempImage[i][256-j];
            }
        }
    }
}
void rotateImage(){
    int n;
    unsigned char tempImage[SIZE][SIZE],secTempImage[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            tempImage[i][j]=image[i][j];
            secTempImage[i][j]=image[i][j];
        }
        
    }
    
    cout<<"Rotate (90), (180) or (270) degrees?"<<endl;
    cin>>n;
    if(n==90){
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j]=tempImage[j][i];
                secTempImage[i][j]=tempImage[j][i];
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j]=secTempImage[256-i][j];
            }
        }
    }
    else if(n==180){
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j]=tempImage[256-i][j];
                secTempImage[i][j]=tempImage[256-i][j];
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j]=secTempImage[i][256-j];
            }
        }
    }
    else if(n==270){
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j]=tempImage[j][i];
                secTempImage[i][j]=tempImage[j][i];
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j]=secTempImage[i][256-j];
            }
        }
    }
}
void mirrorImage(){
    int num;
    cout<<"Enter a number to Apply Filter: ";
    cin>>num;
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j]=image[i][256-j];
        }
        
    }
    
}