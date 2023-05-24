/**
 * @file colors.h 
 * @author Tales Oliveira (tales.olivera@estudante.ifb.edu.br)
 * @brief a header to change colors and letters in the terminal
 */
#ifndef COLORS_H
#define COLORS_H

#define clear_screen() system("cls") //Clear the terminal screen on windows

//CHAR SETTINGS
#define C_RESET "\x1B[0m"   //Reset to the original colors
#define C_BOLD "\x1b[1m"    //Bold the letter
#define C_FAINT "\x1b[2m"   //Faint the letter
#define C_ITALIC "\x1b[3m"  //Italic the letter
#define C_UNDER "\x1b[4m"   //Underline the letter
#define C_BLINK "\x1b[5m"   //Blink the letter
#define C_6 "\x1b[6m"       //
#define C_INVERSE "\x1b[7m" //Inverse BG color with the letter
#define C_HIDE  "\x1b[8m"   //Hide the letter in the terminal
#define C_STRIKE "\x1b[9m"  //Strike through the letter

//REGULAR LETTERS
#define RL_BLA "\x1b[0;30m" //Black
#define RL_RED "\x1b[0;31m" //Red
#define RL_GRN "\x1b[0;32m" //Green
#define RL_YEL "\x1b[0;33m" //Yellow
#define RL_BLU "\x1b[0;34m" //Blue
#define RL_MAG "\x1b[0;35m" //Magenta
#define RL_CYN "\x1b[0;36m" //Cyan
#define RL_WHT "\x1b[0;37m" //White

//STRONG LETTERS
#define SL_BLA "\x1b[1;30m" //Black
#define SL_RED "\x1b[1;31m" //Red
#define SL_GRN "\x1b[1;32m" //Green
#define SL_YEL "\x1b[1;33m" //Yellow
#define SL_BLU "\x1b[1;34m" //Blue
#define SL_MAG "\x1b[1;35m" //Magenta
#define SL_CYN "\x1b[1;36m" //Cyan
#define SL_WHT "\x1b[1;37m" //White

//BACKGROUND COLOR
#define BG_BLA "\x1b[1;40m" //Black
#define BG_RED "\x1b[1;41m" //Red
#define BG_GRN "\x1b[1;42m" //Green
#define BG_YEL "\x1b[1;43m" //Yellow
#define BG_BLU "\x1b[1;44m" //Blue
#define BG_MAG "\x1b[1;45m" //Magenta
#define BG_CYN "\x1b[1;46m" //Cyan
#define BG_WHT "\x1b[1;47m" //White

#endif//COLORS_H