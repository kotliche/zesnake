#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define PINK "\033[1;35m"
#define messa
int block[11][11]= {{0,0,0,0,0,0,0,0,0,0,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,3,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,0,0,0,0,0,0,0,0,0,0}};
int appl_i=5, appl_j=5;//��६���� ��� ���� ��������� ������
int moved ,im=5,jm=5;//��६���� ��� �������� ������
int max_body=3;//����� ������
int game=1;//�த������� ��� ����� ����
int scored=-100;//��६����� ��� �⮡ࠦ���� �窮� ��ப�
int deistvie_menu;//����� �㭪� ����, ��ப ��ࠫ

//�-�� �������� ����
void menu_print();
//�-�� �窮� ��ப�
void score();
//�-�� lose
void game_over();
//�-�� 㤫������ ������ �� �������� ���
void bodyapp();
//�-�� 㤫������ ������ �� �������� ������
void bodys();
//������� ����� ���ᨢ� ���
void apple();
//�-�� ��।������� ��� �� ���� (�� ������� ��譥��)
void apple_move();
//�-�� ���� ����
void print_pole();
//�-�� �������� ������
void move();

// ���
void main()
{
    srand(time(NULL));
    int game_continue=1;
    int menu_id=1;
    printf("\n");
    while(menu_id==1)
    {
        menu_print();
        game_continue=deistvie_menu;
        menu_id=game_continue;
        while(game_continue==1)
        {
            print_pole();
            while(game==1) move();
            game_continue=game;
            printf("������ '1', �⮡� ����� ����� ����. �᫨ ��� ������ ����, ������ '0' == ");
            scanf("%i",&game_continue);
            printf("\n");
            if(game_continue==1) game=1;
            if(game_continue==0) {game=1;menu_id=1;}
        }
    }
}
void menu_print()
{
    int model;
    int dvizh=1;
    int meny=0;
    system("cls");
    printf("������ 'W' ��� 'S'\n");
    while(dvizh==1)
    {
        model=getche();
        if(model>0) system("cls");
        printf("\t\t�������� ����\n\n");
        printf("�롥�� ०�� �� ���, �᫨ ���ࠢ����� ������ 'E'\n###########\n");
        //niz
        if(model==115 || model==235 )
        {
            meny++;
            if(meny>4) meny--;
            if(meny==1) printf("%s����� ��襫쭨��%s\n", RED, RESET);
                else printf("����� ��襫쭨��\n");
            if(meny==2) printf("%s����� �प�୮�� ��襫쭨�� � ����७��� �������� �६���(��� ���)%s\n", RED, RESET);
                else printf("����� �प�୮�� ��襫쭨�� � ����७��� �������� �६���(��� ���)\n");
            if(meny==3) printf("%s����� ��襫쭨��, �� �冷� ��������(��� ���)%s\n", RED, RESET);
                else printf("����� ��襫쭨��, �� �冷� ��������(��� ���)\n");
            if(meny==4) printf("%s�������� ����%s\n", RED, RESET);
                else printf("�������� ����\n");
        }
        //verx
        if(model==119 || model==230)
        {
            meny--;
            if(meny<1) meny=1;
            if(meny==1) printf("%s����� ��襫쭨��%s\n", RED, RESET);
                else printf("����� ��襫쭨��\n");
            if(meny==2) printf("%s����� �प�୮�� ��襫쭨�� � ����७��� �������� �६���(��� ���)%s\n", RED, RESET);
                else printf("����� �प�୮�� ��襫쭨�� � ����७��� �������� �६���(��� ���)\n");
            if(meny==3) printf("%s����� ��襫쭨��, �� �冷� ��������(��� ���)%s\n", RED, RESET);
                else printf("����� ��襫쭨��, �� �冷� ��������(��� ���)\n");
            if(meny==4) printf("%s�������� ����%s\n", RED, RESET);
                else printf("�������� ����\n");
        }
        // e ��� �
        if(model==101 || model==227)
        {
            if(meny==1) dvizh=0;
            if(meny==4)
            {
                dvizh=0;
                game=0;
            }
        }
    }
    deistvie_menu=meny;
}
void score()
{
    scored+=100;
}
void game_over()
{
    //��६���� ��ࠢ������ � ����砫쭮�� ���ﭨ�
    game=0;
    for(int i=0;i<5;i++)
        printf("\n");
    printf("\t\t    GAME OVER\n  ");
    printf("\t\ttotal score: %i\n", scored);
    appl_i=5, appl_j=5;
    im=5,jm=5;
    max_body=3;
    scored=-100;
    for(int i=1;i<10;i++)
        for(int j=1;j<10;j++)
            block[i][j]=1;
    block[im][jm]=3;
}

void bodyapp()
{
    int dlina=4, exit_b=0;
    int imi=12, jmi=12;
    //㢥��稢�� ⥫� ������ �� �������� ���
    max_body=max_body+1;
    while(dlina<=max_body)
    {
        for(int i=1;i<10;i++)
        {
            for(int j=1;j<10;j++)
            {
                //�. ���ᨢ� � ���� ���祭��� �� ������ ᮢ����� � �뭨譨�
                if(i==imi && j==jmi) continue;
                if(block[i][j]==(dlina-1))
                {
                    block[i][j]=dlina;
                    imi=i;
                    jmi=j;
                    exit_b=1;
                    break;
                }
            }
            if(exit_b==1) break;
        }
        dlina++;
        exit_b=0;
    }
}

void bodys()
{
    int dlina=4;
    int exit_b=0;//��室 �� 横��� for() �� ��宦����� �㦭��� �.
    if(max_body>3)
    while(dlina<=max_body)
    {
        for (int i = 1; i < 10;i++)
        {
            for (int j = 1; j < 10;j++)
            {
                // �����塞 �� +1 �� ��砫쭮�� �. ���ᨢ�
                // � ���ᨬ���� �. ���ᨢ� (����� ⥫� ������) =1
                if(block[i][j]==dlina)
                {
                    if(j+1<10)
                        if(block[i][j+1]==dlina-1) {block[i][j+1]=dlina; if(dlina==max_body)block[i][j]=1; exit_b=1; break;}
                    if(j-1>0)
                        if(block[i][j-1]==dlina-1) {block[i][j-1]=dlina; if(dlina==max_body)block[i][j]=1; exit_b=1; break;}
                    if(i+1<10)
                        if(block[i+1][j]==dlina-1) {block[i+1][j]=dlina; if(dlina==max_body)block[i][j]=1; exit_b=1; break;}
                    if(i-1>0)
                        if(block[i-1][j]==dlina-1) {block[i-1][j]=dlina; if(dlina==max_body)block[i][j]=1; exit_b=1; break;}
                }
            }
            if(exit_b==1)break;
        }
        dlina++;
        exit_b=0;
    }
    else block[im][jm]=1;
}

void apple()
{
    //appl �� 1 �� 9 �����⥫쭮
    appl_i=1+rand()%9;
    appl_j=1+rand()%9;
}

void apple_move()
{
    //�⮡ �� �뫮 ᮢ������� ��� � �������
    while(im==appl_i && jm==appl_j)
    {
        apple();
        //�⮡ �� �뫮 ᮢ������� ��� � ⥫�� ������
        while(block[appl_i][appl_j]>3) apple();
    }
    block[appl_i][appl_j]=2;
}

void print_pole()
{
    system("cls");
    if(im==appl_i && jm==appl_j) score();
    printf("PP 1-�� ��ப�: %i\n", scored);
    apple_move();
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if(block[i][j]==0) printf("��");
            if(block[i][j]==1) printf("[]");
            if(block[i][j]==2) printf("%s��%s",RED, RESET);
            if(block[i][j]==3) printf("%s��%s",GREEN, RESET);
            if(block[i][j]>3 && block[i][j]%2==0) printf("%s��%s",BLUE, RESET);
            if(block[i][j]>3 && block[i][j]%2!=0) printf("%s��%s",PINK, RESET);
        }
        printf("\n");
    }
}

void move()
{
    moved = getche();
    //verh(w,�)
    if(moved==119 || moved==230)
    {
        if(block[im-1][jm]==0 || block[im-1][jm]>4) game_over();
        else if(block[im-1][jm]==4) print_pole();
        else
        {
            if(block[im-1][jm]==2)
            {
                bodyapp();
            } else bodys();
            im--;
            block[im][jm]=3;
            print_pole();
        }
    }
    //niz(s,�)
    if(moved==115 || moved==235)
    {
        if(block[im+1][jm]==0 || block[im+1][jm]>4) game_over();
        else if(block[im+1][jm]==4) print_pole();
        else
        {
            if(block[im+1][jm]==2)
            {
                bodyapp();
            } else bodys();
            im++;
            block[im][jm]=3;
            print_pole();
        }
    }
    //leva(a,�)
    if(moved==97 || moved==228)
    {
        if(block[im][jm-1]==0 || block[im][jm-1]>4) game_over();
        else if(block[im][jm-1]==4) print_pole();
        else
        {
            if(block[im][jm-1]==2)
            {
                bodyapp();
            } else bodys();
            jm--;
            block[im][jm]=3;
            print_pole();
        }
    }
    //pravo(d,�)
    if(moved==100 || moved==162)
    {
        if(block[im][jm+1]==0 || block[im][jm+1]>4) game_over();
        else if(block[im][jm+1]==4) print_pole();
        else
        {
            if(block[im][jm+1]==2)
            {
                bodyapp();
            } else bodys();
            jm++;
            block[im][jm]=3;
            print_pole();
        }
    }
}