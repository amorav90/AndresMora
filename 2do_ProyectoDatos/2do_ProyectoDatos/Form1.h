#pragma once
#include "Controladora.h"
#include "Form2.h"
#include "Form3.h"
#include "Form4.h"

namespace My2do_ProyectoDatos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	Controladora* r=new Controladora();
	/// <summary>
	/// Resumen de Form1
	///
	/// ADVERTENCIA: si cambia el nombre de esta clase, deberá cambiar la
	///          propiedad 'Nombre de archivos de recursos' de la herramienta de compilación de recursos administrados
	///          asociada con todos los archivos .resx de los que depende esta clase. De lo contrario,
	///          los diseñadores no podrán interactuar correctamente con los
	///          recursos adaptados asociados con este formulario.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(57, 84);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 41);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Jugar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(265, 84);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 41);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Intercambiar Niveles";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(417, 127);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(136, 41);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Salir";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(110, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(333, 36);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Mundo de Los Animales";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(565, 180);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
			

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->carga();
				 
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->carga();
				 r->fin();
				 delete r;
				 this->Close();
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(r->cantidad_niveles0()>2)
			 {
				 Form4 fr;
				 string t;
				 int op1,op2;
				 t=r->datos_borde();
				 String^ datos=gcnew String(r->datos_borde().c_str());
				 fr.richTextBox1->Text=datos;
				 fr.ShowDialog();
				 try{
					 op1=Convert::ToInt32(fr.get_textbox1());
					 op2=Convert::ToInt32(fr.get_textbox2());
					 int max;
					 max=r->cantidad_niveles0();
					 if(op1<max-1 && op2<max-1)
					 {
						 if(op1>op2)
						 {
							 r->intercambia_niveles(op2,op1);
						 }
						 else
						 {
							 r->intercambia_niveles(op1,op2);
						 }
						 r->fin();
					 }
					 else
					 {
						 MessageBox::Show("Por favor ingrese numeros dentro del rango de niveles","Error");
					 }
				 }
				 catch(...)
				 {
					 if(fr.get_textbox1()!="" && fr.get_textbox2()!="")
					 {
						 MessageBox::Show("Por favor solo digite numeros en las casillas","Error");
					 }
				 }
			 }
			 else
			 {
				 MessageBox::Show("Cantidad de niveles insuficientes para realizar un intercambio","Error");
			 }
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) { 			 
			 juego();
			 r->fin();
		 }

		 void juego()
		 {
			 camina(*r->getRaiz());
		 }

		 void camina(Nodo_Arbol<Animal>& root)
		 {
			 if(!root.getHoja())
			 {
				 Form2 f;
				 f.label2->Text="Responda si el Animal en que usted esta";
				 f.label3->Text="pensando forma parte del siguiente grupo ";
				 f.label4->Text="o posee la caracteristica mencionada.";
				 f.label4->Visible=true;
				 string p;
				 p=root.getDato()->getNombre();
				 String^ w=gcnew String(p.c_str());
				 f.label1->Text=w;
				 f.ShowDialog();
				 if(f.flag_condicion)
				 {
					 camina(*root.getPuntero_1());
				 }
				 else
				 {
					 camina(*root.getPuntero_0());
				 }
			 }
			 else
			 {
				 Form2 f;
				 f.label2->Text="¿El Animal en que usted estaba pensando";
				 f.label3->Text="es el siguiente? ";
				 f.label4->Visible=false;
				 string p;
				 p=root.getDato()->getNombre();
				 String^ w=gcnew String(p.c_str());
				 f.label1->Text=w;
				 f.ShowDialog();
				 if(!f.flag_condicion)
				 {
					 Form3 f3;
					 f3.button1->Enabled=true;
					 f3.pictureBox1->Visible=false;
					 f3.pictureBox2->Visible=true;
					 f3.label2->Visible=true;
					 f3.label3->Visible=true;
					 f3.label4->Visible=true;
					 f3.label5->Visible=true;
					 f3.textBox1->Visible=true;
					 f3.textBox2->Visible=true;
					 f3.label1->Text="Fracaso! He fallado!";
					 f3.ShowDialog();
					 if(f3.get_textBox1()!="" && f3.get_textBox2()!="")
					 {
						 String^ T1;
						 T1=Convert::ToString(f3.get_textBox1());
						 string n,cc;
						 MarshalString(T1,n);
						 String^ T2;
						 T2=Convert::ToString(f3.get_textBox2());
						 MarshalString(T2,cc);
						 Nodo_Arbol<Animal>* name=new Nodo_Arbol<Animal>(new Animal(n),true);
						 Nodo_Arbol<Animal>* esp=new Nodo_Arbol<Animal>(new Animal(cc));
						 Nodo_Arbol<Animal>* anterior=new Nodo_Arbol<Animal>(new Animal(root.getDato()->getNombre()),true);
						 root=*esp;
						 root.setPuntero_0(anterior);
						 root.setPuntero_1(name);
						 r->fin();
					 }
					 //PERDIMOS
				 }
				 else
				 {
					 Form3 f3;
					 f3.pictureBox1->Visible=true;
					 f3.pictureBox2->Visible=false;
					 f3.textBox1->Visible=false;
					 f3.textBox2->Visible=false;
					 f3.label2->Visible=false;
					 f3.label3->Visible=false;
					 f3.label4->Visible=false;
					 f3.label5->Visible=false;
					 f3.label1->Text="Exito! He adivinado";
					 f3.button1->Enabled=true;
					 f3.ShowDialog();
					 //GANAMOS
				 }

			 }

			 
		 }

		 public: void carga()
				 {
					 try
					 {
						 r->iniciar();
					 }
					 catch(...)
					 {
						 MessageBox::Show("Error","Error");
						 this->Close();
						 
					 }
				 }
};
}

