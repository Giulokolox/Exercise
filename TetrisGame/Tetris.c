#include "raylib.h"
#include <time.h>
#include <string.h>
#include "Tetris.h"

//Game Map
int stage[] =                                   
{
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
//All Tetrimino's pose
const int lTetromino0[] =               
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0,
};

const int lTetromino90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    1, 0, 0, 0,
    0, 0, 0, 0,
};

const int lTetromino180[] =
{
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int lTetromino270[] =
{
    0, 0, 1, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino90[] =
{
    1, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino180[] =
{
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino270[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 1, 0,
    0, 0, 0, 0,
};


const int oTetromino[] =
{
    1, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int sTetromino0[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int sTetromino90[] =
{
    0, 0, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 0,
};

const int sTetromino180[] =
{
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
};

const int sTetromino270[] =
{
    0, 0, 0, 0,
    1, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
};


const int tTetromino0[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int tTetromino90[] =
{
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int tTetromino180[] =
{
    0, 1, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int tTetromino270[] =
{
    1, 0, 0, 0,
    1, 1, 0, 0,
    1, 0, 0, 0,
    0, 0, 0, 0,
};

const int iTetromino0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
};

const int iTetromino90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int iTetromino180[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
};

const int iTetromino270[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int zTetromino0[] =
{
    0, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0,
};

const int zTetromino90[] =
{
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 0,
    0, 0, 0, 0,
};

const int zTetromino180[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int zTetromino270[] =
{
    1, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};
//Colors of tetrominos
const Color colorTypes[10] =        
    {
        {156, 156, 156, 255},
        {85, 43, 158, 255},
        {56, 255, 85, 255},
        {255, 255, 63, 255},
        {255, 42, 85, 255},
        {255, 100, 85, 255},
        {97, 5, 85, 255},
        {85, 45, 63, 255},
        {255,255,255,255},
        {0,0,0,255},
};

//Score Level
int score = 0;
int scoreLines = 10;
int lvlScore = 0;

//all different tetromino's type
const int *tetrominoTypes[7][4] =
    {
        {zTetromino0, zTetromino90, zTetromino180, zTetromino270},  
        {sTetromino0, sTetromino90, sTetromino180, sTetromino270},
        {tTetromino0, tTetromino90, tTetromino180, tTetromino270},
        {oTetromino, oTetromino, oTetromino, oTetromino},
        {iTetromino0, iTetromino90, iTetromino180, iTetromino270},
        {jTetromino0, jTetromino90, jTetromino180, jTetromino270},
        {lTetromino0, lTetromino90, lTetromino180, lTetromino270},
};

//Draw tetromino on stage
void drawTetromino(const Color currentColor, const int startOffsetX, const int startOffsetY, const int tetrominoStartX, const int tetrominoStartY, const int *tetromino)
{
    for (int y = 0; y < TETROMINO_SIZE; y++)
    {
        for (int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int offset = y * TETROMINO_SIZE + x;

            if (tetromino[offset] == 1)
            {
                DrawRectangle((x + tetrominoStartX) * TILE_SIZE + startOffsetX, (y + tetrominoStartY) * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, currentColor);
            }
        }
    }
}

//reset line every time when a line or more lines are completed
void ResetLines(int startLineY)                                   
{
    for (int y = startLineY; y >= 0; y--)
    {
        for (int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            const int offset_below = (y + 1) * STAGE_WIDTH + x;

            if (stage[offset_below] == 0 && stage[offset] > 0)
            {
                stage[offset_below] = stage[offset];
                stage[offset] = 0;
            }
        }
    }
}

//delete line every time when a line or more lines are completed
void DeleteLines(int startOffsetX, int startOffsetY)
{
    Sound lineClearMusic = LoadSound("./CompletedLine.wav"); //sound for a completed line
    SetSoundVolume(lineClearMusic, 0.1f);
    float timerDeleteLines = .3f;
    float timer = timerDeleteLines;
    int count = 0;
    int startDeleteOffsetY;
    for (int y = 0; y < STAGE_HEIGHT - 1; y++)
    {
        int checkLine = 1;

        for (int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;

            if (stage[offset] == 0)
            {
                checkLine = 0;
                break;
            }
        }
        if (checkLine)
        {       
            count++;
            if (count == 1)
            {
                startDeleteOffsetY = y;
            }    
            for (int x = 1; x < STAGE_WIDTH - 1; x++)
            {               
                const int offset = y * STAGE_WIDTH + x;
                stage[offset] = 9;  //white color             
            }
            
        }
    }
    //when you complete the line it will change color and disappear
    if (count > 0)
    {
        PlaySound(lineClearMusic); 
        while(timer >=0)
        {
           BeginDrawing();
            
           for (int z = 0; z < STAGE_HEIGHT; z++)
           {
                for (int x = 0; x < STAGE_WIDTH; x++)
                {
                 const int offset = z * STAGE_WIDTH + x;
                 const int color = stage[offset];
                 
                
                  if (stage[offset] != 0)
                   {
                      DrawRectangle(x * TILE_SIZE + startOffsetX, z * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, colorTypes[color - 1]);
                     DrawRectangleLines(x * TILE_SIZE + startOffsetX, z * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, BLACK);
                   }
                } 
           }
           EndDrawing();
           timer -= GetFrameTime();
        }
        // timer for deletelines "animation"
        timer = timerDeleteLines;

        //when you complete one or more lines the score increases
        for (int i = 0; i < count; i++)
        {
            int y = startDeleteOffsetY + i;
            const int offset = y * STAGE_WIDTH + 1;
            memset(stage + offset, 0, (STAGE_WIDTH - 2) * sizeof(int));          
            ResetLines(y);
        }   
        score += (scoreLines * count);
    }  
}

int main(int argc, char **argv, char **environ)
{
   
    //stage size
    const int windowWidth = 600;
    const int windowHeight = 700;
    //stage position
    const int startOffsetX = (windowWidth / 2) - ((STAGE_WIDTH * TILE_SIZE) / 2);
    const int startOffsetY = (windowHeight / 2) - ((STAGE_HEIGHT * TILE_SIZE) / 2);
    //spawnpoint of tetromino 
    const int tetrominoStartX = STAGE_WIDTH / 2;
    const int tetrominoStartY = 0;
    //tetromino current position
    int currentTetrominoX = tetrominoStartX;
    int currentTetrominoY = tetrominoStartY;
    //music settings
    float timeForMusic = 0.0f;
    int isSoundPlaying = 0;
    const float musicBackgroundDuration = 83.0f;

    int gameOver = 0;

    time_t unixTime;

    time(&unixTime);

    SetRandomSeed(unixTime);
    //spawn random tetromino types
    int currentTetrominoType = GetRandomValue(0, 6);
    int currentRotation = 0;
    //Tetromino movement
    float moveTetrominoDownTimer = 1.f;
    float timeToMoveTetrominoDown = moveTetrominoDownTimer;
    int currentColor = GetRandomValue(0, 7);

    TraceLog(LOG_INFO, "Number of arguments : %d", argc);

    for (int i = 0; i < argc; i++)
    {
        TraceLog(LOG_INFO, "Argument : %d = %s", i, argv[i]);
    }

    while (*environ != 0)
    {
        TraceLog(LOG_INFO, "Argument : %s", *environ);
        environ++;
    }

    InitWindow(windowWidth, windowHeight, "Title");

    // Sound
    InitAudioDevice();

    Sound backgroundMusic = LoadSound("./Tetris Theme.wav");
    SetSoundVolume(backgroundMusic, 0.1f);


    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (gameOver == 0)
        {
            if (score - lvlScore == 0)
            {
                //logic to move the tetromino faster based on your score
                moveTetrominoDownTimer-=0.200f;
                TraceLog(LOG_INFO, "Velocity :  = %d", moveTetrominoDownTimer );
                lvlScore += 20;
            }
            
            //your score
            DrawText(TextFormat("SCORE: %d", score),windowWidth / 2 + 150, 30, 20, WHITE);

            if (isSoundPlaying == 0)
            {
                //background music
                PlaySound(backgroundMusic);
                isSoundPlaying = 1;
            }
            else
            {
                timeForMusic += GetFrameTime();
                if (timeForMusic >= musicBackgroundDuration)
                {
                    StopSound(backgroundMusic);
                    isSoundPlaying = 0;
                    timeForMusic = 0.0f;
                }
            }

            timeToMoveTetrominoDown -= GetFrameTime();
            //change tetromino rotation
            if (IsKeyPressed(KEY_SPACE))
            {
                const int lastRotation = currentRotation;

                currentRotation++;

                if (currentRotation > 3)
                {
                    currentRotation = 0;
                }

                if (CheckCollision(currentTetrominoX, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentRotation]))
                {
                    currentRotation = lastRotation;
                }
            }

            if (IsKeyPressed(KEY_RIGHT))
            {
                // No need to check overflow, wall is your protector
                if (!CheckCollision(currentTetrominoX + 1, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentRotation]))
                {
                    currentTetrominoX++;
                }
            }
            if (IsKeyPressed(KEY_LEFT))
            {
                // No need to check overflow, wall is your protector
                if (!CheckCollision(currentTetrominoX - 1, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentRotation]))
                {
                    currentTetrominoX--;
                }
            }

            if (timeToMoveTetrominoDown <= 0 || IsKeyPressed(KEY_DOWN))
            {
                if (!CheckCollision(currentTetrominoX, currentTetrominoY + 1, tetrominoTypes[currentTetrominoType][currentRotation]))
                {
                    currentTetrominoY++;
                    timeToMoveTetrominoDown = moveTetrominoDownTimer;
                }

                else
                {
                    // const int currentTetrominoOffset = currentTetrominoY * STAGE_WIDTH + currentTetrominoX;

                    // stage[currentTetrominoOffset] = 1;

                    for (int y = 0; y < TETROMINO_SIZE; y++)
                    {
                        for (int x = 0; x < TETROMINO_SIZE; x++)
                        {
                            const int offset = y * TETROMINO_SIZE + x;

                            const int *tetromino = tetrominoTypes[currentTetrominoType][currentRotation];

                            if (tetromino[offset] == 1)
                            {
                                const int offset_stage = (y + currentTetrominoY) * STAGE_WIDTH + (x + currentTetrominoX);
                                stage[offset_stage] = currentColor + 1;
                            }
                        }
                    }

                    DeleteLines(startOffsetX, startOffsetY);

                    currentTetrominoX = tetrominoStartX;
                    currentTetrominoY = tetrominoStartY;

                    currentTetrominoType = GetRandomValue(0, 6);
                    currentRotation = 0;
                    currentColor = GetRandomValue(0, 7);
                }
            }
            // if you press up the tetromino will immediately place itself on the ground
            if (IsKeyPressed(KEY_UP))
            {
                while (!CheckCollision(currentTetrominoX, currentTetrominoY + 1, tetrominoTypes[currentTetrominoType][currentRotation]))
                {
                    currentTetrominoY++;
                }                
            }
            
            BeginDrawing();
            //background game scene
            ClearBackground(BLACK);

            for (int y = 0; y < STAGE_HEIGHT; y++)
            {
                for (int x = 0; x < STAGE_WIDTH; x++)
                {
                    const int offset = y * STAGE_WIDTH + x;
                    const int color = stage[offset];

                    if (stage[offset] != 0)
                    {
                        DrawRectangle(x * TILE_SIZE + startOffsetX, y * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, colorTypes[color - 1]);
                    }

                    DrawRectangleLines(x * TILE_SIZE + startOffsetX, y * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, BLACK);
                }
            }

            if (currentTetrominoX == tetrominoStartX)
            {
                if (CheckCollision(currentTetrominoX, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentRotation]))
                {
                    gameOver = 1;
                    EndDrawing();
                    continue;
                }
            }

            drawTetromino(colorTypes[currentColor], startOffsetX, startOffsetY, currentTetrominoX, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentRotation]);

            EndDrawing();
        }
        else
        {
            StopSound(backgroundMusic);
            BeginDrawing();
            ClearBackground(BLACK);
            //Game over scene
            DrawText("GAME OVER", windowWidth / 2 - 250, 50, 80, WHITE);                                                                  
            DrawText(TextFormat("SCORE: %d\n\nPRESS R TO RESTART\n\nPRESS ESC TO EXIT", score), windowWidth / 2 - 120, 300, 20, WHITE);
            //restart button after you lose
            if (IsKeyPressed(KEY_R))                               
            {
                currentTetrominoX = tetrominoStartX;
                currentTetrominoY = tetrominoStartY;
                moveTetrominoDownTimer = 1.0f;
                timeToMoveTetrominoDown = moveTetrominoDownTimer;
                currentTetrominoType = GetRandomValue(0, 6);
                currentRotation = 0;
                currentColor = GetRandomValue(0, 7);
                for (int y = 0; y < STAGE_HEIGHT - 1; y++)
                {
                    for (int x = 1; x < STAGE_WIDTH - 1; x++)
                    {
                        const int offset = y * STAGE_WIDTH + x;
                        if (stage[offset] != 0)
                        {
                            stage[offset] = 0;
                        }                                           
                    }
                }
                PlaySound(backgroundMusic);
                score = 0;
                gameOver = 0;
            }
            // Exit button after you lose
            if(IsKeyPressed(KEY_ESCAPE))   
            {
                CloseWindow();
            }
            EndDrawing();
        }
    }
    UnloadSound(backgroundMusic);
    CloseAudioDevice();
    return 0;
}