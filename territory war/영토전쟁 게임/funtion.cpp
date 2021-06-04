#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int Choose_Number(int player,int chr); //인원수 선택 함수 
int Check_Map(int size,int i,int j); //맵 체크 함수
void gotoxy(int x,int y); //커서 좌표 함수
void Create_Map(int object,int size); // 맵 생성 함수
void Printf_Player(int x,int y,int size); // 플레이어 출력 함수 
void Game_End(int n,int i); //게임 종료 함수 
void Score_Plus(int score,int size,int n); // 점수 추가 함수 
void States_Display(int point,int score,int i,int size,int player,int n,int cnt);//상태창 함수 
void Main_Display() { //메인 디스플레이 함수 
	system("title Territory War"); // 화면 초기값 지정 
	system("mode con cols=180 lines=50");
	int input,T=50,chr;                      
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	gotoxy(0,10);
    puts("                              7417777777777");
	Sleep(T);                                                                                                                                                                                                                                       
    puts("                             98080808888808880                                        788       47");   
	Sleep(T);                                                                                                                                                                            
    puts("                                   708                                                         188"); 
	Sleep(T);                                                                                                                                                                              
    puts("                                    80                                                         780  7");      
	Sleep(T);                                                                                                                                                                      
    puts("                                    08          78880808     88 580808   88 7808089   289   8808880888    7808080     08 7088807 80        80"); 
	Sleep(T);                                                                                                                                   
    puts("                                    807        9887   708    08087  801  080867 788   880      780       8807  588    80805  986 080      800");  
	Sleep(T);                                                                                                                                  
    puts("                                    087       784    1884    887    58   808     86   881       08      980     485   885    787  088    808");   
	Sleep(T);                                                                                                                                  
    puts("                                    881       887780887      08          88           887       80      80      708   80           888  588");   
	Sleep(T);                                                                                                                                   
    puts("                                    881       08807          88          807          087       08      88      789   88            081 08");   
	Sleep(T);                                                                                                                                    
    puts("                                    800       606       507  08          887          881       80      008     80    80             88887");  
	Sleep(T);                                                                                                                                     
    puts("                                    088        40808888808   80          807          882       08       008880807    08              085");    
	Sleep(T);                                                                                                                                    
    puts("                                     7           7488057     05          18            7        64         18067      60             180");       
	Sleep(T);                                                                                                                                  
    puts("                                                                                                                                    788");    
	Sleep(T);                                                                                                                                      
    puts("                                                                                                                                    807");      
	Sleep(T);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    puts("                                                            807        71         807");     
	Sleep(T);                                                                                                                                                                                       
    puts("                                                            988       7808       508");        
	Sleep(T);                                                                                                                                                                                     
    puts("                                                             084      8080       087");        
	Sleep(T);                                                                                                                                                                                     
    puts("                                                             708     60808      180         7       55    777");      
	Sleep(T);                                                                                                                                                               
    puts("                                                              885    08 107     88      188880887   807080808");  
	Sleep(T);                                                                                                                                                                  
    puts("                                                              788   080 788    801     8087   087  70808   887");
	Sleep(T);                                                                                                                                                                
    puts("                                                               087  807  08   788     801     80   788     18");  
	Sleep(T);                                                                                                                                                                  
    puts("                                                               189 809   807  08     708      08   708");     
	Sleep(T);                                                                                                                                                                      
    puts("                                                                80608    780 087     788      80   780");   
	Sleep(T);                                                                                                                                                                        
    puts("                                                                0808      08985       887     087  788");  
	Sleep(T);                                                                                                                                                                         
    puts("                                                                7080      8080        78808080888  780"); 
	Sleep(T);                                                                                                                                                                          
    puts("                                                                 77        64            7227  70   17");
	Sleep(T);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
	gotoxy(0,50);
	while(chr!=13) {
		printf("\n\n\n\n                                                                         [Press Enter to play]");
		Sleep(1000);
		chr=getch();
	}
} 
void Help_Display() {//도움말 함수 
	int input=15,chr,a;
	system("mode con cols=100 lines=50");   
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	puts("           ┌────────────────────────────────────────┐ ");
	for(a=0;a<35;a++)
	puts("           │                                        │ ");
	printf("           └────────────────────────────────────────┘ ");
	gotoxy(23,5);
	puts("<Territory War>");
	gotoxy(25,7);
	puts("-영토 전쟁-"); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	gotoxy(25,15);
	puts("[게임 시작] *");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	gotoxy(25,20);
	puts("[도움말]");
	
	while(chr!=13){
		chr=getch();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		input+=chr==80?5:chr==72?-5:0;
		input=input<15?20:input>20?15:input;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
		gotoxy(25,input);
		puts("              ");
		gotoxy(25,input);
		puts(input==15?"[게임 시작] *":"[도움말]  *");
		gotoxy(25,35-input);
		puts("              ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		gotoxy(25,35-input);
		puts(input==20?"[게임 시작]  ":"[도움말]  ");
		
	}     
	system("cls");
	if(input==20) {
		gotoxy(0,4);
		puts("승리 조건: 플레이어를 움직여 영역을 차지하고 상대방보다 일정 점수에 도달하세요!");
		gotoxy(0,6);
		puts("게임이 시작되면 선택한 인원수에 따라 맵의 크기가 결정됩니다.");
		gotoxy(0,8);
		puts("랜덤으로 생성되는 장애물과 아이템, 턴마다 주어지는 이동횟수를 효율적으로 사용하세요.");
		gotoxy(-1,13);
		puts("┌───────────────────┬──────────────────────────────────────────────┐ ");
		for(a=0;a<9;a++)
		puts("│                   │                                              │ ");
	  	printf("└───────────────────┴──────────────────────────────────────────────┘ ");
		gotoxy(6,15);
		puts("<방향키>");
		gotoxy(8,17);
		puts("상↑");
		gotoxy(2,19);
		puts("좌←");
		gotoxy(8,19);
		puts("하↓");
		gotoxy(14,19);
		puts("우→");
		gotoxy(22,15);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		puts("플레이어:▣");
		gotoxy(22,17);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		puts("맵:□");
		gotoxy(22,19);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
		puts("스코어 아이템:◈");
		gotoxy(22,21);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
		puts("회수 추가 아이템:◈");
		gotoxy(42,15);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		puts("1번 플레이어 영토:▧");
		gotoxy(42,17);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
		puts("2번 플레이어 영토:▧");
		gotoxy(42,19);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		puts("3번 플레이어 영토:▧");
		gotoxy(42,21);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		puts("4번 플레이어 영토:▧");
		gotoxy(0,25);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		puts("시작하려면 Enter...");
		while(1){
			chr=getch();
			if(chr==13) {
				system("cls");
				break;
			}
		}
	}
}
