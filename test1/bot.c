#include <header.h>
extern int bot_body[11][11];
extern int appl_i_bot, appl_j_bot;//переменные для место положения змейки
extern int im_bot,jm_bot;//переменные для движения головы
extern int max_body_bot;//длина змейки
extern int scored_bot;
void apple_bot()
{
    //appl от 1 до 9 включительно
    appl_i_bot=1+rand()%9;
    appl_j_bot=1+rand()%9;
}

void apple_move_bot()
{
    //чтоб не было совпадений яблока с головой
    while(im_bot==appl_i_bot && jm_bot==appl_j_bot)
    {
        apple();
        //чтоб не было совпадений яблока с телом змейки
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
            if(bot_body[i][j]==0) printf("██");
            if(bot_body[i][j]==1) printf("[]");
            if(bot_body[i][j]==2) printf("%s██%s",RED, RESET);
            if(bot_body[i][j]==3) printf("%s██%s",GREEN, RESET);
            if(bot_body[i][j]>3 && bot_body[i][j]%2==0) printf("%s██%s",BLUE, RESET);
            if(bot_body[i][j]>3 && bot_body[i][j]%2!=0) printf("%s██%s",PINK, RESET);
        }
        printf("\n");
    }
}
void move_bot()
{
    if(bot_body);
}
