#include <header.h>
extern int bot_body[11][11];
extern int appl_i_bot, appl_j_bot;//��६���� ��� ���� ��������� ������
extern int im_bot,jm_bot;//��६���� ��� �������� ������
extern int max_body_bot;//����� ������
extern int scored_bot;
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
        apple();
        //�⮡ �� �뫮 ᮢ������� ��� � ⥫�� ������
        while(bot_body[appl_i_bot][appl_j_bot]>3) apple();
    }
    bot_body[appl_i_bot][appl_j_bot]=2;
}
void print_bot()
{
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
void move_bot()
{
    if(bot_body);
}
