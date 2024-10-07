#include <stdio.h>

#include "header/globals.h"
#include "header/init.h"

int main(void)
{ 
    int frameCount = 0;   
    Vector2 mousePoint = { 0.0f, 0.0f };
    GameState state = TITLE;	

    InitWindow(SCREEN_W, SCREEN_H, "Cat Clicker");

    /* === init audio === */
    Sound sdfx[2];
    initAudio(sdfx);
    
    /* === init textures == */
    Texture2D texture[9];
    initTextures(texture);
    
    Rectangle boundingBoxes[5];
    initRectangles(boundingBoxes);
	
    SetTargetFPS(30);
	while(!WindowShouldClose()) {
        mousePoint = GetMousePosition();
        //printf("THE STATE IS: %d\n", state);
    
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) PlaySound(sdfx[1]);
        
        switch(state) {
            case TITLE:
                if(CheckCollisionPointRec(mousePoint, boundingBoxes[0]))
                    state = TITLE1;
                if(CheckCollisionPointRec(mousePoint, boundingBoxes[1]))
                    state = TITLE2;
                break;
            case TITLE1:
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    state = GAME;  
                if(!CheckCollisionPointRec(mousePoint, boundingBoxes[0]))
                    state = TITLE;
                break;
            case TITLE2:
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    goto unload;  
                if(!CheckCollisionPointRec(mousePoint, boundingBoxes[1]))
                    state = TITLE;
                break;
            case GAME:
                if(CheckCollisionPointRec(mousePoint, boundingBoxes[2])) {
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                         state = GAME1;
                }
                break;
            case GAME1:
                if(CheckCollisionPointRec(mousePoint, boundingBoxes[3])) {
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                         state = GAME2;
                }
                break;
            case GAME2:
                if(CheckCollisionPointRec(mousePoint, boundingBoxes[4])) {
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                         state = GAME3;
                }
                break;
            case GAME3:
                StopSound(sdfx[1]);
                if(frameCount > 30 * 3) state = FINAL;
                frameCount++;
                break;
            case FINAL:
                StopSound(sdfx[1]);
                frameCount++;
                if(!IsSoundPlaying(sdfx[0]))
                    PlaySound(sdfx[0]);
                if(frameCount > 30 * 4) goto unload;
                break;
        }
        
        BeginDrawing();
			ClearBackground(DARKBLUE);
            /* === screen swap === */
            switch(state) {
                case TITLE:
                    DrawTexture(texture[0], 0, 0, WHITE);             
                    break;
                case TITLE1:
                    DrawTexture(texture[1], 0, 0, WHITE);
                    break;
                case TITLE2:
                    DrawTexture(texture[2], 0, 0, WHITE);
                    break;
                case GAME:
                    DrawTexture(texture[3], 0, 0, WHITE);
                    DrawRectangleRec(boundingBoxes[2], GREEN);
                    break;
                case GAME1:
                    DrawTexture(texture[4], 0, 0, WHITE);
                    DrawRectangleRec(boundingBoxes[3], GREEN);
                    break;
                case GAME2:
                    DrawTexture(texture[5], 0, 0, WHITE);
                    DrawRectangleRec(boundingBoxes[4], GREEN);
                    break;
                case GAME3:
                    DrawTexture(texture[7], 0, 0, WHITE);
                    break;
                case FINAL:
                    if(frameCount > 90 && frameCount < 95) // takes 5~ frames for the audio to play, idk y
                        DrawRectangle(0,0, SCREEN_W, SCREEN_H, BLACK);
                    else
                        DrawTexture(texture[6], 0, 0, WHITE);
                    break;
            }
            
		EndDrawing();
	}
    
unload:
    for(int i = 0; i < 2; i++) UnloadSound(sdfx[i]);
    CloseAudioDevice();   
    for(int i = 0; i < 9; i++) UnloadTexture(texture[i]);
	CloseWindow();
	return 0;
}
