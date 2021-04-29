// MyGame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
#include <iterator>
#include <Windows.h>

using namespace std;

class obj
{
private:
	pair <float, float> pos;
	pair <float, float> vel;
	char ch;
public:
	obj(char charcter, pair <float,float> position, pair <float, float> velocity)
	{
		ch = charcter;
		pos = position;
		vel = velocity;
	}
	char getCh()
	{
		return ch;
	}
	pair <float, float> getPos()
	{
		return pos;
	}
};

bool GameOver;
const int width = 60;
const int height = 20;
list <obj> objects;

void init()
{
	GameOver = false; //Говорим программе что игра не окончена
	//Создаем объект Игрок
	char ch = '@';
	float x = (width / 2);
	float y = (height / 2);
	pair <float, float> pos(x, y);
	pair <float, float> vel(0.0, 0.0);
	obj player(ch,pos,vel);
	objects.push_back(player);
	//Создаем стены вокруг игрового поля
	for (int i = 0; i <= height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			if (i == 0 || i == height || j == 0 || j == width)
			{
				ch = '#';
				x = j;
				y = i;
				pair <float, float> pos(x, y);
				obj wall(ch, pos, vel);
				objects.push_back(wall);
			}
		}
	}
}

void draw()
{

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	for (list <obj>::iterator it = objects.begin(); it != objects.end(); it++)
	{
		COORD coord = { it->getPos().first, it->getPos().second };
		SetConsoleCursorPosition(hStdOut, coord);
		cout << it->getCh();
	}
}

void input()
{

}

void logic()
{

}

int main()
{
    init();
	while (!GameOver)
	{
		draw();
		input();
		logic();
	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
