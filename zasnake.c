#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define PINK "\033[1;35m"
int block[11][11] = {{0,0,0,0,0,0,0,0,0,0,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,3,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,1,1,1,0},
                    {0,0,0,0,0,0,0,0,0,0,0}};//���ᨢ ���� � ��祣� ��� ��ப�
int appl_i=5, appl_j=5;//��६���� ��� ���� ��������� ���
int moved ,im=5,jm=5;//��६���� ��� �������� ������
int max_body=3;//����� ������
int game=1;//�த������� ��� ����� ����
int scored=-100;//��६����� ��� �⮡ࠦ���� �窮� ��ப�
int deistvie_menu;//����� �㭪� ����, ��ப ��ࠫ

int bot_body[11][11] = {{0,0,0,0,0,0,0,0,0,0,0},
                        {0,1,1,1,1,1,1,1,1,1,0},
                        {0,1,1,1,1,1,1,1,1,1,0},
                        {0,1,1,1,1,1,1,1,1,1,0},
                        {0,1,1,1,1,1,1,1,1,1,0},
                        {0,1,1,1,1,3,1,1,1,1,0},
                        {0,1,1,1,1,1,1,1,1,1,0},
                        {0,1,1,1,1,1,1,1,1,1,0},
                        {0,1,1,1,1,1,1,1,1,1,0},
                        {0,1,1,1,1,1,1,1,1,1,0},
                        {0,0,0,0,0,0,0,0,0,0,0}};//���ᨢ ���� � ��祣� ��� ���
int appl_i_bot=5, appl_j_bot=5;//��६���� ��� ���� ��������� ���(bot)
int im_bot=5,jm_bot=5;//��६���� ��� �������� ������(bot)
int max_body_bot=3;//����� ������(bot)
int scored_bot=-100;//�窨 ���
int chast_bot, pozi_bot;//���� ���ࠢ����� �� ���饬 ����. � ����樨 ������ �㤥� �ਭ����� ������

// ################################################ ��� ####################################
// �-�� ���� ���� (bot)
void game_over_bot()
{
    //��६���� �ਢ���� � ����砫쭮�� ���ﭨ�
    system("cls");
    game=0;
    for(int i=0;i<5;i++)
        printf("\n");
    printf("\t\t    GAME OVER\n  ");
    if(deistvie_menu==2)printf("\t\t  ��� ���ঠ� lose (�१����)\n");
    printf("\t\ttotal score ������: %i\n", scored);
    printf("\t\ttotal score ����: %i\n", scored_bot);
    appl_i=5, appl_j=5;
    im=5,jm=5;
    max_body=3;
    scored=-100;
    appl_i_bot=5, appl_j_bot=5;
    im_bot=5,jm_bot=5;
    max_body_bot=3;
    scored_bot=-100;
    for(int i=1;i<10;i++)
        for(int j=1;j<10;j++)
        {
            block[i][j]=1;
            bot_body[i][j]=1;
        }
    block[im][jm]=3;
    bot_body[im_bot][jm_bot]=3;
}
//�-�� ������ ���, ��砩�� � ���� 
void apple_bot();
//�-�� ����୮�� �맮�� apple_bot(); �� ᮢ������� ��� � ⥫�� ��� ������� ������ 
void apple_move_bot();
//�-�� ���� ����
void print_bot();

//�-�� 㤫������ ������ �� �������� ��� 
void bodyapp_bot()
{
    int dlina=4, exit_b=0;//��室 �� 横��� for() �� ��宦����� �㦭��� �.
    int imi=12, jmi=12;
    //㢥��稢��� ���. ����� ������ �� �������� ���
    max_body_bot=max_body_bot+1;
    while(dlina<=max_body_bot)
    {
        for(int i=1;i<10;i++)
        {
            for(int j=1;j<10;j++)
            {
                //�. ���ᨢ� � ���� ���祭��� �� ������ ᮢ����� � �뭨譨�
                if(i==imi && j==jmi) continue;
                if(bot_body[i][j]==(dlina-1))
                {
                    bot_body[i][j]=dlina;
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

//�-�� ��।������� ������
void bodys_bot()
{
    int dlina=4;
    int exit_b=0;//��室 �� 横��� for() �� ��宦����� �㦭��� �.
    if(max_body_bot>3)
    while(dlina<=max_body_bot)
    {
        for (int i = 1; i < 10;i++)
        {
            for (int j = 1; j < 10;j++)
            {
                // �����塞 �� +1 �� ��砫쭮�� �. ���ᨢ�
                // � ���ᨬ���� �. ���ᨢ� (����� ⥫� ������) =1
                if(bot_body[i][j]==dlina)
                {
                    if(j+1<10)
                        if(bot_body[i][j+1]==dlina-1) {bot_body[i][j+1]=dlina; if(dlina==max_body_bot)bot_body[i][j]=1; exit_b=1; break;}
                    if(j-1>0)
                        if(bot_body[i][j-1]==dlina-1) {bot_body[i][j-1]=dlina; if(dlina==max_body_bot)bot_body[i][j]=1; exit_b=1; break;}
                    if(i+1<10)
                        if(bot_body[i+1][j]==dlina-1) {bot_body[i+1][j]=dlina; if(dlina==max_body_bot)bot_body[i][j]=1; exit_b=1; break;}
                    if(i-1>0)
                        if(bot_body[i-1][j]==dlina-1) {bot_body[i-1][j]=dlina; if(dlina==max_body_bot)bot_body[i][j]=1; exit_b=1; break;}
                }
            }
            if(exit_b==1)break;
        }
        dlina++;
        exit_b=0;
    }
    else bot_body[im_bot][jm_bot]=1;
}

void apple_bot()
{
    //appl �� 1 �� 9 �����⥫쭮
    appl_i_bot=1+rand()%9;
    appl_j_bot=1+rand()%9;
}

void apple_move_bot()
{
    //�⮡ �� �뫮 ᮢ������� ��� � �������
    while(im_bot==appl_i_bot && jm_bot==appl_j_bot)
    {
        apple_bot();
        //�⮡ �� �뫮 ᮢ������� ��� � ⥫�� ������
        while(bot_body[appl_i_bot][appl_j_bot]>3) apple_bot();
    }
    bot_body[appl_i_bot][appl_j_bot]=2;
}
void print_bot()
{
    //���⠥� �窨 �� �������� ���
    if(im_bot==appl_i_bot && jm_bot==appl_j_bot) scored_bot+=100;
    printf("score ���: %i\n", scored_bot);
    apple_move_bot();
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if(bot_body[i][j]==0) printf("��");
            if(bot_body[i][j]==1) printf("[]");
            if(bot_body[i][j]==2) printf("%s��%s",RED, RESET);
            if(bot_body[i][j]==3) printf("%s��%s",GREEN, RESET);
            if(bot_body[i][j]>3 && bot_body[i][j]%2==0) printf("%s��%s",BLUE, RESET);
            if(bot_body[i][j]>3 && bot_body[i][j]%2!=0) printf("%s��%s",PINK, RESET);
        }
        printf("\n");
    }
}

//�-�� ��।������ ������ ��� �ᯮ������ ������ ������ � �� �冷� � ���
/*�� chast_bot=0 - ����� ������ �������, � ���� ᢮������ ����;
chast_bot=1 - �� �� ��஭� ������� � ���� ��஭� �� 0 ��� >3, � ���� �⥭� ��� ⥫� ������;
chast_bot=2 - �� 2-� ��஭� ������� � �� ��. 2-� ��஭� �⥭� ��� ⥫�; � �� chast_bot=3
�� 3 ��஭� �⥭� ��� ⥫� ������ � 1 ��஭� �� ������(����);
chast_bot=4 - ����� �� �� 4 ��஭� �⥭� ��� ⥫� ������, ⮣�� ��� � ����稢�����
� pozi_bot ��।����, � ����� ��஭ �㤥� ���� ��� �⥭� ��� ⥫� ������;*/
void dvizh_bot_dop()
{
    //0,0
    if(bot_body[im_bot-1][jm_bot]==1 &&
    bot_body[im_bot+1][jm_bot]==1 &&
    bot_body[im_bot][jm_bot-1]==1 &&
    bot_body[im_bot][jm_bot+1]==1)
    {
        chast_bot=0; pozi_bot=0;
    }
    //1,1
    if(bot_body[im_bot-1][jm_bot]==1 &&
    (bot_body[im_bot+1][jm_bot]==0 || bot_body[im_bot+1][jm_bot]>3) &&
    bot_body[im_bot][jm_bot-1]==1 &&
    bot_body[im_bot][jm_bot+1]==1)
    {
        chast_bot=1; pozi_bot=1;
    }
    //1,2
    if(bot_body[im_bot-1][jm_bot]==1 &&
    bot_body[im_bot+1][jm_bot]==1 &&
    (bot_body[im_bot][jm_bot-1]==0 || bot_body[im_bot][jm_bot-1]>3) &&
    bot_body[im_bot][jm_bot+1]==1)
    {
        chast_bot=1; pozi_bot=2;
    }
    //1,3
    if((bot_body[im_bot-1][jm_bot]==0 || bot_body[im_bot-1][jm_bot]>3) &&
    bot_body[im_bot+1][jm_bot]==1 &&
    bot_body[im_bot][jm_bot-1]==1 &&
    bot_body[im_bot][jm_bot+1]==1)
    {
        chast_bot=1; pozi_bot=3;
    }
    //1,4
    if(bot_body[im_bot-1][jm_bot]==1 &&
    bot_body[im_bot+1][jm_bot]==1 &&
    bot_body[im_bot][jm_bot-1]==1 &&
    (bot_body[im_bot][jm_bot+1]==0 || bot_body[im_bot][jm_bot+1]>3))
    {
        chast_bot=1; pozi_bot=4;
    }

    //2,1
    if(bot_body[im_bot-1][jm_bot]==1 &&
    bot_body[im_bot][jm_bot+1]==1 &&
    (bot_body[im_bot][jm_bot-1]==0 || bot_body[im_bot][jm_bot-1]>3) &&
    (bot_body[im_bot+1][jm_bot]==0 || bot_body[im_bot+1][jm_bot]>3))
    {
        chast_bot=2; pozi_bot=1;
    }
    //2,2
    if((bot_body[im_bot-1][jm_bot]==0 || bot_body[im_bot-1][jm_bot]>3) &&
    (bot_body[im_bot][jm_bot-1]==0 || bot_body[im_bot][jm_bot-1]>3) &&
    bot_body[im_bot+1][jm_bot]==1 &&
    bot_body[im_bot][jm_bot+1]==1)
    {
        chast_bot=2; pozi_bot=2;
    }
    //2,3
    if((bot_body[im_bot-1][jm_bot]==0 || bot_body[im_bot-1][jm_bot]>3) &&
    (bot_body[im_bot][jm_bot+1]==0 || bot_body[im_bot][jm_bot+1]>3) &&
    bot_body[im_bot][jm_bot-1]==1 &&
    bot_body[im_bot+1][jm_bot]==1)
    {
        chast_bot=2; pozi_bot=3;
    }
    //2,4
    if(bot_body[im_bot-1][jm_bot]==1 &&
    bot_body[im_bot][jm_bot-1]==1 &&
    (bot_body[im_bot][jm_bot+1]==0 || bot_body[im_bot][jm_bot+1]>3) &&
    (bot_body[im_bot+1][jm_bot]==0 || bot_body[im_bot+1][jm_bot]>3))
    {
        chast_bot=2; pozi_bot=4;
    }
    //2,5
    if(bot_body[im_bot-1][jm_bot]==1 &&
    bot_body[im_bot+1][jm_bot]==1 &&
    (bot_body[im_bot][jm_bot+1]==0 || bot_body[im_bot][jm_bot+1]>3) &&
    (bot_body[im_bot][jm_bot-1]==0 || bot_body[im_bot][jm_bot-1]>3))
    {
        chast_bot=2; pozi_bot=5;
    }
    //2,6
    if((bot_body[im_bot+1][jm_bot]==0 || bot_body[im_bot+1][jm_bot]>3) &&
    (bot_body[im_bot-1][jm_bot]==0 || bot_body[im_bot-1][jm_bot]>3) &&
    bot_body[im_bot][jm_bot-1]==1 &&
    bot_body[im_bot][jm_bot+1]==1)
    {
        chast_bot=2; pozi_bot=6;
    }

    //3,1
    if((bot_body[im_bot+1][jm_bot]==0 || bot_body[im_bot+1][jm_bot]>3) &&
    (bot_body[im_bot-1][jm_bot]==0 || bot_body[im_bot-1][jm_bot]>3) &&
    (bot_body[im_bot][jm_bot-1]==0 || bot_body[im_bot][jm_bot-1]>3) &&
    bot_body[im_bot][jm_bot+1]==1)
    {
        chast_bot=3; pozi_bot=1;
    }
    //3,2
    if((bot_body[im_bot-1][jm_bot]==0 || bot_body[im_bot-1][jm_bot]>3) &&
    (bot_body[im_bot][jm_bot-1]==0 || bot_body[im_bot][jm_bot-1]>3) &&
    (bot_body[im_bot][jm_bot+1]==0 || bot_body[im_bot][jm_bot+1]>3) &&
    bot_body[im_bot+1][jm_bot]==1)
    {
        chast_bot=3; pozi_bot=2;
    }
    //3,3
    if((bot_body[im_bot-1][jm_bot]==0 || bot_body[im_bot-1][jm_bot]>3) &&
    (bot_body[im_bot+1][jm_bot]==0 || bot_body[im_bot+1][jm_bot]>3) &&
    (bot_body[im_bot][jm_bot+1]==0 || bot_body[im_bot][jm_bot+1]>3) &&
    bot_body[im_bot][jm_bot-1]==1)
    {
        chast_bot=3; pozi_bot=3;
    }
    //3,4
    if((bot_body[im_bot+1][jm_bot]==0 || bot_body[im_bot+1][jm_bot]>3) &&
    (bot_body[im_bot][jm_bot+1]==0 || bot_body[im_bot][jm_bot+1]>3) &&
    (bot_body[im_bot][jm_bot-1]==0 || bot_body[im_bot][jm_bot-1]>3) &&
    bot_body[im_bot-1][jm_bot]==1)
    {
        chast_bot=3; pozi_bot=4;
    }

    //4,0
    if((bot_body[im_bot+1][jm_bot]==0 || bot_body[im_bot+1][jm_bot]>3) &&
    (bot_body[im_bot][jm_bot+1]==0 || bot_body[im_bot][jm_bot+1]>3) &&
    (bot_body[im_bot][jm_bot-1]==0 || bot_body[im_bot][jm_bot-1]>3) &&
    (bot_body[im_bot-1][jm_bot]==0 || bot_body[im_bot-1][jm_bot]>3))
    {
        chast_bot=4; pozi_bot=0;
    }
}

//�-�� ����� �����e �ॣࠦ���� ���� �� 3 ��஭� �஬� 1, ��� ��� ���㦥�� ���������
void if3()
{
    if(chast_bot==3 && pozi_bot==1){jm_bot++;}//
    if(chast_bot==3 && pozi_bot==2){im_bot++;}//
    if(chast_bot==3 && pozi_bot==3){jm_bot--;}//
    if(chast_bot==3 && pozi_bot==4){im_bot--;}//
    if(chast_bot==4 && pozi_bot==0){game_over_bot(); }
}

//�-�� ��।������ �������� ������
void move_bot()
{
    int con=1; //��६����� ��� ��।������ ������襣� �� 蠣 ���
    if(bot_body[im_bot][jm_bot+1]==2 && con==1) {bodyapp_bot();con=0;jm_bot++;}
    if(bot_body[im_bot][jm_bot-1]==2 && con==1) {bodyapp_bot();con=0;jm_bot--;}
    if(bot_body[im_bot+1][jm_bot]==2 && con==1) {bodyapp_bot();con=0;im_bot++;}
    if(bot_body[im_bot-1][jm_bot]==2 && con==1) {bodyapp_bot();con=0;im_bot--;}
    
if(con==1)
{
    //��।������ ��� �� ���. ���� �������� ������
    int imi=12, jmi=12, ex=1;
    if(im_bot>=appl_i_bot && jm_bot>appl_j_bot && ex==1)
    {
        dvizh_bot_dop();
        bodys_bot();
        if(chast_bot==0 && pozi_bot==0){jm_bot--;}//
        if(chast_bot==1 && pozi_bot==1){jm_bot--;}//
        if(chast_bot==1 && pozi_bot==2){im_bot--;}//
        if(chast_bot==1 && pozi_bot==3){jm_bot--;}//
        if(chast_bot==1 && pozi_bot==4){jm_bot--;}//

        if(chast_bot==2 && pozi_bot==1){im_bot--;}//
        if(chast_bot==2 && pozi_bot==2){im_bot++;}//
        if(chast_bot==2 && pozi_bot==3){jm_bot--;}//
        if(chast_bot==2 && pozi_bot==4){jm_bot--;}//
        if(chast_bot==2 && pozi_bot==5){im_bot--;}//
        if(chast_bot==2 && pozi_bot==6){jm_bot--;}//

        if3();
        ex=0;
    }

    if(im_bot>=appl_i_bot && jm_bot<appl_j_bot && ex==1)
    {
        dvizh_bot_dop();
        bodys_bot();
        if(chast_bot==0 && pozi_bot==0){jm_bot++;}//
        if(chast_bot==1 && pozi_bot==1){jm_bot++;}//
        if(chast_bot==1 && pozi_bot==2){jm_bot++;}//
        if(chast_bot==1 && pozi_bot==3){jm_bot++;}//
        if(chast_bot==1 && pozi_bot==4){im_bot--;}//

        if(chast_bot==2 && pozi_bot==1){jm_bot++;}//
        if(chast_bot==2 && pozi_bot==2){jm_bot++;}//
        if(chast_bot==2 && pozi_bot==3){jm_bot--;}//
        if(chast_bot==2 && pozi_bot==4){im_bot--;}//
        if(chast_bot==2 && pozi_bot==5){im_bot--;}//
        if(chast_bot==2 && pozi_bot==6){jm_bot++;}//

        if3();
        ex=0;
    }

    if(im_bot<appl_i_bot && jm_bot<=appl_j_bot && ex==1)
    {
        dvizh_bot_dop();
        bodys_bot();
        if(chast_bot==0 && pozi_bot==0){im_bot++;}//
        if(chast_bot==1 && pozi_bot==1){jm_bot++;}//
        if(chast_bot==1 && pozi_bot==2){im_bot++;}//
        if(chast_bot==1 && pozi_bot==3){im_bot++;}//
        if(chast_bot==1 && pozi_bot==4){im_bot++;}//

        if(chast_bot==2 && pozi_bot==1){jm_bot++;}//
        if(chast_bot==2 && pozi_bot==2){im_bot++;}//
        if(chast_bot==2 && pozi_bot==3){im_bot++;}//
        if(chast_bot==2 && pozi_bot==4){jm_bot--;}//
        if(chast_bot==2 && pozi_bot==5){im_bot++;}//
        if(chast_bot==2 && pozi_bot==6){jm_bot++;}//

        if3();
        ex=0;
    }

    if(im_bot<appl_i_bot && jm_bot>appl_j_bot && ex==1)
    {
        dvizh_bot_dop();
        bodys_bot();
        if(chast_bot==0 && pozi_bot==0){im_bot++;}//
        if(chast_bot==1 && pozi_bot==1){jm_bot--;}//
        if(chast_bot==1 && pozi_bot==2){im_bot++;}//
        if(chast_bot==1 && pozi_bot==3){im_bot++;}//
        if(chast_bot==1 && pozi_bot==4){im_bot++;}//

        if(chast_bot==2 && pozi_bot==1){jm_bot++;}//
        if(chast_bot==2 && pozi_bot==2){im_bot++;}//
        if(chast_bot==2 && pozi_bot==3){im_bot++;}//
        if(chast_bot==2 && pozi_bot==4){jm_bot--;}//
        if(chast_bot==2 && pozi_bot==5){im_bot++;}//
        if(chast_bot==2 && pozi_bot==6){jm_bot--;}//

        if3();
        ex=0;
    }

    if(im_bot>appl_i_bot && jm_bot==appl_j_bot && ex==1)
    {
        dvizh_bot_dop();
        bodys_bot();
        if(chast_bot==0 && pozi_bot==0){im_bot--;}//
        if(chast_bot==1 && pozi_bot==1){im_bot--;}//
        if(chast_bot==1 && pozi_bot==2){im_bot--;}//
        if(chast_bot==1 && pozi_bot==3){jm_bot--;}//
        if(chast_bot==1 && pozi_bot==4){im_bot--;}//

        if(chast_bot==2 && pozi_bot==1){im_bot--;}//
        if(chast_bot==2 && pozi_bot==2){jm_bot++;}//
        if(chast_bot==2 && pozi_bot==3){jm_bot--;}//
        if(chast_bot==2 && pozi_bot==4){im_bot--;}//
        if(chast_bot==2 && pozi_bot==5){im_bot--;}//
        if(chast_bot==2 && pozi_bot==6){jm_bot++;}//

        if3();
        ex=0;
    }
}
    bot_body[im_bot][jm_bot]=3;
}

//############################################## ����� ########################################

//�-�� �������� ����
void menu_print();
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
        //���� ����
        menu_print();
        game_continue=deistvie_menu;
        menu_id=game_continue;
        while(game_continue==1 || game_continue==2)
        {
            print_pole();
            if(game_continue==2) print_bot();
            //��� � ���� �� � ��⮬
            while(game==1 && (game_continue==1 || game_continue==2)) move();
            if(deistvie_menu==1)printf("������ '1' � ENTER, �⮡� ����� ����� ����. �᫨ ��� ������ ����, ������ '0' � ENTER == ");
            if(deistvie_menu==2)printf("������ '2' � ENTER, �⮡� ����� ����� ����. �᫨ ��� ������ ����, ������ '0' � ENTER == ");
            scanf("%i",&game_continue);
            printf("\n");
            if(game_continue==1 || game_continue==2) game=1;
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
        model=getch();
        if(model>0) system("cls");
        printf("\t\tSNAKE\n\n");
        printf("�롥�� ०�� �� ���, �᫨ ���ࠢ����� ������ 'E'\n###########\n");
        //�஫���뢠��� ����
        if(model==115 || model==235 )
        {
            meny++;
            if(meny>3) meny--;
            if(meny==1) printf("%s���� �����%s\n", RED, RESET);
                else printf("���� �����\n");
            if(meny==2) printf("%s����� � ���%s\n", RED, RESET);
                else printf("����� � ���\n");
            if(meny==3) printf("%s��室%s\n", RED, RESET);
                else printf("��室\n");
        }
        //�஫���뢠��� �����
        if(model==119 || model==230)
        {
            meny--;
            if(meny<1) meny=1;
            if(meny==1) printf("%s���� �����%s\n", RED, RESET);
                else printf("���� �����\n");
            if(meny==2) printf("%s����� � ���%s\n", RED, RESET);
                else printf("����� � ���\n");
            if(meny==3) printf("%s��室%s\n", RED, RESET);
                else printf("��室\n");
        }
        // 'e' ��� '�'
        if(model==101 || model==227)
        {
            if(meny==1) dvizh=0;
            if(meny==3)
            {
                dvizh=0;
                game=0;
            }
            if(meny==2)
            {
                dvizh=0;
            }
        }
    }
    deistvie_menu=meny;
}

void game_over()
{
    system("cls");
    //��६���� ��ࠢ������ � ����砫쭮�� ���ﭨ�
    game=0;
    for(int i=0;i<5;i++)
        printf("\n");
    printf("\t\t    GAME OVER\n  ");
    if(deistvie_menu==2)printf("\t\t  ����� ���ঠ� lose (�१����)\n");
    printf("\t\ttotal score ������: %i\n", scored);
    if(deistvie_menu==2)printf("\t\ttotal score ����: %i\n", scored_bot);
    appl_i=5, appl_j=5;
    im=5,jm=5;
    max_body=3;
    scored=-100;

    appl_i_bot=5, appl_j_bot=5;
    im_bot=5,jm_bot=5;
    max_body_bot=3;
    scored_bot=-100;
    for(int i=1;i<10;i++)
        for(int j=1;j<10;j++)
        {
            block[i][j]=1;
            bot_body[i][j]=1;
        }
    block[im][jm]=3;
    bot_body[im_bot][jm_bot]=3;
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
    //�뢮� �窮�
    if(im==appl_i && jm==appl_j) scored+=100;
    printf("score ��ப�: %i\n", scored);
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

//�-�� �������� � ������� ����������
void move()
{
    moved = getch();
    //�����(w,�)
    if(moved==119 || moved==230)
    {
        if(block[im-1][jm]==0 || block[im-1][jm]>4) game_over();
        else if(block[im-1][jm]==4){print_pole();if(deistvie_menu==2)print_bot();}
        else
        {
            if(block[im-1][jm]==2)
            {
                bodyapp();
            } else bodys();
            im--;
            block[im][jm]=3;
            print_pole();if(deistvie_menu==2){move_bot();if(game==1)print_bot();}
        }
    }
    //����(s,�)
    if(moved==115 || moved==235)
    {
        if(block[im+1][jm]==0 || block[im+1][jm]>4) game_over();
        else if(block[im+1][jm]==4){print_pole();if(deistvie_menu==2)print_bot();}
        else
        {
            if(block[im+1][jm]==2)
            {
                bodyapp();
            } else bodys();
            im++;
            block[im][jm]=3;
            print_pole();if(deistvie_menu==2){move_bot();if(game==1)print_bot();}
        }
    }
    //�����(a,�)
    if(moved==97 || moved==228)
    {
        if(block[im][jm-1]==0 || block[im][jm-1]>4) game_over();
        else if(block[im][jm-1]==4){print_pole();if(deistvie_menu==2)print_bot();}
        else
        {
            if(block[im][jm-1]==2)
            {
                bodyapp();
            } else bodys();
            jm--;
            block[im][jm]=3;
            print_pole();if(deistvie_menu==2){move_bot();if(game==1)print_bot();}
        }
    }
    //��ࠢ�(d,�)
    if(moved==100 || moved==162)
    {
        if(block[im][jm+1]==0 || block[im][jm+1]>4) game_over();
        else if(block[im][jm+1]==4){print_pole();if(deistvie_menu==2)print_bot();}
        else
        {
            if(block[im][jm+1]==2)
            {
                bodyapp();
            } else bodys();
            jm++;
            block[im][jm]=3;
            print_pole();if(deistvie_menu==2){move_bot();if(game==1)print_bot();}
        }
    }
}
