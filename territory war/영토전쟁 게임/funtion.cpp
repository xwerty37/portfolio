#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int Choose_Number(int player,int chr); //�ο��� ���� �Լ� 
int Check_Map(int size,int i,int j); //�� üũ �Լ�
void gotoxy(int x,int y); //Ŀ�� ��ǥ �Լ�
void Create_Map(int object,int size); // �� ���� �Լ�
void Printf_Player(int x,int y,int size); // �÷��̾� ��� �Լ� 
void Game_End(int n,int i); //���� ���� �Լ� 
void Score_Plus(int score,int size,int n); // ���� �߰� �Լ� 
void States_Display(int point,int score,int i,int size,int player,int n,int cnt);//����â �Լ� 
void Main_Display() { //���� ���÷��� �Լ� 
	system("title Territory War"); // ȭ�� �ʱⰪ ���� 
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
void Help_Display() {//���� �Լ� 
	int input=15,chr,a;
	system("mode con cols=100 lines=50");   
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	puts("           ������������������������������������������������������������������������������������ ");
	for(a=0;a<35;a++)
	puts("           ��                                        �� ");
	printf("           ������������������������������������������������������������������������������������ ");
	gotoxy(23,5);
	puts("<Territory War>");
	gotoxy(25,7);
	puts("-���� ����-"); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	gotoxy(25,15);
	puts("[���� ����] *");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	gotoxy(25,20);
	puts("[����]");
	
	while(chr!=13){
		chr=getch();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		input+=chr==80?5:chr==72?-5:0;
		input=input<15?20:input>20?15:input;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
		gotoxy(25,input);
		puts("              ");
		gotoxy(25,input);
		puts(input==15?"[���� ����] *":"[����]  *");
		gotoxy(25,35-input);
		puts("              ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		gotoxy(25,35-input);
		puts(input==20?"[���� ����]  ":"[����]  ");
		
	}     
	system("cls");
	if(input==20) {
		gotoxy(0,4);
		puts("�¸� ����: �÷��̾ ������ ������ �����ϰ� ���溸�� ���� ������ �����ϼ���!");
		gotoxy(0,6);
		puts("������ ���۵Ǹ� ������ �ο����� ���� ���� ũ�Ⱑ �����˴ϴ�.");
		gotoxy(0,8);
		puts("�������� �����Ǵ� ��ֹ��� ������, �ϸ��� �־����� �̵�Ƚ���� ȿ�������� ����ϼ���.");
		gotoxy(-1,13);
		puts("���������������������������������������������������������������������������������������������������������������������������������������� ");
		for(a=0;a<9;a++)
		puts("��                   ��                                              �� ");
	  	printf("���������������������������������������������������������������������������������������������������������������������������������������� ");
		gotoxy(6,15);
		puts("<����Ű>");
		gotoxy(8,17);
		puts("���");
		gotoxy(2,19);
		puts("�¡�");
		gotoxy(8,19);
		puts("�ϡ�");
		gotoxy(14,19);
		puts("���");
		gotoxy(22,15);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		puts("�÷��̾�:��");
		gotoxy(22,17);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		puts("��:��");
		gotoxy(22,19);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
		puts("���ھ� ������:��");
		gotoxy(22,21);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
		puts("ȸ�� �߰� ������:��");
		gotoxy(42,15);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		puts("1�� �÷��̾� ����:��");
		gotoxy(42,17);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
		puts("2�� �÷��̾� ����:��");
		gotoxy(42,19);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
		puts("3�� �÷��̾� ����:��");
		gotoxy(42,21);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		puts("4�� �÷��̾� ����:��");
		gotoxy(0,25);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		puts("�����Ϸ��� Enter...");
		while(1){
			chr=getch();
			if(chr==13) {
				system("cls");
				break;
			}
		}
	}
}
