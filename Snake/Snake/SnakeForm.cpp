#include "SnakeForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main() {
	// Базові налаштування для запуску форми
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Запускаємо вказану форму
	Snake::SnakeForm snake;
	Application::Run(% snake);
}

// Структура, яка зручна для 2D простору 
struct Vector2 {
	int X, Y;
};

Vector2 direction; // Напрямок змійки
Vector2 positionFruit; // Позиція фрукта
Vector2 gameArea; // Ігрова зона


// Констркутор форми
Snake::SnakeForm::SnakeForm(void)
{
	InitializeComponent();

	// Задаємо розмір ігрової зони
	gameArea.X = 420;
	gameArea.Y = 420;

	firstLaunch = true; // перший запуск
	NewGame(); // нова гра
}

// Реалізація дій в грі
void Snake::SnakeForm::GeneratePositionFruit()
{
	// Генеруємо випадкову позицію фрукта
	Random^ rand = gcnew Random();
	positionFruit.X = rand->Next(10, gameArea.X); // 10 - зміщення відносно боків форми 
	positionFruit.Y = rand->Next(111, gameArea.Y); // 111 - зміщення верхньої границі відносно верху форми 

	// Перевірка, щоб фрукт не створився на змійці
	for (int i = 0; i < score; i++) {
		if (positionFruit.X == Snake[i]->Location.X && positionFruit.Y == Snake[i]->Location.Y) {
			GeneratePositionFruit();
		}
	}

	//// Перетворимо значення щоб було кратно кроку
	int tempX = positionFruit.X % step;
	positionFruit.X -= tempX;

	int tempY = positionFruit.Y % step;
	positionFruit.Y -= tempY;

	// Присвоюємо позицію фрукту
	fruit->Location = Point(positionFruit.X, positionFruit.Y);

	// Додаємо об'єкт на форму
	this->Controls->Add(fruit);

}

void Snake::SnakeForm::Eating()
{
	// Перевіряємо позицію голови змії та позицію фрукта
	if (Snake[0]->Location.X == positionFruit.X && Snake[0]->Location.Y == positionFruit.Y) {
		labelScore->Text = "Рахунок: " + ++score;

		// Додаємо новий елемент змійці
		Snake[score] = gcnew PictureBox();
		Snake[score]->Location = Point(Snake[score - 1]->Location.X + step * direction.X, Snake[score - 1]->Location.Y - step * direction.Y);
		Snake[score]->BackColor = Color::Red;
		Snake[score]->Width = step;
		Snake[score]->Height = step;
		this->Controls->Add(Snake[score]);

		GeneratePositionFruit();
	}
}

void Snake::SnakeForm::Movement()
{
	// Рухаємо кожний елемент змійки
	for (int i = score; i >= 1; i--) {
		Snake[i]->Location = Snake[i - 1]->Location;
	}
	Snake[0]->Location = Point(Snake[0]->Location.X + direction.X * step, Snake[0]->Location.Y + direction.Y * step);
}

void Snake::SnakeForm::EatYourself()
{
	// Перевіряємо позицію кожної частини змійки
	for (int i = 1; i < score; i++) {
		if (Snake[0]->Location == Snake[i]->Location) {
			GameOver();
		}
	}
}

void Snake::SnakeForm::GameOver()
{
	play = true;
	die = true;

	labelGameOver->Visible = true;
}

void Snake::SnakeForm::NewGame()
{
	// Якщо ініціалізація була, то видаляємо об'єкти з форми
	if (!firstLaunch) {
		this->Controls->Remove(fruit);

		for (int i = 0; i <= score; i++) {
			this->Controls->Remove(Snake[i]);
		}

		score = 0;
	}
	else {
		firstLaunch = false;
	}

	// Ініціалізуємо змійку
	Snake = gcnew array <PictureBox^,1>(400);
	Snake[0] = gcnew PictureBox();
	Snake[0]->Location = Point(200, 200);
	Snake[0]->BackColor = Color::Blue; 
	Snake[0]->Width = step;
	Snake[0]->Height = step;

	score = 0;
	this->Controls->Add(Snake[0]);

	// Ініціалізуємо фрукт
	fruit = gcnew PictureBox();
	fruit->BackColor = Color::Yellow;
	fruit->Width = step;
	fruit->Height = step;
	GeneratePositionFruit();

	// Задаємо інтервал оновлення і запускаємо таймер для оновленян
	timer->Interval = updateInterval;
	timer->Start();

	// Задаємо напрямок при запуску
	direction.X = 1;
	direction.Y = 0;

	// Дозволяємо грати
	play = true;
	die = false;

	labelScore->Text = "Рахунок: 0";

	// Приховуємо не потрібні компоненти на формі
	labelGameOver->Visible = false;
	groupBoxSettings->Visible = false;

}

void Snake::SnakeForm::CheckBorders()
{
	if (Snake[0]->Location.X >= RightBorder->Location.X || Snake[0]->Location.X <= LeftBorder->Location.X) {
		GameOver();
	}

	if (Snake[0]->Location.Y <= TopBorder->Location.Y || Snake[0]->Location.Y >= BottomBorder->Location.Y) {
		GameOver();
	}
}


// Реалізація подій
System::Void Snake::SnakeForm::новаГраToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	NewGame();
}

System::Void Snake::SnakeForm::паузапродовжитиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (play) {
		play = false;
	}
	else {
		play = true;
		timer->Start();
	}
}

System::Void Snake::SnakeForm::налаштуванняToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (groupBoxSettings->Visible == false) {
		// Призупиняємо гру
		play = false;

		buttonApplySpeed->Enabled = true;
		numericUpDownSpeedSnake->Enabled = true;
		groupBoxSettings->Visible = true;
	}
	else {
		// Запускаємо гру
		play = true;
		timer->Start();

		buttonApplySpeed->Enabled = false;
		numericUpDownSpeedSnake->Enabled = false;
		groupBoxSettings->Visible = false;
	}
}

System::Void Snake::SnakeForm::інформаціяПроГруToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("1. Для керування використовуй стрілки!\n2. Їж фрукти для набору рахунку та збільшення змійки!\n3. Не можна їсти себе і врізатися в стінки!\n4. Якщо все зрозуміло, то бажаю гарної гри!", "Правила гри!");
}
	
System::Void Snake::SnakeForm::вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void Snake::SnakeForm::buttonApplySpeed_Click(System::Object^ sender, System::EventArgs^ e)
{
	updateInterval = Convert::ToSingle(numericUpDownSpeedSnake->Value);
	timer->Interval = updateInterval;

	buttonApplySpeed->Enabled = false;
	numericUpDownSpeedSnake->Enabled = false;
	groupBoxSettings->Visible = false;

	// Запускаємо гру
	play = true;
	timer->Start();
}

System::Void Snake::SnakeForm::SnakeForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	// Зчитуємо натиснуту клавішу
	if (e->KeyCode.ToString() == "Right") {
		direction.X = 1;
		direction.Y = 0;
	}
	else if (e->KeyCode.ToString() == "Left") {
		direction.X = -1;
		direction.Y = 0;
	}
	else if (e->KeyCode.ToString() == "Up") {
		direction.Y = -1;
		direction.X = 0;
	}
	else if (e->KeyCode.ToString() == "Down") {
		direction.Y = 1;
		direction.X = 0;
	}
}

void Snake::SnakeForm::GameForm_Update(Object^ object, EventArgs^ e)
{
	if (!die && play) {
		// Задає рух змійці
		Movement();

		Eating(); // перевірка, чи з'їли фрукт
		EatYourself(); // перевірка, чи з'їли себе
		CheckBorders(); // перевірка, на зіткнення зі стіною
	}
	else if (die && play) {
		timer->Stop();
		MessageBox::Show("Гру закінчено!", "Увага!");
	}
	else if (!play && !die) {
		timer->Stop();
		MessageBox::Show("Гру призупинено!", "Увага!");
	}
}

