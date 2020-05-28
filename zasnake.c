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
                    {0,0,0,0,0,0,0,0,0,0,0}};//массив поля и прочего под игрока
int appl_i=5, appl_j=5;//переменные для место положения яблока
int moved ,im=5,jm=5;//переменные для движения головы
int max_body=3;//длина змейки
int game=1;//продолжение или конец игры
int scored=-100;//переменная для отображения очков игрока
int deistvie_menu;//какой пункт меню, игрок выбрал

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
                        {0,0,0,0,0,0,0,0,0,0,0}};//массив поля и прочего под бота
int appl_i_bot=5, appl_j_bot=5;//переменные для место положения яблока(bot)
int im_bot=5,jm_bot=5;//переменные для движения головы(bot)
int max_body_bot=3;//длина змейки(bot)
int scored_bot=-100;//очки бота
int chast_bot, pozi_bot;//часть направления при будущем движ. и позиции которую будет принимать змейка

// ################################################ БОТ ####################################
// ф-ция конца игры (bot)
void game_over_bot()
{
    //переменные приводим к изначальному состоянию
    system("cls");
    game=0;
    for(int i=0;i<5;i++)
        printf("\n");
    printf("\t\t    GAME OVER\n  ");
    if(deistvie_menu==2)printf("\t\t  БОТ одержал lose (врезался)\n");
    printf("\t\ttotal score ИГРОКА: %i\n", scored);
    printf("\t\ttotal score БОТА: %i\n", scored_bot);
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
//ф-ция появления яблока, случайно в поле 
void apple_bot();
//ф-ция повторного вызова apple_bot(); при совпадении яблока с телом или головой змейки 
void apple_move_bot();
//ф-ция печати поля
void print_bot();

//ф-ция удлинения змейки при поедании яблока 
void bodyapp_bot()
{
    int dlina=4, exit_b=0;//выход из циклов for() при нахождении нужного эл.
    int imi=12, jmi=12;
    //увеличивает мах. длину змейки при поедании яблока
    max_body_bot=max_body_bot+1;
    while(dlina<=max_body_bot)
    {
        for(int i=1;i<10;i++)
        {
            for(int j=1;j<10;j++)
            {
                //эл. массива с прошлым значением не должен совпасть с нынишним
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

//ф-ция передвижения змейки
void bodys_bot()
{
    int dlina=4;
    int exit_b=0;//выход из циклов for() при нахождении нужного эл.
    if(max_body_bot>3)
    while(dlina<=max_body_bot)
    {
        for (int i = 1; i < 10;i++)
        {
            for (int j = 1; j < 10;j++)
            {
                // заменяем на +1 от начального эл. массива
                // а максимальный эл. массива (конец тела змейки) =1
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
    //appl от 1 до 9 включительно
    appl_i_bot=1+rand()%9;
    appl_j_bot=1+rand()%9;
}

void apple_move_bot()
{
    //чтоб не было совпадений яблока с головой
    while(im_bot==appl_i_bot && jm_bot==appl_j_bot)
    {
        apple_bot();
        //чтоб не было совпадений яблока с телом змейки
        while(bot_body[appl_i_bot][appl_j_bot]>3) apple_bot();
    }
    bot_body[appl_i_bot][appl_j_bot]=2;
}
void print_bot()
{
    //печатаем очки при поедании яблока
    if(im_bot==appl_i_bot && jm_bot==appl_j_bot) scored_bot+=100;
    printf("score бота: %i\n", scored_bot);
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

//ф-ция определяющая позицию где расположена голова змейки и что рядом с ней
/*при chast_bot=0 - вокруг змейки единицы, то есть свободное поле;
chast_bot=1 - по три стороны единицы и одна сторона это 0 или >3, то есть стена или тело змейки;
chast_bot=2 - по 2-е стороны единицы и по др. 2-е стороны стена или тело; И при chast_bot=3
по 3 стороны стена или тело змейки и 1 сторона это единица(поле);
chast_bot=4 - когда по все 4 стороны стена или тело змейки, тогда игра и оканчивается
а pozi_bot определяет, с каких сторон будет поле или стена или тело змейки;*/
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

//ф-ция когда змейкe преграждают путь на 3 стороны кроме 1, или она окружена полностью
void if3()
{
    if(chast_bot==3 && pozi_bot==1){jm_bot++;}//
    if(chast_bot==3 && pozi_bot==2){im_bot++;}//
    if(chast_bot==3 && pozi_bot==3){jm_bot--;}//
    if(chast_bot==3 && pozi_bot==4){im_bot--;}//
    if(chast_bot==4 && pozi_bot==0){game_over_bot(); }
}

//ф-ция определения движения змейки
void move_bot()
{
    int con=1; //переменная для определения ближайшего на шаг яблока
    if(bot_body[im_bot][jm_bot+1]==2 && con==1) {bodyapp_bot();con=0;jm_bot++;}
    if(bot_body[im_bot][jm_bot-1]==2 && con==1) {bodyapp_bot();con=0;jm_bot--;}
    if(bot_body[im_bot+1][jm_bot]==2 && con==1) {bodyapp_bot();con=0;im_bot++;}
    if(bot_body[im_bot-1][jm_bot]==2 && con==1) {bodyapp_bot();con=0;im_bot--;}
    
if(con==1)
{
    //определение пути до яблока. Само движение змейки
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

//############################################## ИГРОК ########################################

//ф-ция главного меню
void menu_print();
//ф-ция lose
void game_over();
//ф-ция удлинения змейки при поедании яблока
void bodyapp();
//ф-ция удлинения змейки при движении змейки
void bodys();
//индексы элемента массива яблока
void apple();
//ф-ция передвижения яблока по полю (не задевав лишнего)
void apple_move();
//ф-ция печати кадра
void print_pole();
//ф-ция движения змейки
void move();

// игра
void main()
{
    srand(time(NULL));
    int game_continue=1;
    int menu_id=1;
    printf("\n");
    while(menu_id==1)
    {
        //меню игры
        menu_print();
        game_continue=deistvie_menu;
        menu_id=game_continue;
        while(game_continue==1 || game_continue==2)
        {
            print_pole();
            if(game_continue==2) print_bot();
            //Игра в одно ил с ботом
            while(game==1 && (game_continue==1 || game_continue==2)) move();
            if(deistvie_menu==1)printf("Нажмите '1' и ENTER, чтобы начать новую игру. Если хотите посетить меню, нажмите '0' и ENTER == ");
            if(deistvie_menu==2)printf("Нажмите '2' и ENTER, чтобы начать новую игру. Если хотите посетить меню, нажмите '0' и ENTER == ");
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
    printf("Нажмите 'W' или 'S'\n");
    while(dvizh==1)
    {
        model=getch();
        if(model>0) system("cls");
        printf("\t\tSNAKE\n\n");
        printf("Выберите режим по душе, если понравилось нажмите 'E'\n###########\n");
        //пролистывание вниз
        if(model==115 || model==235 )
        {
            meny++;
            if(meny>3) meny--;
            if(meny==1) printf("%sОдин ИГРОК%s\n", RED, RESET);
                else printf("Один ИГРОК\n");
            if(meny==2) printf("%sИГРОК и БОТ%s\n", RED, RESET);
                else printf("ИГРОК и БОТ\n");
            if(meny==3) printf("%sВыход%s\n", RED, RESET);
                else printf("Выход\n");
        }
        //пролистывание вверх
        if(model==119 || model==230)
        {
            meny--;
            if(meny<1) meny=1;
            if(meny==1) printf("%sОдин ИГРОК%s\n", RED, RESET);
                else printf("Один ИГРОК\n");
            if(meny==2) printf("%sИГРОК и БОТ%s\n", RED, RESET);
                else printf("ИГРОК и БОТ\n");
            if(meny==3) printf("%sВыход%s\n", RED, RESET);
                else printf("Выход\n");
        }
        // 'e' или 'у'
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
    //переменные приравниваем к изначальному состоянию
    game=0;
    for(int i=0;i<5;i++)
        printf("\n");
    printf("\t\t    GAME OVER\n  ");
    if(deistvie_menu==2)printf("\t\t  ИГРОК одержал lose (врезался)\n");
    printf("\t\ttotal score ИГРОКА: %i\n", scored);
    if(deistvie_menu==2)printf("\t\ttotal score БОТА: %i\n", scored_bot);
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
    //увеличивае тела змейки при поедании яблока
    max_body=max_body+1;
    while(dlina<=max_body)
    {
        for(int i=1;i<10;i++)
        {
            for(int j=1;j<10;j++)
            {
                //эл. массива с прошлым значением не должен совпасть с нынишним
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
    int exit_b=0;//выход из циклов for() при нахождении нужного эл.
    if(max_body>3)
    while(dlina<=max_body)
    {
        for (int i = 1; i < 10;i++)
        {
            for (int j = 1; j < 10;j++)
            {
                // заменяем на +1 от начального эл. массива
                // а максимальный эл. массива (конец тела змейки) =1
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
    //appl от 1 до 9 включительно
    appl_i=1+rand()%9;
    appl_j=1+rand()%9;
}

void apple_move()
{
    //чтоб не было совпадений яблока с головой
    while(im==appl_i && jm==appl_j)
    {
        apple();
        //чтоб не было совпадений яблока с телом змейки
        while(block[appl_i][appl_j]>3) apple();
    }
    block[appl_i][appl_j]=2;
}

void print_pole()
{
    system("cls");
    //вывод очков
    if(im==appl_i && jm==appl_j) scored+=100;
    printf("score игрока: %i\n", scored);
    apple_move();
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if(block[i][j]==0) printf("██");
            if(block[i][j]==1) printf("[]");
            if(block[i][j]==2) printf("%s██%s",RED, RESET);
            if(block[i][j]==3) printf("%s██%s",GREEN, RESET);
            if(block[i][j]>3 && block[i][j]%2==0) printf("%s██%s",BLUE, RESET);
            if(block[i][j]>3 && block[i][j]%2!=0) printf("%s██%s",PINK, RESET);
        }
        printf("\n");
    }
}

//ф-ция движения с помощью клавиатуры
void move()
{
    moved = getch();
    //вверх(w,ц)
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
    //вниз(s,ы)
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
    //влево(a,ф)
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
    //вправо(d,в)
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
