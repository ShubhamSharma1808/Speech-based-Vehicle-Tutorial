#pragma once

#include"test_recording.h"
#include<Windows.h>


namespace vehicle_tutorial {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: Microsoft::VisualBasic::PowerPacks::ShapeContainer^  shapeContainer1;
	private: Microsoft::VisualBasic::PowerPacks::LineShape^  lineShape1;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Panel^  panel2;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->shapeContainer1 = (gcnew Microsoft::VisualBasic::PowerPacks::ShapeContainer());
			this->lineShape1 = (gcnew Microsoft::VisualBasic::PowerPacks::LineShape());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->shapeContainer1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1028, 453);
			this->panel1->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label5->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label5->Location = System::Drawing::Point(4, 156);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(138, 478);
			this->label5->TabIndex = 5;
			this->label5->Text = L"bike\r\n\r\ncar\r\n\r\nbus\r\n\r\ntrain\r\n\r\nbicycle\r\n\r\naeroplane\r\n\r\nhelicopter\r\n\r\nboat\r\n\r\ntrac" 
				L"tor\r\n\r\ntruck\r\n\r\nrocket\r\n\r\njcb";
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::Desktop;
			this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(3, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(139, 30);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Recording....";
			this->label3->Visible = false;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Font = (gcnew System::Drawing::Font(L"Elephant", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(-7, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(1240, 60);
			this->label2->TabIndex = 1;
			this->label2->Text = L"SPEAK \'N\' LEARN";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::Desktop;
			this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(3, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 30);
			this->label1->TabIndex = 0;
			this->label1->Text = L"click here";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// shapeContainer1
			// 
			this->shapeContainer1->Location = System::Drawing::Point(0, 0);
			this->shapeContainer1->Margin = System::Windows::Forms::Padding(0);
			this->shapeContainer1->Name = L"shapeContainer1";
			this->shapeContainer1->Shapes->AddRange(gcnew cli::array< Microsoft::VisualBasic::PowerPacks::Shape^  >(1) {this->lineShape1});
			this->shapeContainer1->Size = System::Drawing::Size(1028, 453);
			this->shapeContainer1->TabIndex = 2;
			this->shapeContainer1->TabStop = false;
			// 
			// lineShape1
			// 
			this->lineShape1->BorderColor = System::Drawing::SystemColors::ControlLightLight;
			this->lineShape1->Name = L"lineShape1";
			this->lineShape1->X1 = 150;
			this->lineShape1->X2 = 149;
			this->lineShape1->Y1 = 4;
			this->lineShape1->Y2 = 442;
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(254, 137);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(498, 287);
			this->label6->TabIndex = 6;
			this->label6->Visible = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(149, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1230, 800);
			this->panel2->TabIndex = 7;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel2_Paint);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::HighlightText;
			this->ClientSize = System::Drawing::Size(1028, 453);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"VEHICLE TUTORAL";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {

				//this->label1->ResetText();
				
				//this->label1->ResetForeColor();
				/*System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
					static_cast<System::Int32>(static_cast<System::Byte>(0)));*/
				// this->label3->Visible=true;
				// this->label1->Dispose(true);
	
				 this->label1->ForeColor = System::Drawing::Color::Green;
				 this->label1->Text ="Recording...";
				
				 char image_name[50];
				 //system("Recording_Module.exe 2 input_file.wav input_file.txt");	
				int x=recording_test();
				strcpy(image_name,"images\\");
				itoa(x,image_name+strlen(image_name),10);
				strcat(image_name,".jpg");
				
			
				system(image_name);
				Sleep(3000);
				system("taskkill /IM Microsoft.Photos.exe /F");
				

				this->label1->ForeColor = System::Drawing::Color::White;
				this->label1->Text = L"click here";
			//	 this->label1->Visible=true;
				// this->label3->SetVisibleCore(false);
		//		this->label1->ResetText();
				// this->label3->Visible=false;
			 }
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
};
}

