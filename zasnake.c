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
int appl_i=5, appl_j=5;//переменные для место положения змейки
int moved ,im=5,jm=5;//переменные для движения головы
int max_body=3;//длина змейки
int game=1;//продолжение или конец игры
int scored=-100;//переменная для отображения очков игрока
int deistvie_menu;//какой пункт меню, игрок выбрал

//ф-ция главного меню
void menu_print();
//ф-ция очков игрока
void score();
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
        menu_print();
        game_continue=deistvie_menu;
        menu_id=game_continue;
        while(game_continue==1)
        {
            print_pole();
            while(game==1) move();
            game_continue=game;
            printf("Нажмите '1', чтобы начать новую игру. Если хотите посетить меню, нажмите '0' == ");
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
    printf("Нажмите 'W' или 'S'\n");
    while(dvizh==1)
    {
        model=getche();
        if(model>0) system("cls");
        printf("\t\tГОРБАТАЯ ГОРА\n\n");
        printf("Выберите режим по душе, если понравилось нажмите 'E'\n###########\n");
        //niz
        if(model==115 || model==235 )
        {
            meny++;
            if(meny>4) meny--;
            if(meny==1) printf("%sРежим отшельника%s\n", RED, RESET);
                else printf("Режим отшельника\n");
            if(meny==2) printf("%sРежим хардкорного отшельника с внедрением движения времени(его нет)%s\n", RED, RESET);
                else printf("Режим хардкорного отшельника с внедрением движения времени(его нет)\n");
            if(meny==3) printf("%sРежим отшельника, но рядом компьютер(его нет)%s\n", RED, RESET);
                else printf("Режим отшельника, но рядом компьютер(его нет)\n");
            if(meny==4) printf("%sПокинуть гору%s\n", RED, RESET);
                else printf("Покинуть гору\n");
        }
        //verx
        if(model==119 || model==230)
        {
            meny--;
            if(meny<1) meny=1;
            if(meny==1) printf("%sРежим отшельника%s\n", RED, RESET);
                else printf("Режим отшельника\n");
            if(meny==2) printf("%sРежим хардкорного отшельника с внедрением движения времени(его нет)%s\n", RED, RESET);
                else printf("Режим хардкорного отшельника с внедрением движения времени(его нет)\n");
            if(meny==3) printf("%sРежим отшельника, но рядом компьютер(его нет)%s\n", RED, RESET);
                else printf("Режим отшельника, но рядом компьютер(его нет)\n");
            if(meny==4) printf("%sПокинуть гору%s\n", RED, RESET);
                else printf("Покинуть гору\n");
        }
        // e или у
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
    //переменные приравниваем к изначальному состоянию
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
    if(im==appl_i && jm==appl_j) score();
    printf("PP 1-го игрока: %i\n", scored);
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

void move()
{
    moved = getche();
    //verh(w,ц)
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
    //niz(s,ы)
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
    //leva(a,ф)
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
    //pravo(d,в)
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