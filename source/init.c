#include "header/globals.h"

void initAudio(Sound sdfx[])
{
    InitAudioDevice();
    
    sdfx[0] = LoadSound("source/assets/fnaf.mp3");
    sdfx[1] = LoadSound("source/assets/click.wav");
}

void initRectangles(Rectangle rectangle[]) {
    Rectangle r0 = {500, 205, 100, 40};
    rectangle[0] = r0;
    
    Rectangle r1 = {510, 305, 80, 30};
    rectangle[1] = r1;
    
    Rectangle r2 = {200, 215, 5, 5};
    rectangle[2] = r2;
    
    Rectangle r3 = {500, 100, 3, 3};
    rectangle[3] = r3;
    
    Rectangle r4 = {450, 380, 3, 3};
    rectangle[4] = r4;
}

void initTextures(Texture2D texture[])
{
    Image image1 = LoadImage("source/assets/title1.png");
    texture[0] = LoadTextureFromImage(image1);
    UnloadImage(image1);
    
    Image image2 = LoadImage("source/assets/title2.png");
    texture[1] = LoadTextureFromImage(image2);
    UnloadImage(image2);
    
    Image image3 = LoadImage("source/assets/title3.png");
    texture[2] = LoadTextureFromImage(image3);
    UnloadImage(image3);
    
    Image image4 = LoadImage("source/assets/cat1.png");
    texture[3] = LoadTextureFromImage(image4);
    UnloadImage(image4);
    
    Image image5 = LoadImage("source/assets/cat2.png");
    texture[4] = LoadTextureFromImage(image5);
    UnloadImage(image5);
    
    Image image6 = LoadImage("source/assets/cat3.png");
    texture[5] = LoadTextureFromImage(image6);
    UnloadImage(image6);
    
    Image image7 = LoadImage("source/assets/cat4.png");
    texture[6] = LoadTextureFromImage(image7);
    UnloadImage(image7);
    
    Image image8 = LoadImage("source/assets/warning.png");
    texture[7] = LoadTextureFromImage(image8);
    UnloadImage(image8);
}

