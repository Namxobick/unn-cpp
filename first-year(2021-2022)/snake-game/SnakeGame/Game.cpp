#include "Game.h"

Game::Game(int width, int height, int startLengthSnake, char headStyle, char bodyStyle)
{
    do {
        system("cls");
        _gameMap = GameMap(width, height);
        _snake = Snake(startLengthSnake, headStyle, bodyStyle);
        _food = Food();
        SpawnFood();
        _score = 0;
        _speed = StartSpeed;
        Start();
    } while (ReGame());
}

void Game::SpawnFood()
{
    bool reGenerateFood;
    do
    {
        _food.GenerateFood(_gameMap.GetWidth(), _gameMap.GetHeight());
        auto snakeBody = _snake.GetBody();
        if (std::count(snakeBody.begin(), snakeBody.end(), _food.GetPosition()) > 0)
            reGenerateFood = true;
        else
            reGenerateFood = false;

    } while (reGenerateFood);
}

void Game::ClearScreen()
{
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Game::CheckEating()
{
    int xSnakeHead = _snake.GetHead().first;
    int ySnakeHead = _snake.GetHead().second;
    int xFood = _food.GetPosition().first;
    int yFood = _food.GetPosition().second;

    if (xSnakeHead == xFood && ySnakeHead == yFood) 
    {
        _score++;
        _snake.GrowUp();
        SpawnFood();
    }
}

void Game::Start()
{
    while (!(CkeckHittingWall() || CheckHittingHimself())) {
        ClearScreen();
        _gameMap.Draw(_snake, _food);
        _speed = ((StartSpeed - 2 * _score) >= 0) ? (StartSpeed - 2 * _score) : 0;
        _snake.SetDirection(Controls());
        _snake.Move();
        CheckEating();
        Controls();
        Sleep(_speed);
    }
}

bool Game::ReGame()
{
    std::cout << "     Game Over     " << std::endl;
    std::cout << "Replay? (y / n) " << std::endl;
    char c;
    bool isvalid = false;

    do {
        std::cin >> c;
        if (c == 'y')
            return true;
        else if (c == 'n')
            return false;
        else {
            std::cout << "invalid entry\n";
            isvalid = true;
        }
    } while (isvalid);
}

bool Game::CkeckHittingWall()
{
    int xSnakeHead = _snake.GetHead().first;
    int ySnakeHead = _snake.GetHead().second;
    auto wallPoints = _gameMap.GetWall();

    for (const auto& point : wallPoints)
        if (xSnakeHead == point.first && ySnakeHead == point.second)
            return true;

    return false;
}

bool Game::CheckHittingHimself()
{
    auto snakePoints = _snake.GetBody();
    auto snakeHead = _snake.GetHead();
    if (std::count(snakePoints.begin(), snakePoints.end(), snakeHead) > 1)
        return true;

    return false;
}

char Game::Controls()
{
    /*Определяет, была ли клавиша нажата или нажата во время вызова функции, и была ли клавиша нажата после
    предыдущего вызова GetAsyncKeyState.*/
    if (GetAsyncKeyState(VK_UP) && _snake.GetDirection() != 's')
        return 'w';
    else if (GetAsyncKeyState(VK_DOWN) && _snake.GetDirection() != 'w')
        return 's';
    else if (GetAsyncKeyState(VK_RIGHT) && _snake.GetDirection() != 'a')
        return 'd';
    else if (GetAsyncKeyState(VK_LEFT) && _snake.GetDirection() != 'd')
        return 'a';
}