/*
** EPITECH PROJECT, 2021
** navy.h
** File description:
** navy
*/

#include "./my.h"
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#ifndef NAVY_H_
    #define NAVY_H_

extern char *g_var;

char *load_file(char const *filepath);
int open_file(char const *filepath);
int check_pos(char *pos);
int check_line(char *pos);
int check_size(char *pos);
int check_digits(int digit1, int digit2);
int check_letters(int letter1, int letter2);
void fill_map(int **map);
int convert_pos(char letter);
int check_navy(char *pos);
int get_digits(char nb);
void handler_bip_boop1(int nb, siginfo_t *t, void *pos);
void handler_bip_boop2(int nb, siginfo_t *t, void *);
int player_1_loop(char *pos);
int player_2_loop(char *pos, int pid);
int player_1(int argc, const char **argv);
int player_2(int argc, const char **argv);
int navy(int argc, const char **argv);
int check_pos_navy(int **map, char *pos);
int check_pos_navy_y(int **map, char *pos, int i);
int check_pos_navy_x(int **map, char *pos, int i);
int is_stacked(char *pos);
int is_stacked2(int **map, int i);
char **create_map(char *pos);
void show_map(char **map);
void place_navy(char **map, char *pos);
void place_navy_x(char **map, char *pos, int i);
void place_navy_y(char **map, char *pos, int i);
char **create_map_empty(void);
void print_both_map(char **map, char **enemy);
char *char_to_bin(char c);
char bin_to_char(char *bin);
int start_player_1(char **map, char **enemy);
int start_player_2(char **map, char **enemy, int pid);
void reset_str(char *str, int nb);
char *int_to_char(int nb);
int find_power_pid(int nb);
void send_char(char c, int pid);
void send_signal(char c, int pid);
void handler_zero(int nb, siginfo_t *t, void *);
void handler_one(int nb, siginfo_t *t, void *);
int player_1_game(char **map, char **enemy, int pid);
int player_2_game(char **map, char **enemy, int pid);
void setup_handler(void);
int is_finished(char *msg, char **map, char **enemy);
char *get_attack(void);
int check_attack(char *atk);
void attack(char **enemy, int pid, char *msg);
void attack2(char **enemy, char *msg, char *atk);
void put_attack(char **enemy, char *atk, char sign);
void receive_atk(char **map, int pid, char *msg);
void check_hit(char **map, int pid, char *msg);
int is_navy(char **map);
int is_navy2(char **map, int x, int y);
void free_all(char **map, char **enemy, char *msg);
int is_eof(void);
void quit_eof(void);
int player_2_game_2(char **map, char **enemy, int pid, char *msg);
int player_1_game_2(char **map, char **enemy, int pid, char *msg);

#endif /* !NAVY_H_ */
