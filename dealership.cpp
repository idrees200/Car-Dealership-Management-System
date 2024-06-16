#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class cars {
	string model;
	string brand;
	int milage;
	int doors;
	string color;
	string type;
	int price;
public:
	cars(int m=0,int d=0,string c="",string t="",string mo="",string b="", int p = 0) {
		milage = m;
		doors = d;
		color = c;
		type = t;
		price = p;
		model = mo;
		brand = b;
	}
	void setmodel(string mod) {
		model = mod;
	}
	void setbrand(string mod) {
		brand = mod;
	}
	void setcolor(string mod) {
		color = mod;
	}
	void settype(string mod) {
		type = mod;
	}
	void setmilage(int mod) {
		milage = mod;
	}
	void setdoors(int mod) {
		doors = mod;
	}
	void setprice(int mod) {
		price = mod;
	}
	string getbrand() {
		return brand;
	}
	string getmodel() {
		return model;
	}
	string getcolor() {
		return color;

	}
	string gettyoe() {
		return type;
	}
	void discount(int v) {
		price = (price * v) / 100;
	}
	int getmilage() {
		return milage;
	}
	int getprice() {
		return price;
	}
	int getdoors() {
		return doors;
	}
	

	virtual void show() = 0;
};
class imported :public cars {
	int importyear;
	string vehicletype;
	double grade;
public:
	imported(int m = 0, int d = 0, string c = "", string t = "", string mo = "", string b = "", int p = 0, double g = 0,int y=0) :cars(m, d, c, t, mo, b, p) {
		vehicletype = "I M P O R T E D";
		grade = g;
		importyear = y;
	}
	void setimport(int i) {
		importyear = i;
	}
	void setgrade(double i) {
		grade = i;
	}
	void setvehicle(string i) {
		vehicletype=i;
	}
	void show() {
		cout << "_________________________________________________" << endl;
		cout << "VEHICLE TYPE : " << vehicletype << endl;
		cout << "_________________________________________________" << endl;
		cout << "BRAND : " << getbrand() << endl;
		cout << "MODEL : " << getmodel() << endl;
		cout << "IMPORT YEAR : " << importyear << endl;
		cout << "COLOR : " << getcolor() << endl;
		cout << "NUMBER OF DOORS : " << getdoors() << endl;
		cout << "TRANSMISSION : " << gettyoe() << endl;
		cout << "MILAGE : " << getmilage()<<" KM" << endl;
		cout << "CAR GRADE : " << grade << endl;
		cout << "PRICE : " << getprice() <<" RS"<< endl;


	}
	void addmodel() {
		string mm;
		int count;
		cout << "WHICH BRAND DO YOU WANT TO ADD" << endl;
		cin >> mm;
		ifstream loop("IMPORTED.txt");
		loop >> count;
		int sum = count + 1;
		string* arr = new string[sum];
		for (int i = 0; i < count; i++) {
			loop >> arr[i];
		}
		loop.close();
		ofstream shop("IMPORTED.txt");
		shop << sum << endl;
		for (int i = 0; i < count; i++) {
			shop << arr[i] << endl;
		}
		shop << mm << endl;
		shop.close();
		cout << "BRAND ADDED SUCCESSFULLY" << endl;
		cout << "_____________________________________" << endl;
		cout << "HOW MANY MODELS (VEHICLES) DO YOU WANT TO ADD FOR THIS BRAND ( " << mm << " )" << endl;
		int vehi;
		cin >> vehi;
		string tex = ".txt";
		string filenameee = mm + tex;
		ofstream sweep(filenameee);
		sweep << vehi << endl;
		int real = vehi * 9;
		string no;
		for (int i = 0; i < vehi; i++)
		{
			cout << "ENTER BRAND OF THE VEHICLE" << endl;
			cin >> no;
			sweep << no<<endl;
			cout << "ENTER THE NAME OF THE VEHICLE" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER THE YEAR OF IMPORT" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER THE COLOR OF THE VEHICLE" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER NO OF DOORS OF THE VEHICLE" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER VEHICLE TRANSMISSION" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER MILAGE OF VEHICLE(KM)" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER GRADE OF THE VEHICLE" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER PRICE OF THE VEHICLE (RS)" << endl;
			int o;
			cin >> o;
			sweep << o<<endl;
			cout << "____________________________________" << endl;
		}
		cout << "SUCCESFULLY ADDED" << endl;
	}
	void addvehilce() {
		
		int total;
		int number;
		int option;
		string choosedbrand;
		
		cout << "IN WHICH BRAND DO YOU WANT TO ADD VEHICLE?" << endl;
			ifstream mod("IMPORTED.txt");
			mod >> total;
			
			string *jj=new string[total];
			for (int i = 0; i < total; i++) {
				mod >> jj[i];
			}
			do {
				cout << " BRANDS AVAILIABLE : " << endl;
				for (int i = 0; i < total; i++) {
					cout << i  << "." << jj[i] << endl;
				}
				cin >> option;
				if (option<0 || option>total) {
					cout << "WRONG CHOICE!!" << endl;
					cout << "TRY AGAIN!!" << endl;
				}
			} while (option<0 || option>total);

			string text = ".txt";
			jj[option] = jj[option] + text;
		cout << "HOW MANY VEHICLES DO YOU WANT TO ADD?" << endl;
		int addition;
		cin >> addition;
		int count;
		int sumingup;
		ifstream op(jj[option]);
		int mul;
		int sp;
		if (op.fail()) {
			cout << "ERROR OPENING FILE!!" << endl;
		}else{
			
			op >> count;
			mul = (count + addition) * 9;
			sumingup = count * 9;
			string* array = new string[mul];
			for (int i = 0; i < sumingup; i++) {
				op >> array[i];
			}
			op.close();
			ofstream kk(jj[option]);
		
			sp = count + addition;
			kk << sp << endl;
			for (int i = 0; i < mul; i++) {
				if (i < sumingup) {
					kk << array[i] << endl;
				}
				if (i >= sumingup) {
					cout << "ENTER BRAND OF THE VEHICLE" << endl;
					cin >> array[i];
					kk << array[i] << endl;
					i++;
					cout << "ENTER THE NAME OF THE VEHICLE" << endl;
					cin >> array[i];
					kk << array[i] << endl;
					i++;
					cout << "ENTER THE YEAR OF IMPORT" << endl;
					cin >> array[i];
					kk << array[i] << endl;
					i++;
					cout << "ENTER THE COLOR OF THE VEHICLE" << endl;
					cin >> array[i];
					kk << array[i] << endl;
					i++;
					cout << "ENTER NO OF DOORS OF THE VEHICLE" << endl;
					cin >> array[i];
					kk << array[i] << endl;
					i++;
					cout << "ENTER VEHICLE TRANSMISSION" << endl;
					cin >> array[i];
					kk << array[i] << endl;
					i++;
					cout << "ENTER MILAGE OF VEHICLE (KM)" << endl;
					cin >> array[i];
					kk << array[i] << endl;
					i++;
					cout << "ENTER GRADE OF THE VEHICLE " << endl;
					cin >> array[i];
					kk << array[i] << endl;
					i++;
					cout << "ENTER PRICE OF THE VEHICLE (RS)" << endl;
					int q;
					cin >> q;
					kk <<q << endl;
					i++;
					cout << "____________________________________" << endl;

				}
			}
			kk.close();
		}
		cout << "ADDED SUCCESSFULLY" << endl;
	
	}
};
class localveh :public cars {
	string vehicletype;
	string condition;
	int age;
public:
	localveh(int m = 0, int d = 0, string c = "", string t = "", string mo = "", string b = "", int p = 0, string g = "", int a = 0) :cars(m, d, c, t, mo, b, p) {
		vehicletype = "L O C A L";
	condition= g;
	age = a;
	}
	void setcond(string c) {
		condition = c;
	}
	void setage(int a) {
		age = a;
	}
	void show() {
		cout << "_________________________________________________" << endl;
		cout << "VEHICLE TYPE : " << vehicletype << endl;
		cout << "_________________________________________________" << endl;
		cout << "BRAND : " << getbrand() << endl;
		cout << "MODEL : " << getmodel() << endl;
		cout << "MODEL YEAR : " << age << endl;
		cout << "COLOR : " << getcolor() << endl;
		cout << "NUMBER OF DOORS : " << getdoors() << endl;
		cout << "TRANSMISSION : " << gettyoe() << endl;
		cout << "MILAGE : " << getmilage() <<" KM" << endl;
		cout << "CAR CONDITION : " << condition << endl;
		cout << "PRICE : " << getprice()<<" RS" << endl;


	}
	void addmodel() {
		string mm;
		int count;
		cout << "WHICH BRAND DO YOU WANT TO ADD" << endl;
		cin >> mm;
		ifstream loop("LOCAL.txt");
		loop >> count;
		int sum = count + 1;
		string* arr = new string[sum];
		for (int i = 0; i < count; i++) {
			loop >> arr[i];
		}
		loop.close();
		ofstream shop("LOCAL.txt");
		shop << sum << endl;
		for (int i = 0; i < count; i++) {
			shop << arr[i] << endl;
		}
		shop << mm << endl;
		shop.close();
		cout << "BRAND ADDED SUCCESSFULLY" << endl;
		cout << "_____________________________________" << endl;
		cout << "HOW MANY MODELS (VEHICLES) DO YOU WANT TO ADD FOR THIS BRAND ( " << mm << " )" << endl;
		int vehi;
		cin >> vehi;
		string tex = "LOCAL.txt";
		string filenameee = mm + tex;
		ofstream sweep(filenameee);
		sweep << vehi << endl;
		int real = vehi * 9;
		string no;
		for (int i = 0; i < vehi; i++)
		{
			cout << "ENTER BRAND OF THE VEHICLE" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER THE NAME OF THE VEHICLE" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER THE YEAR OF MODEL" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER THE COLOR OF THE VEHICLE" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER NO OF DOORS OF THE VEHICLE" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER VEHICLE TRANSMISSION" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER MILAGE OF VEHICLE (KM)" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER CONDITION OF THE VEHICLE (USED OR NEW)" << endl;
			cin >> no;
			sweep << no << endl;
			cout << "ENTER PRICE OF THE VEHICLE (RS)" << endl;
			int o;
			cin >> o;
			sweep << o << endl;
			cout << "____________________________________" << endl;
		}
		cout << "SUCCESFULLY ADDED" << endl;
	}
	void addvehilce() {
		
		int total;
		int number;
		int option;
		string choosedbrand;

		cout << "IN WHICH BRAND DO YOU WANT TO ADD VEHICLE?" << endl;
		ifstream moda("LOCAL.txt");
		moda >> total;

		string* jj = new string[total];
		for (int i = 0; i < total; i++) {
			moda >> jj[i];
		}
		do {
			cout << " BRANDS AVAILIABLE : " << endl;
			for (int i = 0; i < total; i++) {
				cout << i << "." << jj[i] << endl;
			}
			cin >> option;
			if (option<0 || option>total) {
				cout << "WRONG CHOICE!!" << endl;
				cout << "TRY AGAIN!!" << endl;
			}
		} while (option<0 || option>total);

		string text = "LOCAL.txt";
		jj[option] = jj[option] + text;
		cout << "HOW MANY VEHICLES DO YOU WANT TO ADD?" << endl;
		int addition;
		cin >> addition;
		int count;
		int sumingup;
		ifstream ope(jj[option]);
		int mul;
		int sp;
		if (ope.fail()) {
			cout << "ERROR OPENING FILE!!" << endl;
		}
		else {

			ope >> count;
			mul = (count + addition) * 9;
			sumingup = count * 9;
			string* array = new string[mul];
			for (int i = 0; i < sumingup; i++) {
				ope >> array[i];
			}
			ope.close();
			ofstream kol(jj[option]);

			sp = count + addition;
			kol << sp << endl;
			for (int i = 0; i < mul; i++) {
				if (i < sumingup) {
					kol << array[i] << endl;
				}
				if (i >= sumingup) {
					cout << "ENTER BRAND OF THE VEHICLE" << endl;
					cin >> array[i];
					kol << array[i] << endl;
					i++;
					cout << "ENTER THE NAME OF THE VEHICLE" << endl;
					cin >> array[i];
					kol << array[i] << endl;
					i++;
					cout << "ENTER THE MODEL YEAR " << endl;
					cin >> array[i];
					kol << array[i] << endl;
					i++;
					cout << "ENTER THE COLOR OF THE VEHICLE" << endl;
					cin >> array[i];
					kol << array[i] << endl;
					i++;
					cout << "ENTER NO OF DOORS OF THE VEHICLE" << endl;
					cin >> array[i];
					kol << array[i] << endl;
					i++;
					cout << "ENTER VEHICLE TRANSMISSION" << endl;
					cin >> array[i];
					kol << array[i] << endl;
					i++;
					cout << "ENTER MILAGE OF VEHICLE (KM)" << endl;
					cin >> array[i];
					kol << array[i] << endl;
					i++;
					cout << "ENTER CONDITION OF THE VEHICLE (USED OR NEW)" << endl;
					cin >> array[i];
					kol << array[i] << endl;
					i++;
					cout << "ENTER PRICE OF THE VEHICLE (RS)" << endl;
					int q;
					cin >> q;
					kol << q << endl;
					i++;
					cout << "____________________________________" << endl;

				}
			}
			kol.close();
		}
		
		cout << "ADDED SUCCESSFULLY" << endl;

	}
};
int submenu() {
	int choice;
	cout << "CHOOSE YOUR OPTION" << endl;
	do {
		cout << "1.ADD TO A CURRENT BRAND?" << endl;
		cout << "2.ADD A NEW BRAND AND A VEHICLE?" << endl;
		cin >> choice;
		if (choice != 1 && choice != 2) {
			cout << "WRONG CHOICE!" << endl;
			cout << "TRY AGAIN!!" << endl;
		}
	} while (choice != 1 && choice != 2);
	return choice;
}
int mainmenu() {
	int choice;
	cout << "CHOOSE YOUR OPTION" << endl;
	do {
	cout << "1.BUYING CARS" << endl;
	cout << "2.ADDING ONE TO STOCK" << endl;
	cin >> choice;
	if (choice != 1 && choice != 2) {
		cout << "WRONG CHOICE!" << endl;
		cout << "TRY AGAIN!!" << endl;
	}
	} while (choice != 1 && choice != 2);
	return choice;
}
int menu() {
	int choice;
	cout << "WHAT TYPE OF VEHICLE YOU ARE LOOKING FOR?" << endl;
	do {
		cout << "1.IMPORTED" << endl;
		cout << "2.LOCAL" << endl;
	
		cin >> choice;
		if (choice != 1 && choice != 2) {
			cout << "WRONG CHOICE!" << endl;
			cout << "TRY AGAIN!!" << endl;
		}
	} while (choice != 1 && choice != 2);
	return choice;
}
void login() {
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "~ ~ ~ S H O W R O O M ~ ~ ~" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "ENTER YOUR LOGIN INFORMATION" << endl;
	cout << endl;
	string username = "admin";
	string g;
	string p;
	string pw = "1234";
	do {
		cout << " ENTER USER NAME : ";
		cin >> g;
		cout << " ENTER PASSWORD : ";
		cin >> p;
		if (username != g || pw != p) {
			cout << "TRY AGAIN !" << endl;
		}
	} while (username != g || pw != p);

}
int main() {
	login();
	imported buffer;
	localveh obj;
	
	if (mainmenu() == 2) {
		if (menu() == 1) {
	
			if (submenu() == 1) {
				buffer.addvehilce();
			}
			else {
				buffer.addmodel();
			}
		}
		else {
			if (submenu() == 1) {
				obj.addvehilce();
			}
			else {
				obj.addmodel();
			}
			
		}
		
	}
	else {
		if (menu() == 1) {
			ifstream imp("IMPORTED.txt");
			cout << "CHOOSE ANY BRAND" << endl;
			int c;
			imp >> c;
			string *a=new string [c];
			for (int i = 0; i < c; i++) {
				imp >> a[i];
				cout << i << " . " << a[i] << endl;;
			}
			int inp;
			do {
				cin >> inp;
				if (inp<0 || inp>c - 1) {
					cout << "WRONG CHOICE!" << endl;
					cout << "TRY AGAIN!" << endl;
				}
			} while (inp<0 || inp>c - 1);
			string t=".txt";
			string s = a[inp] + t;
			ifstream sh(s);
			int var;
			sh >> var;
			imported* jeep = new imported[var];
			string nay;
			int opac;
			double g;
			for (int i = 0; i < var; i++) {
				sh >> nay;
				jeep[i].setbrand(nay);
				sh >> nay;
				jeep[i].setmodel(nay);
				sh >> opac;
				jeep[i].setimport(opac);
				sh >> nay;
				jeep[i].setcolor(nay);
				sh >> opac;
				jeep[i].setdoors(opac);
				sh >> nay;
				jeep[i].settype(nay);
				sh >> opac;
				jeep[i].setmilage(opac);
				sh >> g;
				jeep[i].setgrade(g);
				sh >> opac;
				jeep[i].setprice(opac);
			}
			sh.close();
			cout << "CHOOSE ANY VEHICLE" << endl;
			for (int i = 0; i < var; i++) {
				cout<<i<<" . "<<jeep[i].getmodel()<<endl;
			}
			int yo;
			do {
				cin >> yo;
				if (yo<0 || yo>var - 1) {
					cout << "WRONG CHOICE!" << endl;
					cout << "TRY AGAIN!" << endl;
				}
			} while (yo<0 || yo>var - 1);
			cars* p = &jeep[yo];
			cout << "_______________________________" << endl;
			p->show();
			cout << "DO YOU WANT TO BUY ?" << endl;
			cout << "1.YES " << endl;
			cout << "2.NO" << endl;
			int buy;
			do {
				cin >> buy;
				if (buy != 1 && buy != 2) {
					cout << "WRONG CHOICE!" << endl;
					cout << "TRY AGAIN!" << endl;
				}
			} while (buy != 1 && buy != 2);
			if (buy == 1) {
				cout << "DO YOU WANT DISCOUNT??" << endl;
				cout << "1.YES " << endl;
				cout << "2.NO" << endl;
				int dis;
				do {
					cin >> dis;
					if (dis != 1 && dis != 2) {
						cout << "WRONG CHOICE!" << endl;
						cout << "TRY AGAIN!" << endl;
					}
				} while (dis != 1 && dis != 2);
				if (dis == 1) {
					cout << "ENTER DISCOUNT %" << endl;
					int discount;
					cin >> discount;
					cout << "PRICE BEFORE DISCOUNT :" << jeep[yo].getprice() << " RS" << endl;;
					jeep[yo].discount(discount);
					cout << "PRICE AFTER DISCOUNT : " << jeep[yo].getprice() << " RS" << endl;
					cout << "_________________________________________________" << endl;
					cout << endl;
					cout << "IT WAS NICE TRADING YOU ! :)" << endl;
					cout << endl;
					cout << "_________________________________________________" << endl;
				}
				else {
					cout << "_________________________________________________" << endl;
					cout << "PRICE : " << jeep[yo].getprice() << " RS" << endl;
					cout << "_________________________________________________" << endl;
					cout << endl;
					cout << "IT WAS NICE TRADING YOU ! :)" << endl;
					cout << endl;
					cout << "_________________________________________________" << endl;
				}
			}
			else {
				
				cout << "_________________________________________________" << endl;
				cout << endl;
				cout << "THANKS FOR TRADING ! :)" << endl;
				cout << endl;
				cout << "_________________________________________________" << endl;

			}
		}
		else {
		ifstream imp("LOCAL.txt");
		cout << "CHOOSE ANY BRAND" << endl;
		int c;
		imp >> c;
		string* a = new string[c];
		for (int i = 0; i < c; i++) {
			imp >> a[i];
			cout << i << " . " << a[i] << endl;;
		}
		int inp;
		do {
			cin >> inp;
			if (inp<0 || inp>c - 1) {
				cout << "WRONG CHOICE!" << endl;
				cout << "TRY AGAIN!" << endl;
			}
		} while (inp<0 || inp>c - 1);
		string t = "LOCAL.txt";
		string s = a[inp] + t;
		ifstream sh(s);
		int var;
		sh >> var;
		localveh* jeep = new localveh[var];
		string nay;
		int opac;
		double g;
		for (int i = 0; i < var; i++) {
			sh >> nay;
			jeep[i].setbrand(nay);
			sh >> nay;
			jeep[i].setmodel(nay);
			sh >> opac;
			jeep[i].setage(opac);
			sh >> nay;
			jeep[i].setcolor(nay);
			sh >> opac;
			jeep[i].setdoors(opac);
			sh >> nay;
			jeep[i].settype(nay);
			sh >> opac;
			jeep[i].setmilage(opac);
			sh >> nay;
			jeep[i].setcond(nay);
			sh >> opac;
			jeep[i].setprice(opac);
		}
		sh.close();
		cout << "CHOOSE ANY VEHICLE" << endl;
		for (int i = 0; i < var; i++) {
			cout << i << " . " << jeep[i].getmodel() << endl;
		}
		int yo;
		do {
			cin >> yo;
			if (yo<0 || yo>var - 1) {
				cout << "WRONG CHOICE!" << endl;
				cout << "TRY AGAIN!" << endl;
			}
		} while (yo<0 || yo>var - 1);
		cars* p = &jeep[yo];
		cout << "_______________________________" << endl;
		p->show();
		cout << "DO YOU WANT TO BUY ?" << endl;
		cout << "1.YES " << endl;
		cout << "2.NO" << endl;
		int buy;
		do {
			cin >> buy;
			if (buy != 1 && buy != 2) {
				cout << "WRONG CHOICE!" << endl;
				cout << "TRY AGAIN!" << endl;
			}
		} while (buy != 1 && buy != 2);
		if (buy == 1) {
			cout << "DO YOU WANT DISCOUNT??" << endl;
			cout << "1.YES " << endl;
			cout << "2.NO" << endl;
			int dis;
			do {
				cin >> dis;
				if (dis != 1 && dis != 2) {
					cout << "WRONG CHOICE!" << endl;
					cout << "TRY AGAIN!" << endl;
				}
			} while (dis != 1 && dis != 2);
			if (dis == 1) {
				cout << "ENTER DISCOUNT %" << endl;
				int discount;
				cin >> discount;
				cout << "PRICE BEFORE DISCOUNT :" << jeep[yo].getprice() << " RS" << endl;;
				jeep[yo].discount(discount);
				cout << "PRICE AFTER DISCOUNT : " << jeep[yo].getprice() << " RS" << endl;
				cout << "_________________________________________________" << endl;
				cout << endl;
				cout << "IT WAS NICE TRADING YOU ! :)" << endl;
				cout << endl;
				cout << "_________________________________________________" << endl;
			}
			else {
				cout << "_________________________________________________" << endl;
				cout << "PRICE : " << jeep[yo].getprice() << " RS" << endl;
				cout << "_________________________________________________" << endl;
				cout << endl;
				cout << "IT WAS NICE TRADING YOU ! :)" << endl;
				cout << endl;
				cout << "_________________________________________________" << endl;
			}
		}
		else {

			cout << "_________________________________________________" << endl;
			cout << endl;
			cout << "THANKS FOR TRADING ! :)" << endl;
			cout << endl;
			cout << "_________________________________________________" << endl;

		}
		}
	}
	
	


	return 0;
}
