#include<bits/stdc++.h>
#include "consolole.h"
using namespace std;

// mot so bien toan cuc
// hai mau chu dao : light red and light yellow 
unsigned long long Tien_hien_co = 0;
int xuc_xac = 0;
int red = 12, vang = 10;
string cau_mo_dau = "Hi, I'm KhaiBaDao from Viet Nam              ";
string cau_tiep_theo = "Today I'm going to show you my game, inspired by a betting game from my country and let's get started right here !!                 ";
int tong_xuc_xac = 0;
string T_X = "";
long long tien_cuoc = 50;
int luot_choi = 2;

// chu dau tien

void hien_chu()
{
	gotoxy(30, 2);
	for(int i = 0 ; i < cau_mo_dau.size() ; i++){
		SetColor(red);
		cout << cau_mo_dau[i];
		Sleep(50);
	}
	system("cls");
	gotoxy(10, 2);
	for(int i = 0 ; i < cau_tiep_theo.size() ; i++){
		SetColor(vang);
		cout << cau_tiep_theo[i];
		Sleep(30);
	}
	system("cls");
}

// khung hinh

void ve_khung()
{
	int x_duoi = 80, y_duoi = 30;
	int so = 0;
	for(int i = 20 ; i <= 80 ; i++){
		if(so == 0){
			so++;
			SetColor(red);
		}else
		{
			so = 0;
			SetColor(vang);
		}
		gotoxy(i, 5);
		cout << '*';
		gotoxy(x_duoi, 30);
		cout << '*';
		x_duoi--;
		Sleep(20);
	}
	for(int i = 5 ; i <= 30 ; i++){
		if(so == 0){
			so++;
			SetColor(red);
		}else
		{
			so = 0;
			SetColor(vang);
		}
		gotoxy(19, y_duoi);
		cout << '*';
		y_duoi--;
		gotoxy(81, i);
		cout << '*';
		
		Sleep(20);
	}
	// x = 20 ---> 80
	// y = 5 ----> 30
	gotoxy(43, 7);
	SetColor(red);
	cout << "GAME TAI XIU !!";
	gotoxy(23, 9);
	SetColor(vang);
	cout << "Rule : ";
	gotoxy(23, 11);
	SetColor(red);
	cout << "1. First you will receive a random amount ($100 - $300)";
	gotoxy(23, 14);
	SetColor(vang);
	cout << "2. The game will have 2 results, respectively: TAI XIU";
	// toi lam tiep doi co phien dich tieng anh
	// h ngoi ghi noi dung luat choi 
	gotoxy(23, 17);
	SetColor(red);
	cout << "3. There will be 3 dice, a total of 3 sides of the dice";
	gotoxy(26, 18);
	SetColor(red);
	cout << "corresponds to the result";
	gotoxy(23, 21);
	SetColor(vang);
	cout << "4. Total from 3 --> 10 : XIU , total from 11 --> 18 TAI";
	gotoxy(23, 24);
	SetColor(red);
	cout << "5. When you run out of money, you will get 2 turns";
	gotoxy(26, 25);
	cout << " of support from the game";
	gotoxy(23, 27);
	SetColor(vang);
	cout << "6.                    GOOD LUCK ;))";
}

// ham random ()

int Ran(long long l, long long r){
	return l + rand() % (r - l + 1);
}

void so_random(){
	Tien_hien_co = Ran(100, 300);
	gotoxy(29, 35);
	SetColor(vang);
	cout << "---> ";
	gotoxy(27, 33);
	SetColor(red);
	cout << "Click Space to get 1 random amount !!!";
	while(true){
		if(_kbhit()){
			char ki_tu = getch();
			if(ki_tu == ' ') {
				gotoxy(38, 35);
				SetColor(vang);
				cout << "Your money : ";
				SetColor(vang);
				cout << Tien_hien_co;
				SetColor(red);
				cout << " $";
				for(int i = 0 ; i <= 5 ; i++) Sleep(300);
				break;
			}
		}
		gotoxy(35, 35);
		cout << "   ";
		SetColor(vang);
		cout << Ran(100, 300);
		SetColor(red); cout << " $";
		Sleep(50);
	}
	system("cls");
}

// khung tai xiu :))) metchetme lun

void khung_tai_xiu()
{
	// y tuong hien tai : ve khung to : 8x5
	//                    ve khung nho : 5x3
	// khoang cach giua o nho va o lon <---> == 10
	// khung ben trai : xT = 10 + 20, xP = 18 + 20, yT = 5, yD = 9
	// khung ben phai : xT = 43 + 20 , xP = 51 + 20, yT = 5, yD = 9
	int xT1 = 30, xP1 = 38, xT2 = 63, xP2 = 71;  
	int so = 0;
	for(int i = 10 + 20; i <= 18 + 20 ; i++){
		if(so == 0){
			so++;
			SetColor(red);
		}else
		{
			so = 0;
			SetColor(vang);
		}
		gotoxy(i, 5);
		cout << '-';
		gotoxy(xP1, 9);
		cout << '-';
		xP1--;
		gotoxy(xT2, 5);
		cout << '-';
		xT2++;
		gotoxy(xP2, 9);
		cout << '-';
		xP2--;
		Sleep(100);
	}
	// ve canh ben :))
	// xP1 = 29, xT1 = 39, xP2 = 42, xT2 = 72
	int yT1 = 6, yD1 = 9, yT2 = yT1, yD2 = yD1;
	for(int i = 6 ; i <= 9 ; i++){
		if(so == 0){
			so++;
			SetColor(red);
		}else   
		{
			so = 0;
			SetColor(vang);
		}
		gotoxy(29, i);
		cout << '*';
		gotoxy(62, i);
		cout << '*';
		gotoxy(39, yD1);
		cout << '*';
		gotoxy(72, yD1);
		cout << '*';
		yD1--;
		Sleep(100);
	}
}

// chu hien tren man hinh 
// sau khi ma kiem tra xong thi sao, ta phai cho no toi lun vong tiep theo
// van phai giu cho cái so giây nó chay duoc 
// luc nay can phai co bien de kiem tra tai hay xiu va tang giam tien cuoc
// tai sao ko tach cai vong while giay ra lam 2 vong while :)))))
// maybe can do it

void Dat_cuoc()
{
	int giay = 30;
	int mau1 = red, mau2 = vang, mau_fake = red; //////////////////////////
	// chu Tai : x = 33, y = 7
	gotoxy(0, 0);
	SetColor(vang);
	cout << "Your money : " << Tien_hien_co;
	SetColor(red);
	cout << " $";
	while(true){
		gotoxy(32, 7);
		SetColor(mau1);
		cout << "TAI !!";
		gotoxy(65	, 7);
		SetColor(mau2);
		cout << "XIU !!";
		gotoxy(30 - 3, 11);
		SetColor(vang);
		cout << "Choose 1 :";
		SetColor(red);
		cout << " XIU                   ";
		SetColor(vang);
		cout << "Choose 2 :";
		SetColor(red);
		cout << " TAI";
		gotoxy(29 + 1, 13); 
		SetColor(mau2);
		cout << "1. XIU !";
		gotoxy(59 + 4, 13);
		SetColor(mau1); 
		cout << "2. TAI !";
		if(_kbhit()){
			char ki_tu = getch();
			if(ki_tu == '1'){
				T_X = "XIU";
				break;
			}else if(ki_tu == '2'){
				T_X = "TAI";
				break;
			}
		}
		Sleep(600);
		mau1 = mau2, mau2 = mau_fake, mau_fake = mau1;
	}
	while(true){
		gotoxy(32, 7);
		SetColor(mau1);
		cout << "TAI !!";
		gotoxy(65	, 7);
		SetColor(mau2);
		cout << "XIU !!";
		gotoxy(30, 13);
       	cout << "                                                                              ";
       	gotoxy(20, 11);
        SetColor(vang);
	    cout << "                       Your choose : ";
        SetColor(red); cout << T_X << "                   ";
        gotoxy(10, 13);
        SetColor(vang);
        cout << "Select the ";
		SetColor(red);
		cout << "'F' ";
		SetColor(vang);
		cout << "or";
		SetColor(red);
		cout << " 'J' ";
		SetColor(vang);
		cout << "button to increase or decrease the bet amount then press ";
		SetColor(red);
		cout << "Space ";
		SetColor(vang);
		cout << "to start";
        gotoxy(30 + 9, 15);
		SetColor(red);
        cout << '-';
        gotoxy(50 + 10 + 4, 15);
        SetColor(red);
        cout << '+';
        if(tien_cuoc > Tien_hien_co) tien_cuoc = Tien_hien_co;
		if(_kbhit()){
			char ki_tu = getch();
			if(ki_tu == ' '){
		    	system("cls");
		    	break;
		    // khi tien cuoc 10 ---> 1 ==> tien_cuoc > 1 va tien_cuoc <= 10
		    
		    // neu so tien vuot qua 1000 thi se tru di moi lan nhu the la : 100
		    
			}else if((ki_tu == 'f' || ki_tu == 'F' || ki_tu == '-') && (1 < tien_cuoc && tien_cuoc <= 10)) tien_cuoc -= 1;
			else if((ki_tu == 'f' || ki_tu == 'F' || ki_tu == '-')&& (tien_cuoc <= 50 && tien_cuoc > 0)) tien_cuoc -= 10;
		    else if((ki_tu == 'f' || ki_tu == 'F' || ki_tu == '-') && tien_cuoc > 50) tien_cuoc -= 50;
		    //khi Tien_hien_co - tien_cuoc < 10 && Tien_hien_co - tien_cuoc >= 10
		    else if((ki_tu == 'j' || ki_tu == 'J' || ki_tu == '+') && (Tien_hien_co - tien_cuoc < 10) && tien_cuoc < Tien_hien_co) tien_cuoc += 1;
		    // khi Tien_hien_co - tien_cuoc < 50 && Tien_hien_co - tien_cuoc >= 10 ===> tien_cuoc += 10
		    else if((ki_tu == 'j' || ki_tu == 'J' || ki_tu == '+')  && ((Tien_hien_co - tien_cuoc < 50) && Tien_hien_co - tien_cuoc >= 10)) tien_cuoc += 10;
		    else if((ki_tu == 'j' || ki_tu == 'J' || ki_tu == '+') && (tien_cuoc < 50 && tien_cuoc >= 0 && tien_cuoc <= Tien_hien_co)) tien_cuoc += 10;
		    else if((ki_tu == 'j' || ki_tu == 'J' || ki_tu == '+') && (tien_cuoc >= 50 && tien_cuoc > 0 && tien_cuoc <= Tien_hien_co) && tien_cuoc + 50 <= Tien_hien_co) tien_cuoc += 50;
		}
        gotoxy(48, 15);
        SetColor(vang);
        cout << tien_cuoc;
        SetColor(red);
        cout << " $  ";
		Sleep(600);
		mau1 = mau2, mau2 = mau_fake, mau_fake = mau1;
	}
}

// ham xuc xac

//ham ve khung xuc xac : 

void ve_khung_xuc_xac(int x1, int y1, int x2, int y2){
	int x_fake = x1;
	for(int i = 0 ; i < 6 ; i++){
		gotoxy(x1, y1);
		cout << "* " << ' ';
		gotoxy(x1, y2);
		cout << "* " << ' ';
		x1++;
	}
	for(int i = 0 ; i < 3 ; i++){
		gotoxy(x_fake, y1);
		cout << '*';
		gotoxy(x2, y1);
		cout << '*';
		y1++;
	}
}

void ba_cham()
{
	string ba_cham = "  *     *     *    *       ";
	gotoxy(10, 4);
	for(int i = 0 ; i < ba_cham.size() ; i++){
		SetColor(vang);
		cout << ba_cham[i];
		Sleep(50);
	}
	system("cls");
}

// ham xuc xac

void gieo_xuc_xac(){	
    ba_cham();
    gotoxy(0, 0);
	SetColor(vang);
	cout << "Your money : " << Tien_hien_co;
	SetColor(red);
	cout << " $";
    gotoxy(12, 6);
    string mui_ten = "----> ";
	for(int i = 0 ; i < mui_ten.size() ; i++){
		SetColor(vang);
		cout << mui_ten[i];
		Sleep(150);
	}
	SetColor(red);
	int x1 = 20, y1 = 5, x2 = 26, y2 = 7;
	for(int i = 0 ; i < 3 ; i++){
		ve_khung_xuc_xac(x1, y1, x2, y2);
		x1 += 13, x2 += 13;
		Sleep(500);
	}
	x1 = 23, y1 = 6;
	int gia_tri = 1;
	for(int i = 0 ; i < 3 ; i++){
		xuc_xac = Ran(1, 6);
		tong_xuc_xac += xuc_xac;
		gotoxy(x1, y1);
		SetColor(vang);
		cout << xuc_xac;
		x1 += 14 - gia_tri;
		gia_tri++;
		if(gia_tri == 2) gia_tri -= 1;
		Sleep(500);
	}
	string tong_ba_cuc_xuc_xac = "The total three dice are : ";
	gotoxy(16, 9);
	SetColor(red);
	for(int i = 0 ; i < tong_ba_cuc_xuc_xac.size() ; i++){
		cout << tong_ba_cuc_xuc_xac[i];
		Sleep(60);
	}
	SetColor(vang);
	cout << tong_xuc_xac;
	string t_x_tuong_ung = "---->      ", ket_qua = "";
	if(3 <= tong_xuc_xac && tong_xuc_xac <= 10){
		ket_qua = "XIU";
	}else if(11 <= tong_xuc_xac && tong_xuc_xac <= 18){
		ket_qua = "TAI";
	}
	gotoxy(25, 11);
	SetColor(vang);
	for(int i = 0 ; i < t_x_tuong_ung.size() ; i++){
		cout << t_x_tuong_ung[i];
		Sleep(100);
	}
	SetColor(red);
	cout << ket_qua << " !";
	gotoxy(20, 13);
	SetColor(vang);
	SetColor(vang);
	string y = "Your choose :    ";
	gotoxy(19, 13);
	for(int i = 0 ; i < y.size() ; i++){
		SetColor(vang);
		cout << y[i];
		Sleep(100);
	}
	SetColor(red);
	cout << T_X << " !";
	string win = "SO LUCKY, YOU WINN !!! ";
	string lost = "  SORRY YOU LOST !!!";
	string bla = "Your money : ";
	if(T_X == ket_qua){
		gotoxy(19, 15);
		SetColor(vang);
		cout << win;
		gotoxy(5, 17);
		for(int i = 0 ; i < t_x_tuong_ung.size() ; i++){
			SetColor(vang);
			cout << t_x_tuong_ung[i];
			Sleep(100);
		}
		for(int i = 0 ; i < bla.size(); i++){
			SetColor(vang);
			cout << bla[i];
			Sleep(100);
		}
		SetColor(vang);
		cout << Tien_hien_co;
		SetColor(red);
		cout << " $    ";
		SetColor(red);
		for(int i = 0 ; i < 9 ; i++){
		    cout <<	t_x_tuong_ung[i];
			Sleep(100);
		}
		gotoxy(45, 17);
		SetColor(vang);
		cout << "    ";
		cout << Tien_hien_co + tien_cuoc; SetColor(red); cout << " $";
		gotoxy(13, 0);
		Tien_hien_co += tien_cuoc;
		SetColor(vang);
		cout << Tien_hien_co;
	}else if(T_X != ket_qua){
		gotoxy(19, 15);
		SetColor(vang);
		cout << lost;
		gotoxy(5, 17);
		for(int i = 0 ; i < t_x_tuong_ung.size() ; i++){
			SetColor(vang);
			cout << t_x_tuong_ung[i];
			Sleep(100);
		}
		for(int i = 0 ; i < bla.size(); i++){
			SetColor(vang);
			cout << bla[i];
			Sleep(100);
		}
		SetColor(vang);
		cout << Tien_hien_co;
		SetColor(red);
		cout << " $    ";
		SetColor(vang);
		for(int i = 0 ; i < 9 ; i++){
		    cout <<	t_x_tuong_ung[i];
			Sleep(100);
		}
		gotoxy(45, 17);
		SetColor(vang);
		cout << "    ";
		cout << Tien_hien_co - tien_cuoc; SetColor(red); cout << " $";
		gotoxy(13, 0);
		cout << "    ";
		gotoxy(13, 0);
		Tien_hien_co -= tien_cuoc;
		SetColor(vang);
		cout << Tien_hien_co;
	}
	for(int i = 10; i >= 1 ; --i){
		Sleep(150);
	}
	system("cls");
	SetColor(vang);
	string man_tt = "The next turn will begin later : ";
	gotoxy(20, 3);
	cout << man_tt;
	SetColor(red);
	for(int i = 5 ; i >= 1 ; --i){
		gotoxy(54, 3);
		cout << i << " s";
		Sleep(700);
	}
	system("cls");
}

void so_random_2(){
	system("cls");
	for(int i = 0 ; i < 5 ; i++){
		SetColor(vang);
		gotoxy(10, 3);
		cout << "Your money has reached 0, turn help will be used";
		Sleep(500);
	}
	system("cls");
	gotoxy(29, 7);
	SetColor(vang);
	luot_choi--;
	gotoxy(0, 0);
	SetColor(vang);
	cout << "Your turn help : ";
    SetColor(red);
    cout << luot_choi;
	Tien_hien_co = Ran(100, 300);
	gotoxy(29, 7);
	SetColor(vang);
	cout << "---> ";
	gotoxy(27, 5);
	SetColor(vang);
	cout << "Click";
	SetColor(red);
	cout << " Space";
	SetColor(vang);
	cout << " to get 1 random amount !!!";
	while(true){
		if(_kbhit()){
			char ki_tu = getch();
			if(ki_tu == ' ') {
				gotoxy(38, 7);
				SetColor(vang);
				cout << "Your money : ";
				SetColor(vang);
				cout << Tien_hien_co;
				SetColor(red);
				cout << " $";
				for(int i = 0 ; i <= 5 ; i++) Sleep(300);
				break;
			}
		}
		gotoxy(37, 7);
		cout << "   ";
		SetColor(vang);
		cout << Ran(100, 300);
		SetColor(red); cout << " $";
		Sleep(50);
	}
	system("cls");
}

int main()
{
	srand(time(NULL));
    hien_chu();
    ve_khung();
	so_random();
	khung_tai_xiu();
	while(luot_choi){
		if(Tien_hien_co == 0){
			so_random_2();
			khung_tai_xiu();
			Dat_cuoc();
	    	gieo_xuc_xac();
		}else
		{
			khung_tai_xiu();
			Dat_cuoc();
	    	gieo_xuc_xac();
		}
		tong_xuc_xac = 0;
		tien_cuoc = 50;
    	if(luot_choi == 0){
	    	int mau1 = red, mau2 = vang, mau_fake = red;
    	    for(int i = 0 ; i <= 15 ; i++){
    	    	SetColor(mau1);
    	    	gotoxy(20, 5);
    	    	cout << "Your help is over, see you soon ; )";
    	    	Sleep(200);
			}
			exit(0);
		}
	}
	return 0;
}                                                                                             
