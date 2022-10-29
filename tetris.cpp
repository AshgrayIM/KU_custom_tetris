#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib") 

using namespace std;

const int EXT_KEY = 0xffffffe0;   //확장키 인식값 
const int KEY_LEFT = 0x4b;
const int KEY_RIGHT = 0x4d;
const int KEY_UP = 0x48;
const int KEY_DOWN = 0x50;
const int KEY_PAUSE = 0x70;
const int KEY_HOLD = 0x68;
const int KEY_ESC = 0x1b;
const int KEY_ENTER = 13;
const int KEY_SPACEBAR = 32;

class SYSTEM {
public:
	static char block[8][4][4][4];

	enum {
		BLACK,      /*  0 : 까망 */
		DARK_BLUE,    /*  1 : 어두운 파랑 */
		DARK_GREEN,    /*  2 : 어두운 초록 */
		DARK_SKY_BLUE,  /*  3 : 어두운 하늘 */
		DARK_RED,    /*  4 : 어두운 빨강 */
		DARK_VOILET,  /*  5 : 어두운 보라 */
		DARK_YELLOW,  /*  6 : 어두운 노랑 */
		GRAY,      /*  7 : 회색 */
		DARK_GRAY,    /*  8 : 어두운 회색 */
		BLUE,      /*  9 : 파랑 */
		GREEN,      /* 10 : 초록 */
		SKY_BLUE,    /* 11 : 하늘 */
		RED,      /* 12 : 빨강 */
		VOILET,      /* 13 : 보라 */
		YELLOW,      /* 14 : 노랑 */
		WHITE,      /* 15 : 하양 */
	};

	int gotoxy(int x, int y)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos;
		pos.Y = y;
		pos.X = x;
		SetConsoleCursorPosition(hConsole, pos);
		return 0;
	}

	void SetColor(int color)

	{
		static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(std_output_handle, color);

	}
	void CursorView(char show)//커서숨기기
	{
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		ConsoleCursor.bVisible = show;
		ConsoleCursor.dwSize = 1;
		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	}
};

char SYSTEM::block[8][4][4][4] = {
	//막대모양
	1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

	//네모모양
	1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

	//'ㅓ' 모양
	0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,

	//'ㄱ'모양
	1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,

	//'ㄴ' 모양
	1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,

	//'Z' 모양
	1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,

	//'S' 모양
	0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,

	//커스터마이징
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};


class CUSTOMIZE {
private:
	SYSTEM s;
public:
	CUSTOMIZE() {}

	void inIt() {
		int input;
		int select;
		int answer = 0;
		int x = 0, y = 0;
		init_custom_block();

		system("cls");

		s.gotoxy(12, 4);
		s.SetColor(s.GRAY);
		cout << "[Customizing Block]" << endl;
		for (int i = 0; i < 4; i++) {
			s.gotoxy(17, 6 + i);
			for (int j = 0; j < 4; j++) {

				cout << "□";
			}
			cout << endl;
		}

		s.gotoxy(17, 6);
		cout << "■";

		s.gotoxy(11, 11);
		cout << "Make your own block!!";
		s.gotoxy(5, 12);
		cout << "┌──────────────┐";
		s.gotoxy(5, 13);
		cout << "│ → ← ↑ ↓ : move cursor  │";
		s.gotoxy(5, 14);
		cout << "│SPACEBAR : choose one block │";
		s.gotoxy(5, 15);
		cout << "│  ENTER  : make block       │";
		s.gotoxy(5, 16);
		cout << "└──────────────┘";

		while (answer != KEY_ENTER)
		{
			select = _getch();
			if (select == KEY_ENTER) {
				system("cls");
				s.gotoxy(12, 4);
				s.SetColor(s.GRAY);
				cout << "[Customized Block]" << endl;

				s.SetColor(s.DARK_BLUE);
				for (int i = 0; i < 4; i++) {
					s.gotoxy(17, 6 + i);
					for (int j = 0; j < 4; j++) {
						if (SYSTEM::block[7][0][i][j] == 1)
							cout << "■";
						else
							cout << "  ";
					}
					cout << endl;
				}

				answer = KEY_ENTER;
			}
			if (select == KEY_SPACEBAR)
			{
				SYSTEM::block[7][0][y][x] = 1;
				for (int i = 0; i < 4; i++) {
					s.gotoxy(17, 6 + i);
					for (int j = 0; j < 4; j++) {
						if (SYSTEM::block[7][0][i][j] == 1)
							cout << "■";
						else
							cout << "□";
					}
					cout << endl;
				}
			}

			if (select == 224)
			{
				select = _getch();
				switch (select)
				{
				case KEY_RIGHT:
					if (SYSTEM::block[7][0][y][x] == 0) {
						s.gotoxy(2 * x + 17, y + 6);
						cout << "□";
					}
					if (x == 3) {
						x = 0;
						s.gotoxy(2 * x + 17, y + 6);
						cout << "■";
					}
					else {
						x++;
						s.gotoxy(2 * x + 17, y + 6);
						cout << "■";
					}
					break;
				case KEY_LEFT:
					if (SYSTEM::block[7][0][y][x] == 0) {
						s.gotoxy(2 * x + 17, y + 6);
						cout << "□";
					}
					if (x == 0) {
						x = 3;
						s.gotoxy(2 * x + 17, y + 6);
						cout << "■";
					}
					else {
						x--;
						s.gotoxy(2 * x + 17, y + 6);
						cout << "■";
					}
					break;
				case KEY_DOWN:
					if (SYSTEM::block[7][0][y][x] == 0) {
						s.gotoxy(2 * x + 17, y + 6);
						cout << "□";
					}
					if (y == 3) {
						y = 0;
						s.gotoxy(2 * x + 17, y + 6);
						cout << "■";
					}
					else {
						y++;
						s.gotoxy(2 * x + 17, y + 6);
						cout << "■";
					}
					break;
				case KEY_UP:
					if (SYSTEM::block[7][0][y][x] == 0) {
						s.gotoxy(2 * x + 17, y + 6);
						cout << "□";
					}
					if (y == 0) {
						y = 3;
						s.gotoxy(2 * x + 17, y + 6);
						cout << "■";
					}
					else {
						y--;
						s.gotoxy(2 * x + 17, y + 6);
						cout << "■";
					}
					break;
				default:
					break;
				}
			}

		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					if (j == 0 || j == 3 || k == 0 || k == 3) {
						SYSTEM::block[7][i + 1][3 - k][j] = SYSTEM::block[7][i][j][k];
					}
					else {
						SYSTEM::block[7][i + 1][j][k] = SYSTEM::block[7][i][k][3 - j];
					}
				}
			}
		}
		for (int i = 0; i < 3; i++) {      //(커스터마이징) 
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					if (j == 0 || j == 3 || k == 0 || k == 3) {
						SYSTEM::block[7][i + 1][3 - k][j] = SYSTEM::block[7][i][j][k];
					}
					else {
						SYSTEM::block[7][i + 1][j][k] = SYSTEM::block[7][i][k][3 - j];
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int l = 0; l < 3; l++){
				if ((SYSTEM::block[7][i][l][0] + SYSTEM::block[7][i][l][1] + SYSTEM::block[7][i][l][2] + SYSTEM::block[7][i][l][3]) == 0) {
					for (int j = 0; j < 4; j++) {
						for (int k = 0; k < 3; k++) {
							SYSTEM::block[7][i][k][j] = SYSTEM::block[7][i][k + 1][j];
						}
					}
					for (int k = 0; k < 4; k++) {
						SYSTEM::block[7][i][3 - l][k] = 0;
					}
					if (SYSTEM::block[7][i][l + 1][0] + SYSTEM::block[7][i][l + 1][1] + SYSTEM::block[7][i][l + 1][2] + SYSTEM::block[7][i][l + 1][3]){
						l = 3;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int l = 0; l < 3; l++){
				if ((SYSTEM::block[7][i][0][l] + SYSTEM::block[7][i][1][l] + SYSTEM::block[7][i][2][l] + SYSTEM::block[7][i][3][l]) == 0) {
					for (int j = 0; j < 4; j++) {
						for (int k = 0; k < 3; k++) {
							SYSTEM::block[7][i][j][k] = SYSTEM::block[7][i][j][k + 1];
						}
					}
					for (int k = 0; k < 4; k++) {
						SYSTEM::block[7][i][k][3 - l] = 0;
					}
					if (SYSTEM::block[7][i][0][l + 1] + SYSTEM::block[7][i][1][l + 1] + SYSTEM::block[7][i][2][l + 1] + SYSTEM::block[7][i][3][l + 1]){
						l = 3;
					}
				}
			}
		}

		s.SetColor(s.GRAY);
		s.gotoxy(8, 11);
		cout << "press any key to play game";
		s.gotoxy(8, 12);
		cout << "     with this block.";

		_getch();
		system("cls");
	}

	void init_custom_block() {      //커스터마이징할 블럭자리 0으로 초기화
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				SYSTEM::block[7][0][i][j] = 0;
		}
	}

	int get_bin() const {   //커스터마이징을 했는지 안했는지 여부 
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (SYSTEM::block[7][0][i][j]) {      //1이 단 하나라도 있으면
					return 1;
				}
			}
		}

		return 0;
	}
};

class SCENE {
private:
	const int ab_x = 5, ab_y = 1;
	SYSTEM s;
public:
	void show_pause() { //일시정지 화면
		PlaySound(NULL, 0, 0); //노래도 일시정지
		s.SetColor(s.RED);

		for (int i = 0; i < 20; i++)
		{
			for (int j = 1; j < 13; j++)
			{
				s.gotoxy((j * 2) + ab_x, i + ab_y);
				cout << "  ";
				if (i == 0 || i == 19 || j == 1 || j == 12) {
					s.gotoxy((j * 2) + ab_x, i + ab_y);
					cout << " \"";
				}
			}
			cout << endl;
		}
		s.gotoxy((5 * 2) + ab_x, 9 + ab_y);
		cout << "p a u s e";
		fflush(stdin);

		_getch(); //아무키나 입력받으면 게임 시작
		PlaySound(TEXT("C:\\res\\tetrixBGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //노래도 시작
	}

	bool show_gameover(int score)
	{
		int ans;

		s.SetColor(s.RED);
		s.gotoxy(20, 7);
		cout << "┏━━━━━━━━━┓";
		s.gotoxy(20, 8);
		cout << "┣━━━━━━━━━┫";
		s.gotoxy(20, 9);
		cout << "┃*    GAME OVER   *┃";
		s.gotoxy(20, 10);
		cout << "┣━━━━━━━━━┫";
		s.gotoxy(20, 11);
		cout << "┃ SCORE :          ┃";
		s.gotoxy(20, 12);
		cout << "┃  RECORD (ENTER)  ┃";
		s.gotoxy(20, 13);
		cout << "┃     EXIT(ESC)    ┃";
		s.gotoxy(20, 14);
		cout << "┗━━━━━━━━━┛";

		s.gotoxy(31, 11);
		cout << setw(6) << setfill(' ') << score;

		while (1) {
			ans = _getch();
			if (ans == KEY_ENTER) {
				PlaySound(NULL, 0, 0);
				return true;
			}
			else if (ans == KEY_ESC) {
				PlaySound(NULL, 0, 0);
				return false;
			}
			else
				continue;
		}

	}

	void show_register() {

		s.SetColor(s.SKY_BLUE);
		s.gotoxy(20, 7);
		cout << "┏━━━━━━━━━┓";
		s.gotoxy(20, 8);
		cout << "┣━━━━━━━━━┫";
		s.gotoxy(20, 9);
		cout << "┃*  RECORD SCORE  *┃";
		s.gotoxy(20, 10);
		cout << "┣━━━━━━━━━┫";
		s.gotoxy(20, 11);
		cout << "┃ ENTER YOUR NAME  ┃";
		s.gotoxy(20, 12);
		cout << "┃    (3 initial)   ┃";
		s.gotoxy(20, 13);
		cout << "┃                  ┃";
		s.gotoxy(20, 14);
		cout << "┗━━━━━━━━━┛";
	}

	void show_interface() {
		for (int i = 21; i < 24; i++)
		{
			s.SetColor(s.GRAY);
			s.gotoxy(5, i + 1);

			for (int j = 0; j < 14; j++)
			{
				if (j == 0 || j == 13 || i == 21 || i == 23)
					cout << "■";
				else
					cout << "  ";
			}
		}
	}
	void erase_interface() {
		s.gotoxy(7, 23);
		cout << "                        ";
	}
};

class STAGE {      //각 스테이지마다의 난이도 설정
private:
	int speed;   //숫자가 낮을수록 속도가 빠르다
	int stick_rate;      //막대가 나오는 확률 0~99 , 99면 막대기만 나옴
	int clear_line;
public:
	STAGE(const int &sp, const int &sr, const int &cl) :speed(sp), stick_rate(sr), clear_line(cl) {}

	const int get_speed() { return speed; }
	const int get_stick_rate() { return stick_rate; }
	const int get_clear_line() { return clear_line; }
};

class BLOCK {
private:
	int shape, angle, x, y;
public:
	BLOCK(const int sh) :shape(sh), angle(0) {}

	int get_block_x() const { return x; }
	int get_block_y() const { return y; }
	int get_block_shape() const { return shape; }
	int get_block_angle() const { return angle; }

	void set_block_x(int _x) { x = _x; }
	void set_block_y(int _y) { y = _y; }
	void set_block_shape(int s) { shape = s; }
	void set_block_angle(int a) { angle = a; }

	void init() {
		angle = 0;
		x = 5;
		y = -3;
	}
	void upperX() { x++; }
	void lowerX() { x--; }
	void upperY() { y++; }
	void lowerY() { y--; }
	void upperAngle() { angle = (angle + 1) % 4; }
};

class HOLD {
private:
	int hold_block_shape;//홀드한 블락
	bool hold_check;//홀드했는지 안했는지
	int hold_index;//홀드키를 연속으로 누르는 것을 검사할 때 필요한 변수
public:
	HOLD() :hold_block_shape(-1), hold_check(false), hold_index(-1) {}

	void init() {
		hold_block_shape = -1;
		hold_check = false;
		hold_index = -1;
	}
	void set_hold_index(const int index) { hold_index = index; }
	void set_hold_check(const bool check) { hold_check = check; }
	void set_hold_block_shape(const int shape) { hold_block_shape = shape; }

	int get_hold_index() { return hold_index; }
	int get_hold_block_shape() { return hold_block_shape; }

	bool get_hold_check() { return hold_check; }

};

class TIME {
private:
	const int LAST_TIME = 180;
	int last_time;   //남은 시간
	clock_t start, end, timer;   //남은 시간 계산 변수
	SYSTEM s;
	SCENE c;
public:
	TIME() :last_time(LAST_TIME) {}

	bool time_check() {
		if (timer / 1000 == 1) { //timer=end-start로 start()함수에서 for문이 돌기 전 시간을 start에 저장하고 for문 안에서의 시간을 end에 저장한다. 만약 timer가 1초이면.
			start = clock(); // 다시 start에 시간을 저장한다 (다시 timer를 구하기 위해)
			last_time--; // 남은 시간을 1초 깎는다
			if (last_time <= 0) // 남은 시간이 없다면
				return 1; // 1을 반환해 게임 오버 시킨다.
			else { //있다면 
				if (last_time <= 30) { //남은 시간이 30초보다 작을경우
					c.erase_interface();
					s.gotoxy(7, 23);
					s.SetColor(s.GRAY);
					cout << "a few seconds left.."; //메시지출력
				}
				return 0; // 0을 반환해 게임을 계속 진행시킨다. 
			}

		}
	}

	void init() {
		last_time = LAST_TIME;
	}
	void show_last_time() {

		s.gotoxy(35, 14);
		s.SetColor(s.WHITE);


		if (last_time <= 30)
			s.SetColor(s.RED);

		cout << setw(2) << setfill('0') << last_time / 60 << ":";
		cout << setw(2) << setfill('0') << last_time % 60;
	}
	void set_timer() { timer = end - start; }
	void set_end(clock_t clock) { end = clock; }
	void set_start(clock_t clock) { start = clock; }

	int get_last_time() { return last_time; }
};

class GAME {
private:
	int level;
	int index;//추가
	const int ab_x = 5, ab_y = 1;
	int next_block_shape;
	int score;
	int lines;
	int z_skill;
	int x_skill;
	char total_block[21][14];
	BLOCK preBlock = BLOCK(0);
	BLOCK preGhBlock = BLOCK(0);
	STAGE *stage_data[9];
	TIME t;
	SCENE c;
	SYSTEM s;
	HOLD h;
	CUSTOMIZE m;
public:
	GAME()
	{
		stage_data[0] = new STAGE(40, 20, 2);
		stage_data[1] = new STAGE(38, 18, 20);
		stage_data[2] = new STAGE(35, 18, 20);
		stage_data[3] = new STAGE(30, 17, 20);
		stage_data[4] = new STAGE(25, 16, 20);
		stage_data[5] = new STAGE(20, 14, 20);
		stage_data[6] = new STAGE(15, 14, 20);
		stage_data[7] = new STAGE(10, 13, 20);
		stage_data[8] = new STAGE(6, 12, 99999);
	}
	~GAME() {
		for (int i = 0; i < 10; i++) {
			delete stage_data[i];
		}
	}

	int move_block()
	{
		erase_cur_block(preBlock);

		preBlock.upperY();   //블럭을 한칸 아래로 내림
		if (strike_check(preBlock, preBlock.get_block_angle()) == 1)
		{
			c.erase_interface();

			if (preBlock.get_block_y() < 0)   //게임오버
			{
				return 1;
			}

			index++;//추가

			preBlock.lowerY();
			merge_block();
			preBlock = BLOCK(next_block_shape);
			next_block_shape = make_new_block();

			block_start();
			show_next_block(next_block_shape);
			return 2;
		}
		return 0;
	}
	int move_Ghblock()
	{
		preGhBlock.upperY(); //블럭을 한칸 아래로 내림
		if (strike_check(preGhBlock, preGhBlock.get_block_angle()) == 1)
		{
			preGhBlock.lowerY();
			return 1;
		}
		return 0;
	}
	int make_new_block()
	{
		int shape;
		int i;
		i = rand() % 100;
		if (i <= stage_data[level]->get_stick_rate())      //막대기 나올확률 계산
			return 0;                     //막대기 모양으로 리턴

		shape = (rand() % (6 + m.get_bin()) + 1);      //shape에는 1~6+get_bin()의 값이 들어감
		show_next_block(shape);
		return shape;
	}
	int strike_check(BLOCK& Block, int angle)
	{
		int block_dat;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (((Block.get_block_x() + j) == 0) || ((Block.get_block_x() + j) == 13))
					block_dat = 1;
				else
				{
					if (Block.get_block_y() + i >= 0)
						block_dat = total_block[Block.get_block_y() + i][Block.get_block_x() + j];
					else
						block_dat = 0;
				}
				if ((block_dat == 1) && (SYSTEM::block[Block.get_block_shape()][angle][i][j] == 1))                                                                     //좌측벽의 좌표를 빼기위함
				{
					return 1;
				}
			}
		}
		return 0;
	}

	void init()
	{
		srand((unsigned)time(NULL));

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				if ((j == 0) || (j == 13))
				{
					total_block[i][j] = 1;
				}
				else {
					total_block[i][j] = 0;
				}
			}
		}

		for (int j = 0; j < 14; j++)         //화면의 제일 밑의 줄은 1로 채운다.
			total_block[20][j] = 1;

		level = 0;
		lines = 0;
		score = 0;
		h.init();
		t.init();
		index = 0;
		z_skill = 3;
		x_skill = 1;
	}
	void mini()
	{
		s.gotoxy(23, 15);
		for (int i = 0; i < 10; i++)
		{
			s.SetColor(s.DARK_BLUE);
			for (int j = 0; j < 12; j++)
			{
				if (i == 0 || i == 9 || j == 11)
				{
					s.gotoxy(23 + 2 * i, 15 + j);
					cout << "■";
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			s.SetColor(s.DARK_GREEN);
			for (int j = 0; j < 5; j++)
			{
				if (i == 0 || i == 4 || j == 0 || j == 4) {
					s.gotoxy(43 + 2 * i, 15 + j);
					cout << "■";
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			s.SetColor(s.DARK_SKY_BLUE);
			for (int j = 0; j < 5; j++)
			{
				if (i == 0 || i == 4 || j == 0 || j == 4) {
					s.gotoxy(43 + 2 * i, 22 + j);
					cout << "■";
				}
			}
		}
		s.SetColor(s.DARK_GRAY);
		s.gotoxy(29, 25);
		cout << "■";
		s.gotoxy(31, 25);
		cout << "■";
		s.gotoxy(33, 25);
		cout << "■";
		s.gotoxy(31, 24);
		cout << "■";
		s.SetColor(s.YELLOW);
		s.gotoxy(31, 20);
		cout << "■";
		s.gotoxy(31, 21);
		cout << "■";
		s.gotoxy(33, 21);
		cout << "■";
		s.gotoxy(33, 22);
		cout << "■";
		s.SetColor(s.RED);
		s.gotoxy(45, 16);
		cout << "■";
		s.gotoxy(45, 17);
		cout << "■";
		s.gotoxy(45, 18);
		cout << "■";

	}
	void init2() {
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				if ((j == 0) || (j == 13))
				{
					total_block[i][j] = 1;
				}
				else {
					total_block[i][j] = 0;
				}
			}
		}

		for (int j = 0; j < 14; j++)         //화면의 제일 밑의 줄은 1로 채운다.
			total_block[20][j] = 1;

		lines = 0;
		h.init();
		t.init();

		index = 0;
	}
	void skill_x()
	{
		x_skill--;//스킬 사용시 사용 가능 횟수 줄임
		for (int i = 0; i < 20; i++)
		{
			for (int j = 1; j < 7; j++)
			{
				total_block[i][13 - j] = total_block[i][j];
				//모든 줄을 돌면서 1 2 3 4 5 6 7 8 9 10 11 12 를
				//                1 2 3 4 5 6 6 5 4 3  2  1 로 만든다
			}
		}
		show_total_block();

		Sleep(30);
		check_full_line();//스킬로 인하여 가득찬 줄을 지워주고 표시한다.
		preBlock.upperY();
		show_total_block();
		show_cur_block(preBlock.get_block_shape(), preBlock.get_block_angle(), preBlock.get_block_x(), preBlock.get_block_y());
	}
	void skill_z()
	{
		int j;
		z_skill--;//스킬 사용시 사용 가능 횟수 줄임
		s.SetColor(s.RED);
		s.gotoxy(1 * 2 + ab_x, 19 + ab_y);
		for (j = 1; j<13; j++)
		{
			s.SetColor(j + 1);
			cout << "□";
			Sleep(10);
		}
		//가장 아래 한줄을 지운다.
		s.gotoxy(1 * 2 + ab_x, 19 + ab_y);
		for (j = 1; j<13; j++)
		{
			cout << "  ";
			Sleep(10);
		}

		for (int k = 19; k>0; k--)
		{
			//그 후 한칸씩 아래로 당겨준다.
			for (j = 1; j<13; j++)
				total_block[k][j] = total_block[k - 1][j];
		}
		for (j = 1; j<13; j++)
			total_block[0][j] = 0;
		show_gamestat();
		preBlock.upperY();
		show_total_block();
		//화면에 표시
	}
	void regiRank()
	{
		ifstream read("Rank.txt");//파일을 읽어온다.
		int row = 0;
		read >> row;//가장 첫번째 숫자를 받아온다.
		char r_name[4];
		s.gotoxy(37, 12);
		cin >> r_name[0] >> r_name[1] >> r_name[2];
		if (row == NULL)//첫번째 숫자가 없음-> 처음실행
		{
			ofstream write("Rank.txt");//파일을 쓰기용으로 연다
			write << 1 << endl;//가장위에 1을 입력
			write << r_name[0] << r_name[1] << r_name[2] << " " << score;
			//나머지 닉네임과 점수 입력
		}
		else //처음 실행이 아니면
		{
			char **nameList = NULL;
			nameList = new char *[row];
			for (int i = 0; i < row; i++)
				nameList[i] = new char[4];
			int *scoreList = NULL;
			scoreList = new int[row];


			//파일에서 이름과 점수를 받을 배열 동적 생성
			for (int i = 0; i < row; i++)
			{
				read >> nameList[i][0] >> nameList[i][1] >> nameList[i][2] >> scoreList[i];
				//동적 생성된 배열에 텍스트 파일의 값을 저장
			}
			read.close();


			bool switc = false;//랭킹을 반복해서 쓰지 않기위한 bool값
			int r_temp = row + 1;

			ofstream write("Rank.txt");//쓰기용으로 불러온다
			write.clear();//전체 지움

			write << r_temp << endl;//맨 위에 row+1을 입력해준다.

			for (int i = 0; i < row; i++)
			{
				if (score > scoreList[i] && switc == false)//스코어 값으로 비교하며 한줄한줄씩 저장
				{
					write << r_name[0] << r_name[1] << r_name[2] << " " << score << endl;
					switc = true;
				}
				write << nameList[i][0] << nameList[i][1] << nameList[i][2] << " " << scoreList[i] << endl;
				if (score < scoreList[i] && i == (row - 1) && switc == false)//혹시 신규 랭킹값이 가장 작을때를 대비
				{
					write << r_name[0] << r_name[1] << r_name[2] << " " << score << endl;
					switc = true;
				}
			}

			write.close();
			//쓰기용 파일 닫기

			//동적배열 삭제
			for (int i = 0; i < row; i++)
				delete[] nameList[i];
			delete[] nameList;
			delete[] scoreList;

		}
	}
	void showRank()
	{

		system("cls");

		ifstream rank("Rank.txt");
		char name[5];
		int scrore;
		int temp;
		int row;
		s.SetColor(s.GRAY);
		s.gotoxy(10, 3);
		cout << "┏━━━━<RANKING >━━━━━┓";
		Sleep(10);
		rank >> temp;
		for (int i = 0; i < 15; i++)
		{
			row = i;
			s.gotoxy(10, i + 4);
			s.SetColor(s.GRAY);
			rank >> name >> score;
			if (name[0] == NULL)//비어있을시 아무것도 표시 안함
			{
				row--;
				break;
			}
			cout << "┃";
			s.SetColor(i + 1);
			cout << i + 1;
			if (i + 1 >= 10)
				cout << ". ";
			else
				cout << ".  ";
			cout << name[0] << name[1] << name[2];//한줄씩 출력
			cout << setw(21) << score;
			s.SetColor(s.GRAY);
			cout << "┃";

		}
		s.gotoxy(10, row + 5);
		cout << "┗━━━━━━━━━━━━━━┛";

		cout << endl << "화면전환하려면 아무키나 누르세요." << endl;
		_getch();
		system("cls");
	}
	void show_logo()
	{
		PlaySound(TEXT("C:\\res\\start.wav"), NULL, SND_FILENAME | SND_ASYNC);
		s.gotoxy(13, 3);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━┓";
		Sleep(100);
		s.gotoxy(13, 4);
		cout << "┃◆◆◆  ◆◆◆  ◆◆◆   ◆◆     ◆   ◆  ◆ ┃";
		Sleep(100);
		s.gotoxy(13, 5);
		cout << "┃  ◆    ◆        ◆     ◆ ◆    ◆    ◆◆  ┃";
		Sleep(100);
		s.gotoxy(13, 6);
		cout << "┃  ◆    ◆◆◆    ◆     ◆◆     ◆     ◆   ┃";
		Sleep(100);
		s.gotoxy(13, 7);
		cout << "┃  ◆    ◆        ◆     ◆ ◆    ◆    ◆◆  ┃";
		Sleep(100);
		s.gotoxy(13, 8);
		cout << "┃  ◆    ◆◆◆    ◆     ◆  ◆   ◆   ◆  ◆ ┃";
		Sleep(100);
		s.gotoxy(13, 9);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━┛";

		s.gotoxy(28, 20);
		cout << "Please Press Any Key~!";

		for (int i = 0; i >= 0; i++)
		{
			if (i % 40 == 0)
			{


				for (int j = 0; j < 5; j++)
				{
					s.gotoxy(18, 14 + j);
					cout << "                                                          ";


				}
				show_cur_block(rand() % 7, rand() % 4, 6, 14);
				show_cur_block(rand() % 7, rand() % 4, 12, 14);
				show_cur_block(rand() % 7, rand() % 4, 19, 14);
				show_cur_block(rand() % 7, rand() % 4, 24, 14);
			}
			if (_kbhit())
				break;
			Sleep(30);
		}
		PlaySound(NULL, 0, 0);
		_getch();
		system("cls");
	}
	void merge_block()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				total_block[preBlock.get_block_y() + i][preBlock.get_block_x() + j] |= SYSTEM::block[preBlock.get_block_shape()][preBlock.get_block_angle()][i][j];
			}
		}
		check_full_line();
		show_total_block();
	}
	void block_start()
	{
		preBlock.init();
	}
	void show_gamestat()
	{
		static int printed_text = 0;
		s.SetColor(s.GRAY);
		if (printed_text == 0)
		{
			s.gotoxy(35, 7);
			cout << "STAGE";

			s.SetColor(s.GRAY);
			s.gotoxy(35, 9);
			cout << "SCORE";

			s.SetColor(s.GRAY);
			s.gotoxy(35, 11);
			cout << "LINES";

			s.SetColor(s.GRAY);
			s.gotoxy(35, 13);
			cout << "TIME";

			s.SetColor(s.VOILET);
			s.gotoxy(34, 16);
			cout << "Z";
			s.SetColor(s.GRAY);
			cout << "-SKILL: ";

			s.SetColor(s.YELLOW);
			s.gotoxy(34, 17);
			cout << "X";
			s.SetColor(s.GRAY);
			cout << "-SKILL: ";

		}
		s.gotoxy(41, 7);
		cout << level + 1;
		s.SetColor(s.WHITE);
		s.gotoxy(35, 10);
		cout << score;
		s.SetColor(s.WHITE);
		s.gotoxy(35, 12);
		if (stage_data[level]->get_clear_line() - lines >= 0)
			cout << setw(2) << setfill(' ') << stage_data[level]->get_clear_line() - lines;
		s.SetColor(s.WHITE);
		s.gotoxy(43, 16);
		cout << z_skill;
		s.SetColor(s.WHITE);
		s.gotoxy(43, 17);
		cout << x_skill;
	}
	void check_full_line()
	{
		int line_count = 0; //한번에 몇개의 줄이 채워졌는지 확인하기 위한 변수 
		int add_score = 0;
		int j;

		for (int i = 0; i < 20; i++)
		{
			for (j = 1; j < 13; j++)
			{
				if (total_block[i][j] == 0)
					break;
			}
			if (j == 13)   //한줄이 다 채워졌음
			{
				line_count++;
				lines += 1;
				show_total_block();
				s.SetColor(s.BLUE);
				s.gotoxy(1 * 2 + ab_x, i + ab_y);
				for (j = 1; j < 13; j++)
				{
					cout << "□";
					Sleep(10);
				}
				s.gotoxy(1 * 2 + ab_x, i + ab_y);
				for (j = 1; j < 13; j++)
				{
					cout << "  ";
					Sleep(10);
				}

				for (int k = i; k > 0; k--)
				{
					for (j = 1; j < 13; j++)
						total_block[k][j] = total_block[k - 1][j];
				}
				for (j = 1; j < 13; j++)
					total_block[0][j] = 0;
				add_score += 100 + (level * 10) + (rand() % 10);
			}
			score += add_score;
			show_gamestat();
		}
		c.erase_interface();
		s.gotoxy(7, 23);

		if (line_count == 1) {
			s.SetColor(s.GREEN);
			cout << "clear a line! +" << add_score;
		}
		else if (line_count > 1) {
			s.SetColor(s.GREEN);
			cout << line_count << " lines combo! ";
			cout << "+" << add_score;
		}
	}
	void show_total_block()
	{
		s.SetColor(s.DARK_GRAY);
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				if (j == 0 || j == 13 || i == 20)      //레벨에 따라 외벽 색이 변함
				{
					s.SetColor((level % 6) + 1);

				}
				else {
					s.SetColor(s.DARK_GRAY);
				}
				s.gotoxy((j * 2) + ab_x, i + ab_y);
				if (total_block[i][j] == 1)
				{
					cout << "■";
				}
				else {
					cout << "  ";
				}

			}
		}
		s.SetColor(s.BLACK);
		s.gotoxy(77, 23);
	}
	void hold_block(HOLD& h) { // 블록을 저장하는 함수
		c.erase_interface();
		s.gotoxy(7, 23);
		s.SetColor(s.GRAY);
		cout << "Hold!";

		int tmp = h.get_hold_block_shape(); //tmp에 홀드되어 있는 블록을 저장
		erase_cur_block(preBlock);
		erase_cur_block(preGhBlock);
		if (h.get_hold_check() == false) { //홀드를 처음 사용했을 경우
			tmp = next_block_shape; // tmp에 다음에 올 블록 저장한다.
			h.set_hold_check(true); //홀드를 사용함
		}

		h.set_hold_block_shape(preBlock.get_block_shape()); //현재 블록을 홀드
		show_hold_block(h.get_hold_block_shape());
		preBlock = BLOCK(tmp); //현재블록을 tmp에 저장되어 있는 블록으로 바꾸기(홀드를 처음할 경우는 다음에 올 블록, 그렇지 않은 경우 홀드되어 있는 블록이 tmp에 저장되어 있음)
		block_start();
		show_next_block(next_block_shape);
		move_block();
	}
	void ghost(int &ghost_over) {
		//미리보기로 보여줄 블록을 현재 블록 값과 같게 만든다.
		preGhBlock.set_block_shape(preBlock.get_block_shape());
		preGhBlock.set_block_angle(preBlock.get_block_angle());
		preGhBlock.set_block_x(preBlock.get_block_x());
		preGhBlock.set_block_y(preBlock.get_block_y());

		//떨어뜨린다
		while (ghost_over == 0) {
			ghost_over = move_Ghblock();
		}

		ghost_over = 0;


		if (check_Gh_overlap()) { //미리보기로 보여주는 블록과 현재블록이 겹칠 때
			show_cur_block(preBlock.get_block_shape(), preBlock.get_block_angle(), preBlock.get_block_x(), preBlock.get_block_y()); // 현재 블록을 보여줌
			return; //반환
		}

		show_cur_Ghblock(preGhBlock.get_block_shape(), preGhBlock.get_block_angle(), preGhBlock.get_block_x(), preGhBlock.get_block_y()); //미리보기 블록을 보여줌

	}
	void show_next_block(int shape)
	{
		s.SetColor((level + 1) % 6 + 1);
		for (int i = 1; i < 7; i++)
		{
			s.gotoxy(33, i);
			for (int j = 0; j < 6; j++)
			{
				if (i == 1 || i == 6 || j == 0 || j == 5)
				{
					cout << "■";
				}
				else {
					cout << "  ";
				}

			}
		}
		show_cur_block(shape, 0, 15, 1);
	}
	void show_hold_block(int shape) {
		s.SetColor((level + 1) % 6 + 2);
		for (int i = 19; i < 25; i++)
		{
			s.gotoxy(33, i);
			for (int j = 0; j < 6; j++)
			{
				if (i == 19 || i == 24 || j == 0 || j == 5)
				{
					cout << "■";
				}
				else {
					cout << "  ";
				}

			}
		}
		if (shape == -1)
			return;
		show_cur_block(shape, 0, 15, 19);
	}

	void erase_hold_block() {
		for (int i = 19; i < 25; i++)
		{
			s.gotoxy(33, i);
			for (int j = 0; j < 6; j++)
			{
				if (i == 19 || i == 24 || j == 0 || j == 5)
				{
					cout << "■";
				}
				else {
					cout << "  ";
				}

			}
		}
	}
	void erase_cur_block(BLOCK& Block)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (SYSTEM::block[Block.get_block_shape()][Block.get_block_angle()][j][i] == 1)
				{
					s.gotoxy((i + Block.get_block_x()) * 2 + ab_x, j + Block.get_block_y() + ab_y);
					cout << "  ";

				}
			}
		}
	}
	void show_cur_block(int shape, int angle, int x, int y)
	{
		switch (shape)
		{
		case 0:
			s.SetColor(s.RED);
			break;
		case 1:
			s.SetColor(s.BLUE);
			break;
		case 2:
			s.SetColor(s.SKY_BLUE);
			break;
		case 3:
			s.SetColor(s.WHITE);
			break;
		case 4:
			s.SetColor(s.YELLOW);
			break;
		case 5:
			s.SetColor(s.VOILET);
			break;
		case 6:
			s.SetColor(s.GREEN);
			break;
		case 7:
			s.SetColor(s.DARK_BLUE);
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if ((j + y) < 0)
					continue;

				if (SYSTEM::block[shape][angle][j][i] == 1)
				{
					s.gotoxy((i + x) * 2 + ab_x, j + y + ab_y);
					cout << "■";

				}
			}
		}
		s.SetColor(s.BLACK);
		s.gotoxy(77, 23);
	}
	void show_cur_Ghblock(int shape, int angle, int x, int y) {
		s.SetColor(s.WHITE);

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if ((j + y) < 0)
					continue;

				if (SYSTEM::block[shape][angle][j][i] == 1)
				{
					s.gotoxy((i + x) * 2 + ab_x, j + y + ab_y);
					cout << "□";

				}
			}
		}
		s.SetColor(s.BLACK);
		s.gotoxy(77, 23);
	}

	bool input_data()
	{
		while (1) {
			system("cls");
			int i = 0;
			s.SetColor(s.GRAY);
			s.gotoxy(22, 3);
			cout << "┏━━━━<GAME KEY>━━━━━┓";
			Sleep(10);
			s.gotoxy(22, 4);
			cout << "┃ UP   : Rotate Block        ┃";
			Sleep(10);
			s.gotoxy(22, 5);
			cout << "┃ DOWN : Move One-Step Down  ┃";
			Sleep(10);
			s.gotoxy(22, 6);
			cout << "┃ SPACE: Move Bottom Down    ┃";
			Sleep(10);
			s.gotoxy(22, 7);
			cout << "┃ LEFT : Move Left           ┃";
			Sleep(10);
			s.gotoxy(22, 8);
			cout << "┃ RIGHT: Move Right          ┃";
			Sleep(10);
			s.gotoxy(22, 9);
			cout << "┃ Z    : Remove Lowest Line  ┃";
			Sleep(10);
			s.gotoxy(22, 10);
			cout << "┃ X    : Decalcomanie        ┃";
			Sleep(10);
			s.gotoxy(22, 11);
			cout << "┃ H    : Hold ( Saving )     ┃";
			Sleep(10);
			s.gotoxy(22, 12);
			cout << "┃ P    : Pause               ┃";
			Sleep(10);
			s.gotoxy(22, 13);
			cout << "┗━━━━━━━━━━━━━━┛";

			s.gotoxy(12, 1);
			s.SetColor(s.YELLOW);
			cout << "★";
			s.SetColor(s.WHITE);
			cout << " Select and Enter Start level[1 - 8]";
			s.SetColor(s.YELLOW);
			cout << "★" << endl;

			mini();
			int pos_y = 4;
			s.gotoxy(6, 4);
			s.SetColor(s.YELLOW);
			cout << "▶";
			s.SetColor(s.WHITE);

			s.gotoxy(11, 4);
			int select;
			int answer = 0;
			while (answer != KEY_ENTER)
			{
				for (int j = 0; j < 12; j++)
				{
					if (j == 9)
					{
						s.gotoxy(11, 4 + 2 * j);
						if (pos_y == 22)
							s.SetColor(s.GREEN);
						cout << "CUSTOMIZE";
						s.SetColor(s.WHITE);
					}
					if (j == 10)
					{
						s.gotoxy(11, 4 + 2 * j);
						if (pos_y == 24)
							s.SetColor(s.SKY_BLUE);
						cout << "RANKING ";
						s.SetColor(s.WHITE);
					}
					if (j == 11)
					{
						s.gotoxy(11, 4 + 2 * j);
						if (pos_y == 26)
							s.SetColor(s.RED);
						cout << "EXIT";
						s.SetColor(s.WHITE);
					}
					else if (j != 10 && j != 9)
					{
						s.gotoxy(11, 4 + 2 * j);
						if (pos_y == 4 + 2 * j)
							s.SetColor(s.YELLOW);
						cout << "LEVEL " << setw(2) << j + 1;
						s.SetColor(s.WHITE);
					}

				}

				select = _getch();
				if (select == KEY_ENTER)
				{
					answer = KEY_ENTER;
				}
				if (select == 224)
				{
					select = _getch();

					PlaySound(NULL, 0, 0); //끄기
					PlaySound(TEXT("C:\\res\\click.wav"), NULL, SND_FILENAME | SND_ASYNC); //켜기

					switch (select)
					{
					case KEY_DOWN:
						s.gotoxy(6, pos_y);
						cout << "  ";
						s.SetColor(s.YELLOW);
						if (pos_y == 26) {
							pos_y = 4;
							s.gotoxy(6, pos_y);
							cout << "▶";
						}
						else {
							pos_y += 2;
							s.gotoxy(6, pos_y);
							cout << "▶ ";
						}
						s.SetColor(s.WHITE);
						break;
					case KEY_UP:
						s.gotoxy(6, pos_y);
						cout << "  ";
						s.SetColor(s.YELLOW);
						if (pos_y == 4) {
							pos_y = 26;
							s.gotoxy(6, pos_y);
							cout << "▶";
						}
						else {
							pos_y -= 2;
							s.gotoxy(6, pos_y);
							cout << "▶";
						}
						s.SetColor(s.WHITE);
						break;
					default:
						break;
					}
				}

			}
			level = (pos_y - 4) / 2;
			if (level >= 0 && level < 9) {
				system("cls");
				return false;
			}
			else if (level == 9) {
				system("cls");
				m.inIt();
			}
			else if (level == 10) {
				system("cls");
				showRank();
			}
			else {
				return true;
			}
		}
	}
	bool show_clear() {
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("C:\\res\\gameclear.wav"), NULL, SND_FILENAME | SND_ASYNC);

		s.SetColor(s.SKY_BLUE);
		s.gotoxy((2 * 2) + ab_x, 5 + ab_y);
		cout << "┌────────┐";
		s.gotoxy((2 * 2) + ab_x, 6 + ab_y);
		cout << "┣━━━━━━━━┫";
		s.gotoxy((2 * 2) + ab_x, 7 + ab_y);
		cout << "│* STAGE CLEAR  *│";
		s.gotoxy((2 * 2) + ab_x, 8 + ab_y);
		cout << "┣━━━━━━━━┫";
		s.gotoxy((2 * 2) + ab_x, 9 + ab_y);
		cout << "│      SCORE     │";
		s.gotoxy((2 * 2) + ab_x, 10 + ab_y);
		cout << "│  (+TimeBonus)  │";
		s.gotoxy((2 * 2) + ab_x, 11 + ab_y);
		cout << "│  " << setw(8) << setfill(' ') << score << "      │";
		s.gotoxy((2 * 2) + ab_x, 12 + ab_y);
		cout << "├────────┤" << endl;
		s.gotoxy((2 * 2) + ab_x, 13 + ab_y);
		cout << "│  NEXT(any key) │";
		s.gotoxy((2 * 2) + ab_x, 14 + ab_y);
		cout << "│    EXIT(ESC)   │";
		s.gotoxy((2 * 2) + ab_x, 15 + ab_y);
		cout << "└────────┘";

		int ans = _getch();

		if (ans == KEY_ESC) {
			show_total_block();
			return false;
		}
		else {
			PlaySound(NULL, 0, 0);
			PlaySound(TEXT("C:\\res\\tetrixBGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			t.set_start(clock());
			return true;
		}
	}
	bool check_Gh_overlap() {

		erase_cur_block(preGhBlock);
		show_cur_Ghblock(preGhBlock.get_block_shape(), preGhBlock.get_block_angle(), preGhBlock.get_block_x(), preGhBlock.get_block_y());

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (preBlock.get_block_y() + j == preGhBlock.get_block_y()) {
					return true;
				}
			}
		}
		return false;

	}

	int start()
	{
		s.CursorView(0);
		bool check = false;
		int is_gameover = 0;
		int ghost_over = 0;
		int input;
		char keytemp;


		bool was_x = false;
		bool doingCheck = false;



		init();
		show_logo();

		while (1)
		{


			if (input_data())
			{
				return 0;
			}



			PlaySound(NULL, 0, 0);
			PlaySound(TEXT("C:\\res\\tetrixBGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

			show_total_block();
			preBlock = BLOCK(make_new_block());
			preGhBlock = BLOCK(preBlock.get_block_shape());
			next_block_shape = make_new_block();
			show_next_block(next_block_shape);
			show_hold_block(h.get_hold_block_shape());
			block_start();
			c.show_interface();
			show_gamestat();

			t.set_start(clock());

			for (int i = 1; 1; i++)
			{
				ghost(ghost_over);

				t.set_end(clock());
				t.set_timer();

				t.show_last_time();

				if (t.time_check())
					is_gameover = 1;

				if (_kbhit())
				{
					keytemp = _getch();
					if (keytemp == EXT_KEY)
					{
						keytemp = _getch();
						switch (keytemp)
						{
						case KEY_UP:      //회전하기


						{
							erase_cur_block(preBlock);
							erase_cur_block(preGhBlock);
							if (preBlock.get_block_shape() == 0 && preBlock.get_block_x() == 10)
							{
								preBlock.lowerX();
								was_x = true;
								doingCheck = true;
							}
							if (preBlock.get_block_x() >= 11)
							{
								if (preBlock.get_block_shape() == 0)
								{
									preBlock.lowerX();
									preBlock.lowerX();
									preBlock.lowerX();
									if (strike_check(preBlock, (preBlock.get_block_angle() + 1) % 4) != 0)
									{
										preBlock.upperX();
										preBlock.upperX();
										preBlock.upperX();
									}
								}
								else
									preBlock.lowerX();

								was_x = true;
								doingCheck = true;
							}
							if (strike_check(preBlock, (preBlock.get_block_angle() + 1) % 4) == 0)
							{
								preBlock.upperAngle();
								if (was_x == true && doingCheck == false)
								{
									if (preBlock.get_block_shape() == 0)
									{
										preBlock.upperX();
										preBlock.upperX();
										preBlock.upperX();
									}
									else
										preBlock.upperX();
									was_x = false;
								}
								if (was_x == true && doingCheck == false)
								{
									preBlock.upperX();
									was_x = false;
								}
							}

							show_cur_block(preBlock.get_block_shape(), preBlock.get_block_angle(), preBlock.get_block_x(), preBlock.get_block_y());

							ghost(ghost_over);
							doingCheck = false;

						}
						break;
						case KEY_LEFT:      //왼쪽으로 이동
							if (preBlock.get_block_x() > 1)
							{
								erase_cur_block(preBlock);
								erase_cur_block(preGhBlock);

								preBlock.lowerX();
								if (strike_check(preBlock, preBlock.get_block_angle()) == 1)
									preBlock.upperX();

								show_cur_block(preBlock.get_block_shape(), preBlock.get_block_angle(), preBlock.get_block_x(), preBlock.get_block_y());

								ghost(ghost_over);
							}
							break;
						case KEY_RIGHT:      //오른쪽으로 이동

							if (preBlock.get_block_x() < 14)
							{
								erase_cur_block(preBlock);
								erase_cur_block(preGhBlock);

								preBlock.upperX();
								if (strike_check(preBlock, preBlock.get_block_angle()) == 1)
									preBlock.lowerX();

								show_cur_block(preBlock.get_block_shape(), preBlock.get_block_angle(), preBlock.get_block_x(), preBlock.get_block_y());

								ghost(ghost_over);
							}
							break;
						case KEY_DOWN:      //아래로 이동
							is_gameover = move_block();
							show_cur_block(preBlock.get_block_shape(), preBlock.get_block_angle(), preBlock.get_block_x(), preBlock.get_block_y());

							break;
						}
					}

					if (keytemp == KEY_SPACEBAR)   //스페이스바를 눌렀을때
					{
						while (is_gameover == 0)
						{
							is_gameover = move_block();
						}
						show_cur_block(preBlock.get_block_shape(), preBlock.get_block_angle(), preBlock.get_block_x(), preBlock.get_block_y());
					};

					if (keytemp == KEY_PAUSE) { //p를 입력받을 경우
						s.SetColor(s.GRAY);
						c.show_pause(); //pause 화면 보여줌
						t.set_start(clock()); //일시정지가 풀리면 start시간을 다시 받는다.
						show_total_block();
					}

					if (keytemp == KEY_HOLD) {
						if (h.get_hold_index() == index) {//홀드키를 연속으로 누를 경우 홀드x
							c.erase_interface();
							s.gotoxy(7, 23);
							s.SetColor(s.GRAY);
							cout << "You can't hold!";
							continue;
						}
						hold_block(h);
						h.set_hold_index(index);
					}
					if (keytemp == 120)
					{
						if (x_skill > 0)
						{
							skill_x();
						}
					}
					if (keytemp == 122)
					{
						if (z_skill > 0)
						{
							skill_z();
							show_cur_block(preBlock.get_block_shape(), preBlock.get_block_angle(), preBlock.get_block_x(), preBlock.get_block_y());
						}
					}
					if (keytemp == KEY_ESC) {
						is_gameover = 1;
					}
				}

				if (i%stage_data[level]->get_speed() == 0)
				{
					is_gameover = move_block();
					show_cur_block(preBlock.get_block_shape(), preBlock.get_block_angle(), preBlock.get_block_x(), preBlock.get_block_y());
				}

				if ((stage_data[level]->get_clear_line() <= lines)&&(preBlock.get_block_y() > -2))   //클리어 스테이지
				{
					score += t.get_last_time() * 5;
					if (show_clear()) {
						level++;
						lines = 0;
						init2();
						show_total_block();
						show_gamestat();
						erase_hold_block();
					}
					else
						is_gameover = 1;
				}

				if (is_gameover == 1)
				{
					//PlaySound함수를 이용한 음악 재생,정지
					PlaySound(NULL, 0, 0); //끄기
					PlaySound(TEXT("C:\\res\\gameover1.wav"), NULL, SND_FILENAME | SND_ASYNC); //켜기


					if (c.show_gameover(score)) {
						c.show_register();
						regiRank();
						break;
					}
					else
						break;
					fflush(stdin);
					Sleep(1000);
					system("cls");
					s.SetColor(s.GRAY);
					break;
				}

				s.gotoxy(77, 23);
				Sleep(15);
				s.gotoxy(77, 23);
			}
			init();
			is_gameover = 0;
			ghost_over = 0;

		}
	}
};

void main(int argc, char* argv[])
{
	GAME tetrix;
	tetrix.start();
}