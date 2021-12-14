#pragma once

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SnakeForm
	/// </summary>
	public ref class SnakeForm : public System::Windows::Forms::Form
	{
	public:
		SnakeForm(void);

		

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SnakeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ менюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ новаГраToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ паузапродовжитиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ налаштуванняToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ інформаціяПроГруToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вихідToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBoxGameData;
	private: System::Windows::Forms::Label^ labelScore;

	private: System::Windows::Forms::GroupBox^ groupBoxSettings;
	private: System::Windows::Forms::Button^ buttonApplySpeed;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownSpeedSnake;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ TopBorder;

	private: System::Windows::Forms::PictureBox^ BottomBorder;


	private: System::Windows::Forms::PictureBox^ RightBorder;
	private: System::Windows::Forms::PictureBox^ LeftBorder;
	private: System::Windows::Forms::Timer^ timer;



	private: System::Windows::Forms::Label^ labelGameOver;
	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SnakeForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->менюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->новаГраToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->паузапродовжитиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->налаштуванняToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->інформаціяПроГруToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вихідToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBoxGameData = (gcnew System::Windows::Forms::GroupBox());
			this->labelScore = (gcnew System::Windows::Forms::Label());
			this->groupBoxSettings = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonApplySpeed = (gcnew System::Windows::Forms::Button());
			this->numericUpDownSpeedSnake = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TopBorder = (gcnew System::Windows::Forms::PictureBox());
			this->BottomBorder = (gcnew System::Windows::Forms::PictureBox());
			this->RightBorder = (gcnew System::Windows::Forms::PictureBox());
			this->LeftBorder = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelGameOver = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->groupBoxGameData->SuspendLayout();
			this->groupBoxSettings->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSpeedSnake))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TopBorder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BottomBorder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RightBorder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LeftBorder))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->менюToolStripMenuItem,
					this->інформаціяПроГруToolStripMenuItem, this->вихідToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(570, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// менюToolStripMenuItem
			// 
			this->менюToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->новаГраToolStripMenuItem,
					this->паузапродовжитиToolStripMenuItem, this->налаштуванняToolStripMenuItem
			});
			this->менюToolStripMenuItem->Name = L"менюToolStripMenuItem";
			this->менюToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->менюToolStripMenuItem->Text = L"Меню";
			// 
			// новаГраToolStripMenuItem
			// 
			this->новаГраToolStripMenuItem->Name = L"новаГраToolStripMenuItem";
			this->новаГраToolStripMenuItem->Size = System::Drawing::Size(226, 26);
			this->новаГраToolStripMenuItem->Text = L"Нова гра";
			this->новаГраToolStripMenuItem->Click += gcnew System::EventHandler(this, &SnakeForm::новаГраToolStripMenuItem_Click);
			// 
			// паузапродовжитиToolStripMenuItem
			// 
			this->паузапродовжитиToolStripMenuItem->Name = L"паузапродовжитиToolStripMenuItem";
			this->паузапродовжитиToolStripMenuItem->Size = System::Drawing::Size(226, 26);
			this->паузапродовжитиToolStripMenuItem->Text = L"Пауза/продовжити";
			this->паузапродовжитиToolStripMenuItem->Click += gcnew System::EventHandler(this, &SnakeForm::паузапродовжитиToolStripMenuItem_Click);
			// 
			// налаштуванняToolStripMenuItem
			// 
			this->налаштуванняToolStripMenuItem->Name = L"налаштуванняToolStripMenuItem";
			this->налаштуванняToolStripMenuItem->Size = System::Drawing::Size(226, 26);
			this->налаштуванняToolStripMenuItem->Text = L"Налаштування";
			this->налаштуванняToolStripMenuItem->Click += gcnew System::EventHandler(this, &SnakeForm::налаштуванняToolStripMenuItem_Click);
			// 
			// інформаціяПроГруToolStripMenuItem
			// 
			this->інформаціяПроГруToolStripMenuItem->Name = L"інформаціяПроГруToolStripMenuItem";
			this->інформаціяПроГруToolStripMenuItem->Size = System::Drawing::Size(161, 24);
			this->інформаціяПроГруToolStripMenuItem->Text = L"Інформація про гру";
			this->інформаціяПроГруToolStripMenuItem->Click += gcnew System::EventHandler(this, &SnakeForm::інформаціяПроГруToolStripMenuItem_Click);
			// 
			// вихідToolStripMenuItem
			// 
			this->вихідToolStripMenuItem->Name = L"вихідToolStripMenuItem";
			this->вихідToolStripMenuItem->Size = System::Drawing::Size(60, 24);
			this->вихідToolStripMenuItem->Text = L"Вихід";
			this->вихідToolStripMenuItem->Click += gcnew System::EventHandler(this, &SnakeForm::вихідToolStripMenuItem_Click);
			// 
			// groupBoxGameData
			// 
			this->groupBoxGameData->Controls->Add(this->labelScore);
			this->groupBoxGameData->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxGameData->Location = System::Drawing::Point(12, 31);
			this->groupBoxGameData->Name = L"groupBoxGameData";
			this->groupBoxGameData->Size = System::Drawing::Size(156, 64);
			this->groupBoxGameData->TabIndex = 1;
			this->groupBoxGameData->TabStop = false;
			this->groupBoxGameData->Text = L"Ігрові дані";
			// 
			// labelScore
			// 
			this->labelScore->AutoSize = true;
			this->labelScore->Font = (gcnew System::Drawing::Font(L"Segoe Print", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelScore->Location = System::Drawing::Point(6, 21);
			this->labelScore->Name = L"labelScore";
			this->labelScore->Size = System::Drawing::Size(127, 35);
			this->labelScore->TabIndex = 0;
			this->labelScore->Text = L"Рахунок: 0";
			// 
			// groupBoxSettings
			// 
			this->groupBoxSettings->Controls->Add(this->label1);
			this->groupBoxSettings->Controls->Add(this->buttonApplySpeed);
			this->groupBoxSettings->Controls->Add(this->numericUpDownSpeedSnake);
			this->groupBoxSettings->Controls->Add(this->label2);
			this->groupBoxSettings->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxSettings->Location = System::Drawing::Point(57, 225);
			this->groupBoxSettings->Name = L"groupBoxSettings";
			this->groupBoxSettings->Size = System::Drawing::Size(464, 111);
			this->groupBoxSettings->TabIndex = 2;
			this->groupBoxSettings->TabStop = false;
			this->groupBoxSettings->Text = L"Налаштування";
			this->groupBoxSettings->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Print", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(416, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 35);
			this->label1->TabIndex = 3;
			this->label1->Text = L"мс";
			// 
			// buttonApplySpeed
			// 
			this->buttonApplySpeed->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonApplySpeed->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Blue;
			this->buttonApplySpeed->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Cyan;
			this->buttonApplySpeed->Font = (gcnew System::Drawing::Font(L"MV Boli", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonApplySpeed->Location = System::Drawing::Point(169, 65);
			this->buttonApplySpeed->Name = L"buttonApplySpeed";
			this->buttonApplySpeed->Size = System::Drawing::Size(144, 37);
			this->buttonApplySpeed->TabIndex = 2;
			this->buttonApplySpeed->Text = L"Застосвувати";
			this->buttonApplySpeed->UseVisualStyleBackColor = true;
			this->buttonApplySpeed->Click += gcnew System::EventHandler(this, &SnakeForm::buttonApplySpeed_Click);
			// 
			// numericUpDownSpeedSnake
			// 
			this->numericUpDownSpeedSnake->Location = System::Drawing::Point(319, 31);
			this->numericUpDownSpeedSnake->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDownSpeedSnake->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownSpeedSnake->Name = L"numericUpDownSpeedSnake";
			this->numericUpDownSpeedSnake->Size = System::Drawing::Size(103, 31);
			this->numericUpDownSpeedSnake->TabIndex = 1;
			this->numericUpDownSpeedSnake->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 150, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe Print", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(6, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(307, 35);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Введіть швидкість змійки: ";
			// 
			// TopBorder
			// 
			this->TopBorder->BackColor = System::Drawing::Color::Black;
			this->TopBorder->Location = System::Drawing::Point(10, 101);
			this->TopBorder->Name = L"TopBorder";
			this->TopBorder->Size = System::Drawing::Size(550, 10);
			this->TopBorder->TabIndex = 3;
			this->TopBorder->TabStop = false;
			// 
			// BottomBorder
			// 
			this->BottomBorder->BackColor = System::Drawing::Color::Black;
			this->BottomBorder->Location = System::Drawing::Point(10, 641);
			this->BottomBorder->Name = L"BottomBorder";
			this->BottomBorder->Size = System::Drawing::Size(550, 10);
			this->BottomBorder->TabIndex = 4;
			this->BottomBorder->TabStop = false;
			// 
			// RightBorder
			// 
			this->RightBorder->BackColor = System::Drawing::Color::Black;
			this->RightBorder->Location = System::Drawing::Point(560, 101);
			this->RightBorder->Name = L"RightBorder";
			this->RightBorder->Size = System::Drawing::Size(10, 550);
			this->RightBorder->TabIndex = 5;
			this->RightBorder->TabStop = false;
			// 
			// LeftBorder
			// 
			this->LeftBorder->BackColor = System::Drawing::Color::Black;
			this->LeftBorder->Location = System::Drawing::Point(0, 101);
			this->LeftBorder->Name = L"LeftBorder";
			this->LeftBorder->Size = System::Drawing::Size(10, 550);
			this->LeftBorder->TabIndex = 6;
			this->LeftBorder->TabStop = false;
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &SnakeForm::GameForm_Update);
			// 
			// labelGameOver
			// 
			this->labelGameOver->AutoSize = true;
			this->labelGameOver->Font = (gcnew System::Drawing::Font(L"Segoe Print", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelGameOver->Location = System::Drawing::Point(126, 122);
			this->labelGameOver->Name = L"labelGameOver";
			this->labelGameOver->Size = System::Drawing::Size(316, 100);
			this->labelGameOver->TabIndex = 7;
			this->labelGameOver->Text = L"Game over!\r\nПерезапустіть гру!";
			this->labelGameOver->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->labelGameOver->Visible = false;
			// 
			// SnakeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(570, 651);
			this->Controls->Add(this->labelGameOver);
			this->Controls->Add(this->LeftBorder);
			this->Controls->Add(this->RightBorder);
			this->Controls->Add(this->BottomBorder);
			this->Controls->Add(this->TopBorder);
			this->Controls->Add(this->groupBoxSettings);
			this->Controls->Add(this->groupBoxGameData);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"SnakeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Snake";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SnakeForm::SnakeForm_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBoxGameData->ResumeLayout(false);
			this->groupBoxGameData->PerformLayout();
			this->groupBoxSettings->ResumeLayout(false);
			this->groupBoxSettings->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSpeedSnake))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TopBorder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BottomBorder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RightBorder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LeftBorder))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// -----------------------------------------------
		// Ігрові дані
		PictureBox^ fruit; // фркут
		array <PictureBox^>^ Snake; // змія
		bool play; // грати
		bool die; // смерть 
		bool firstLaunch; // перший запуск
		int step = 10; // крок
		float updateInterval = 150; // інтервал оновлення (швидкість)
		int score = 0; // рахунок


		// -----------------------------------------------
		// Ігрові дії 
		void GeneratePositionFruit();
		void Eating();
		void Movement();
		void EatYourself();
		void GameOver();
		void NewGame();
		void CheckBorders();

		// -----------------------------------------------
		// Ігрові події

		// Обробник натисків на кнопки
		private: System::Void новаГраToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void паузапродовжитиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void налаштуванняToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void інформаціяПроГруToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void buttonApplySpeed_Click(System::Object^ sender, System::EventArgs^ e);

		// Відстежування натиску на клавішу
		private: System::Void SnakeForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);

		// Подія по оновленню гри - вказується в timer
		void GameForm_Update(Object^ object, EventArgs^ e);
	
};
}
