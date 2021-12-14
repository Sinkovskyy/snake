#include "SnakeForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main() {
	// ����� ������������ ��� ������� �����
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// ��������� ������� �����
	Snake::SnakeForm snake;
	Application::Run(% snake);
}

// ���������, ��� ������ ��� 2D �������� 
struct Vector2 {
	int X, Y;
};

Vector2 direction; // �������� �����
Vector2 positionFruit; // ������� ������
Vector2 gameArea; // ������ ����


// ����������� �����
Snake::SnakeForm::SnakeForm(void)
{
	InitializeComponent();

	// ������ ����� ������ ����
	gameArea.X = 420;
	gameArea.Y = 420;

	firstLaunch = true; // ������ ������
	NewGame(); // ���� ���
}

// ��������� �� � ��
void Snake::SnakeForm::GeneratePositionFruit()
{
	// �������� ��������� ������� ������
	Random^ rand = gcnew Random();
	positionFruit.X = rand->Next(10, gameArea.X); // 10 - ������� ������� ���� ����� 
	positionFruit.Y = rand->Next(111, gameArea.Y); // 111 - ������� ������� ������� ������� ����� ����� 

	// ��������, ��� ����� �� ��������� �� �����
	for (int i = 0; i < score; i++) {
		if (positionFruit.X == Snake[i]->Location.X && positionFruit.Y == Snake[i]->Location.Y) {
			GeneratePositionFruit();
		}
	}

	//// ����������� �������� ��� ���� ������ �����
	int tempX = positionFruit.X % step;
	positionFruit.X -= tempX;

	int tempY = positionFruit.Y % step;
	positionFruit.Y -= tempY;

	// ���������� ������� ������
	fruit->Location = Point(positionFruit.X, positionFruit.Y);

	// ������ ��'��� �� �����
	this->Controls->Add(fruit);

}

void Snake::SnakeForm::Eating()
{
	// ���������� ������� ������ �쳿 �� ������� ������
	if (Snake[0]->Location.X == positionFruit.X && Snake[0]->Location.Y == positionFruit.Y) {
		labelScore->Text = "�������: " + ++score;

		// ������ ����� ������� �����
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
	// ������ ������ ������� �����
	for (int i = score; i >= 1; i--) {
		Snake[i]->Location = Snake[i - 1]->Location;
	}
	Snake[0]->Location = Point(Snake[0]->Location.X + direction.X * step, Snake[0]->Location.Y + direction.Y * step);
}

void Snake::SnakeForm::EatYourself()
{
	// ���������� ������� ����� ������� �����
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
	// ���� ����������� ����, �� ��������� ��'���� � �����
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

	// ���������� �����
	Snake = gcnew array <PictureBox^,1>(400);
	Snake[0] = gcnew PictureBox();
	Snake[0]->Location = Point(200, 200);
	Snake[0]->BackColor = Color::Blue; 
	Snake[0]->Width = step;
	Snake[0]->Height = step;

	score = 0;
	this->Controls->Add(Snake[0]);

	// ���������� �����
	fruit = gcnew PictureBox();
	fruit->BackColor = Color::Yellow;
	fruit->Width = step;
	fruit->Height = step;
	GeneratePositionFruit();

	// ������ �������� ��������� � ��������� ������ ��� ���������
	timer->Interval = updateInterval;
	timer->Start();

	// ������ �������� ��� �������
	direction.X = 1;
	direction.Y = 0;

	// ���������� �����
	play = true;
	die = false;

	labelScore->Text = "�������: 0";

	// ��������� �� ������ ���������� �� ����
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


// ��������� ����
System::Void Snake::SnakeForm::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	NewGame();
}

System::Void Snake::SnakeForm::���������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (play) {
		play = false;
	}
	else {
		play = true;
		timer->Start();
	}
}

System::Void Snake::SnakeForm::������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (groupBoxSettings->Visible == false) {
		// ������������ ���
		play = false;

		buttonApplySpeed->Enabled = true;
		numericUpDownSpeedSnake->Enabled = true;
		groupBoxSettings->Visible = true;
	}
	else {
		// ��������� ���
		play = true;
		timer->Start();

		buttonApplySpeed->Enabled = false;
		numericUpDownSpeedSnake->Enabled = false;
		groupBoxSettings->Visible = false;
	}
}

System::Void Snake::SnakeForm::����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("1. ��� ��������� ������������ ������!\n2. �� ������ ��� ������ ������� �� ��������� �����!\n3. �� ����� ���� ���� � �������� � �����!\n4. ���� ��� ��������, �� ����� ����� ���!", "������� ���!");
}
	
System::Void Snake::SnakeForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

	// ��������� ���
	play = true;
	timer->Start();
}

System::Void Snake::SnakeForm::SnakeForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	// ������� ��������� ������
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
		// ���� ��� �����
		Movement();

		Eating(); // ��������, �� �'��� �����
		EatYourself(); // ��������, �� �'��� ����
		CheckBorders(); // ��������, �� �������� � �����
	}
	else if (die && play) {
		timer->Stop();
		MessageBox::Show("��� ��������!", "�����!");
	}
	else if (!play && !die) {
		timer->Stop();
		MessageBox::Show("��� �����������!", "�����!");
	}
}

