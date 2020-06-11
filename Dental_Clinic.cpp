#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Appointment_List;
class Patient;
class Dentists;
class Dentists_List;
class Patient_List;
class Appointment;

    class Dental_Clinic
    {
        string address;
        string opening_hours;
        string telephone_number;
        Appointment_List* list_app;
        Dentists_List* dentist;
        Patient_List* patient;
        Appointment* app;

    public:
        Dental_Clinic(string address, string opening_hours, string telephone_number);
        ~Dental_Clinic();
        string get_address(){return address;}
        string get_opening_hours(){return opening_hours;}
        string get_telephone_number(){return telephone_number;}
        void print();
        void print_patient();
        void print_dentist();
        void print_appointments();
        Appointment_List*get_list(){return list_app;}//returns address of given object
        Patient* create_patient(string new_name, string new_surname, int new_id, string new_PESEL, string new_home_address, string new_phone_number);//returns address of given object
        Dentists* create_dentist(int new_dentists_id, string new_dentists_name, string new_dentists_surname);//returns address of given object
        void make_appointemnt(string hour, Dentists* dentist, Patient* patient);
        void remove_dentist(int new_dentists_id);
        void remove_patient(int new_id);

     };
    class Patient
	{
            string name;
            string surname;
            int id;
            string PESEL;
            string home_address;
            string phone_number;
            Patient*next;

        public:

            Patient(string name, string surname, int id, string PESEL, string home_address, string phone_number);
            ~Patient();


			string get_name() const{return name;}
			string get_surname()const {return surname;}
			int get_id() const{return id;}
			string get_home_address()const {return home_address;}
			string get_phone_number()const {return phone_number;}
			Patient* get_next_patient()const {return next;}
			void set_next_Patient(Patient* nxt){ next = nxt; };
			void print();
	};
	class Dentists
	{
		private:

            int dentists_id;
			string dentists_name;
			string dentists_surname;
            Dentists*next;
        public:


			Dentists(int dentists_id, string dentists_name, string dentists_surname);
			~Dentists();

			int get_dentist_id()const {return dentists_id;}
			string get_dentists_name() const {return dentists_name;}
			string get_dentists_surname()const {return dentists_surname;}
			Dentists* get_next()const {return next;}
			void set_next_Dentists(Dentists* nxt){ next = nxt; };
			void print();

	};

		class Appointment
    {
        string hour;
        Dentists* dentist;
        Patient* patient;
        Appointment* next;


        public:
            Appointment( string hour, Dentists* dentist, Patient* patient);
            ~Appointment();
            void print();
            Appointment* get_next_app()const { return next; }
            void set_next_Appointment(Appointment* nxt){ next = nxt; };
            string get_hour(){return hour;}
            Dentists*get_dentist(){return dentist;};
            Patient*get_patient(){return patient;}
    };

		class Appointment_List
    {
            Appointment* head;
        public:
            Appointment_List();
            ~Appointment_List();
            Appointment* get_head(){return head;};
            Appointment* set_head(Appointment*head2){return head=head2;};
            bool is_free(int dentists_id);
            bool has_appointment(int id);
            bool check_if_dentist_avaible(Dentists*dentist, string hour);
            bool check_if_patient_does_not_have_appointment(Patient*patient, string hour);
            void make_appointemnt(string hour, Dentists* dentist, Patient* patient);
            void print();
    };
        class Dentists_List
    {
            Dentists* head;
        public:
            Dentists_List();
            ~Dentists_List();
            bool check_if_dentist_exist(int dentists_id);
            Dentists*  add_dentist(int new_dentists_id, string new_dentists_name, string new_dentists_surname);
            void print();
            Dentists* get_head(){return head;};
            Dentists* set_head(Dentists* head2){return head=head2;};
    };
    class Patient_List
    {
            Patient* head;
        public:
            Patient_List();
            ~Patient_List();
            bool check_if_patient_exist(int id);
            Patient*  add_patient(string new_name, string new_surname, int new_id, string new_PESEL, string new_home_address, string new_phone_number);
            void print();
            Patient* get_head(){return head;};
            Patient* set_head(Patient* head2){return head=head2;};
    };



Dental_Clinic::Dental_Clinic(string new_address, string new_opening_hours, string new_telephone_number)
{
    address = new_address;
    opening_hours = new_opening_hours;
    telephone_number= new_telephone_number;
    list_app=new Appointment_List();
    dentist = new Dentists_List();
    patient = new Patient_List();

}
Dental_Clinic::~Dental_Clinic()
{
    cout<<"clinic has been removed"<<endl;
}



Patient::Patient(string new_name, string new_surname, int new_id, string new_PESEL, string new_home_address, string new_phone_number)
{
    name = new_name;
    surname = new_surname;
    PESEL=new_PESEL;
    home_address = new_home_address;
    phone_number = new_phone_number;
    id = new_id;
    next = NULL;

}
Patient::~Patient()
{

}
Dentists::Dentists(int new_dentists_id, string new_dentists_name, string new_dentists_surname)
{
    dentists_name = new_dentists_name;
    dentists_surname = new_dentists_surname;
    dentists_id = new_dentists_id;
    next = NULL;

}
Dentists::~Dentists()
{

}

Appointment_List::Appointment_List()
{
    head = NULL;
    cout<<"List created"<<endl;
}
Appointment_List::~Appointment_List()
{
    Appointment *temp = NULL;
    while(head != NULL){
    temp = head;
    head = head->get_next_app();
    delete temp;
    }

}
Dentists_List::Dentists_List()
{
     head = NULL;
     cout<<"List created"<<endl;
}
Dentists_List::~Dentists_List()
{
    Dentists *temp = NULL;
    while(head != NULL){
    temp = head;
    head = head->get_next();
    delete temp;
}
}
Patient_List::Patient_List()
{
    head=NULL;
    cout<<"List created"<<endl;
}
Patient_List::~Patient_List()
{
    Patient *temp = NULL;
    while(head != NULL){
    temp = head;
    head = head->get_next_patient();
    delete temp;
}
}
Appointment::Appointment( string new_hour, Dentists* new_dentist, Patient* new_patient)
{
    hour = new_hour;
    dentist = new_dentist;
    patient = new_patient;
    next = NULL;

}

Appointment::~Appointment()
{
       cout << " Appointment deleted" << endl;
}

Patient*  Dental_Clinic::create_patient(string new_name, string new_surname, int new_id, string new_PESEL, string new_home_address, string new_phone_number)
{
    if(patient->check_if_patient_exist(new_id)){
        return NULL;
    }

        Patient * current = patient->get_head();
        Patient *temp = new Patient(new_name, new_surname, new_id, new_PESEL, new_home_address, new_phone_number);
        if(patient->get_head() == NULL){
            patient->set_head(temp);
            cout << "patient added to the list" << endl;
            return temp;
            }
        else if(new_id < patient->get_head()->get_id()){//if patient is not the first one
            temp->set_next_Patient(patient->get_head());
            patient->set_head(temp);
            cout << "Patient added to the list" << endl;
            return temp;
        }
        else{
            while(current != NULL){
                if(current->get_id() < new_id && (current->get_next_patient() == NULL || new_id< current->get_next_patient()->get_id())){
                    temp->set_next_Patient(current->get_next_patient());
                    current->set_next_Patient(temp);
                    cout << "Patient added to the list" << endl;

                    return temp;
                }
                current = current->get_next_patient();
                }
            }


}
Dentists*  Dental_Clinic::create_dentist(int new_dentists_id, string new_dentists_name, string new_dentists_surname)
{
    if(dentist->check_if_dentist_exist(new_dentists_id)){
        return NULL;
    }

        Dentists* current = dentist->get_head();
        Dentists*temp = new Dentists(new_dentists_id, new_dentists_name, new_dentists_surname);
        if(dentist->get_head() == NULL){
            dentist->set_head(temp);
            cout << "dentist added to the list" << endl;
            return temp;
            }
        else if(new_dentists_id < dentist->get_head()->get_dentist_id()){//if dentist is not the first one
            temp->set_next_Dentists(dentist->get_head());
            dentist->set_head(temp);
            cout << "Dentist added to the list" << endl;
            return temp;
        }
        else{
            while(current != NULL){
                if(current->get_dentist_id() < new_dentists_id && (current->get_next() == NULL || new_dentists_id< current->get_next()->get_dentist_id())){
                    temp->set_next_Dentists(current->get_next());
                    current->set_next_Dentists(temp);
                    cout << "Dentist added to the list" << endl;

                    return temp;
                }
                current = current->get_next();
                }
            }


}


bool Dentists_List::check_if_dentist_exist(int dentists_id)
{
    Dentists *current = NULL;
    current = head;
    while(current != NULL){
        if(current->get_dentist_id() == dentists_id){
            return true;
        }
        else
            current = current->get_next();
    }
}

bool Patient_List::check_if_patient_exist(int id)
{
    Patient *current = NULL;
    current = head;
    while(current != NULL){
        if(current->get_id() == id){
            return true;
        }
        else
            current = current->get_next_patient();
    }
}

void Dental_Clinic::make_appointemnt(string hour, Dentists* dentist, Patient* patient)
{
     int id=dentist->get_dentist_id();

   if ( list_app->check_if_dentist_avaible(dentist, hour)!=1 || list_app->check_if_patient_does_not_have_appointment(patient,hour)!=1)
          {
              cout<<"This hour is already taken"<<endl;
                    return ;
          }


        Appointment *current = list_app->get_head();
        Appointment *temp = new Appointment( hour, dentist, patient );


        if(list_app->get_head() == NULL){
            list_app->set_head(temp);
            cout << "Appointment added to the list" << endl;
            }
        else if(id< list_app->get_head()->get_dentist()->get_dentist_id()){
            temp->set_next_Appointment(list_app->get_head());
            list_app->set_head(temp);
            cout << "Appointment added to the list" << endl;
        }
        else{
            while(current != NULL){
                if(current->get_dentist()->get_dentist_id() <= id && (current->get_next_app() == NULL || id <current->get_next_app()->get_dentist()->get_dentist_id())){
                    temp->set_next_Appointment(current->get_next_app());
                    current->set_next_Appointment(temp);
                    cout << "Appointment added to the list" << endl;

                    return;
                }
                current = current->get_next_app();
            }
        }
        return;
    }


bool Appointment_List::check_if_dentist_avaible(Dentists*dentist, string hour){
    Appointment *current = head;
    int id=dentist->get_dentist_id();
    if(current == NULL){
        cout << "The list is empty" << endl;
    }
    while(current != NULL){
        if(id==current->get_dentist()->get_dentist_id())
        {

          if(hour==current->get_hour())
            {
                return false;
            }
        }
        current = current->get_next_app();


    }
    return true;

}
bool Appointment_List::check_if_patient_does_not_have_appointment(Patient*patient, string hour)
{
    Appointment*current=head;
    int id=patient->get_id();
    if(current == NULL){
        cout << "The list is empty" << endl;
    }
    while(current != NULL){
        if(id==current->get_patient()->get_id())
        {
          if(hour==current->get_hour())
            {
                return false;
            }
        }
        current = current->get_next_app();
}
    return true;
}
void Patient::print(){

    cout<< "id: " << get_id()<< "\tname: " << get_name()<<"\tsurname:" <<get_surname()<< endl;
}
void Dentists::print()
{
    cout<< "dentists_id: " << get_dentist_id()<< "\tname: " << get_dentists_name()<<"\tsurname:" <<get_dentists_surname()<< endl;
}
void Dental_Clinic::print()
{
    cout<< "Clinic's address: " << get_address()<< "\tOpening Hours: " << get_opening_hours()<<"\ttelephone number" <<get_telephone_number()<< endl;
}


void Appointment::print(){
    string hour;
    cout<< "hour: " << get_hour();
    dentist->print();
    patient->print();
    Dentists* dentist;
    Patient* patient;
    Appointment* next;
}

void Appointment_List::print()
{
    Appointment *current = head;
    if(current == NULL){
        cout << "The list is empty" << endl;
        return;
    }
    cout << "\n--------- list of appointments: "<< endl;
    while(current != NULL){
        current->print();
        current = current->get_next_app();
        cout << "----------------------------------------------------------------------------" << endl;

    }
    cout << "--------------------------" << endl<< endl;
}

void Dentists_List::print()
{

    Dentists *current = head;
    if(current == NULL){
        cout << "The list is empty" << endl;
        return;
    }
    cout << "\n--------- list of dentists : "<< endl;
    while(current != NULL){
        current->print();
        current = current->get_next();
        cout << "----------------------------------------------------------------------------" << endl;

    }
    cout << "--------------------------" << endl<< endl;
}
void Patient_List::print()
{
    Patient *current = head;
    if(current == NULL){
        cout << "The list is empty" << endl;
        return;
    }
    cout << "\n--------- list of patients: "<< endl;
    while(current != NULL){
        current->print();
        current = current->get_next_patient();
        cout << "----------------------------------------------------------------------------" << endl;

    }
    cout << "--------------------------" << endl<< endl;
}
void Dental_Clinic::print_patient()
{
    patient->print();

}

void Dental_Clinic::print_dentist()
{
    dentist->print();
}
void Dental_Clinic::print_appointments()
{
    list_app->print();
}

void Dental_Clinic:: remove_dentist( int new_dentists_id )
{
    if (!list_app->is_free(new_dentists_id))
    {
        cout << "Cannot be removed, because dentist has undone job " << endl;
        return;
    }
   {
    Dentists *temp = NULL;
    Dentists *current = dentist->get_head();
    if(dentist->get_head() == NULL){
        return;
    }
    else{
        while(current != NULL){
            if(dentist->get_head()->get_dentist_id() == new_dentists_id){
            dentist->set_head(temp);
            dentist->set_head(dentist->get_head()->get_next());
            delete temp;
            }
            else{
                while (current->get_next() != NULL){
                    if (current->get_next()->get_dentist_id() == new_dentists_id){
                        temp = current->get_next();
                        current->set_next_Dentists(current->get_next()->get_next());
                        delete temp;
                    }
                    else{
                        current = current->get_next();
                    }
                }
            }
            current = current->get_next();
        }

    }
}

}
void Dental_Clinic:: remove_patient( int patient_id )
{
    if (!list_app->has_appointment(patient_id))
    {
        cout << "Cannot be removed, because patient has arranged appointment " << endl;
        return;
    }
   {
    Patient *temp = NULL;
    Patient *current = patient->get_head();
    if(patient->get_head() == NULL){
        return;
    }
    else{
        while(current != NULL){
            if(patient->get_head()->get_id() == patient_id){
            patient->set_head(temp);
            patient->set_head(patient->get_head()->get_next_patient());
            delete temp;
            }
            else{
                while (current->get_next_patient() != NULL){
                    if (current->get_next_patient()->get_id() == patient_id){
                        temp = current->get_next_patient();
                        current->set_next_Patient(current->get_next_patient()->get_next_patient());
                        delete temp;
                    }
                    else{
                        current = current->get_next_patient();
                    }
                }
            }
            current = current->get_next_patient();
        }

    }
}

}
bool Appointment_List::is_free(int id)
{
    Appointment *current = head;
    if(current == NULL){
        cout << "The list is empty" << endl;
    }
    while(current != NULL){
        if(id==current->get_dentist()->get_dentist_id())

        {
                return false;

        }
        current = current->get_next_app();


    }
    return true;

}

bool Appointment_List::has_appointment(int id)
{
    Appointment *current = head;
    if(current == NULL){
        cout << "The list is empty" << endl;
    }
    while(current != NULL){
        if(id==current->get_patient()->get_id())

        {
                return false;

        }
        current = current->get_next_app();


    }
    return true;

}
int main()
{
    /*Dentists dent1(1,"Marian","Nowak");
    Patient pat1("Jan", "Kowalski", 4, "1234689", "ul.Zielona", "654354323");
    Dentists dent2(2,"JA","TY");
    Patient pat2("elek", "Kolek", 7, "1234689", "ul.Ziulona", "654354323");
    Dentists dent3(3,"Marek","Wladca");
    Patient pat3("Mirek", "Szmirek", 2, "1234689", "ul.Zielena", "654354323");*/



    Dental_Clinic clinic1("Warsaw, Wolska Street 33","24/7", "678901234");//creating list of patient, list of dentist and list of appointments
    Patient* pat1 = clinic1.create_patient("Paulina", "Szotczewska", 1, "1234681", "ul.Zielona", "654354323");
    Patient* pat2 = clinic1.create_patient("Barbara", "Wilk", 2, "1234682", "ul.Zielona", "654354323");
    Patient* pat3 = clinic1.create_patient("Jakub", "Martyniuk", 3, "1234683", "ul.Zielona", "654354323");
    Patient* pat4 = clinic1.create_patient("Jolanta", "Boczkowska", 4, "1234684", "ul.Zielona", "654354323");
    Patient* pat5 = clinic1.create_patient("Mateusz", "Wrona", 5, "1234685", "ul.Zielona", "654354323");
    Patient* pat6 = clinic1.create_patient("Lucjusz", "Blak", 6, "1234686", "ul.Zielona", "654354323");
    Patient* pat7 = clinic1.create_patient("Alicja", "Czarowna", 8, "1234687", "ul.Zielona", "654354323");
    Patient* pat8 = clinic1.create_patient("Lech", "Zimny", 6, "1234688", "ul.Zielona", "654354323");//will not be added because patient with such id alredy exists and unable to use in make appointment

    Dentists* dent1 = clinic1.create_dentist(11,"Jan","Nowak");
    Dentists* dent2 = clinic1.create_dentist(12,"Zofia","Wolak");
    Dentists* dent3 = clinic1.create_dentist(13,"Zdzislaw","Kot");
    Dentists* dent4 = clinic1.create_dentist(14,"Zdzislaw","Kot");
    Dentists* dent6 = clinic1.create_dentist(16,"Jacek","Berierka");
    Dentists* dent7 = clinic1.create_dentist(17,"Katarzyna","Kolej");
    Dentists* dent8 = clinic1.create_dentist(16,"Andrzej","Polak");//will not be added to the the list and unable to use in method "make_appointment"

    //Dental_Clinic clinic1("Warsaw, Wolska Street 33","07:00-21:00", "678901234");
    /*Patient* pat1 = clinic1.create_patient("Paulina", "Szotczewska", 1, "1234681", "ul.Zielona", "654354323");
    Patient* pat2 = clinic1.create_patient("Barbara", "Wilk", 2, "1234682", "ul.Zielona", "654354323");
    Patient* pat3 = clinic1.create_patient("Jakub", "Martyniuk", 3, "1234683", "ul.Zielona", "654354323");
    Patient* pat4 = clinic1.create_patient("Jolanta", "Boczkowska", 4, "1234684", "ul.Zielona", "654354323");
    Patient* pat5 = clinic1.create_patient("Mateusz", "Wrona", 5, "1234685", "ul.Zielona", "654354323");
    Patient* pat6 = clinic1.create_patient("Lucjusz", "Blak", 6, "1234686", "ul.Zielona", "654354323");
    Patient* pat7 = clinic1.create_patient("Alicja", "Czarowna", 8, "1234687", "ul.Zielona", "654354323");
    Patient* pat8 = clinic1.create_patient("Lech", "Zimny", 6, "1234688", "ul.Zielona", "654354323");// will not be addedto the the list and unable to use in method "make_appointment"
*/


    //Dental_Clinic list1("Warsaw, Wolska Street 33","07:00-21:00", "678901234");
    clinic1.make_appointemnt("13:00", dent1, pat1);
    clinic1.make_appointemnt("13:00", dent1, pat3);//will not be added because dentist has already appointment on that hour
    clinic1.make_appointemnt("14:00", dent3, pat2);
    clinic1.make_appointemnt("17:00", dent4, pat3);
    clinic1.make_appointemnt("17:00", dent3, pat3);//will not be added because patient has already appointment on that hour
    clinic1.make_appointemnt("17:00", dent6, pat1);
    clinic1.make_appointemnt("19:00", dent6, pat6);
    clinic1.make_appointemnt("8:00", dent4, pat3);

    //Appointment app1("465",dent1, pat1);
    //cout<< app1.get_dentist()->get_dentist_id()<<endl;
    //Appointment app1("13:00", dent1, pat1);
//Dental_Clinic clinic1("Warsaw, Wolska Street 33","07:00-21:00", "678901234");
    clinic1.print_dentist();
    clinic1.print_patient();
    clinic1.remove_dentist(17);
    clinic1.remove_dentist(16);// will not be removed because has appointment
    clinic1.remove_dentist(99);//no such dentist, will not be removed
    clinic1.remove_patient(14);// will not be removed because has an appointment
    clinic1.remove_patient(17);// no such patient, will not be removed
    clinic1.remove_patient(4);
    clinic1.print();
    clinic1.print_dentist();
    clinic1.print_patient();
//clinic1.get_list()->make_appointemnt("13:00", dent1, pat1);
//clinic1.get_list()->print();
    clinic1.print_appointments();


    Dental_Clinic clinic2("Krakow, Garncarska Street 33","24/7", "678901234");//prenting empty lists and removing from empty lists
    clinic2.print();
    clinic2.print_dentist();
    clinic2.print_patient();
    clinic2.print_appointments();
    clinic2.remove_dentist(6);
    clinic2.remove_patient(6);
    clinic2.print_dentist();
    clinic2.print_patient();

    Dental_Clinic* clinic3=new Dental_Clinic("Wrocław Garncarska Street 33","24/7", "678901234");// deleting whole clinic
    Patient* pat13 = clinic3->create_patient("Paulina", "Szotczewska", 19, "1234681", "ul.Zielona", "654354323");
    Dentists* dent17 = clinic3->create_dentist(96,"Jan","Nowak");
    clinic3->print();
    clinic3->print_dentist();
    clinic3->print_patient();
    clinic3->print_appointments();



        delete clinic3;

    return 0;
}
