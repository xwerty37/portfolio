#include"funtion.cpp"
int main() {
	Main_Display();
	Help_Display();
	int size,i,j,n,player=6,chr=0,rx,r1,r2,r3,cnt,point[4]={0,0,0,0},score[4]={0,0,0,0},p_x[4],p_y[4];
	char map[100][100]={}; // �� �迭 ���� 
	player=Choose_Number(player,chr);
	size=player*5+20;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++) {
			map[i][j]=Check_Map(size,i,j); // �� �迭 Ȯ���ϱ�   
		}	
	}
	p_x[0]=p_y[0]=p_x[2]=p_y[3]=1;// �� �÷��̾� ��ǥ �迭 ����, �ʱⰪ �Է� 
	p_x[1]=p_x[3]=size*2-5;
	p_y[1]=p_y[2]=size-2;
	srand(time(NULL));
	for(i=2;i<size-2;i++){
		r1=rand()%(size-2);
		for(j=2;j<size-2;j++)
			map[i][r1]=7; 
	}
	for(n=0;n<player;) { // �����̼� ����
		system("cls");
		cnt=0;
		srand(time(NULL));
		r1=rand()%(size-1);
		r2=rand()%(size-1);
		r3=rand()%(100);
		
		if(r1>1&r2>1&r3>0&r3<50)
			map[r1][r2]=2;
		else if(r1>1&r2>1&r3>=100/player&r3<100/player+30)
			map[r1][r2]=6;
			
		for(i=0;i<size;i++) {
			for(j=0;j<size;j++)
				Create_Map(map[i][j],size); // �� �迭 ��� 
			puts("");
		}
		gotoxy(p_x[n],p_y[n]); // Ŀ�� ��ǥ ���� 
		for(i=0;i<player;i++)
			States_Display(point[i],score[i],i,size,player,n,cnt);
		while(chr!=13) { // �Է� ������ enter�� �ƴ� ��� ���� �ݺ� 
	  		chr=getch(); // �Է� ������ Ű���� �� �Է�  
	  		rx=p_x[n]/2+1; // ȭ�鿡 ǥ�õ� ���� ��ǥ rx�� p_x[�÷��̾� ��ȣ]�� ��ȯ ���� ����
			   
			if(chr==0|chr==0xe0&cnt<player+10) { // �Է� ���� Ű���� ���� ������ �����ϴ��� ��  
				gotoxy(p_x[n],p_y[n]); // ���� Ŀ�� ��ǥ ����  
				map[p_y[n]][rx]=n==1?1:n==2?3:n==3?5:4; //�÷��̾��� ���並 �����Ͽ� �ʿ� ���� 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),map[p_y[n]][rx]);//���� ���� ���� 
				printf("��");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//�� ���� ���� 
				
				chr=getch(); //Ű���� ���� �Է� �޾� �÷��̾� �̵� 
				if(chr==75&map[p_y[n]][rx-1]!=7&map[p_y[n]][rx-1]!=15)
					p_x[n]-=2;
				else if(chr==77&map[p_y[n]][rx+1]!=7&map[p_y[n]][rx+1]!=15)
					p_x[n]+=2;
				else if(chr==72&map[p_y[n]-1][rx]!=7&map[p_y[n]-1][rx]!=15)
					p_y[n]--;
				else if(chr==80&map[p_y[n]+1][rx]!=7&map[p_y[n]+1][rx]!=15)
					p_y[n]++;
				rx=p_x[n]/2+1;
				
		   		if(map[p_y[n]][rx]==0) { //�÷��̾��� ��ġ�� ���� ���� ��ȭ 
				   	point[n]++;
			   		score[n]+=10;
			   		cnt++;
				} else if(map[p_y[n]][rx]==1&n!=1) {
					point[1]--;
				   	score[1]-=10;
				   	point[n]++;
			   		score[n]+=10;
			   		cnt++;
				} else if(map[p_y[n]][rx]==2) {
					score[n]+=100;
					Score_Plus(100,size,n);
					point[n]++;
			   		score[n]+=10;
		   			Sleep(500);
		   			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		   			Printf_Player(p_x[n],p_y[n],size);
					cnt++;
				} else if(map[p_y[n]][rx]==3&n!=2) {
					point[2]--;
					score[2]-=10;
					point[n]++;
			   		score[n]+=10;
			   		cnt++;
				} else if(map[p_y[n]][rx]==4&n!=0) {
					point[0]--;
			   		score[0]-=10;
					point[n]++;
			   		score[n]+=10;
			   		cnt++;			
				} else if(map[p_y[n]][rx]==5&n!=3) {
					point[3]--;
					score[3]-=10;
					point[n]++;
			   		score[n]+=10;
			   		cnt++;
				} else if(map[p_y[n]][rx]==6) {
		   			gotoxy(30,size+player+2);
		   			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
		   			printf("+5��");
		   			cnt-=4;
		   			point[n]++;
			   		score[n]+=10;
					Sleep(500);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					Printf_Player(p_x[n],p_y[n],size);
				}
				Printf_Player(p_x[n],p_y[n],size);//�÷��̾� ����ϱ� 
				for(i=0;i<player;i++)
					States_Display(point[i],score[i],i,size,player,n,cnt);
				gotoxy(40,size+n+1);
				printf("        ");	
				gotoxy(30,size+player+2);
				printf("        ");
		   		if(score[n]>=player*400) {
		   			Game_End(n,i); 
		   			Sleep(2000);
		   			return 0;
				} 	
	  		}
 		}
 		system("cls");
		map[p_y[n]][rx]=15;
 		for(i=0;i<size;i++) {
			for(j=0;j<size;j++)
				Create_Map(map[i][j],size); // �� �迭 ��� �Լ� 
			puts("");
		}
		gotoxy(0,size+4);
		puts("����Ϸ��� �ƹ�Ű�� �Է�");
		chr=getch();
		chr=0; 
		n++;
		if(n==player)
			n=0;
	}
}
int Choose_Number(int player,int chr) {
	gotoxy(0,2);
	puts("<�÷��̾��� ���ڸ� ���Ű�� �������ּ���>");
	gotoxy(0,6);
	puts("[2�ο�] ");
	gotoxy(0,8);
	puts("[3�ο�] ");
	gotoxy(0,10);
	puts("[4�ο�] ");
	gotoxy(8,6);
	printf("*");
	while(chr!=13){
		chr=getch();
		gotoxy(8,player);
		printf(" ");
		player+=chr==80?2:chr==72?-2:0;
		player=player<6?10:player>10?6:player;
		gotoxy(8,player);
		printf("*");
	}
	if(player>6) {
		system("mode con cols=150 lines=60");
	}
	return player/2-1;
}
int Check_Map(int size,int i,int j) {
	if(i==0|j==0|i==size-1|j==size-1)
		return 7;
	else
		return 0;
}
void gotoxy(int x,int y) {
	COORD Pos={x+1,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}
void Create_Map(int object,int size) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),object);
	printf(object==1|object==3|object==4|object==5?"��":object==2|object==6?"��":object==15?"��":object==7?"��":"  ");
}
void Printf_Player(int x,int y,int size) {
	gotoxy(x,y);
	printf("��");
}
void States_Display(int point,int score,int i,int size,int player,int n,int cnt) {
	gotoxy(0,size+i+1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i==1?1:i==2?3:i==3?5:4);
	printf("%d�� �÷��̾� / ����:%d�� / ����:%d��     ",i+1,point,score);
	gotoxy(48,size+n+1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	printf("*");
	gotoxy(0,size+player+2);
	printf("���� �̵� Ƚ��: %d��    ",player-cnt+10);
	if(cnt==player+10) {
		gotoxy(0,size+player+2);
		printf("EnterŰ�� ���� �� ����      ");
	}
}
void Score_Plus(int score,int size,int n) {
	gotoxy(40,size+n+1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	printf("+%d��",score);
}
void Game_End(int n,int i) {
	system("cls");
	gotoxy(20,20);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),n==1?1:n==2?3:n==3?5:4);
	printf("%d�� �÷��̾� win!",n+1);
	gotoxy(20,30);
	printf("�����Ϸ��� Enter...");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
